#include <iostream>
#include "soferie.h"
using namespace std;
int main()
{
	masina m;
	m.setFirma((char*)"BMW");
	m.setConsum();
	m.setKilometraj();
	m.setNrLitri();
	m.bisnitar();
	m.cursa(50);
	m.getFirma();
	m.getConsum();
	m.getKilometraj();
	m.getNrLitri();
	return 0;
}