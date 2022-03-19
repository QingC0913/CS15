###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author:  Qing Cheng

## Put your variables and rules here.  You can use previous Makefiles
## as examples, and you can refer to the "make" documentation on the
## course Reference page.

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

CalcYouLater: main.o RPNCalc.o DatumStack.o Datum.o parser.o got_int.o
	$(CXX) $(CXXFLAGS) -o $@ $^

#to run program with a test main function for parser
# parse: testParseRString.o parser.o 
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# testParseRString.o: testParseRString.cpp
# 	$(CXX) $(CXXFLAGS) -c $^

parser.o: parser.cpp 
	$(CXX) $(CXXFLAGS) -c $^

got_int.o: got_int_func.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

#to run program with a test main function for DatumStack and RPNCalc classes
testing: test_main.o RPNCalc.o DatumStack.o Datum.o parser.o got_int.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test_main.o: test_main.cpp parser.cpp got_int_func.cpp \
						RPNCalc.h DatumStack.h Datum.h 
	$(CXX) $(CXXFLAGS) -o test_main.o -c test_main.cpp

# main: main.cpp RPNCalc.h DatumStack.h Datum.h 
# 	$(CXX) $(CXXFLAGS) main.cpp

main.o: main.cpp RPNCalc.h DatumStack.h Datum.h 
	$(CXX) $(CXXFLAGS) -c main.cpp

RPNCalc.o: RPNCalc.cpp DatumStack.h Datum.h
	$(CXX) $(CXXFLAGS) -c RPNCalc.cpp 

DatumStack.o: DatumStack.cpp DatumStack.h Datum.h
	$(CXX) $(CXXFLAGS) -c DatumStack.cpp 

## CAUTION:  DO NOT JUST USE THE OLD RULES FOR 'clean'!!!
##           You do NOT want to remove Datum.o!!
##
##  --- Delete these comments and put appropriate comments in ---


##
## Here is a rule for compiling .cyl files for use in your testing
##
%.cylc:  %.cyl
	./cylc $^
