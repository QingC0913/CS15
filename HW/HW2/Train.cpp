/*
    CS15 HW2
    by Qing Cheng, Oct 2021
    
    Train.cpp
    The Train object is a list of PassengerQueue objects, where each Passenger-
    Queue represents a list of Passengers in a specific train carriage. Passen-
    gers broad train carriages based on their destination stations. Note that 
    the constructor does not add Passengers to the Train; the clients have to 
    use public Train functions to add or remove Passengers from the Train. 
*/    
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Passenger.h"
#include "PassengerQueue.h"
#include "Train.h"

/* 
Train()
Purpose: default constructor, creates the obj but doesn't do anything else
Parameters: none
*/
Train::Train()
{
    
}

/*
getStationList()
Purpose: retrieves the station list and calls helper function
Parameters: ref var to an input stream file containing the list of stations
Returns: none
*/
void Train::getStationList(ifstream &stationList)
{
    initializeCarriages(stationList); 
}

/*
initializeCarriages()
Purpose: populates the vector of PQ objs by reading in stations from a file 
Parameters: ref var to an input file of station names 
Returns: nothing
Effects: resets the file getline because file was already read in MetroSim.cpp
*/
void Train::initializeCarriages(ifstream &stationList)
{
    stationList.clear();    //reset getline()
    stationList.seekg(0);
    
    string line; 
    while (getline(stationList, line) and !line.empty())  
    {
        stationNames.push_back(line);  
        PassengerQueue pq; 
        carriages.push_back(pq); 
    }
}

/*
Boarding()
Purpose: adds a Passenger to a specific train carriage based on destination 
Parameters: const ref var to a Passenger obj 
Returns: none 
*/
void Train::Boarding(const Passenger &pass)
{
    int destinStationId = pass.to; 
    //adds Passenger to the train carriage based on Passenger's destination 
    carriages.at(destinStationId - 1).enqueue(pass); 
}

/*
Exiting()
Purpose: when Train arrives at next station, Passengers whose destination is 
    at this station exit the train and the simulation 
Parameters: ref var to the output file, the current station id
Returns: none 
Effects: directs exiting Passenger info into output file 
*/
void Train::Exiting(ofstream &output, int currStationId)
{
    int carriageIdx = currStationId - 1; 
    int sizeOfCarriage = carriages.at(carriageIdx).size(); 
    for (int i = 0; i < sizeOfCarriage; i++)
    { 
        output << "Passenger " 
               << carriages.at(carriageIdx).front().id 
               << " left train at station " 
               << stationNames.at(carriageIdx) << endl;
        carriages.at(carriageIdx).dequeue(); 
    }
}

/*
printPassengersOnTrain()
Purpose: prints the list of all Passengers who are currently on the Train  
Parameters: none 
Returns: none 
Effects: prints Passenger info to output 
*/
void Train::printPassengersOnTrain()
{
    std::cout << "Passengers on the train: {"; 
    for (size_t i = 0; i < carriages.size(); i++)
    {
        carriages.at(i).print(std::cout);
    }
    std::cout << "}" << endl;
}