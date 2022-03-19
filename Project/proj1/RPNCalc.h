#ifndef __RPNCALC_H__
#define __RPNCALC_H__

#include "Datum.h"
#include "DatumStack.h"
#include <vector>
#include <iostream>

class RPNCalc
{
private:
    DatumStack ds; 
    void run(std::string cmd, std::istream &input);
    void intDatum(int value);
    void boolDatum(std::string cmd);
    void notOperation();
    void dupOperation();
    void swapOperation(); 
    void arithOperations(std::string cmd);
    void boolOperations(std::string cmd); 
    void equalOperation();
    void printOperation();
    void dropOperation();
    void rStringOperation(std::istream &input); 
    void execOperation();
    void fileOperation(); 
    void runFileCommands(std::istream &input);
    void ifOperation(); 
    void quitOperation(); 

public:
    RPNCalc(); 
    ~RPNCalc(); 
    void run(); 

};


#endif