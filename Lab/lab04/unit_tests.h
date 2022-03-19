#include <cassert>
#include <iostream>
#include "CircularBuffer.h"

using namespace std;

void test_constructor()
{
    CircularBuffer cb; 
    cb.addAtBack("first one");
    cb.addAtFront("the real first one!");
    cb.addAtBack("the last one!");
    cb.printBuffer();

}