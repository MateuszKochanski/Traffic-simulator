#pragma once
#include <vector>
#include <iostream>
#include "CZnak.h"
#include "CSwiatla.h"

/// @file CSkrzyzowanie.h
/// @brief Plik nag³ówkowy klasy CSkrzyzowanie

/// @brief Klasa skrzy¿owania
class CSkrzyzowanie
{
protected:
	/// @brief Numer ID skrzy¿owania
	int ID;
	/// @brief Wspó³rzêdna X skrzy¿owania
	int x;
	/// @brief Wspó³rzêdna Y skrzy¿owania
	int y;
	/// @brief Tablica dróg które ³¹cz¹ siê nad danym skrzy¿owaniu
	vector <int> id_drogi;
	/// @brief Tablica znaków dla ka¿dej drogi
	vector <vector <CZnak*>> znaki;
	/// @brief Tablica sygnalizacji œwietlnych
	vector <CSwiatla*> swiatla;
	/// @brief Numer sekwencji do której nale¿y dana sygnalizacja
	int sekwencjeSwiatel; 
	/// @brief Zajêtoœæ skrzy¿owania przz dany pojazd nadrzêdna nad prawami ruchu drogowego  
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

