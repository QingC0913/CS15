/*
    CS15 HW2
    provided in setup files
    
    Passenger.cpp
    Clients of the Passenger struct can access the Passenger's information 
    by using the public print() function or by accessing using the dot operator
*/  
#include <iostream>
#include <string>
#include "Passenger.h"

/*
print()
Purpose: prints to cout or output file the Passenger's info 
Parameters: ostream ref var -- where to direct output 
Returns: none
*/
void Passenger::print(std::ostream &output)
{
    output << "[" << id << ", " << from <<"->" << to << "]"; 
}
