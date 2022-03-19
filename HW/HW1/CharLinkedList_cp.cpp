/* 
 * CharLinkedList.cpp
 * 
 * COMP 15 homework 1
 * by C.R. Calabrese, January 2021
 * edited by [NAME], [DATE]
 * 
 * Stores characters in a certain order. It imitates some functions of the
 * C++ string. 
 * 
 * NOTE: This is implemented using a doubly-linked list. It is not circular
 *       and does not have a "back" pointer.
 */

#include "CharLinkedList.h"

// for the print function
#include <iostream>

using namespace std;

/* Purpose: initializes an empty CharLinkedList */
CharLinkedList::CharLinkedList()
{
    // TODO
}

/*    Purpose: initializes a CharLinkedList containing one character
 * Parameters: the character that should be stored in the new list
 */
CharLinkedList::CharLinkedList(char c)
{
    // TODO
}

/*    Purpose: initializes a CharLinkedList containing all of the specified 
 *             characters, in the given order
 * Parameters: An array (in order) of characters to be stored in the list;
 *             the length of the given array (as an int)
 */
CharLinkedList::CharLinkedList(char *arr, int size)
{
    // TODO
}

/* Purpose: copy constructor -- creates a list with the same information as
 *          the one passed in
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other) 
{
    // TODO
}

/* Purpose: destructor -- frees all memory associated with the list */
CharLinkedList::~CharLinkedList()
{
    // TODO
}

/* Purpose: assignment operator -- makes the current list contain the same
 *          information as the one on the right hand side
 */
CharLinkedList &CharLinkedList::operator =(const CharLinkedList &rhs) 
{
    // TODO
    return *this;
}

/* isEmpty
 *    Purpose: Check if the list is empty
 * Parameters: none
 *    Returns: a boolean -- true if the list is empty, false if it isn't
 */
bool CharLinkedList::isEmpty() const 
{
    // TODO
    return true;
}

/* size
 *    Purpose: Get the number of characters being stored in the list
 * Parameters: none
 *    Returns: The number of characters currently stored in the list, as an
 *             int (will never be negative)
 */
int CharLinkedList::size() const 
{
    // TODO
    return 0;
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
    // TODO
    return 'a';
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
    // TODO
    return 'a';
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
    // TODO
    return 'a';
}

/* print
 *    Purpose: Prints the list to the terminal (cout)
 * Parameters: None
 *    Returns: None
 */
void CharLinkedList::print() const
{
    // TODO
}

/* clear
 *    Purpose: Makes the list empty
 * Parameters: None
 *    Returns: None
 */
void CharLinkedList::clear() 
{
    // TODO
}

/* pushAtBack
 *    Purpose: Adds a character to the back of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharLinkedList::pushAtBack(char c)
{
    // TODO
}

/* pushAtFront
 *    Purpose: Adds a character to the front of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharLinkedList::pushAtFront(char c)
{
    // TODO
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
    // TODO
}

/* popFromFront
 *    Purpose: Removes the first element from the list
 * Parameters: None
 *    Returns: None
 *       Note: Prints an error message and exits if the list is empty
 */
void CharLinkedList::popFromFront()
{
    // TODO
}

/* popFromBack
 *    Purpose: Removes the last element from the list
 * Parameters: None
 *    Returns: None
 *       Note: Prints an error message and exits if the list is empty
 */
void CharLinkedList::popFromBack()
{
    // TODO
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
    // TODO
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
    // TODO
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
    // TODO
}
