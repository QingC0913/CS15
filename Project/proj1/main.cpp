#include <iostream>
#include <fstream>
#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"

std::string parseRString(std::istream &input);

int main(int argc, char *argv[])
{
    (void) argc; 
    (void) argv; 

    RPNCalc calc; 
    calc.run(); 

    return 0;
}