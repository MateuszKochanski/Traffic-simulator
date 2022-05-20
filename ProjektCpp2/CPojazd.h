#pragma once
#include "CObserwowana.h"
#include "CObserwator.h"
#include "CDroga.h"
#include "CSkrzyzowanie.h"
#include <cstdlib>
#include <ctime>

class CPojazd : public CObserwowana
{
private:
	int ID;
	double x;
	double y;
	double odleglosc;
	int idDrogi;
	int idNastDrogi;
	int kierunek;
	int nieKierunek;
	double kat;
	vector <CObserwator*> obserwatorzy;
	double predkosc;
	bool jestNastDroga;//czy wylosowano nastêpn¹ drogê


	double sx;
	double sy;
	int* kolejnoscDrog;	
	double* katy;//posortowane k¹ty wszystkich drog
	bool trybSkretu;//czy skrêca czy nie skrêca
	double promien;//promien skrêtu
	bool kierunekSkretu;//1 skrêt w prawo, 0 -skrêt w lewo
	bool czyGotowyDoSkretu;
	double odlegloscRozpoczeciaSkretu;
	double odlSkretu;
	double katNastDrogi;
	double katPoczatkowy;
	bool wlasnieZmienionoDroge;

	int cierpliwosc;
	bool czyWlasnieUstal;

	double licznikCzekania;
	bool boPojazdyNaSkrzyzowaniu;
	bool czyMogeJechac;

	void odswierzKolejnoscDrog(vector <CDroga*> drogi, vector <CSkrzyzowanie*> skrzyzowania);
public:
	CPojazd(int id,vector <CSkrzyzowanie*> s, CDroga* droga, int odl, int kier);

	int getID();
	int getX();
	int getY();
	int getIDDrogi();
	int getOdleglosc();
	double getKat();
	void odswierz(vector <CDroga*> drogi, vector <CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc);
	double getPromien();
	bool getKierunekSkretu();
	double getSx();
	double getSy();
	bool czyStoi();
	double getKatNastDrogi();

	void attach(CObserwator*);
	void detach(CObserwator*);
	void notify();
};

