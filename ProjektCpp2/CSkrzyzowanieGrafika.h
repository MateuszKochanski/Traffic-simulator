#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CSkrzyzowanieGrafika
{
	int x;
	int y;
	bool czyRondo;
public:
	CSkrzyzowanieGrafika(int a, int b, bool rond = false);
	void rysuj(sf::RenderWindow* w);
};

