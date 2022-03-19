/*
    CS15 HW2
    by Qing Cheng, Oct 2021
    
    PassengerQueue.h
    PassengerQueue is a class that represents an ordered list of Passengers. 
    Every PassengerQueue instance begins empty until the client adds Passengers
    into the queue. Clients can also remove Passengers from the queue, or 
    access the first Passenger in the queue and the size of the queue.   
*/  
#ifndef __PASSENGER_QUEUE_H__
#define __PASSENGER_QUEUE_H__
#include <vector>
#include <string>
#include <ostream>

#include "Passenger.h"
using namespace std;

class PassengerQueue
{
private:
    vector<Passenger> queue; 
    
public:
    PassengerQueue(); 
    Passenger front(); 
    void dequeue(); 
    void enqueue(const Passenger &passenger); 
    int size(); 
    void print(ostream &output); 
};

#endif
