#pragma once


class masina
{
private:
	char* firma;
	int nrLitri;
	int consum;
	int kilometraj;
public:
	void setFirma(char* firma);
	void setNrLitri();
	void setConsum();
	void setKilometraj();

	void getFirma();
	void getNrLitri();
	void getConsum();
	void getKilometraj();

	void bisnitar();
	void cursa(int distanta);
};