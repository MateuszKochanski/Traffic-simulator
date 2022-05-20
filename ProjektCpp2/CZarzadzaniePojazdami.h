#pragma once
#include "CMapa.h"
#include <cstdlib>
#include <ctime>

class CZarzadzaniePojazdami : public CObserwowana
{
	CMapa* mapa;
	int ilePojazdow;
	void dodajPojazd();
	void utworzPojazdy();
	vector <CObserwator*> obserwatorzy;
public:
	CZarzadzaniePojazdami(CMapa *m, int ile = 100);
	void odswierz();
	void attach(CObserwator*);
	void detach(CObserwator*);
	void notify();
};

