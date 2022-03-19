#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std; 

double factorial(double n); 
double sterling(double n);
void absol(double true_value, double est); 

int main()
{   
    cout << fixed << setprecision(2);
    double ster, fact; 
    int x; 
    for (double i = 1; i <= 5; i++)
    {
        x = i * 10; 
        ster = sterling(x); 
        fact = factorial(x); 
        cout << "n = " << x << endl;
        cout << "Sterling's approximation: " << ster << endl; 
        cout << "               Factorial: " << fact << "\n" << endl; 
        absol(fact, ster);
    }
    
    return 0; 
}

void absol(double true_value, double est)
{
    double absolute_error = abs(true_value - est); 
    double relative_error = absolute_error / true_value; 
    cout << "          relative error: " 
         << (relative_error * 100) << "%" << endl;
}

double factorial(double n)
{
    if (n > 1)  
        return n * factorial(n - 1); 
    else
        return 1; 
}

double sterling(double n) 
{
    double a1 = sqrt(2 * M_PI * n); 
    double a2 = pow(n, n); 
    double a3 = pow(M_E, (-n));
    return ((a1 * a2)*(a2 * a3)/(a2)); 
}