#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CObserwator.h"
#include "CPojazd.h"


class CPojazdGrafika : public CObserwator
{
	double x;
	double y;
	double kat;
	CPojazd* pojazd;
	double sx;
	double sy;
	double promien;
	bool trybSkretu;
	bool kierunekSkretu;
public:
	CPojazdGrafika(CPojazd* poj);
	void update(int arg = 0);
	void rysuj(sf::RenderWindow* w);
	void liczSrodekObrotu(bool kierunek);
};

