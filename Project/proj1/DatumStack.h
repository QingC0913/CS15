#ifndef __DATUMSTACK_H__
#define __DATUMSTACK_H__

#include "Datum.h"
#include <vector>
#include <iostream>

class DatumStack
{
private: 
    std::vector<Datum> dStack; 

public: 
    DatumStack(); 
    DatumStack(Datum *arr, int size); 
    bool isEmpty(); 
    void clear(); 
    int size();
    Datum top(); 
    void pop(); 
    void push(Datum &datum); 
};

#endif