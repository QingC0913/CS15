/*
    CS15 HW2
    by Qing Cheng, Oct 2021
    
    Train.h
    Train is a class that represents a train, where each train carriage 
    contains an ordered list of Passengers. The Train object keeps track of the
    Passengers that are currently on board, and clients can use Train function-
    alities to to have Passengers get on or off the Train. 

*/

#ifndef __TRAIN_H__
#define __TRAIN_H__

#include <iostream>
#include <string>
#include <vector>

#include "Passenger.h"
#include "PassengerQueue.h"

class Train
{
private:
    vector<PassengerQueue> carriages;    //each carriage is a PQ
    vector<string> stationNames; 
    void initializeCarriages(ifstream &stationList);

public: 
    Train();
    void getStationList(ifstream &stationList);
    void Boarding(const Passenger &pass); 
    void Exiting(ofstream &output, int currStationId); 
    void printPassengersOnTrain(); 
}; 

#endif
