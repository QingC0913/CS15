/* 
 * unit_tests.h
 * 
 * CS 15 homework 1
 * by C.R. Calabrese, January 2021
 * edited by Qing Cheng, 28 Sept 2021
 * 
 * Uses Matt Russell's unit_test framework to test the CharArrayList and
 * CharLinkedList.
 * More information on this testing framework can be found in the Lab 1
 * handout
 */

#include <cassert>
#include <iostream>
#include "CharArrayList.h"
#include "CharLinkedList.h"

using namespace std;
/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/

/* default constructor test
 * Run the ArrayList default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void default_constructor_AL()
{
    CharArrayList testArrayList;
}

void constructor_overloaded1()
{
    CharArrayList test{'a'};  
    assert(test.isEmpty() == false);
}

void constructor_overloaded2()    
{
    char arr[] = {'a', 'b', 'c'}; 
    CharArrayList test{arr, 3}; 
    assert(test.isEmpty() == false);    

    char arr2[0]; 
    CharArrayList test2{arr2, 0};     
    assert(test2.isEmpty()); 
}

void isEmpty_test()
{
    CharArrayList test; 
    assert(test.isEmpty()); 

    CharArrayList test2{'b'};
    assert(test2.isEmpty() == false); 
}

void size_test() 
{
    CharArrayList test;
    assert(test.size() == 0);

    CharArrayList test2{'b'};
    assert(test2.size() == 1); 

    char arr[] = {'a', 'b', 'c'};
    CharArrayList test3 {arr, 3};
    assert(test3.size() == 3); 

    char arr2[] = {}; 
    CharArrayList test4 {arr2, 0};    
    assert(test4.size() == 0); 
}

void first_test()
{
    CharArrayList test{'a'};
    assert(test.first() == 'a'); 

    char arr[3] = {'0', '1', '2'};
    CharArrayList test2{arr, 3}; 
    assert(test2.first() =='0');

    CharArrayList test3;     
    // test3.first();   //this will fail the test bc list is empty
}

void last_test()
{
    char arr[] = {'a', 'b', 'c', 'd'};
    CharArrayList test{arr, 4};
    assert(test.last() == 'd'); 

    test.pushAtBack('z'); 
    assert(test.last() != 'd');
    assert(test.last() == 'z');

    CharArrayList test2{'a'};
    assert(test2.last() == 'a'); 

    CharArrayList test3; 
    // cout << test3.last() << endl; //will fail test bc list is empty 
}

void elementAt_test()
{ 
    char arr[] = {'a', 'b', 'c', 'd'};
    CharArrayList test{arr, 4};
    assert(test.elementAt(0) == 'a');
    assert(test.elementAt(1) == 'b');
    assert(test.elementAt(test.size() - 1) == 'd');

    CharArrayList test2{'z'};
    assert(test2.elementAt(0) == 'z');
    // cout << test2.elementAt(3); //will fail test bc out of bounds 
}

//get_cap() was only for testing purposes!!!
//it is not used in the program 
// void get_cap_test()    
// {
//     CharArrayList test{'a'}; 
//     assert(test.get_cap() == 1); 
//     assert(test.isEmpty() == false); 
// 
//     char arr[] = {'a', 'b', 'c', 'd'};
//     CharArrayList test2{arr, 4};  //cap should be 4
//     assert(test2.get_cap() == 4); 
//     test2.pushAtBack('e');
//     assert(test2.get_cap() == 8);  //cap should be doubled
// 
//     CharArrayList test3; 
//     assert(test3.get_cap() == 3);
// }

// void expand_test()    //was public ONLY for testing!!!
// {
//     CharArrayList test;    
//     test.expand();   
//     assert(test.get_cap() == 1);  //get_cap() only for testing, not in .h
// 
//     CharArrayList test2{'b'};    //array has cap of 1
//     test2.expand();    //cap should now be 2 
//     assert(test2.get_cap() == 2); 
//     test2.expand();
//     test2.expand();    
//     assert(test2.get_cap() == 8);
// }

void print_test()
{
    CharArrayList test;   //this is to test the length-0 output
    CharArrayList test2{'n'};  //to test length-1 output 
    test.print(); 
    test2.print();

    char arr[] = {'n', 'm', 'o', 'q'};
    CharArrayList test3{arr, 4}; 
    test3.print(); 
}

void pushAtBack_test()
{
    CharArrayList test;    //testing inserting one elem in empty list
    test.pushAtBack('c'); 
    assert(test.last() == 'c');

    CharArrayList test2{'a'};
    test2.pushAtBack('b');
    assert(test2.last() == 'b');

    char arr[] = {'n', 'm', 'o', 'q'};
    CharArrayList test3{arr, 4}; 
    test3.pushAtBack('Z'); 
    assert(test3.last() == 'Z');
    assert(test3.size() == 5);
}

void pushAtFront_test()
{
    CharArrayList test; 
    test.pushAtFront('2');  //add to empty list 
    test.pushAtFront('1');  //add to nonempty list 
    test.pushAtFront('0');  
    assert(test.first() == '0');
}

void insertAt_test()
{
    CharArrayList test; 
    test.insertAt('a', 0); //<<a>>, add to empty list 
    test.insertAt('z', 1); //<<az>>, add to back 
    test.insertAt('Z', 1);  //<<aZz>>, add in middle 
    test.insertAt('0', 0);  //<<0aZz>>, add to beginning 
    test.print(); 

    CharArrayList test2;
    // test2.insertAt('c', 3);  //will fail test
}

void replaceAt_test()
{
    CharArrayList test; 
    // test.replaceAt('c', 0);  //will fail test, empty list 

    CharArrayList test2{'b'};
    test2.replaceAt('B', 0);
    assert(test2.first() == 'B');

    char arr[] = {'n', 'm', 'o', 'q'};
    CharArrayList test3{arr, 4}; 
    test3.replaceAt('M', 1);
    assert(test3.elementAt(1) == 'M');
}

void removeAt_test()
{
    char arr[] = {'n', 'm', 'o', 'q'};
    CharArrayList test{arr, 4}; 
    test.print(); //<<nmoq>>
    test.removeAt(1);  //remove from middle <<noq>>
    assert(test.size() == 3);
    test.print();  
    test.removeAt(2);  //remove from end, <<no>>
    test.print();
    // test.removeAt(2);  //will fail test 
}

void popFromBack_test()
{
    char arr[] = {'n', 'm', 'o', 'q'};
    CharArrayList test{arr, 4}; 
    test.popFromBack();
    assert(test.size() == 3);
    assert(test.last() == 'o'); 

    CharArrayList test2; 
    // test2.popFromBack();  //will fail test
}

// void shrink_test()  //made public only for testing!
// {
//     char arr[] = {'n', 'm', 'o', 'q', 'z'};
//     CharArrayList test{arr, 5}; 
//     test.expand(); //cap = 10
//     test.expand();  //cap = 20
//     assert(test.get_cap() == 20); 
//     test.shrink();  //should be 10 
//     assert(test.get_cap() == 10); 
// }

// void shrink_test2()  //was public only for testing!!
// {
//     char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
//     CharArrayList test{arr, 8}; 
//     assert(test.get_cap() == 8); 
//     for (int i = 0; i < 6; i++)  //remove 6 elements 
//     {
//         test.removeAt(1);
//     }
//     test.print();
//     assert(test.size() == 2); 
// 
//     cout << "curr cap: " << test.get_cap() << endl; 
//     assert(test.get_cap() == 4);  //only 2 out of 8 elems left, = 1 / 4
//     //cap should have shrunk 
// }

void copy_constru_test()
{
    CharArrayList test; 
    test.pushAtFront('a');
    test.pushAtBack('c');
    test.insertAt('b', 1);
    test.print();  //<<abc>>

    CharArrayList test2 = test; 
    test2.print();  //should also be <<abc>>

    test2.pushAtBack('d'); 

    test.print();  //<<abc>> 
    test2.print();  //<<abcd>>
}

void clear_test()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    CharArrayList test{arr, 8}; 
    assert(test.size() == 8); 
    test.clear();
    assert(test.size() == 0); 
    //assert(test.get_cap() == 4);   //get_cap is now private class mem

    CharArrayList test2;
    test2.clear(); 
    assert(test.size() == 0); 
}

void assignm_operat_test()
{
    CharArrayList test{'b'}; 
    test.print();  //<<b>>
    CharArrayList test2; 
    test2 = test; 
    test2.print();  //should be same as test, <<b>>
    
    CharArrayList test3{'B'}; 
    test2 = test3;     
    test2.print(); //<<B>>
    test3 = test;  //<<b>>
    assert(test3.first() == 'b');

    CharArrayList test4; 
    test3 = test4; 
    assert(test3.isEmpty()); 
}

void concatenate_test()
{
    char a[4] = {'a', 'b', 'c', 'd'}; 
    CharArrayList test{a, 4}; 
    test.print(); //<<abcd>>

    CharArrayList test2{'A'}; 
    test2.pushAtBack('B'); 
    test2.insertAt('C', 2); 
    test2.print();  //<<ABC>>

    test.concatenate(test2);
    test.print();  //<<abcdABC>>

    CharArrayList test3; 
    test2.concatenate(test3); //unchanged, <<ABC>>
    test2.print();
    test3.print(); //unchanged, <<>>

    test2.concatenate(test2); 
    test2.print();  //<<ABCABC>>

    CharArrayList test4; 
    test4.print();  //<<>>
    CharArrayList test5{'Z'}; 
    test5.print();  //<<Z>>
    test4.concatenate(test5); 
    test4.print();  //<<Z>>
}
/*******************************************************************\
*                      CHAR LINKED LIST TESTS                       *
\*******************************************************************/

/* default constructor test
 * Run the LinkedList default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void default_constructor_LL()
{
    CharLinkedList testLinkedList;
}

void size_LL()
{
    CharLinkedList test; 
    assert(test.size() == 0); 
    test.pushAtFront('c');
    assert(test.size() == 1); 

    CharLinkedList test2{'z'}; 
    assert(test2.size() == 1); 

    char arr[] = {'a', 'b', 'c', 'd'};
    CharLinkedList test3{arr, 4}; 
    assert(test3.size() == 4); 
}

void isEmpty_LL()
{
    CharLinkedList test; 
    //assert(test.isEmpty() == false); //false, will crash
    test.pushAtFront('b'); 
    assert(test.isEmpty()==false);

    CharLinkedList test2{'a'}; 
    assert(test.isEmpty() == false);
}

void first_LL()
{
    CharLinkedList test;
    //list is empty, test will fail
    // cout << "test's first elem: " << test.first() << endl;   
    test.pushAtFront('z');
    assert(test.first() == 'z');
    
    test.pushAtFront('a'); 
    assert(test.first() == 'a');
}

void last_LL()
{
    CharLinkedList test;
    //list is empty, test will fail
    // cout << "test's last elem: " << test.last() << endl; 
    test.pushAtFront('a');
    assert(test.last() == 'a');
    test.pushAtBack('z'); 
    assert(test.last() == 'z');

    char arr[] = {'c', 'd', 'e', 'f'};
    CharArrayList test2{arr, 4};
}

void constructor_overloaded1_LL()
{
    CharLinkedList test{'c'}; 
    assert(test.first() == 'c');
    assert(test.size() == 1);
}

void pushAtBack_LL()
{
    CharLinkedList test; 
    test.pushAtBack('c'); 
    assert(test.first() == 'c');
    assert(test.last() == 'c');
    assert(test.size() == 1); 

    char arr[] = {'a', 'b', 'c', 'd'}; 
    CharLinkedList test2{arr, 4};
    test2.print(); //should be <<abcd>>
    test2.pushAtBack(' '); 
    assert(test2.size() == 5);
    test2.print();  //should be <<abcd >>
}

void popFromFront_LL()
{
    CharLinkedList test; 
    assert(test.isEmpty());
    // test.popFromFront();    //will fail bc list is empty 

    test.pushAtFront('z');
    assert(test.first() == 'z');
    test.popFromFront();    //pop from len-1 list
    assert(test.isEmpty() == true);

    test.pushAtFront('h');
    test.pushAtFront('a');
    test.pushAtBack('z'); 
    test.popFromFront(); 
    assert(test.size() == 2);    //pop from len-1+ list
}

void pushAtFront_LL()
{
    CharLinkedList test;  //test for if LL is empty 
    test.pushAtFront('c'); 
    // (assert(test.front == nullptr));    //test will fail 
    //made front ptr public only for testing!!
    
    test.pushAtFront('b');
    test.pushAtFront('a');
    assert(test.size() == 3);
    test.print();  //should be <<abc>>
}

void popFromBack_LL()
{
    CharLinkedList test; 
    // test.popFromBack();   //test will fail, pop from len-0 list
    test.pushAtFront('a');
    assert(test.size() == 1); 
    assert(test.last() == 'a'); 
    test.popFromBack();   //pop from len-1 list
    assert(test.isEmpty()); 
}

void removeAt_LL()
{
    CharLinkedList test; 
    //test.removeAt(2);    //will fail, index out of bounds
    test.pushAtBack('b');
    test.removeAt(0);   //remove in len-1 list 
    assert(test.isEmpty());
    
    CharLinkedList test2{'c'};
    test2.pushAtBack('d');
    test2.pushAtBack('e');
    test2.print();  //should be <<cde>>
    test2.removeAt(2);    //remove from end 
    assert(test2.size() == 2);
    test2.removeAt(0); 
    test2.print();  //should be <<d>> 
    
    CharLinkedList test3{'f'};
    test3.pushAtBack('g');
    test3.pushAtBack('h');
    test3.removeAt(1);    //remove from middle 
    assert(test3.size() == 2);
}

void replaceAt_LL()
{
    CharLinkedList test;
    // test.replaceAt('a', 0);  //will fail test, replace elem in len-0 list
    test.pushAtFront('a'); 
    test.replaceAt('b', 0);  //replace elem in len-1 list, replace first
    assert(test.first() == 'b'); 
    
    test.pushAtFront('c'); 
    test.pushAtFront('d');
    test.pushAtBack('a');
    test.replaceAt('Z', 3);  //replace elem in len-1+ list
    assert(test.last() == 'Z');  //replace last
    
    test.replaceAt('0', 2);  //replace elem in middle 
    test.print(); //should be <<dc0Z>>
}

void elementAt_LL()
{
    CharLinkedList test; 
    // cout << test.elementAt(3); //will fail test, elem in empty list
    test.pushAtFront('d'); 
    assert(test.elementAt(0) == 'd'); //elem in len-1 list, in beginning
    test.pushAtFront('c'); 
    test.pushAtFront('b'); 
    test.pushAtFront('a'); 
    //elem in len-1+ list, at end 
    assert(test.elementAt(test.size() - 1) == 'd'); 
    //assert(test.elementAt(1) == 'b');  //elem in middle 
}

void print_LL()
{
    CharLinkedList test{'f'}; 
    test.pushAtFront('e');
    test.pushAtFront('d');
    test.print();    //should be <<def>> 

    CharLinkedList test2;
    test2.print();    //should be <<>>
}

void constructor_overloaded2_LL()
{
    char arr[] = {'1', '2', '3'}; 
    CharArrayList test(arr, 3); 
    test.print();  //should be <<123>>    

    char arr2[0]; 
    CharArrayList test2(arr2, 0); 
    test2.print();  //should be <<>>
}

void concatenate_LL()
{   
    char arr[] = {'a', 'b', 'c', 'd'}; 
    CharArrayList test{arr, 4}; 
    test.print(); //should be <<abcd>>

    char arr2[] = { 'e', 'f', 'g', 'h', 'i'}; 
    CharArrayList test2{arr2, 5}; 
    test2.print();  //should be <<efghi>>
    cout << test2.last() << endl;

    test.concatenate(test2); //concat two non-empty lists 
    test.print(); //should be <<abcdefghi>>
    
    char arr3[0]; 
    CharArrayList test3{arr3, 0}; 
    test.concatenate(test3);   //concat w empty list
    test.print();   //should be same as before, <<abcdefghi>>
    
    test.concatenate(test);   //concat itself 
    test.print();  //should be <<<<abcdefghiabcdefghi>>
    
    test3.concatenate(test3); //concat two empty lists 
    test3.print(); //should be <<>>
}

void insertAt_LL()
{
    CharLinkedList test; 
    // test.insertAt('c', -1); //index out of range, test will fail
    test.insertAt('c', 0);  //insert in empty list
    test.print();  //should be <<c>>

    test.pushAtFront('b'); //populate the list
    test.pushAtFront('a');
    test.pushAtBack('d');
    test.print();  //should be <<abcd>>
    
    test.insertAt('Z', 2);  //insert in the middle
    test.print();  //should be <<abZcd>>
    
    test.insertAt('T', test.size());    //insert at the end
    test.insertAt('L', 0);  //insert in beginning
    test.print();  //should be <<LabZcdT>>
}

void copy_constru_LL()
{
    char arr1[] = {'a', 'b', 'c', 'd'}; 
    CharArrayList test1{arr1, 4}; 
    test1.print();  //should be <<abcd>>
    cout << test1.last() << endl;

    CharArrayList test2 = test1;    //copy instance from non-empty list 
    test2.print();  //should be <<abcd>>
    
    CharArrayList test3; 
    CharArrayList test4 = test3;    //copy instance from empty list  
    test3.print();  //should be <<>> empty
    test4.print(); //should be <<>> empty
}

void clear_LL()
{
    CharLinkedList test; 
    assert(test.size() == 0); 
    test.clear(); 
    assert(test.size() == 0);  //nothing happens to it 

    test.pushAtBack('a'); 
    assert(test.size() == 1); 
    test.clear();
    assert(test.size() == 0);  //should be emptied 

    test.pushAtBack('z'); 
    test.pushAtBack('y'); 
    test.pushAtBack('x');
    test.pushAtBack('w');
    assert(test.size() == 4); 
    test.clear(); 
    assert(test.size() == 0); 
}

void assignm_operat_LL()
{    
    CharLinkedList test1{'a'}; 
    test1.print(); //should be <<a>>
    CharLinkedList test2{'z'}; 
    test2.print();  //should be <<z>>

    test2 = test1; 
    test2.print();  //should now be should be <<a>>

    CharLinkedList test; 
    test.print(); 
    test = test1;  //was empty, should now be should be <<a>>
    test1.print();   
}