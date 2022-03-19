/*
* CharArrayList.cpp
* 
* COMP 15 homework 1
* by C.R. Calabrese, January 2021
* edited by Qing Cheng, 9/28/2021
* 
* Stores characters in a certain order. It imitates some functions of the
* C++ string. 
* 
* Notes: this implementation uses a dynamic array. So, potential
* drawbacks as compared to the CharLinkedList class include slower insertions
* and removals at the front of the list. On the other hand, since only one
* pointer variable is needed for the entire list (as opposed to one pointer
    * per element in the CharLinkedList), the CharArrayList class has the
    * advantage of more efficient memory usage over the CharLinkedList.
    */
    
    #include "CharArrayList.h"
    
    // for print
    #include <iostream>
    
    using namespace std;
    
    /* Purpose: initializes an empty CharArrayList */
    CharArrayList::CharArrayList()
    {
        len  = 0;
        cap  = 0;
        data = nullptr;
    }
    
    /*    Purpose: initializes a CharArrayList containing one character
    * Parameters: the character that should be stored in the new list
    */
    CharArrayList::CharArrayList(char c)
    {
        len = 0;
        cap = 0;
        data = nullptr; 
        if (c != '\0')    //if input is not an empty character
        {
            data = new char[1];  //create AL of size 1  
            cap++; 
            data[0] = c;
            len++; 
        }
    }
    
    /*    Purpose: initializes a CharArrayList containing all of the specified 
    *             characters, in the given order
    * Parameters: An array (in order) of characters to be stored in the list;
    *             the length of the given array (as an int)
    */
    CharArrayList::CharArrayList(char *arr, int size)
    {
        len  = 0;
        cap  = 0;
        data = nullptr;
        if (size != 0)
        {
            data = new char[size];  
            cap = size;    //initial capacity is size of input array 
            for (int i = 0; i < size; i++)
            {
                data[i] = arr[i]; 
            }
            len = size;  
        }
    }
    
    /* Purpose: copy constructor -- creates a list with the same information as
    *          the one passed in
    * 
    *    Note: The array capacity may be different from the capacity of the list
    *          that is copied from. That is fine. What is important is that both
    *          lists will store the same information -- to the client, they will
    *          be the same.
    * 
    */
    CharArrayList::CharArrayList(const CharArrayList &other) 
    {
        len = 0; // start with an empty list
        cap = 0;
        data = nullptr;
        
        // push each item from the other list onto this one
        for (int i = 0; i < other.size(); i++) {
            pushAtBack(other.elementAt(i));
        }
    }
    
    /* Purpose: destructor -- frees all memory associated with the list */
    CharArrayList::~CharArrayList()
    {
        delete [] data;
    }
    
    /* Purpose: assignment operator -- makes the current list contain the same
    *          information as the one on the right hand side
    * 
    *    Note: The array capacity may be different from the list that is being
    *          copied from.
    * 
    */
    CharArrayList &CharArrayList::operator =(const CharArrayList &rhs) 
    {
        if (this != &rhs) 
        {
            clear(); // clear the current list
            
            // add each element from the other list into this one
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
    * 
    *       Note: "empty" refers to if the client is currently storing any
    *             information in the list. The capacity of the ArrayList is
    *             irrelevant.
    */
    bool CharArrayList::isEmpty() const 
    {
        return (len == 0);
    }
    
    /* size
    *    Purpose: Get the number of characters being stored in the list
    * Parameters: none
    *    Returns: The number of characters currently stored in the list, as an
    *             int (but will never be negative)
    */
    int CharArrayList::size() const 
    {
        return len;
    }
    
    /* first
    *    Purpose: Get the first element in the list.
    * Parameters: none
    *    Returns: The first element in the list, as a char.
    * 
    *       Note: Prints an error and exits if the list is empty.
    */
    char CharArrayList::first() const 
    {
        if (isEmpty())
        {
            cerr << "Cannot get the first element of an empty list" << endl; 
            exit(EXIT_FAILURE);
        }
        else
            return data[0]; 
    }
    
    /* last
    *    Purpose: Get the last element in the list.
    * Parameters: none
    *    Returns: The last element in the list, as a char.
    * 
    *       Note: prints an error and exits if the list is empty.
    */
    char CharArrayList::last() const 
    {
        if (isEmpty())
        {
            cerr << "Cannot get the last element of an empty list" << endl;
            exit(EXIT_FAILURE);
        }
        else
            return data[len - 1];
    }
    
    /* elementAt
    *    Purpose: Get the character at a given position.
    * Parameters: The index to be accessed, as an int. Should be in bounds; in 
    *             other words, should be in the range [0, size() )
    *    Returns: The element at the specified index, as a char
    *
    *       Note: prints an error and exits if given index is out of range.
    */
    char CharArrayList::elementAt(int idx) const
    {
        if (idx < 0 or idx >= len)
        {
            cerr << "index " << idx << " not in range [0.."
                 << len << ")" << endl; 
            exit(EXIT_FAILURE); 
        }
        else 
            return data[idx]; 
    }
    
    /* print
    *    Purpose: Prints the list to the terminal (cout)
    * Parameters: None
    *    Returns: None
    * 
    *    TODO: Currently does not work because elementAt is not implemented.
    */
    void CharArrayList::print() const
    {
        cout << "[CharArrayList of size " << len <<  " <<";
        
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
    void CharArrayList::clear() 
    {
        if (isEmpty())
            return; 
            
        len = 0;
        shrink();  
    }
    
    /* pushAtBack
    *    Purpose: Adds a character to the back of the list
    * Parameters: The character to be added to the list
    *    Returns: None
    */
    void CharArrayList::pushAtBack(char c)
    {
        if (isFull())
            expand(); 
        data[len] = c; 
        len++;
    }
    
    /* pushAtFront
    *    Purpose: Adds a character to the front of the list
    * Parameters: The character to be added to the list
    *    Returns: None
    */
    void CharArrayList::pushAtFront(char c)
    {
        if (isFull())
            expand();
        if (len > 0)
        {
            for (int i = (len - 1); i >= 0; i--)  //loop backwards 
            {
                data[i + 1] = data[i];  //move each elem forward by one index  
            }
        }
        data[0] = c;    //if the list was empty to begin with 
        len++;     
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
    */
    void CharArrayList::insertAt(char c, int idx)
    {
        if (idx < 0 or idx > len)    //can = size() which is insert at end
        {
            cerr << "index " << idx << " not in range [0.." << len << "]"
                 << endl;
            exit(EXIT_FAILURE);
        }
        if (isFull())
            expand();
            
        for (int i = (len - 1); i >= idx; i--)
        {
            data[i + 1] = data[i]; 
        }
        
        data[idx] = c; 
        len++; 
    }
    
    /* popFromFront
    *    Purpose: Removes the first element from the list
    * Parameters: None
    *    Returns: None
    *
    *       Note: Prints an error message and quits if the list is empty
    */
    void CharArrayList::popFromFront()
    {
        // confirm list is non-empty
        if (isEmpty()) {
            cerr << "Cannot pop from an empty list" << endl;
            exit(EXIT_FAILURE);
        }
        removeAt(0);
        
        if (len <= (cap / 4)) 
            shrink();
    }
    
    /* popFromBack
    *    Purpose: Removes the last element from the list
    * Parameters: None
    *    Returns: None
    * 
    *       Note: Prints an error message and exits if the list is empty
    */
    void CharArrayList::popFromBack()
    {
        // confirm list is non-empty
        if (isEmpty()) {
            cerr << "Cannot pop from an empty list" << endl;
            exit(EXIT_FAILURE);
        }
        removeAt(len - 1);
        
        if (len <= (cap / 4)) 
            shrink();
    }
    
    /* removeAt
    *    Purpose: Removes the element at a given index
    * Parameters: The position at which to remove an element, which should be the
    *             index of an element currently in the list; in other words,
    *             should be in the interval [0, size)
    *    Returns: None
    * 
    *       Note: If the amount of space in the array that is in use drops to less 
    *             than one fourth, the array should be shrunk to half its size.
    */
    void CharArrayList::removeAt(int idx)
    {
        // confirm index is in range
        if (idx < 0 or idx >= len) {
            cerr << "index " << idx << " not in range [0.." << len << ")"
            << endl;
            exit(EXIT_FAILURE);
        }
        // remove the element by shifting all subsequent elements to the left
        //"overwrite" the elem to be removed 
        for (int i = idx; i < len - 1; i++) {
            data[i] = data[i + 1];
        }
        // update the length
        len--;
        
        if (len <= (cap / 4))  
            shrink();
    }
    
    /* replaceAt
    *    Purpose: Replaces the element at the given index with the given value
    * Parameters: A character to put in the list and the index of the
    *             element to replace. The index should be in-bounds, in the
    *             range [0, size() )
    * 
    *       Note: Prints an error message and exits if the index is out of bounds
    */
    void CharArrayList::replaceAt(char c, int idx)
    {
        if (idx < 0 or idx >= len)
        {
            cerr << "index " << idx << " not in range [0.." << len << ")" 
                 << endl;
            exit(EXIT_FAILURE);
        }
        
        data[idx] = c;
    }
    
    /* concatenate
    *    Purpose: Adds the contents of a CharArrayList to the back of the current 
    *             one.
    * Parameters: A CharArrayList whose contents should be pushed to the back of
    *             the current list. Will not be altered
    *    Returns: None
    */
    void CharArrayList::concatenate(const CharArrayList &other)
    {
        int other_size = other.size();
        if (other_size == 0)
            return;  //no change is made to this AL if other AL is empty  
        
        for (int i = 0; i < other_size; i++)
        {
            pushAtBack(other.elementAt(i));
        }        
    }
    
    /* expand 
    *    Purpose: Expands the current capacity of the AL by factor of 2
                  unless the cap is 0, then just increase by 1
    * Parameters: none 
    *    Returns: None
    *    Effects: allocates space on the heap for a new AL, copies all elems 
    *            from the old list to the new. Recycles old list 
    */    void CharArrayList::expand()
    {
        if (data == nullptr)    //need this for instances created using default
        {
            data = new char[1]; 
            cap++; 
        }
        else
        {
            cap *= 2;    //WHAT IF CAP IS 0? 
            char *new_array = new char [cap]; 
            for (int i = 0; i < len; i++)
            {
                new_array[i] = data[i]; 
            }
            delete [] data;
            data = new_array;   //IS THIS CORRECT?
        }
    }
    
    /* get_cap
    *    Purpose: get the current capacity of the AL
    * Parameters: none 
    *    Returns: the current capacity 
    */
    int CharArrayList::get_cap()
    {
        return cap; 
    }
    
    /* isFull 
    *    Purpose: checks whether all allocated space in the current AL is filled
    * Parameters: none 
    *    Returns: true or false, that the list is full 
    */
    bool CharArrayList::isFull()
    {
        return (len == cap); 
    }
    
    /* shrink 
    *    Purpose: shrinks the AL by a factor of 2 when len is 1/4 of capacity 
                  unless there is only 1 (or 0) elem left 
    * Parameters: none 
    *    Returns: None
    */
    void CharArrayList::shrink()
    {
        if (cap / 2 == 0)  //if the cap is already small, no need to shrink
            return; 

        cap /= 2; 
        char *new_array = new char[cap]; 
        for (int i = 0; i < cap; i++)
        {
            new_array[i] = data[i]; 
        }
        
        delete [] data;
        data = new_array; 
    }
    