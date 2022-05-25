#include "CZnakGrafika.h"

/// @file CZnakGrafika.cpp
/// @brief Plik Ÿród³owy klasy CZnakGrafika

/// @brief Konstruktor klasy CZnakGrafika
/// @param a Wspó³rzêdna X po³o¿enia znaku
/// @param b Wspó³rzêdna Y po³o¿enia znaku
/// @param katt K¹t znaku
/// @param tp Typ znaku (U - ust¹p pierwszeñstwo, P - droga z pierwszenstwem, R - rondo)
CZnakGrafika::CZnakGrafika(int a, int b, double katt ,char tp)
{
	x = a;
	y = b;
	kat = katt;
	typ = tp;
}

/// @brief Rysuje znak w oknie programu
/// @param window Okno programu
void CZnakGrafika::rysuj(sf::RenderWindow* window)
{
	if (typ == 'U')
	{
		sf::CircleShape znak(7, 3);
		znak.setOrigin(sf::Vector2f(7, 7));
		znak.setFillColor(sf::Color(255, 150, 0, 255));
		znak.setPosition(sf::Vector2f(x, y));
		znak.setRotation(kat + 90);
		window->draw(znak);
	}
	else if (typ == 'P')
	{
		sf::RectangleShape znak;
		znak.setFillColor(sf::Color(255, 255, 10, 255));
		znak.setSize(sf::Vector2f(10, 10));
		znak.setOrigin(sf::Vector2f(5, 5));
		znak.setPosition(sf::Vector2f(x, y));
		znak.setRotation(kat + 45);
		window->draw(znak);
	}
	else if (typ == 'R')
	{
		sf::CircleShape znakA;
		sf::CircleShape znakB;
		sf::CircleShape znakC;
		znakA.setRadius(7);
		znakA.setOrigin(sf::Vector2f(7, 7));
		znakA.setFillColor(sf::Color(0, 0, 255, 255));
		znakA.setPosition(sf::Vector2f(x, y));

		znakB.setRadius(5);
		znakB.setOrigin(sf::Vector2f(5, 5));
		znakB.setFillColor(sf::Color(255, 255, 255, 255));
		znakB.setPosition(sf::Vector2f(x, y));

		znakC.setRadius(4);
		znakC.setOrigin(sf::Vector2f(4, 4));
		znakC.setFillColor(sf::Color(0, 0, 255, 255));
		znakC.setPosition(sf::Vector2f(x, y));

		window->draw(znakA);
		window->draw(znakB);
		window->draw(znakC);
	}
	else if (typ == 'T')
	{
		sf::CircleShape znakA(7, 8);
		sf::RectangleShape znakB;
		znakA.setOrigin(sf::Vector2f(7, 7));
		znakA.setFillColor(sf::Color(255, 0, 0, 255));
		znakA.setPosition(sf::Vector2f(x, y));
		znakA.setRotation(kat+22);
		znakB.setSize(sf::Vector2f(2,8));
		znakB.setOrigin(sf::Vector2f(1, 4));
		znakB.setFillColor(sf::Color(255, 255, 255, 255));
		znakB.setPosition(sf::Vector2f(x, y));
		znakB.setRotation(kat);
		window->draw(znakA);
		window->draw(znakB);
	}
}
