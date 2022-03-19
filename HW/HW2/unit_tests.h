/* 
 * unit_tests.h
 * 
 * CS 15 homework 2
 * Qing Cheng, 28 Sept 2021
 * 
 * Uses Matt Russell's unit_test framework to test functions 
 */

#include <cassert>
#include <iostream>
#include "MetroSim.h"
#include "Train.h"
#include "PassengerQueue.h"
#include "Passenger.h"

using namespace std;

/*-----------------------------------------------------------------
                            Passenger
------------------------------------------------------------------*/
/*Purpose: tests the Passenger class's print function
Parameters: none
Returns: none
*/
void Passenger_print()
{
    Passenger pass; 
    pass.print(cout);    //default values = -1

    Passenger pass2(1, 5, 7); 
    pass2.print(cout); 
}

/*-----------------------------------------------------------------
                            PassengerQueue
------------------------------------------------------------------*/
/*Purpose: tests the PassengerQueue's constructor
Parameters: none
Returns: none
*/
void PassengerQueue_const()
{
    // PassengerQueue pq;  //throws error bc no arg given 
    PassengerQueue pq1;
}

/*Purpose: tests the PassengerQueue's enqueue function
Parameters: none
Returns: none
*/
void PassengerQueue_enqueue()
{
    Passenger pass(1, 2, 3); 
    Passenger pass2(2, 2, 3); 
    PassengerQueue pq; 
    cout << pq.size() << endl; //should be 0
    pq.enqueue(pass); 
    cout << pq.size() << endl;  //should be 1
    pq.enqueue(pass2); 
    cout << pq.size() << endl;  //should be 2
}

/*Purpose: tests the PassengerQueue's size function
Parameters: none
Returns: none
*/
void PassengerQueue_size()
{
    PassengerQueue pq1;
    cout << pq1.size() << endl;  //should be 0 
}

/*Purpose: tests the PassengerQueue's front function
Parameters: none
Returns: none
*/
void PassengerQueue_front()
{
    PassengerQueue pq1;
    // pq1.front().print(cout);  //test will fail, queue is empty
    Passenger pass(1, 2, 3); 

    pq1.enqueue(pass);
    pq1.front().print(cout); 
}

/*Purpose: tests the PassengerQueue's print function
Parameters: none
Returns: none
*/
void PassengerQueue_print()
{
    PassengerQueue pq1;
    PassengerQueue pq2; 
    Passenger pass1(1, 0, 0); 
    Passenger pass2(2, 0, 0); 
    Passenger pass3(3, 0, 0); 

    pq1.print(cout);
    pq2.print(cout);    
}

/*Purpose: tests the PassengerQueue's dequeue function
Parameters: none
Returns: none
*/
void PassengerQueue_dequeue()
{
    PassengerQueue pq1;
    Passenger pass1(1, 0, 0); 
    Passenger pass2(2, 0, 0); 
    Passenger pass3(3, 0, 0); 
    pq1.enqueue(pass1); 
    pq1.enqueue(pass2); 
    pq1.enqueue(pass3);
    pq1.dequeue(); 
    pq1.print(cout);  //should print 2 Passengers
}

