// s6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

using namespace std;
int main()
{
	int v[] = { sugar, spice, spice, everything_nice, sugar, spice, spice, everything_nice, everything_nice, sugar, };
	int length = 10;
	Professor a(v, length);
	//a.GetIngredients();
	//a.creareFetita();
	MojoJojo mojo;
	batalie(a, mojo);
	cout << endl;
    //std::cout << "Hello World!\n";
}

/*
	Profesorul X a decis sa faca mai multe fetite PowerPuff, si evident are nevoie de sugar/spice and everything nace
	Pt ca ii este lene, da o comanda cu Glovo si ii spune curieruui sa i aduca tot zaharul/condimentele/fainutzul din magazin
	Implementati clasa abstracta PowerPuffGirl si clasele care mostenesc interfata : Bubbles, Blossom, Buttercup

	Fiecare dintre fetite are
	Damage, health

	clasa Profesor care primeste o lista de ingrediente care a reusit curierul sa le cumpere
	ex: sugar, spice, spice, everything_nice, sugar

	Ca sa creeze o fetita powerpuff are nevoie de
	1x sugar
	1x spice
	1x everything_nice

	O sa creeze cat de multe fetite poate
	cu o sansa de 33% sa fie ori un ButterCup, ori un Blossom, ori un Bubbles

	clasa MojoJojo
	care are
	damage, health

	Si apoi implementati o metoda globala care simuleaza lupta intre MojoJojo si fetitele powerpuff ale profesorului

	Daunele se efectueaza in ture
	In fiecare tura fetitele dau damage lui MojoJojo
	si MojoJojo alege o fetita aleatoare care sa o dauneze

	Scrieti o metoda care afiseaza castigatorul bataliei
	Si o metoda care sa afiseze cate fetite au supravietuit si cu cata viata


*/