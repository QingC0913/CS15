/*
 * test.cpp
 * CS 15 HW3: Binary Search Trees
 * Spring 2021
 * 
 * edited by Qing Cheng
 * Purpose: this is a testing file, contains the main function that creates 
    BSTs and performs operations on them. 
 * 11/16/2021 
 */
 #include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv; 
    cout << "testing main!" << endl;
    BinarySearchTree bst; 

    cout << "--------------INSERT-------------\n"; 
    //random
    // bst.insert(5);  //these had testing print statements 
    // bst.insert(0); 
    // bst.insert(1); 
    // bst.insert(0); 
    // bst.insert(-1); 
    // bst.insert(7);
    // bst.print_tree();  
    
    //linked list
    //commented out previous section and inserted new nodes
    // bst.insert(0); 
    // bst.insert(1); 
    // bst.insert(2); 
    // bst.insert(3); 
    // bst.insert(4); 
    // bst.insert(90); 
    // bst.insert(500000); 
    // bst.print_tree();

    //duplicates
    // bst.insert(2); 
    // bst.insert(3); 
    // bst.insert(1000); 
    // bst.insert(1000); 
    // bst.insert(1000); 
    // bst.insert(4); 
    // bst.insert(1000); 
    // bst.print_tree();

    cout << "--------------CONTAINS-------------\n"; 
    //commented out previous section
    //empty tree, not found
    // cout << bst.contains(0) << endl;       
    // bst.insert(100);
    
    //non-empty tree, not found 
    // cout << bst.contains(2) << endl; 
    
    //found   
    // cout << bst.contains(100) << endl;  
    
    //contains dup
    // bst.insert(0); 
    // bst.insert(1); 
    // bst.insert(2); 
    // bst.insert(3); 
    // bst.insert(4); 
    // bst.insert(90); 
    // bst.insert(5000); 
    // cout << bst.contains(100) <<endl; 

    cout << "--------------NODE_COUNT-------------\n"; 
    //empty tree, 0
    // cout << "count: " << bst.node_count() << endl;   

    //nonemtpy tree, total = 7, contains dup
    // bst.insert(0); 
    // bst.insert(7); 
    // bst.insert(15); 
    // bst.insert(1); 
    // bst.insert(9); 
    // bst.insert(7);
    // bst.insert(10); 
    // bst.insert(50);    
    // cout << "count: " << bst.node_count() << endl;   
      
    // contains 1 node
    // bst.insert(1); 
    // bst.insert(1); 
    // cout << bst.node_count() << endl;
    cout << "--------------FIND_MIN-------------\n"; 

    //empty tree
    // cout << bst.find_min() << endl; //this should be the MAX int possible 

    //1 node tree
    // bst.insert(100); 
    // cout << bst.find_min() << endl; 

    //multi node tree
    // bst.insert(16); 
    // bst.insert(5); 
    // bst.insert(8); 
    // bst.insert(10); 
    // cout << bst.find_min() << endl;

  cout << "--------------FIND_MAX-------------\n"; 

    //empty tree
    cout << bst.find_min() << endl;
    cout << bst.find_max() << endl; //this should be the MIN int possible 
    bst.insert(10);
    cout << bst.find_min() << endl;
    cout << bst.find_max() << endl;

    //1 node tree
    // bst.insert(100); 
    // cout << bst.find_max() << endl; 

    //multi node tree
    // bst.insert(16); 
    // bst.insert(5); 
    // bst.insert(8); 
    // bst.insert(10); 
    // cout << bst.find_max() << endl;    //16

  cout << "--------------COUNT_TOTAL-------------\n"; 
    //empty tree, sum = 0
    // cout << bst.count_total() << endl;

  //nonempty tree, sum = 100
  // bst.insert(100); 
  // cout << bst.count_total() << endl;

  //nonempty tree, sum = 111
  // bst.insert(10); 
  // bst.insert(1); 
  // cout << bst.count_total() << endl;

  //nonempty tree, with dup, sum = 511
  // bst.insert(100);
  // bst.insert(100);
  // bst.insert(100);
  // bst.insert(100);
  // cout << bst.count_total() << endl;

  cout << "--------------TREE_HEIGHT-------------\n"; 
    //empty tree, height = -1
    // cout << bst.tree_height() << endl; 
    // 
    //contains root, height = 0
    // bst.insert(0); 
    // cout << bst.tree_height() << endl;
    // 
    //linked list, height = 5 (plus the node of 0)
    // bst.insert(1); 
    // bst.insert(2); 
    // bst.insert(3); 
    // bst.insert(4); 
    // cout << bst.tree_height() << endl;    
 
  cout << "--------------PRE_ORDER_COPY-------------\n"; 
// bst.insert(5);
// bst.insert(2);
// bst.insert(6);
// bst.insert(4);
// bst.insert(-2); 
// bst.insert(10); 
// bst.insert(6); 
// cout << "*****bst*****\n"; 
// bst.print_tree(); 

  cout << "--------------ASSIGNMENT OPERATOR-------------\n"; 
// BinarySearchTree bst2; 

//is emtpy, prints nothing 
// cout << "*****bst2*****\n"; 
// bst2.print_tree();    
// bst2 = bst; 

//should be same as bst from above
// cout << "*****bst2*****\n"; 
// bst2.print_tree();     
// bst = bst;

//self assignment, does nothing, should be same 
// cout << "*****bst*****\n"; 
// bst.print_tree();    
// 

//has 3 nodes   
// BinarySearchTree bst3; 
// bst3.insert(0); 
// bst3.insert(10); 
// bst3.insert(-10); 
// cout << "*****bst3*****\n";  
// bst3.print_tree();   
 
//now is same as bst and bst2  
// bst3 = bst2; 
// cout << "*****bst3*****\n";  
// bst3.print_tree();    

cout << "--------------REMOVE-------------\n"; 
//remove from emtpy tree, does nothing 
// bst.remove(6); 
// bst.print_tree(); 

//removing leaf nodes
// BinarySearchTree bst2; 
// cout << "*****bst2*****\n";  
// bst2.insert(5); 
// bst2.insert(4); 
// bst2.insert(6); 
// bst2.print_tree(); 
// cout << "remove 4\n"; 
// bst2.remove(4); 
// bst2.print_tree();
// cout << "remove 6\n"; 
// bst2.remove(6); 
// bst2.print_tree(); 
// cout << "remove 5\n"; 
// bst2.remove(5); 
// bst2.print_tree();

//removing nodes that don't exist in the BST
// bst.remove(-2); 
// bst.remove(4); 
// bst.remove(10); 
// bst.print_tree();

//removing node with two children 
BinarySearchTree b; 
// cout << "*****b*****\n";  
// b.insert(9); 
// b.insert(12); 
// b.insert(11); 
// b.insert(16); 
// b.insert(15); 
// b.insert(17); 
// b.print_tree(); 
// cout << "remove 12 (replaced by 15)\n"; 
// b.remove(12); 
// b.print_tree(); 
//remove node with one child (and node is the root)
// cout << "remove 9 (replaced by 11)\n"; 
// b.remove(9); 
// b.print_tree(); 

//removing leaf nodes, then last of all the root
// BinarySearchTree c;
// cout << "*****c*****\n";  
// c.insert(9); 
// c.insert(4); 
// c.insert(13); 
// c.insert(11); 
// c.insert(15); 
// c.print_tree(); 
// cout << "remove 9 (replaced by 11)\n"; 
// c.remove(9); 
// c.print_tree(); 
// cout << "remove 13 (replaced by 15)\n"; 
// c.remove(13);
// c.print_tree();
// cout << "remove 4 (leaf)\n"; 
// c.remove(4); 
// c.print_tree();
// cout << "remove 5 (doesn't exist)\n"; 
// c.remove(5); 
// c.print_tree();
// cout << "remove 15 (leaf)\n"; 
// c.remove(15); 
// c.print_tree();
// cout << "remove 11 (root)\n"; 
// c.remove(11); 
// c.print_tree();

// BinarySearchTree d; 
// int arr[] = {30, 19, 39, 14, 21, 17, 20, 22, 36, 42, 38, 40}; 
// for (int i = 0; i < 12; i++)
// {
//     d.insert(arr[i]);
// }
// 
// 
// cout << "*****d*****\n";  
// d.print_tree();
// cout << "remove 39 (replaced by 40)\n"; 
// d.remove(39);
// d.print_tree(); 
// cout << "remove 36 (replaced by 38)\n"; 
// d.remove(36);
// d.print_tree();
// cout << "remove 30 (replaced by 38)\n"; 
// d.remove(30);  
// d.print_tree(); 
// cout << "remove 19 (replaced by 20)\n"; 
// d.remove(19); 
// d.print_tree(); 

//removing node with no right subtree
BinarySearchTree e; 
cout << "*****e*****\n";  
int arr2[] = {30, 18, 60, 50, 70, 40, 39, 44, 42, 46, 45, 43}; 
for (int i = 0; i < 12; i++)
{
    e.insert(arr2[i]);
}
e.print_tree(); 
cout << "remove 50 (replaced by 46)\n"; 
e.remove(50); 
e.print_tree(); 
cout << "remove 60 (replaced by 70)\n"; 
e.remove(60); 
e.print_tree(); 
cout << "remove 70 (replaced by 46)\n"; 
e.remove(70); 
e.print_tree(); 

cout << "*****f*****\n";  
BinarySearchTree f; 
int arr3[] = {30, 18, 60, 70, 65, 64, 66, 63, 64}; 
for (int i = 0; i < 9; i++)
{
    f.insert(arr3[i]);
}
f.print_tree(); 
cout << "remove 70 (replaced by 66)\n"; 
f.remove(70); 
f.print_tree();
cout << "remove 60 (replaced by 63)\n"; 
f.remove(60); 
f.print_tree();
cout << "remove 64 (no * now)\n"; 
f.remove(64); 
f.print_tree();

BinarySearchTree g; 

cout << "*****g*****\n";  
int arr4[] = {70, 40, 50, 60, 45, 47}; 
for (int i = 0; i < 6; i++)
{
    g.insert(arr4[i]);
}
g.print_tree(); 
cout << "remove 70 (replaced by 60)\n"; 
g.remove(70); 
g.print_tree(); 
cout << g.tree_height() << endl;    //should be 4 
return 0; 
}