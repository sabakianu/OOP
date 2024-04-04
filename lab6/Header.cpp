#include "Header.h"
#include <iostream>
using namespace std;
int verificare(Professor y)
{
	int ok = 0;
	for (int i = 0; i < y.getNumar(); i++)
		if (y.x[i]->getHp() <= 0)
			ok++;
	if (ok < y.getNumar())
		return 1;
	return 0;
}
void batalie(Professor y, MojoJojo z)
{
	int ok1 = 1, ok2 = 1;
	while (ok1 && ok2)
	{
		for (int i = 0; i < y.getNumar(); i++)
			if(y.x[i]!=nullptr)
			if(y.x[i]->getHp()>0)
		{
				z.minusDamage(y.x[i]->getDamage());
		}
		if (z.getHp() <= 0)
			ok2 = 0;
		if (ok2 == 0)
		{
			cout << "Fetitele au castigat";
			break;
		}
		int c = rand() % y.getNumar();
		while (y.x[c]->getHp() <= 0)
			c = rand() % y.getNumar();
		y.x[c]->minusDamage(z.getDamage());
		if (verificare(y) == 0)
			ok1 = 0;
			if (ok1 == 0)
			{
				cout << "Mojojojo a castigat";
				break;
			}
	}
}