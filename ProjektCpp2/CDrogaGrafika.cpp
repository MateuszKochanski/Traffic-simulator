#include "CDrogaGrafika.h"
/**
* @file CDrogaGrafika.cpp
* @brief Plik Ÿród³owy klasy CDrogaGrafika
*/


/// @brief Konstruktor klasy CDrogaGrafika
/// @param a Wspó³rzêdna X pocz¹tku drogi
/// @param b Wspó³rzêdna Y pocz¹tku drogi
/// @param dl D³ugoœæ drogi
/// @param katt K¹t drogi
CDrogaGrafika::CDrogaGrafika(int a, int b, int dl, double katt)
{
	x = a;
	y = b;
	dlugosc = dl;
	kat = katt;
}

/// @brief Rysuje drogê w oknie programu
/// @param window Okno programu
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
