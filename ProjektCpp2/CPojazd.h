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
	bool jestNastDroga;
	int* kolejnoscDrog;	
	
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


	void attach(CObserwator*);
	void detach(CObserwator*);
	void notify();
};

