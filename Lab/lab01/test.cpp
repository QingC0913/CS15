
#include <iostream>
using namespace std;
#include "ArrayList.h"

int main()
{
    ArrayList l; 
    l.pushAtBack(3); 
    l.pushAtBack(5); 
    l.pushAtBack(7); 
    if (not l.isEmpty())
        cout << "not empty" << endl;
    else 
        cout << "empty" << endl;
    cout << l.toString() << endl;
    cout << "size: " << l.size() << endl;
    if (l.find(5))
        cout << "was found!\n"; 
    l.popFromBack(); 
    cout << "size: " << l.size() << endl;
    return 0; 
}