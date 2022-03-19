#include "DatumStack.h"
#include "Datum.h"
#include <stdexcept>

/*
DatumStack()
Purpose: default constructor, creates empty stack 
Parameters: none
*/
DatumStack::DatumStack()
{

}

/*
DatumStack()
Purpose: overloaded constructor, populates stack with given Datum objs
Parameters: an array of Datum objs and the size of the array
*/
DatumStack::DatumStack(Datum *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        push(arr[i]);
    }
}

/*
isEmtpy
Purpose: checks if stack is emtpy 
Parameters: none
Returns: true if is empty, false otherwise 
*/
bool DatumStack::isEmpty()
{
    return (dStack.size() == 0); 
}

/*
clear
Purpose: empties the stack 
Parameters:none
Returns: none
*/
void DatumStack::clear()
{
    dStack.clear(); 
}


int DatumStack::size()
{
    return dStack.size(); 
}
/*
top
Purpose: returns the Datum obj at the top of the stack 
Parameters: none 
Returns: Datum obj at the top of the stack, throws error if stack is empty 
*/
Datum DatumStack::top()
{
    if (isEmpty())
        throw std::runtime_error("empty_stack"); 
    return dStack.back(); 
     
}

/*
push
Purpose: adds an obj onto the stack 
Parameters: the obj to push onto the stack 
Returns: none
Effects: adds an obj to the stack
*/
void DatumStack::push(Datum &datum)
{
    dStack.push_back(datum); 
}

/*
pop
Purpose: removes the obj at the top of the stack
Parameters: none
Returns: none
Effects: the top object is removed, throws error if stack is empty 
*/
void DatumStack::pop()
{
    if (isEmpty())
        throw std::runtime_error("empty_stack"); 
    dStack.pop_back(); 
}

