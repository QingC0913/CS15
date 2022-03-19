#
# Makefile for Binary Search Tree
# edited by Qing Cheng 
# 11/16/2017
# Homework 3 (fall 2021)
#

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11 


test: test.o BinarySearchTree.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

hw3: hw3.o BinarySearchTree.o
	${CXX} -o $@ $^

%.o: %.cpp $(shell echo *.h)
	${CXX} ${CXXFLAGS} -c $<

clean:
	rm -rf hw3 *.o *.dSYM

# Don't forget to add your testing files to this rule if you use it!
provide:
	provide comp15 hw3_BST hw3.cpp BinarySearchTree.cpp BinarySearchTree.h \
	        README Makefile my.txt test.cpp 

