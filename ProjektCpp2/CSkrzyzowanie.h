#pragma once
#include <vector>
#include <iostream>
#include "CZnak.h"
#include "CSwiatla.h"

/// @file CSkrzyzowanie.h
/// @brief Plik nag��wkowy klasy CSkrzyzowanie

/// @brief Klasa skrzy�owania
class CSkrzyzowanie
{
protected:
	/// @brief Numer ID skrzy�owania
	int ID;
	/// @brief Wsp�rz�dna X skrzy�owania
	int x;
	/// @brief Wsp�rz�dna Y skrzy�owania
	int y;
	/// @brief Tablica dr�g kt�re ��cz� si� nad danym skrzy�owaniu
	vector <int> id_drogi;
	/// @brief Tablica znak�w dla ka�dej drogi
	vector <vector <CZnak*>> znaki;
	/// @brief Tablica sygnalizacji �wietlnych
	vector <CSwiatla*> swiatla;
	/// @brief Numer sekwencji do kt�rej nale�y dana sygnalizacja
	int sekwencjeSwiatel; 
	/// @brief Zaj�to�� skrzy�owania przz dany pojazd nadrz�dna nad prawami ruchu drogowego  
	int bufor;
public:
	CSkrzyzowanie(int id, int a, int b);
	~CSkrzyzowanie();
	int getID();
	int getX();
	int getY();
	void set(int, int, int);
	int getTyp();
	vector <int> getIdDrogi();
	vector <vector <CZnak*>> getZnaki();
	vector <CSwiatla*> getSwiatla();
	void dodajDroge(int idDrogi, vector <CZnak*> zn);
	void dodajSwiatla(vector <int> drogi, int czas);
	void setBufor(int id);
	int getBufor();
};

