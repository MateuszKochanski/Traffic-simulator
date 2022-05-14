#pragma once
#include "CMapa.h"
#include <fstream>

class CWczytywaczMapy
{
	void wczytajMape(CMapa*, string);
public:
	CWczytywaczMapy();
	CWczytywaczMapy(CMapa*, string);
	void setMapa(CMapa*, string);
};
