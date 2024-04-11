
#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
    Dictionary<int, int> intDict;
    intDict.set(1, 2);
    intDict.set(2, 22);
    intDict.set(3, 24);
    intDict.set(4, 7);
    cout << intDict.get(2) << endl;

    Dictionary<const char*, const char*> strDict;
    strDict.set("Ana", "Maria");
    strDict.set("Bere", "Pere");
    strDict.set("nO", "YEs");
    cout << strDict.get("Bere") << endl;
}
