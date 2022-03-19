# Makefile
# Matt Russell
# COMP 15 lab 1

# This Makefile builds the executable used by unit_test
#
# Do not do "make unit_test" yourself.  It won't work.
# Just run "unit_test" in this directory, and the unit_test script
# will take care of everything.
#
# Why: unit_test_driver.cpp does not exist in the current working directory.
# The unit_test script copies a template and synthesizes unit_test_driver.cpp
# based on your unit_tests.h file.
#
# After the unit_test script runs, it removes the executable and driver
# source.
#
# If you would like to write your own main program, you may do so.
# Create a main.cpp that uses ArrayList, and then "make lab_test"
# will build a program based on your main program.

CXX      = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

unit_test: unit_test_driver.o ArrayList.o
	${CXX} unit_test_driver.o ArrayList.o

lab_test: test.cpp ArrayList.cpp ArrayList.h
	${CXX} test.cpp ArrayList.cpp -o lab_test

unit_test_driver.o: unit_test_driver.cpp
	${CXX} ${CXXFLAGS} -c unit_test_driver.cpp

ArrayList.o: ArrayList.cpp ArrayList.h
	${CXX} ${CXXFLAGS} -c ArrayList.cpp

test.o: test.cpp ArrayList.h
	${CXX} ${CXXFLAGS} -c test.cpp

# --- clean destroys all the .o files
clean:
	rm -rf *.o *~ core* a.out unit_test_driver.cpp 
