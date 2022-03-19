/*
    CS15 HW2
    by Qing Cheng, Oct 2021
    
    MetroSim.h
    MetroSim is a class that represents the Metro Simuation itself. It 
    processes user commands and facilitates movement of the Train as well as 
    the movement of the Passengers. All the client has to do is to call the 
    MetroSim instance to start the simulation.
*/    
#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"

// Put any other necessary includes here
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "PassengerQueue.h"
#include "Train.h"

class MetroSim
{
    
private:
    // Put any other structs you need here
    struct a_station    //represents an individual station 
    {
        string name;
        PassengerQueue stationQueue; 
    };   
     
    size_t currStationId; 
    size_t numStations; 
    int numPassIds; 
    Train train; 
    vector<a_station> stations; 

    void initializeStations(ifstream &stationList);
    void processCommand(istream &command, ofstream &output);
    void checkPCommand(string line);
    bool isCommand(string line, string correctCmd); 
    void callExitFail(size_t numToCheck);
    void addPassenger(int arr, int des);
    string removeLeadingWhitespace(string line);
    void moveTrain(ofstream &output);
    void nextStationId();
    void printMap();
    void endSimulation();
        
public:
    MetroSim();
    MetroSim(ifstream &stationList);
    void startSimulation(istream &command, ofstream &output);
};

#endif
