#include <iostream>
#include <fstream>
using namespace std; 

/*
parseRString
Purpose: reads inputstream and convert input into a string
Parameters: stream of input 
Returns: the command from the stream, as a string 
*/
string parseRString(istream &input)
{
    string cmd = "{ ";
    string s; 

    input >> s; 
    while(!input.fail()) 
    {   
        if (cmd[cmd.length() - 1] == '}') // //add space after non-final bracket
            cmd += " ";
        
        if (s == "}")    //base case
            return cmd += "}";   //bracket and no space at the end!  

        else if (s == "{")
            cmd += parseRString(input);    //recursive case
 
        else if (s != "\n")    //skip new line chars
        {
            cmd += s; 
            // stream doesn't read space so manually add space 
            cmd += " ";   
        }
        
        input >> s; 
    }
    
    throw runtime_error("reached end of program when searching for }");
    return cmd;  //will not get here; if unmatched {}, input is not valid anyway
}

