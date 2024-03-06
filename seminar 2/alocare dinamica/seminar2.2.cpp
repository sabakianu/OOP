
#include <iostream>
#include "numar.h"
int main()
{
	NumberList n;
	n.Init();
	n.Add(4);
	n.Add(2);
	n.Add(1);
	n.Add(5);
	n.Add(6);
	n.Add(2);
	n.Add(1);
	n.Add(5);
	n.Add(6);
	n.Add(2);
	n.Add(1);
	n.Add(5);
	n.Add(6);
	n.Add(2);
	n.Add(1);
	n.Add(2);
	n.Add(1);
	n.Add(5);
	n.Add(6);
	n.Add(2);
	n.Add(1);
	n.Add(5);
	n.Sort();
	n.Print();
}
