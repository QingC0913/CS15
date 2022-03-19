/*
 * SixDegrees.cpp
 *
 * COMP 15 Project 2: Six Degrees of Collaboration
 * 
 * by Qing Cheng, 12/4/2021
 * 
 * purpose: 
    Represent the graph traversal program, where a graph is created based on
    the client's input file. The client can choose from several types of 
    traversals by providing input, whether from a file or using commandline.
    The cilent should call the program to start.  
 */

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

#include "Artist.h"
#include "CollabGraph.h"
#include "SixDegrees.h"
using namespace std; 

/*
SixDegrees 
Purpose: constructor, populates a graph with vertices and edges 
Parameters: reference var to an input file containing info about Artists
Effects: calls helper functions to populate the graph
*/
SixDegrees::SixDegrees(ifstream &artistFile)
{
    populate_artist_vector(artistFile); 

    graph.populate_graph(artist_vector); 
}

/*
~SixDegrees 
Purpose: default destructor
Parameters: none
*/
SixDegrees::~SixDegrees()
{

}

/*
populate_artist_vector
Purpose: populate a vector with a list of Artists and their songs
Parameters: a ref var to an input file containing artist info  
Returns: a populated vector 
*/
void SixDegrees::populate_artist_vector(ifstream &artistFile)
{
    string line; 

    while (getline(artistFile, line)) 
    {
        //store artist name as artist instance
        Artist a(line);    

        //add songs to Artist's discography
        while (getline(artistFile, line) and line != "*") 
        {
            //ignore empty lines for song names
            if (line != "")  
                a.add_song(line); 
        }
        artist_vector.push_back(a); 
    }

}

/*
initialize
Purpose: takes user commands and perform corresponding tasks,
    directing any output to the appointed output stream 
Parameters: ref var to input and output streams 
Returns: none
Note: traversal algorithms are not yet implemented for phase 1 
*/
void SixDegrees::initialize(istream &input, ostream &output)
{
    string line; 
    while (getline(input, line))
    {
        if (line == "print")
        {
            if (not artist_vector.empty())
                graph.print_graph(output);
        }

        else if (line == "quit")
            return; 

        else if (line == "dfs" or line == "bfs" or line == "not")
        {   
            //checks whether each given Artist is a vertex
            vector<string> name = checking(input, output, line); 

            //bfs and not commands take similar approaches for shortest path
            if (not name.empty() and (line == "bfs" or line == "not"))
                bfs(name, line, output);

            else if (not name.empty() and line == "dfs")
                dfs(name, output);
        }
        else 
            output << line << " is not a command. Please try again.\n";
    }
}

/*
print_path
Purpose: prints each intermediate connection from start to end vertices
Parameters: two Artists instances that are the start and end vertices 
    respectively, and the ref var to the output stream
Returns: none
*/
void SixDegrees::print_path(const Artist& source, 
                            const Artist& dest, ostream &output)
{
    //get the stack of Artists in the path
    stack<Artist> path = graph.report_path(source, dest); 
    if (path.size() < 2)
    {
        output << "A path does not exist between \"" << source.get_name()
             << "\" and \"" << dest.get_name() << "\"." << endl; 
        return;
    }

    while (path.size() > 1)  
    //no more collab if there is only one Artist left in stack 
    {
        Artist one = path.top(); 
        path.pop(); 
        //artist two will be the top for the next iteration 
        Artist two = path.top(); 

        string song_name = graph.get_edge(one, two); 

        output << "\"" << one.get_name() << "\" collaborated with \"" 
             << two.get_name() << "\" in \"" << song_name << "\"." << endl;
    }

    output << "***\n";
}

/*
dfs
Purpose: performs depth-first traversal on given artists
Parameters: a vector of artist names, should only contain source and dest names
    a ref var to an output stream
Returns: none
Effects: calls a recursive helper function and the print_path function
*/
void SixDegrees::dfs(vector<string> name, ostream &output)
{
    Artist start_a(name.at(0)); 
    Artist end_a(name.at(1));

    dfs_helper(start_a, start_a, end_a);
    print_path(start_a, end_a, output); 

}

/*
dfs_helper
Purpose: recursively traverses the graph in a dfs manner
Parameters: three artists: the curr artist being processed, 
    the source and the destination artists 
Returns: true if dest is found
*/
bool SixDegrees::dfs_helper(Artist curr, Artist start, Artist dest)
{
    if (curr == dest)
        return true; 
        
    if (graph.is_marked(curr))
        return false;

    graph.mark_vertex(curr);

    vector<Artist> neighbors = graph.get_vertex_neighbors(curr); 
    
    for (size_t i = 0; i < neighbors.size(); i++)
    {
        //for each neighbor that is not the source, mark its pred as itself 
        if (neighbors.at(i) != start)
            graph.set_predecessor(neighbors.at(i), curr); 
        
        //if can get to dest from this neighbor, don't need to iterate 
        //thru other neighbors, break out of loop
        if (dfs_helper(neighbors.at(i), start, dest))
            i = neighbors.size();  
    }
    return false; 
}

/*
checking
Purpose: reads in artists' names and check whether they're valid vertices
     in the graph
Parameters: ref vars to input and output streams, the string command from the 
    command loop
Returns: a vector of names
    for bfs and dfs, should just be the start and dest artist' names
    for not, should be the two as well as any artists to exclude
Effects: calls the valid_vertices function
*/
vector<string> SixDegrees::checking(istream &input, ostream &output, string cmd)
{
    string start, end, to_exclude; 
    vector<string> name; 
    getline(input, start); 
    getline(input, end);
    name.push_back(start); 
    name.push_back(end);
    
     if (cmd == "not") 
     {
        while (getline(input, to_exclude) and not (to_exclude == "*")) 
        {
            //push each artist to exclude onto vector
            if (to_exclude != "")
                name.push_back(to_exclude); 
        }
    }

    //check if each artist is a vertex in graph
    if (not valid_vertices(output, name))
    {
        //if any is invalid, return empty vector 
        vector<string> empty; 
        return empty;  //return 
    }
    
    //ready for traversal, clear the data
    graph.clear_metadata(); 
    return name; 
}

/*
bfs
Purpose: traverses the graph in a breadth-first search manner on given artists
Parameters: a vector of artist names, should only contain source and dest names
    a ref var to an output stream
Returns: none
Effects: calls the print_path function
*/
void SixDegrees::bfs(vector<string> name, string cmd, ostream &output)
{
    Artist start_a(name.at(0));    //get start artist name 
    Artist end_a(name.at(1));      //get dest artist name
    queue<Artist> artist_queue; 
    Artist curr; 
    artist_queue.push(start_a);    //start vertex is pushed onto queue

    while (not artist_queue.empty()) {
        curr = artist_queue.front(); 
        artist_queue.pop(); 
        if (curr == end_a) {       //if reached the dest, return
            print_path(start_a, end_a, output); 
            return; 
        }
        // if (cmd == "not" and not graph.is_marked(curr) and not name.empty()) {
        //     for (size_t i = 2; i < name.size(); i++) {
        //         //mark as visited, so no need to check whether to exclude again
        //         if (name.at(i) == curr.get_name())
        //             graph.mark_vertex(curr);    
        //     }
        // }
        if (not graph.is_marked(curr)) {
            vector<Artist> neighbors = graph.get_vertex_neighbors(curr); 
            for (size_t i = 0; i < neighbors.size(); i++) {
                if (neighbors.at(i) != start_a)  
                    graph.set_predecessor(neighbors.at(i), curr); 
                artist_queue.push(neighbors.at(i)); 
            }
            graph.mark_vertex(curr); 
        }
    }
    print_path(start_a, end_a, output);
}

/*
valid_vertices
Purpose: checks whether each artist in the given vector is a valid vertex 
    in the graph
Parameters: ref var to an output stream, a vector of artist names
Returns: true if all are valid, false if any is invalid
*/
bool SixDegrees::valid_vertices(ostream &output, const vector<string>& artists)
{
    bool success = true; 
    string str; 
    for (size_t i = 0; i < artists.size(); i++)
    {
        str = artists.at(i); 

        //will print error msg for each invalid vertex
        //if any is invalid, will return false
        if (not graph.is_vertex(str))
        {
            output << "\"" << str << "\" was not found in the dataset :(\n";
            success = false; 
        }
    }

    return success; 
}
