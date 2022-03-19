/*
 * Planet.cpp
 * 
 * Comp 15 Lab 2
 * Edited by Elizabeth Hom, Sept 2020
 * Edited by Matt Russell, Juliana Vega, and Alexis Blair, Jan 2021 
 * 
 * The Planet class contains functions and info regarding a Planet object.
 */

#include <ostream>
#include "Planet.h"

using namespace std;

/* 
 * Default constructor
 */
Planet::Planet() {}

/* Parametrized constructor
 *    Purpose: Creates a Planet object with the given name
 * Parameters: string - name of planet
 *    Returns: none
 */
Planet::Planet(string name, int distance_from_sun)
{
    this->name = name;
    this->distance_from_sun = distance_from_sun;
}

/* Operator= overload
 *    Purpose: Updates the information of 'this' to be the same as that of
 *             'other'
 * Parameters: string - name of planet
 *    Returns: none
 */
Planet& Planet::operator=(const Planet &other)
{
    if (this != &other){
        this->name = other.name;
        this->distance_from_sun = other.distance_from_sun;
    }
    return *this;
}

/* print
 *    Purpose: Prints out the name associated with a Planet object
 * Parameters: ostream & - where to print
 *    Returns: none
 */
void Planet::print(ostream &out) const
{
    out << this->name << " " << this->distance_from_sun;    
}


