#pragma once
#include <iostream>
#include <cstdlib> 
using namespace std;
enum ingredients{ sugar, spice, everything_nice };
class PowerpuffGirl
{
protected:
	int damage;
	int hp;
public:
	virtual int getDamage()=0;
	virtual int getHp()=0;
	virtual void minusDamage(int input)=0;
};
class Bubless : public PowerpuffGirl
{
public:
	Bubless()
	{
		damage = 100;
		hp = 100;
	}
	int getDamage() { return this->damage; };
	int getHp() { return this->hp; };
	void minusDamage(int input)
	{
		this->hp = this->hp - input;
		if (this->hp <= 0)
			cout << "a murit o fetita :(" << endl;
	};
};
class Blossom : public PowerpuffGirl
{
public:
	Blossom()
	{
		damage = 150;
		hp = 50;
	}
	int getDamage() { return this->damage; };
	int getHp() { return this->hp; };
	void minusDamage(int input)
	{
		this->hp = this->hp - input;
		if (this->hp <= 0)
			cout << "a murit o fetita :(" << endl;
	};
};
class Buttercup : public PowerpuffGirl
{
public:
	Buttercup()
	{
		damage = 50;
		hp = 150;
	}
	int getDamage() { return this->damage; };
	int getHp() { return this->hp; };
	void minusDamage(int input)
	{
		this->hp = this->hp - input;
		if (this->hp <= 0)
			cout << "a murit o fetita :(" << endl;
	};
};
class Professor
{
private:
	int v[3] = { 0,0,0 };
	int numar;
public:
	PowerpuffGirl** x;
	Professor(int x[], int length)
	{
		for (int i = 0; i < length; i++)
		{
			v[x[i]]++;
		}
		this->creareFetita();
	}
	void GetIngredients()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << v[i] << ' ';
		}
	}
	void creareFetita()
	{
		int minim = this->v[0];
		for (int i = 1; i < 3; i++)
			if (minim > this->v[i])
				minim = this->v[i];
		this->numar = minim;
		this->x = new PowerpuffGirl*[minim];
		for (int i = 0; i < minim; i++)
		{
			int c= rand() % 3 + 1;
			if (c == 1)
				this->x[i] = new Blossom;
			else if (c == 2)
				this->x[i] = new Bubless;
			else if (c == 3)
				this->x[i] = new Buttercup;
		}
	}
	int getNumar()
	{
		return this->numar;
	};
};
class MojoJojo
{
private:
	int damage;
	int hp;
public:
	MojoJojo()
	{
		hp = 400;
		damage = 200;
	}
	int getDamage() { return this->damage; };
	int getHp() { return this->hp; };
	void minusDamage(int input)
	{
		this->hp = this->hp - input;
		if (this->hp <= 0)
			cout << "a murit mojojojo :)" << endl;
	};
};
void batalie(Professor y, MojoJojo z);