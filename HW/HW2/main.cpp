/*
    CS15 HW2
    by Qing Cheng, Oct 2021
    
    main.cpp
    This is the driver file for the MetroSim program. 
    Run this file and provide the necessary inputs to start the simulation
    The simulation will start automatically if the input files are valid. 
*/  
#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

template<typename streamtype>
void openedSuccessfully(streamtype &stream, string fileName); 

int main(int argc, char *argv[])
{
    if (argc != 3 and argc != 4)
    {
        std::cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]"
                  << endl;
        exit(EXIT_FAILURE); 
    }
    
    ifstream stationsList; 
    openedSuccessfully(stationsList, argv[1]);
    ofstream output_file; 
    openedSuccessfully(output_file, argv[2]);
    
    MetroSim metro(stationsList);  //create and initialize MetroSim obj
    
    if (argc == 4)  //determines what the input method is, input file or cin 
    {
        ifstream commands_file; 
        openedSuccessfully(commands_file, argv[3]);
        metro.startSimulation(commands_file, output_file); 
    }
    else
        metro.startSimulation(cin, output_file);
    
    return 0;
}

/*
openedSuccessfully()
Purpose: checks whether all in/out-put files are opened correctly 
Parameters: ref var to an input or output stream, name of file to open 
Returns: none
Effects: cerr and exit if file can't be opened 
*/
template<typename streamtype>
void openedSuccessfully(streamtype &stream, string file_name)
{
    stream.open(file_name); 
    if (not stream.is_open())
    {
        std::cerr << "Error: could not open file " << file_name << endl;
        exit(EXIT_FAILURE); 
    }
}
