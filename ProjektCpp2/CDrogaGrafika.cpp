#include "CDrogaGrafika.h"

CDrogaGrafika::CDrogaGrafika(int a, int b, int dl, double katt)
{
	x = a;
	y = b;
	dlugosc = dl;
	kat = katt;
}

void CDrogaGrafika::rysuj(sf::RenderWindow* window)
{
	sf::RectangleShape linia;
	linia.setFillColor(sf::Color(50, 50, 50, 255));

	linia.setSize(sf::Vector2f(dlugosc, 20));
	linia.setOrigin(sf::Vector2f(0, 20 / 2));
	linia.setPosition(sf::Vector2f(x, y));
	linia.setRotation(kat);
	window->draw(linia);
}
