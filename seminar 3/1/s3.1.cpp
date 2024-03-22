#include <iostream>
#include "math.h"
using namespace std; 
int main()
{
    Math a;
    cout << Math::Add(2, 4) << endl;
    cout << Math::Add(2, 4, 6) << endl;
    cout << Math::Add(2.0f, 1.2f) << endl;
    cout << Math::Add(2.5f, 4.0f, 5.5f) << endl;
    cout << Math::Mul(2, 4) << endl;
    cout << Math::Mul(2, 4, 6) << endl;
    cout << Math::Mul(2.0f, 1.2f) << endl;
    cout << Math::Mul(2.5f, 4.0f, 5.5f) << endl;
    cout << Math::Add("test", "123")<<endl;
    cout << Math::Add(5, 1,2,3,4,5) << endl;
    if (Math::Add(nullptr, "123") == nullptr)
        cout << "nu" << endl;
}