/* 
 * LinkedList.cpp
 * 
 * COMP 15 homework 1
 * by C.R. Calabrese, January 2020
 * Edited by Matt Russell, Juliana Vega, and Alexis Blair, Jan 2021 
 * 
 * An implementation of the LinkedList interface, the LinkedList can be used
 * to store Planets. 
 * 
 * NOTE: This is implemented using a singly-linked list with no back pointer.
 */
#include <ostream>
#include "LinkedList.h"

using namespace std;

/* Purpose: initializes an empty LinkedList */
LinkedList::LinkedList()
{
    front = nullptr;
    size  = 0;
}

/* print
 *    Purpose: Prints the list to the provided ostream
 * Parameters: an ostream to print to
 *    Returns: None
 */
void LinkedList::print(ostream &out) const
{
    out << "\nLinkedList of size " << this->size << "\n";
    out << "---------------------\n";
    
    Node *curr = this->front;
    while (curr != nullptr){
        curr->print(out);
        out << endl;
        curr = curr->next;
    }
       
    out << "\n" << endl;
}


/* ****************************************
 * TODO: implement the pushAtFront function
 * **************************************** 
 * pushAtFront
 *    Purpose: Adds a Planet to the front of the list
 * Parameters: The Planet to be added to the list
 *    Returns: None
 */
void LinkedList::pushAtFront(Planet p)
{
    //we have a Planet obj as an input
    //create a new node, where the info struct = p 
    //insert new node after the front var
    //Planet new_p = p; 
    Node *new_node = new Node; 
    new_node->info = p; 
    new_node->next = front; 
    front = new_node; 
    size++; 
}



/* ****************************************
 * TODO: implement the reverse function
 * **************************************** 
 * reverse
 *    Purpose: reverses the list
 * Parameters: None
 *    Returns: None
 */
void LinkedList::reverse()
{
    
}

/* 
 * ****************************************
 * TODO: implement the pushAtBack function
 * ****************************************
 * pushAtBack
 *    Purpose: Adds a Planet to the back of the list
 * Parameters: The Planet to be added to the list
 *    Returns: None
 */
void LinkedList::pushAtBack(Planet p)
{
    if (front == nullptr)  
        pushAtFront(p); 
    else
    {
        Node *new_node = new Node; 
        new_node->info = p; 
        Node *curr = front; 
        
        while (curr->next != nullptr)
        {
            curr = curr->next; 
        }
        curr->next = new_node; 
        new_node->next = nullptr; 
        size++; 
    }
        
}

