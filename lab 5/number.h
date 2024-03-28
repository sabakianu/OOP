#pragma once
#include <cstring>
class Number
{
	int base10;
	int base;
	char* as_char;
public:
	Number(const char* value, int base)
	{
		this->as_char = new char[100];
		strcpy_s(this->as_char, 100, value);
		this->base = base;
		this->base10 = 0;
		for (int i = 0; value[i] != '\0'; i++)
		{
			int r;
			char c=value[i];
			switch (c)
			{
			case 'A':
				r = 10;
				break;
			case 'B':
				r = 11;
				break;
			case 'C':
				r = 12;
				break;
			case 'D':
				r = 13;
				break;
			case 'E':
				r = 14;
				break;
			case 'F':
				r = 15;
				break;
			default:
				r = (value[i] - '0');
			}
			this->base10 = this->base10 * this->base + r;
		}	
	}
	Number()
	{
		this->base10 = -1;
		this->base = -1;
		this->as_char = new char[100];
	}
	Number(int x)
	{
		this->base10 = x;
		this->base = 10;
		char temp[100] = "";
		int k = 0;
		while (x)
		{
			temp[k] = char(x % 10 + '0');
			k++;
			x = x / 10;
		}
		this->as_char = new char[100];
		for (int i = 0; i < k; i++)
			this->as_char[i] = temp[k - 1 - i];
		this->as_char[k] = '\0';
	}
	Number(const Number& x)
	{
		this->base = x.base;
		this->base10 = x.base10;
		this->as_char = new char[100];
		strcpy_s(this->as_char, 100, x.as_char);
	}
	Number(Number&& x)
	{
		this->base = x.base;
		this->base10 = x.base10;
		this->as_char = new char[100];
		strcpy_s(this->as_char, 100, x.as_char);
		x.as_char = nullptr;
	}
		// where base is between 2 and 16
	~Number()
	{
		delete as_char;
	}
	Number operator+(Number x);
	Number operator-(Number x);
	Number operator=(Number&& x);
	bool operator>(Number x);
	bool operator<(Number x);
	bool operator<=(Number x);
	bool operator>=(Number x);
	bool operator==(Number x);
	Number& operator=( int x);
	Number operator+=(Number x);
	Number operator=(const char* x);
	char operator[](int index);
	Number operator--();
	Number operator--(int x);
	// add operators and copy/move constructor

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};