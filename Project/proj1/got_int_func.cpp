#include <string>
#include <iostream>

/*
got_int
Author:  Mark A. Sheldon, Tufts University, Fall 2016
Purpose: A function that will tell you whether a string can be interpreted
         as a integer number, and, if so, give the value. 
Parameters: string to check, pointer to an int var in which to store the 
    value if the string can be converted into an int
Returns: true if the string can be interpreted as an int, false otherwise
*/
bool got_int(std::string s, int *resultp)
{
        /* Holds the first non-whitespace character after the integer */
        char extra;

        return sscanf(s.c_str(), " %d %c", resultp, &extra) == 1;
}