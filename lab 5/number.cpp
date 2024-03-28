#include "number.h"
#include <cstring>
#include <iostream>
using namespace std;
bool Number::operator>(Number x)
{
	if (this->base10 > x.base10)
		return true;
	else
		return false;
}
bool Number::operator<(Number x)
{
	if (this->base10 < x.base10)
		return true;
	else
		return false;
}
bool Number::operator>=(Number x)
{
	if (this->base10 >= x.base10)
		return true;
	else
		return false;
}
bool Number::operator<=(Number x)
{
	if (this->base10 <= x.base10)
		return true;
	else
		return false;
}
bool Number::operator==(Number x)
{
	if (this->base10 == x.base10)
		return true;
	else
		return false;
}
char Number::operator[](int index)
{
	return this->as_char[index];
}
Number Number::operator+(Number x)
{
	Number y = (*this);
	if (x.base > y.base)
		y.base = x.base;
	y.base10 += x.base10;
	y.SwitchBase(y.base);
	return y;
}
Number Number::operator-(Number x)
{
	Number y = (*this);
	if (x.base > y.base)
		y.base = x.base;
	y.base10 -= x.base10;
	y.SwitchBase(y.base);
	return y;
}
Number Number::operator--()
{
	this->base10 = this->base10 / 10;
	for (int i = 0; this->as_char[i] != '\0'; i++)
		this->as_char[i] = this->as_char[i + 1];
	return (*this);
}
Number Number::operator--(int x)
{
	int y = this->GetDigitsCount();
	
	this->as_char[y-1] = '\0';
		return 0;
}
Number Number::operator=(const char* x)
{
	this->base10 = 0;
	for (int i = 0; x[i] != '\0'; i++)
		this->base10 = this->base10 * 10 + (int(x[i]) - '0');
	this->SwitchBase(this->base);
	return (*this);
}
Number Number::operator=(Number&& x)
{
	this->base = x.base;
	this->base10 = x.base10;
	strcpy_s(this->as_char, 100, x.as_char);
	x.as_char = nullptr;
	return *(this);
}
void Number::SwitchBase(int newbase)
{
	int copy = this->base10;
	char* nrbaza = new char[100];
	int k = 0;
	while (copy)
	{
		int r = copy % newbase;
		char c;
		switch (r)
		{
		case 10:
			c = 'A';
			break;
		case 11:
			c = 'B';
			break;
		case 12:
			c = 'C';
			break;
		case 13:
			c = 'D';
			break;
		case 14:
			c = 'E';
			break;
		case 15:
			c = 'F';
			break;
		default:
			r = r + 48;
			c = char(r);
		}
		nrbaza[k] = c;
		k++;
		copy = copy / newbase;
	}
	strcpy_s(this->as_char, 100, "");
	for (int i = 0; i < k; i++)
		this->as_char[i] = nrbaza[k - 1 - i];
	this->as_char[k] = '\0';
	this->base = newbase;
}
Number& Number::operator=(int x)
{
	this->base10 = x;
	this->SwitchBase(this->base);
	return *(this);
}
void Number::Print()
{
	cout << "baza 10:" << ' ' << this->base10 << endl;
	cout << "baza" << this->base << ':' << ' ' << this->as_char << endl << endl;
}
Number Number::operator+=(Number x)
{
	(*this) = (*this) + x;
	return (*this);
}
int  Number::GetDigitsCount()
{
	int nr = 0;
	for (int i = 0; this->as_char[i] != '\0'; i++)
		nr++;
	return nr;
}
int  Number::GetBase()
{
	return this->base;
}