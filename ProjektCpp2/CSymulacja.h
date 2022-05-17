#pragma once
#include <stdio.h>
#include <time.h>
#include "CMapa.h"
#include "CZarzadzaniePojazdami.h"


class CSymulacja
{
	clock_t start;
	clock_t now;
	double elapsed;
	int czestotliwosc;
	CMapa* mapa;
	CZarzadzaniePojazdami* zarzadaniePojazdami;
public:
	CSymulacja();
	CSymulacja(CMapa* m, int cz, CObserwator* obs);
	void setMapa(CMapa* m, int cz);
	void uruchom();
};

