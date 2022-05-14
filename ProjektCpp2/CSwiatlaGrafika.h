#pragma once
#include "CObserwator.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CSwiatlaGrafika : public CObserwator
{
	float x;
	float y;
	float xz;
	float yz;
	float xcz;
	float ycz;

	double kat;
	int kolor;
public:
	void update(int kol);
	CSwiatlaGrafika(int a, int  b, double katt, int kol, double sinus, double cosinus);
	void rysuj(sf::RenderWindow* w);
};

