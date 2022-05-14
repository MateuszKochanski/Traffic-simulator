#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CDrogaGrafika
{
	int x;
	int y;
	int dlugosc;
	double kat;
public:
	CDrogaGrafika(int a, int b, int dl, double katt);
	void rysuj(sf::RenderWindow* window);
};

