#pragma once
#include <vector>
#include <iostream>
#include "CZnak.h"
#include "CSwiatla.h"

using namespace std;
class CSkrzyzowanie
{
protected:
	int ID;
	int x;
	int y;
	vector <int> id_drogi;
	vector <vector <CZnak*>> znaki;
	vector <CSwiatla*> swiatla;
	int sekwencjeSwiatel; 
	int typ;
	int bufor;
public:
	CSkrzyzowanie();
	int getID();
	int getX();
	int getY();
	void set(int, int, int, int);
	int getTyp();
	vector <int> getIdDrogi();
	vector <vector <CZnak*>> getZnaki();
	vector <CSwiatla*> getSwiatla();
	void dodajDroge(int idDrogi, vector <CZnak*> zn);
	void dodajSwiatla(vector <int> drogi, int czas);
	void setBufor(int id);
	int getBufor();
};

