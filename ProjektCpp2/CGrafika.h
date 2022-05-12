#pragma once
#include "CMapa.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CGrafika
{
private:
	sf::RenderWindow* window;
	CMapa* mapa;
	void rysujDrogi();
	void rysujSkrzyzowania();
public:
	void rysuj();
	CGrafika(sf::RenderWindow*, CMapa*);

};

