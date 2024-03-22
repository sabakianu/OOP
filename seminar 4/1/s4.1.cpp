#include <iostream>
#include "Sort.h"
#include <cstdlib>
using namespace std;

int main()
{
    Sort s(5, 2, 20);
    int v[] = { 1,4,6,7,4,3 };
    Sort a(6, v);
    Sort b;
    Sort c(5, 6, 9, 8, 4, 1);
    char l[] = "10,40,100,5,70";
    Sort d(l);
    s.Print();
    cout << endl;
    a.Print();
    cout << endl;
    b.Print();
    cout << endl;
    c.Print();
    cout << endl;
    d.Print();
    return 0;
}
