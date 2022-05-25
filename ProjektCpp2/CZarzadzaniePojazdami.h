#pragma once
#include "CMapa.h"
#include <cstdlib>
#include <ctime>
#include "CUprzywilejowany.h"
#include "COsobowy.h"

/// @file CZarzadzaniePojazdami.h
/// @brief Plik nag³ówkowy klasy CZarzadzaniePojazdami

/// @brief Klasa tworz¹ca pojazdy na mapie
class CZarzadzaniePojazdami : public CObserwowana
{
	CMapa* mapa;
	int ilePojazdow;
	void dodajPojazd();
	void utworzPojazdy();
	vector <CObserwator*> obserwatorzy;
public:
	CZarzadzaniePojazdami(CMapa *m, int ile = 50);
	void attach(CObserwator*);
	void detach(CObserwator*);
	void notify();
};

