#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"
using namespace std; 

//functions used that are defined outside of this file 
string parseRString(istream &input);
bool got_int(string s, int *resultp);

/*
RPNCalc
Purpose: constructor, initiates and starts the calculater
Parameters: none
*/
RPNCalc::RPNCalc()
{

}

/*
~RPNCalc
Purpose: destructor
Parameters: none
*/
RPNCalc::~RPNCalc()  //todo something is not freed 
{
    ds.clear();
}

/*
run
Purpose: wrapper func for the overloaded run func that takes parameters 
    this run func reads commands from cin
Parameters: none
Returns: none
*/
void RPNCalc::run()
{
    string cmd;  
    cin >> cmd; 
    while (not cin.fail())
    {
        run(cmd, cin);
        cin >> cmd; 
    }
    quitOperation(); 
}

/*
run (overloaded)
Purpose: calls helper functions to run commands, can be called by helper funcs
Parameters: a single command as a string, an input stream 
    (can be input file, stringstream, or cin)
Returns: none
*/
void RPNCalc::run(string cmd, istream &input)
{   
    int value; 
    if (got_int(cmd, &value))
        intDatum(value); 
    else if (cmd == "#t" or cmd == "#f")
        boolDatum(cmd);  
    else if(cmd == "+" or cmd == "-" 
         or cmd == "*" or cmd == "/" or cmd == "mod")
        arithOperations(cmd); 
    else if (cmd == "==")
        equalOperation(); 
    else if (cmd == "<" or cmd == ">"
                        or cmd == "<=" or cmd == ">=")
        boolOperations(cmd); 
    else if (cmd == "not")
        notOperation(); 
    else if (cmd == "swap")
        swapOperation();
    else if (cmd == "print")
        printOperation(); 
    else if (cmd == "clear") 
        ds.clear(); 
    else if (cmd == "drop")
        dropOperation();  
    else if (cmd == "dup")
        dupOperation(); 
    else if (cmd == "{")
        rStringOperation(input);
    else if (cmd == "file")
        fileOperation(); 
    else if (cmd == "exec")
        execOperation();
    else if (cmd == "if")
        ifOperation(); 
    else if (cmd == "quit") 
        quitOperation(); 
    else   
        cerr << cmd << ": unimplemented\n"; 
}

/*
quitOperation
Purpose: exits the entire CalcYouLater program, whether because user enters 
    "quit" or because we have reached the end of input file
Parameters: none
Returns: none
Effects: prints closing message to cerr, exit successfully
*/
void RPNCalc::quitOperation()
{
    cerr << "Thank you for using CalcYouLater.\n";
    exit(EXIT_SUCCESS);
}

/*
ifOperation
Purpose: handles the "if" command and executes the true or false rstring case   
    based on the corresponding boolean Datum obj
Parameters: none
Returns: none
Effects: prints statement to cerr if has empty stack 
*/
void RPNCalc::ifOperation()
{
    try
    {
        Datum falseCase(ds.top()); 
        ds.pop(); 
        Datum trueCase(ds.top());
        ds.pop(); 

        if (not falseCase.isRString() or not trueCase.isRString()) {
            cerr << "Error: expected rstring in if branch\n";
            return; 
        }

        Datum boolCase(ds.top()); 
        ds.pop();
        if (not boolCase.isBool())
        {
            cerr << "Error: expected boolean in if test\n"; 
            return; 
        }

        if (boolCase.getBool())
            ds.push(trueCase); 
        else    
            ds.push(falseCase); 
        run("exec", cin);    //after t/f case is pushed, exec
    }
    catch(const runtime_error &e)    //empty stack error
    {
        cerr << "Error: " << e.what() << endl;
    }    
}

/*
fileOperation
Purpose: handles opening and reading commands from a file, passes each command  
    into the overloaded run func 
Parameters: none
Returns: none
Effects: prints statement to cerr if has empty stack, top Datum is not rstring, 
    or file can't be opened 
*/
void RPNCalc::fileOperation() 
{
    try 
    {
        string name; 
        ifstream input; 
        Datum file_rstring(ds.top()); 
        ds.pop(); 
        if (not file_rstring.isRString())
        {
            cerr << "Error: file operand not rstring\n";
            return; 
        }
        
        //get the name of file, starting from after "{ "
        //use string substr func, length of substr is original string's len - 4 
        name = file_rstring.getRString(); 
        name = name.substr(2, name.length() - 4); 
        
        input.open(name);    //rstring might not be file name 
        if(not input.is_open())
        {
            cerr << "Unable to read " << name << endl;
            return; 
        }
        
        runFileCommands(input); //this will process cmds from opened file
    }
    catch(const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

/*
runFileCommands
Purpose: helper func to fileOperation(), processes commands stored in a file 
Parameters: input stream (file)
Returns: none
Effects: feeds each cmd from file into the overloaded run func to execute cmd
*/
void RPNCalc::runFileCommands(istream &input)
{
    stringstream ss; 
    string line, cmd, space = " "; 

    while (getline(input, line))    
    {
        ss << line;    //add each line of file to stringstream
        ss << space;    //to separate cmds on diff lines that have no spaces
    }

    while (ss >> cmd) 
        run(cmd, ss);    //process each command; rstring cmds need a stream 
}

/*
execOperation
Purpose: exec commands stored in an rstring 
Parameters: none
Returns: none
Effects: prints statement to cerr if has empty stack, if top obj is not rstring
*/
void RPNCalc::execOperation()
{
    try 
    {
        stringstream ss; 
        string cmd; 

        Datum to_exec(ds.top());    //should be rstring Datum obj  
        ds.pop(); 
        if (not to_exec.isRString())
        {
            cerr << "Error: cannot execute non rstring\n";
            return ;
        }
        ss << to_exec.getRString();    //pass rString into string stream  
        ss >> cmd;    //read each command 

        if (cmd == "{")
            ss >> cmd;    //ignore {, move to next input 

        while (cmd != "}" and (not ss.fail()))
        {
            run(cmd, ss);    //pass each command into command loop!   
            ss >> cmd; 
        }    
    }
    catch (const runtime_error &e)
    {
            cerr << "Error: " << e.what() << endl;
    }
}

/*
rStringOperation
Purpose: creates an rstring obj and pushes it onto the stack
Parameters: ref to an input stream 
Returns: noen
Effects: prints statement to cerr if closing bracket not found (from input file)
*/
void RPNCalc::rStringOperation(istream &input)    
{
    try
    {
        string cmd = parseRString(input);
        Datum to_push(cmd); 
        ds.push(to_push);    //rstring Datum obj is pushed onto stack 
    }
    catch(const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl; 
    }
}

/*
dropOperation
Purpose: removes top Datum obj from stack
Parameters: none
Returns: none
Effects: prints statement to cerr if has empty stack
*/
void RPNCalc::dropOperation()
{
    try
    {
        ds.pop();
    }
    catch(const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    } 
}

/*
printOperation
Purpose: prints to cout the content(s) of the top Datum obj from stack
Parameters: none
Returns: none
Effects: prints statement to cerr if has empty stack
*/
void RPNCalc::printOperation()
{
    try 
    {
        cout << ds.top().toString() << endl;
    }
    catch(const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl; 
    }
}

/*
equalOperation
Purpose: checks if two Datum objs contain the same value
    if diff types, false
    if same type, diff values, false
    if same type, same value, true
Parameters: none
Returns: none
Effects: prints statement to cerr if has empty stack
*/
void RPNCalc::equalOperation()
{
    try
    {
        Datum one(ds.top()); 
        ds.pop(); 
        Datum two(ds.top());
        ds.pop(); 

        bool value = (one == two);
        Datum to_push(value); 
        ds.push(to_push); 
    }
    catch(const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

/*
boolOperations
Purpose: checks two Datum int objs using comparison operators and store the     
    resulting bool value in a new Datum obj, which will be pushed onto stack
Parameters: the string command -- the specific operator to execute
Returns: none
Effects: prints statement to cerr if has empty stack or if one/both Datum are 
    not int   
*/
void RPNCalc::boolOperations(string cmd)
{
    try 
    {
        Datum one(ds.top()); 
        ds.pop(); 
        Datum two(ds.top()); 
        ds.pop();
        if (not one.isInt() or not two.isInt())    //if one of them is not int
        {
            cerr << "Error: datum_not_int\n"; 
            return; 
        }

        bool value = false; 
        if (cmd == "<")
            value = (two < one); 
        else if (cmd == "<=")
            value = ((two < one) or (two == one));
        else if (cmd == ">")
            value = (not (two < one) and not (two == one)); //not <=, so is >
        else if (cmd == ">=")
            value = (not (two < one)); //not <, so is > or = 
        
        Datum to_topush(value); 
        ds.push(to_topush);
    }
    catch(const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl; 
    }
}

/*
arithOperations
Purpose: performs arithematic operations on two Datum objs and store resulting 
    value in new Datum obj, which will be pushed onto the stack
Parameters: the string command -- the specific operator to perform
Returns: none
Effects: prints statement to cerr if has empty stack or if one/both Datum are 
    not int   
*/
void RPNCalc::arithOperations(string cmd) //todo too long 
{
    try 
        {
        Datum one(ds.top()); 
        ds.pop(); 
        Datum two(ds.top()); 
        ds.pop(); 
        if (not one.isInt() or not two.isInt())
        {
            cerr << "Error: datum_not_int\n"; 
            return; 
        }

        int data = 0; 
        if (cmd == "+")
            data = one.getInt() + two.getInt(); 
        else if (cmd == "*")
            data = one.getInt() * two.getInt(); 
        else if (cmd == "-")
            data = two.getInt() - one.getInt(); 
        else if (one.getInt() == 0)
        {
            cerr << "Error: division by 0.\n";
            return; 
        }
        else if (cmd == "/")
            data = two.getInt() / one.getInt(); 
        else  //mod
            data = two.getInt() % one.getInt(); 
        
        Datum to_push(data); 
        ds.push(to_push);
    }
    catch(const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl; 
    } 
}

/*
dupOperation
Purpose: creates duplicate of top Datum obj on stack 
Parameters: none 
Returns: none
Effects: prints statement to cerr if has empty stack
*/
void RPNCalc::dupOperation()
{
    try
    {
        Datum to_push(ds.top());    
        ds.push(to_push); 
    }
    catch(const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }    
}

/*
swapOperation
Purpose: swaps the order of the top two objs on the stack
Parameters: none
Returns: none
Effects: prints statement to cerr if has empty stack
*/
void RPNCalc::swapOperation()
{
    try
    {
        Datum first(ds.top()); 
        ds.pop(); 
        Datum second(ds.top()); 
        ds.pop(); 

        ds.push(first); 
        ds.push(second); 
    }
    catch(const runtime_error &e)  //empty_stack error
    {
        cerr << "Error: " << e.what() << endl; 
    }
}

/*
notOperation
Purpose: removes top obj from stack and pushes a new obj with the opposite bool 
    value 
Parameters: none
Returns: none
Effects: prints statement to cerr if has empty stack or if the top obj is not a 
    bool
*/
void RPNCalc::notOperation() 
{
    try 
    {
        Datum temp(ds.top());    //copies the top Datum obj
        ds.pop(); 

        if (not temp.isBool())
        {
            cerr << "Error: " << "datum_not_bool\n"; 
            return; 
        }

        Datum to_push(not temp.getBool()); 
        ds.push(to_push);  
    }
    catch(const runtime_error &e) 
    {
        cerr << "Error: " << e.what() << endl; 
    }

}

/*
boolDatum
Purpose: creates and pushes a Datum obj which stores a boolean value
Parameters: string representation of value to store e.g. true/false
Returns: none
*/
void RPNCalc::boolDatum(string cmd)
{
    bool value = false; 
    if (cmd[1] == 't')
        value = true; 
    else if(cmd[1] == 'f')
        value = false; 
    
    Datum to_push(value); 
    ds.push(to_push); 
}

void RPNCalc::intDatum(int value)
{
    Datum to_push(value);
    ds.push(to_push); 
}