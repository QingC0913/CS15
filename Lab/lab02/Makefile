#
#  CS 15: Data Structures
#  Tufts University
#  Makefile for Lab 2
#
#  Makefile for planet-driver, LinkedList and Planet
#

CXX      = clang++
CXXFLAGS = -Wall -Wextra -g

planet-driver: planet-driver.o LinkedList.o Planet.o
	$(CXX) $(LDFlagS) -o planet-driver planet-driver.o LinkedList.o Planet.o 

# If you'd like to use unit_test on your LinkedList class, you can do so
# by creating a unit_tests.h file with testing functions. Remember that you won't
# run make to use unit_test; intead, just run unit_test
unit_test: unit_test_driver.o LinkedList.o Planet.o
	$(CXX) $(CXXFLAGS) unit_test_driver.o LinkedList.o Planet.o

unit_test_driver.o: unit_test_driver.cpp LinkedList.h Planet.h
	$(CXX) $(CXXFLAGS) -c unit_test_driver.cpp

#
# Only listing dependencies here
# make has a default rule that knows how to build a .o
# file from a .cpp file using $(CXX) and $(CXXFLAGS)
#
planet-driver.o: planet-driver.cpp LinkedList.h
	$(CXX) $(CXXFLAGS) -c planet-driver.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Planet.h
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp

Planet.o: Planet.cpp Planet.h
	$(CXX) $(CXXFLAGS) -c Planet.cpp

clean:
	rm -f *.o core* *~ planet-driver
