#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CZnakGrafika
{
	int x;
	int y;
	double kat;
	char typ;
public:
	CZnakGrafika(int a, int  b, double katt, char tp);
	void rysuj(sf::RenderWindow* w);
};

