/*
    CS15 HW2
    by Qing Cheng, Oct 2021
    
    MetroSim.cpp
    The client should pass in a list of station names in order for the Metro-
    Sim instance to inistantiate the train Stations and the Train object. 
    After that, the MetroSim instance will read in and process each of the 
    client's commands and add Passengers to the simulation, move the Train and
    faciliate where the Passengers go, or end the simulation. 

    bugs: 
    -if there is a blank line in the stations file, the program will skip 
    reading it, but it could affect other functions related to vector bounds 
    -does not support capitalized inputs, even in the correct format 
*/    
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Passenger.h"
#include "PassengerQueue.h"
#include "Train.h"
#include "MetroSim.h"

/*
Purpose: default constructor 
Parameters: none
*/
MetroSim::MetroSim()
{
    
}

/*
MetroSim()
Purpose: constructor, initializes member vars, create Stations and the Train 
Parameters: ref var to the input file of station names
*/
MetroSim::MetroSim(ifstream &stationList)
{    
    currStationId = 1; 
    numPassIds = 0; 
    numStations = 0; 
    initializeStations(stationList); //to update num of stations
    train.getStationList(stationList);  //to initialize Train obj
}

/*
startSimulation()
Purpose: the driver file/program should call this func to begin the simulation 
Parameters: command line args -- ref var to the input file of commands, or cin 
    and the output file 
Returns: none 
Effects: prints to cout Passengers on the train (should be empty) and the map
*/
void MetroSim::startSimulation(istream &command, ofstream &output)
{
    train.printPassengersOnTrain(); 
    printMap(); 
    processCommand(command, output);
}

/*
processCommand()
Purpose: reads each line in command input file/cin, process each command 
Parameters: ref var to the input file of commands, or cin, and the output file 
Returns: none 
*/
void MetroSim::processCommand(istream &command, ofstream &output)
{
    string line;   
    cout << "Command? ";
    while (getline(command, line) and (!line.empty()))
    {
        line = removeLeadingWhitespace(line); 
        if (isCommand(line, "mm"))    //metro move 
            moveTrain(output); 
            
        else if (line[0] == 'p')  //adding passengers
        {
            string sub = line.substr(1);    //to get arr and des station ids
            checkPCommand(sub); 
        }
        
        else if (isCommand(line, "mf"))  //metro finish 
            endSimulation();
            
        train.printPassengersOnTrain(); 
        printMap(); 
        cout << "Command? ";
    }
    
    endSimulation();    //reached end of file
}

/*
checkPCommand()
Purpose: checks whether user has entered valid command for adding passengers 
Parameters: a string line of command from input file 
Returns: none 
Effects: removes whitespace from the line of command, stores arrival and 
    destination station ids as ints and check whether they are within range 
    if there is any error in stoi or range, the program will exit 
*/
void MetroSim::checkPCommand(string line)
{
    size_t i = 0, arrivalStationId, destinStationId; 
    
    try
    {
        line = removeLeadingWhitespace(line);
        arrivalStationId = stoi(line);  
            
        while(i != line.length() and line[i] != ' ')
        {
            i++;  //find the destination id in the string line of command 
        }
        
        if ((i == 0) or (i == line.length()))  //if user enters e.g. p 12 
            endSimulation(); 
        else 
        {
            string line2 = removeLeadingWhitespace(line.substr(i));  
            destinStationId = stoi(line2);
            callExitFail(arrivalStationId);  //if out of bounds, will exit 
            callExitFail(destinStationId);
            //if everything is correct, add a new Passenger to the simulation! 
            addPassenger(arrivalStationId, destinStationId);}
        }
        
    catch(exception &err)
    {
        endSimulation();  //if one or both stoi calls fail, exit
    }
}

/*
callExitFail()
Purpose: will call exit fail if arrival or destination station id of a 
    Passenger is out of range 
Parameters: the station id to check 
Returns: none 
Effects: will print to cout that there is a floating exception, as demonstrated
    in the reference program, then exit 
*/
void MetroSim::callExitFail(size_t numToCheck)
{
    if (numToCheck < 1 or numToCheck > numStations)
    {
        cerr << "Floating exception" << endl;
        exit(EXIT_FAILURE); 
    }
}

/*
removeLeadingWhitespace() 
Purpose: removes the spaces in the front of a line of command or a string 
Parameters: the string to check 
Returns: the string without leading whitespaces  
*/
string MetroSim::removeLeadingWhitespace(string line)
{
    int l = line.length(); 
    int start = 0; 
    string to_return = ""; 
    
    for (int i = 0; i < l; i++)
    {
        if (line[i] != ' ')
        {    
            start = i;  //find where first non-space char is
            i = l;    //get out of loop 
        }    
    }
    
    for (int i = start; i < l; i++)
    {
        to_return += line[i]; //copy over the rest of the string 
    }
    
    return to_return;
}

/*
addPassenger()
Purpose: adds a passenger to the simulation 
Parameters: the arrival and destination station ids
Returns: none 
Effects: creates new Passenger, assigns id to Passenger, enqueue by arr station
*/
void MetroSim::addPassenger(int arr, int des)
{
    numPassIds++;  //hand out Passenger ids  
    Passenger person(numPassIds, arr, des);
    
    stations.at(arr - 1).stationQueue.enqueue(person);
}

/*
isCommand()
Purpose: checks whether the metro move/metro finish commands are valid 
Parameters: one line of command, the correct command i.e. "m m" or "m f"
Returns: none 
*/
bool MetroSim::isCommand(string line, string correctCmd)
{
    string nonSpaces = ""; 
    for (size_t i = 0; i < line.length(); i++)  //removes all spaces 
    {
        if (line[i] != ' ')
            nonSpaces += line[i]; 
    }

    size_t found = nonSpaces.find(correctCmd); 
    return (found != string::npos);  //checks if correct cmd is in line 
}

/*
moveTrain() 
Purpose: Passengers at curr station get on train, train moves to next station, 
    passengers exit from the train and from the simulation 
Parameters: ref var to the output file 
Returns: none 
*/
void MetroSim::moveTrain(ofstream &output)
{
    int currStationIdx = currStationId - 1;
    int queueLen = stations.at(currStationIdx).stationQueue.size(); 
    for (int i = 1; i <= queueLen; i++)  
    {
        //each person at the current station get on the train 
        train.Boarding(stations.at(currStationIdx).stationQueue.front()); 
        stations.at(currStationIdx).stationQueue.dequeue(); 
    }
    
    nextStationId(); //move train to next station
    //arrive at new station, passengers get off train
    train.Exiting(output, currStationId);  
}

/*
nextStationId() 
Purpose: moves the Train to the next station in a circular fashion 
Parameters: none 
Returns: none 
Effects: updates currStationId
*/
void MetroSim::nextStationId()
{
    currStationId++; 
    
    if (currStationId == numStations + 1)
        currStationId = 1; 
}

/*
endSimulation()
Purpose: terminate simulation either because end of file is reached or user 
    wants to quit 
Parameters: none 
Returns: none 
Effects: prints to cout an ending message and exit success
*/
void MetroSim::endSimulation()
{
    cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
    exit(EXIT_SUCCESS);
}

/*Purpose: to create Stations 
Parameters: ref var to the list of stations (given as commandline arg)
Returns: none 
Effects: changes numStations 
*/
void MetroSim::initializeStations(ifstream &stationList)
{
    string line; 
    while (getline(stationList, line))
    {
        if (!line.empty())
        {
            numStations++;
            //initializing a struct, which contains a station name & a PQ obj
            a_station temp_struct;  
            temp_struct.name = line; 
            temp_struct.stationQueue = PassengerQueue(); 
            stations.push_back(temp_struct);
        }
    }
}

/*
printMap()
Purpose: prints to cout all the stations, all Passengers in line at each 
    station, and where the Train is 
Parameters: none 
Returns: none 
*/
void MetroSim::printMap()
{
    for (size_t i = 0; i < numStations; i++)
    {
        string name = stations.at(i).name;
        if (currStationId == i + 1)
            cout << "TRAIN: ";
        else
            cout << "       ";
        cout << "[" << (i + 1) << "] "; 
        cout << name << " {"; 
        stations.at(i).stationQueue.print(cout); 
        cout << "}" << endl; 
    }
}
