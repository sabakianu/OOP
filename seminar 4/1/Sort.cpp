#include <cstdlib>
#include "Sort.h"
#include <iostream>

using namespace std;

void Sort::Print()
{
	for (int i = 0; i < this->lung; i++)
	{
		cout << this->list[i] << ' ';
	}
}