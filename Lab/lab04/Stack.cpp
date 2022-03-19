/*
 *      Stack.cpp 
 *      PartyPlaylist 
 *      Comp 15 Lab 3
 *
 *      Implementation of the Stack class
 *
 *      2016-09-16 Created by Yennie Jun
 *      2016-09-20 Modified by Mark A. Sheldon
 *                 Added documentation
 *      2020-01-31 Modified by Juliana Vega
 *                 Removed "sequence" wording
 */


#include <iostream>
#include "Stack.h"

using namespace std;


/*  Purpose: Default constructor 
 *  Notes:   Nothing necessary. Data member construction runs automatically.
 */
Stack::Stack() 
{
        // The sequence is automatically initialized
}

/*
 * If given an initial capacity, we need to run the non-default
 * constructor for our sequence data member.
 * In C++ this is one using  something called a "member initialization
 * list," which is a bunch of initializations specified after the
 * function head and a colon and before the opening brace of the
 * function body.
 */
Stack::Stack(int initialCapacity) : stack(initialCapacity)
{
        // Work done in member initialization list
}

/*
 *  Purpose: Destructor
 */
Stack::~Stack() 
{
        // nothing to do:  sequence destructor runs automatically
}

/*
 *  Purpose: Remove top element from the stack and return it.
 */
ElementType Stack::pop()
{
        return(stack.removeFromFront()); 
}


/*
 *  Purpose:    Add given element to the top of the stack.
 *  Parameters: element - the element to add.
 *  Notes:      ElementType is defined in .h file.
 */
void Stack::push(ElementType element)
{
        (void) element;
        stack.addAtFront(element); 
}

/*
 *  Purpose: Print contents in stack in order from top to bottom.
 */
void Stack::printStack() 
{
        stack.printBuffer();
}
