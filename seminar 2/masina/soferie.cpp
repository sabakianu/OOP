#include <iostream>
#include "soferie.h"
#include <cstring>
using namespace std;

void masina::setNrLitri()
{
	int x;
	cin >> x;
	this->nrLitri = x;
}
void masina::getNrLitri()
{

	cout << this->nrLitri << "L" << endl;
}

void masina::setConsum()
{
	int x;
	cin >> x;
	this->consum = x;
}
void masina::getConsum()
{

	cout << this->consum << "km/h" << endl;
}

void masina::setKilometraj()
{
	int x;
	cin >> x;
	this->kilometraj = x;
}
void masina::getKilometraj()
{

	cout << this->kilometraj << "km" << endl;
}

void masina::bisnitar()
{
	this->kilometraj = this->kilometraj - 1000;
	if (this->kilometraj < 0)
		cout << "nu e bisnitar bun!" << endl;
}
void masina::cursa(int distanta)
{
	this->nrLitri = this->nrLitri - distanta * this->consum;
	if (this->nrLitri < 0)
		cout << "ai ramas blocat pe drum" << endl;;
}
void masina::setFirma(char* firma)
{
	this->firma = new char[100];
	strcpy_s(this->firma,sizeof(this->firma), firma);
}
void masina::getFirma()
{
	cout << this->firma << endl;
}