#include <iostream>
#include <fstream>
#include <sstream>
using namespace std; 

string parseRString(istream &input);

int main(int argc, char *argv[])
{
    (void) argc; 
    (void) argv; 

    //to test cin input
    cout << "this is the string: " << parseRString(cin) << endl; 

    // to test input file 
    ifstream input; 
    input.open("cmds.txt"); 
    if (not input.is_open())
    {
        cerr << "Error: could not open file cmds.txt" << endl;
        exit(EXIT_FAILURE); 
    }
    
    try 
    {
         cout << parseRString(input) << endl; 
    }
    catch(const runtime_error &e)  //for if } is not found in input file
    {
        cout << "Error: " << e.what() << endl; 
    }
    return 0;
}
