/*
    CS15 HW2
    by Qing Cheng, Oct 2021
    
    PassengerQueue.cpp
    The PassengerQueue class only supports adding Passengers to the back of the
    queue and removing Passengers from the front of the queue in order to 
    imitate a queue in real life. Note that the constructor does not add 
    Passengers to the queue; the clients have to add each Passenger using 
    the push_back() function.
*/  
#include <iostream>
#include <string>
#include <vector>
#include "Passenger.h"
#include "PassengerQueue.h"

/*
PassengerQueue()
Purpose: constructor, doesn't do anything 
Parameters: none 
*/
PassengerQueue::PassengerQueue()
{
}

/*
front()
Purpose: returns first Passenger obj without removing it 
Parameters: none
Returns: the first Passenger obj in the PassengerQueue
*/
Passenger PassengerQueue::front()
{
    if (queue.empty())
    {
        std::cerr << "the queue is empty" << endl;
        exit(EXIT_FAILURE);
    }
    return queue.front(); 
}

/*
dequeue()
Purpose: removes the first Passenger from the start of the queue
Parameters: none
Returns: none
*/
void PassengerQueue::dequeue()
{
    if (queue.empty())
    {
        std::cerr << "the queue is empty" << endl;
        exit(EXIT_FAILURE);
    }
    queue.erase(queue.begin());
}


/*
enqueue()
Purpose: adds a Passenger to the back of the queue
Parameters: const reference var to a Passenger obj to be added to the back
Returns: none
*/
void PassengerQueue::enqueue(const Passenger &passenger)
{
    queue.push_back(passenger); 
}

/*
size()
Purpose: getter function for size of PQ
Parameters: none
Returns: int size of this PQ
*/
int PassengerQueue::size()
{
    return queue.size(); 
}


/*
print()
Purpose: prints out (to cout or file) info of all Passengers in this PQ
Parameters: ref to an ostream output obj, can be cout or output file
Returns: none
*/
void PassengerQueue::print(ostream &output)
{
    for (size_t i = 0; i < queue.size(); i++)
    {
        queue.at(i).print(output);    //calling each Passenger's print() 
    }
}
