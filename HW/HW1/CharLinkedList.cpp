/* 
 * CharLinkedList.cpp
 * 
 * COMP 15 homework 1
 * by C.R. Calabrese, January 2021
 * edited by Qing Cheng, 28 Sept 2021
 * 
 * Stores characters in a certain order. It imitates some functions of the
 * C++ string. 
 * 
 */

#include "CharLinkedList.h"

// for the print function
#include <iostream>

using namespace std;

/* Purpose: initializes an empty CharLinkedList */
CharLinkedList::CharLinkedList()
{
    len = 0; 
    front = tail = nullptr;
}

/*    Purpose: initializes a CharLinkedList containing one character
 * Parameters: the character that should be stored in the new list
 */
CharLinkedList::CharLinkedList(char c)
{
    len = 0; 
    front = tail = newNode(c, nullptr, nullptr); 
}

/*    Purpose: initializes a CharLinkedList containing all of the specified 
 *             characters, in the given order
 * Parameters: An array (in order) of characters to be stored in the list;
 *             the length of the given array (as an int)
 */
CharLinkedList::CharLinkedList(char *arr, int size)
{
    len = 0; 
    front = tail = nullptr; 
    for (int i = 0; i < size; i++)
    {
        pushAtBack(arr[i]);
    }    
}

/* Purpose: copy constructor -- creates a list with the same information as
 *          the one passed in
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other) 
{
    len = 0; 
    front = tail = nullptr; 
    for (int i = 0; i < other.size(); i++)
    {
        pushAtBack(other.elementAt(i)); 
    }
}

/* Purpose: destructor -- frees all memory associated with the list */
CharLinkedList::~CharLinkedList()
{
    clear(); 
}

/* Purpose: assignment operator -- makes the current list contain the same
 *          information as the one on the right hand side
 */
CharLinkedList &CharLinkedList::operator =(const CharLinkedList &rhs) 
{
    if (this != &rhs)  //if this and other objs are not the same obj  
    {
        clear(); 
        
        //add each element from the other list into this one
        for (int i = 0; i < rhs.size(); i++) 
        {
            pushAtBack(rhs.elementAt(i));
        }
    }
    return *this;
}

/* isEmpty
 *    Purpose: Check if the list is empty
 * Parameters: none
 *    Returns: a boolean -- true if the list is empty, false if it isn't
 */
bool CharLinkedList::isEmpty() const 
{
    return (len == 0);
}

/* size
 *    Purpose: Get the number of characters being stored in the list
 * Parameters: none
 *    Returns: The number of characters currently stored in the list, as an
 *             int (will never be negative)
 */
int CharLinkedList::size() const 
{
    return len;
}

/* first
 *    Purpose: Get the first element in the list.
 * Parameters: none
 *    Returns: The first element in the list, as a char.
 * 
 *       Note: Prints an error message and exits if the list is empty.
 */
char CharLinkedList::first() const 
{
    if (isEmpty())
    {
        cerr << "Cannot get the first element of an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    
    return front->data;
}

/* last
 *    Purpose: Get the last element in the list.
 * Parameters: none
 *    Returns: The last element in the list, as a char.
 * 
 *       Note: Prints an error message and exits if the list is empty.
 */
char CharLinkedList::last() const 
{
    if (isEmpty())
    {
        cerr << "Cannot get the last element of an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    
    return tail->data;
}

/* elementAt
 *    Purpose: Get the character at a given position.
 * Parameters: The index to be accessed, as an int. Should be in bounds; in 
 *             other words, should be in the range [0, size() )
 *    Returns: The element at the specified index, as a char
 *
 *       Note: prints an error and exits if given index is out of range.
 */
char CharLinkedList::elementAt(int idx) const
{
    if ((idx < 0) or (idx >= len))
    {
        cerr << "index " << idx << " not in range [0.." << len << ")" 
             << endl;
        exit(EXIT_FAILURE);
    }
    
    Node *curr = movePointer(idx);  //moves curr pointer to the node at idx
        
    return (curr->data); 
}

/* print
 *    Purpose: Prints the list to the terminal (cout)
 * Parameters: None
 *    Returns: None
 */
void CharLinkedList::print() const
{
    cout << "[CharLinkedList of size " << len << " <<"; 
    for (int i = 0; i < len; i++)
    {
        cout << elementAt(i); 
    }
    cout << ">>]" << endl;
}

/* clear
 *    Purpose: Makes the list empty
 * Parameters: None
 *    Returns: None
 */
void CharLinkedList::clear() 
{
    while (front != nullptr)
    {
        popFromFront(); 
    }   
}

/* pushAtBack
 *    Purpose: Adds a character to the back of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharLinkedList::pushAtBack(char c)
{
    if (isEmpty())
        pushAtFront(c); 
    else
    {
        tail->next = newNode(c, tail, nullptr); 
        tail = tail->next; 
    }
}

/* pushAtFront
 *    Purpose: Adds a character to the front of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharLinkedList::pushAtFront(char c)
{
    if (isEmpty())
        front = tail = newNode(c, nullptr, nullptr); 
    else
    {
        front = front->prev = newNode(c, nullptr, front); 
        //tail->prev = front;    //todo ????
    }
}

/* insertAt
 *    Purpose: Adds a character to the list at a given position
 * Parameters: The character to be added to the list and the position at which
 *             it should be added. The position should be in-bounds, that is,
 *             in the range [0, size()]. Providing size() as the index will
 *             insert the character at the back of the list.
 *    Returns: None
 *
 *       Note: prints an error and exits if given index is out of range.
 * 
 *      To-Do: Would be fun to figure out how to do this recursively -- prev
 *             pointer makes it a little more complicated
 */
void CharLinkedList::insertAt(char c, int idx)
{
    if ((idx < 0) or (idx > len))
    {
        cerr << "index "<< idx << " not in range [0.." << len 
             << "]" << endl;
        exit(EXIT_FAILURE);
    } 
    
    if (idx == 0)
        pushAtFront(c);
    else if (idx == len)
        pushAtBack(c); 
    else
    {
        Node *curr = movePointer(idx - 1);  //stops at node before desired idx  
        curr->next->prev = curr->next = newNode(c, curr, curr->next); 
    }
}

/* popFromFront
 *    Purpose: Removes the first element from the list
 * Parameters: None
 *    Returns: None
 *       Note: Prints an error message and exits if the list is empty
 */
void CharLinkedList::popFromFront() //to do, unit testing!!
{
    if (isEmpty())
    {
        cerr << "Cannot pop from an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    else if (len == 1)
    {
        delete front; 
        front = nullptr;
        len = 0; 
    }
    else 
    {
        front->next->prev = nullptr; 
        Node *curr = front; 
        front = front->next; 
        delete curr; 
        len--; 
    }   
}

/* popFromBack
 *    Purpose: Removes the last element from the list
 * Parameters: None
 *    Returns: None
 *       Note: Prints an error message and exits if the list is empty
 */
void CharLinkedList::popFromBack()
{
    if (isEmpty())
    {
        cerr << "Cannot pop from an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    else if (len == 1)
        popFromFront();
    else
    {
        Node *curr = tail; 
        tail = tail->prev; 
        tail->next = nullptr; 
        delete curr; 
        len--;
    }
}

/* removeAt
 *    Purpose: Removes the element at a given index
 * Parameters: The position at which to remove an element, which should be the
 *             index of an element currently in the list; in other words,
 *             should be in the interval [0, size)
 *    Returns: None
 */
void CharLinkedList::removeAt(int idx)
{
    if (idx < 0 or idx >= len)
    {
        cerr << "index "<< idx << " not in range [0.." << len 
             << ")" << endl;
        exit(EXIT_FAILURE);
    }
    if (idx == 0)
        popFromFront(); 
    else if (idx == len - 1)
        popFromBack(); 
    else
    {
        Node *curr = movePointer(idx);  //moves pointer to node at desired idx 
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev; 
        delete curr;
        len--; 
    }
}

/* replaceAt
 *    Purpose: Replaces the element at the given index with the given value
 * Parameters: A character to put in the list and the index of the
 *             element to replace. The index should be in-bounds, in the
 *             range [0, size() )
 *       Note: Prints an error message and exits if the index is out of bounds
 */
void CharLinkedList::replaceAt(char c, int idx)
{
    if ((idx < 0) or (idx >= len))
    {
        cerr << "index " << idx << " not in range [0.." << len << ")" 
             << endl;
        exit(EXIT_FAILURE);
    }
    
    Node *curr = movePointer(idx); 
    curr->data = c; 
}

/* concatenate
 *    Purpose: Adds the contents of a CharLinkedList to the back of the current 
 *             one.
 * Parameters: A CharLinkedList whose contents should be pushed to the back of 
 *             the current list. Will not be altered
 *    Returns: None
 */
void CharLinkedList::concatenate(const CharLinkedList &other)
{
    if (other.isEmpty())
        return; 
    for (int i = 0; i < other.size(); i++)
    {
        pushAtBack(other.elementAt(i)); 
    }
}

/* newNode 
purpose: to create and initialize a new node
parameters:the value to store, pointers to previous and next nodes
returns: the pointer to the node that was just created
notes: increases the length of the LInkedList by 1
*/

CharLinkedList::Node *CharLinkedList::newNode(char c, Node *prev, Node *next)
{
    Node *new_node = new Node;
    new_node->data = c; 
    new_node->prev = prev; 
    new_node->next = next;
    len++;  
    return new_node; 
} 

/* movePointer
 *    Purpose: Sets a pointer to point at a desired node/a node at a desired
 *              index 
 * Parameters: The desired index to which the pointer should point
 *    Returns: a pointer to the desired node 
 */
CharLinkedList::Node *CharLinkedList::movePointer(int index_to_stop) const
{
    Node *curr = front; 
    int count = 0; 
    
    while (count != index_to_stop)
    {
        curr = curr->next; 
        count++;
    }
    
    return curr; 
}