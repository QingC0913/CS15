/*
    CS15 HW2
    provided in setup files
    
    Passenger.h
    Passenger is a struct that represents a passenger in the simulation. Every
    Passenger has a unique passenger id, enters the simulation at a specific 
    arrival station, and exits the simulation at a destination station. 
*/  
#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>
#include <string>

struct Passenger
{
    int id, from, to;
    
    Passenger()
    {
        id   = -1;
        from = -1;
        to   = -1;
    }

    Passenger(int newId, int arrivalStation, int departureStation)
    {
        id   = newId;
        from = arrivalStation;
        to   = departureStation;
    }

    void print(std::ostream &output);
};

#endif
