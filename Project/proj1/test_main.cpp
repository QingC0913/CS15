#include "RPNCalc.h"
#include "DatumStack.h"
#include "Datum.h"
#include <iostream>
using namespace std; 

int main(int argc, char *argv[])
{
    (void) argc; 
    (void) argv; 

    // cout << "-------------TESTING DATUMSTACK CLASS--------------\n"; 
    Datum d1("one");
    Datum d2(2); 
    Datum d3(true);
    DatumStack ds; 

    cout << "this tests the push function\n"; 
    ds.push(d1);  //bottom
    ds.push(d2);  //middle
    ds.push(d3);  //top 

    cout << "this tests the isEmtpy function\n"; 
    if (ds.isEmpty())
        cout << "      is emtpy" << endl; 
    else   
        cout << "      not empty" << endl;


    cout << "this tests the top function\n"; 
    cout << "      top item is: " << ds.top().toString() << endl;

    cout << "this tests the pop function\n";  
     //toString() was only included in DatumStack for testing, is removed 
    // ds.toString(); 
    ds.pop(); 
    // ds.toString(); 
    ds.pop(); 
    // ds.toString(); 
    ds.pop(); 
    ds.clear(); 
    if (ds.isEmpty())
        cout << "      is emtpy" << endl; 
    else   
        cout << "      not empty" << endl;

    cout << "this tests the overloaded constructor\n"; 
    Datum a("two"); 
    Datum b(false); 
    Datum c(9); 
    Datum d(c); 
    Datum dArray[] = {a, b, c, d}; 
    
    DatumStack ds2(dArray, 4); 
    // ds2.toString(); 

    cout << "this tests the clear function\n"; 
    ds.clear(); 
    if (ds.isEmpty())
        cout << "      is emtpy" << endl; 
    else   
        cout << "      not empty" << endl;
    
    DatumStack ds3; 
    //the following will abort due to runtime error (empty_stack) 
    // ds3.top(); 
    // ds3.pop();

    cout << "-------------TESTING RPNCALC CLASS--------------\n"; 

    RPNCalc calc;
    return 0; 
}