#include "CSwiatlaGrafika.h"

/// @file CSwiatlaGrafika.cpp
/// @brief Plik �r�d�owy klasy CSwiatlaGrafika

/// @brief Aktualizacja aktualnego koloru �wiat�a
/// @param kol Aktualny kolor �wat�a
void CSwiatlaGrafika::update(int kol)
{
	kolor = kol;
}
/// @brief Konstruktor klasy CSwiatlaGrafika
/// @param a Wsp�rz�dna X �rodka sygnalizacji
/// @param b Wsp�rz�dna Y �rodka sygnalizacji
/// @param katt K�t sygnalizacji
/// @param kol Pocz�tkowy kolor �wiat�a sygnalizacji
/// @param sinus Warto�� sinusa k�ta sygnalizacji
/// @param cosinus Warto�� cosinusa k�ta sygnalizacji
CSwiatlaGrafika::CSwiatlaGrafika(int a, int b, double katt, int kol, double sinus, double cosinus)
{
	x = a;
	y = b;
	xz = a + cosinus * 10.0;
	yz = b + sinus * 10.0;
	xcz = a - cosinus * 10.0;
	ycz = b - sinus * 10.0;

	kat = katt;
	kolor = kol;
}

/// @brief Rysuje sygnalizacj� �wietln� w oknie programu
/// @param window Okno programu
void CSwiatlaGrafika::rysuj(sf::RenderWindow* window)
{
	sf::RectangleShape podstawa;
	podstawa.setSize(sf::Vector2f(30, 10));
	podstawa.setOrigin(15, 5);
	podstawa.setPosition(sf::Vector2f(x, y));
	podstawa.setFillColor(sf::Color(0, 0, 250, 255));
	podstawa.setRotation(kat);

	sf::CircleShape zielony;
	zielony.setRadius(4);
	zielony.setOrigin(sf::Vector2f(4, 4));
	zielony.setPosition(sf::Vector2f(xz, yz));

	sf::CircleShape zolty;
	zolty.setRadius(4);
	zolty.setOrigin(sf::Vector2f(4, 4));
	zolty.setPosition(sf::Vector2f(x, y));

	sf::CircleShape czerwony;
	czerwony.setRadius(4);
	czerwony.setOrigin(sf::Vector2f(4, 4));
	czerwony.setPosition(sf::Vector2f(xcz, ycz));

	if (kolor == 1)
	{
		zielony.setFillColor(sf::Color(0, 255, 0, 255));
		zolty.setFillColor(sf::Color(255, 255, 0, 50));
		czerwony.setFillColor(sf::Color(255, 0, 0, 50));
	}
	else if(kolor==2)
	{
		zielony.setFillColor(sf::Color(0, 255, 0, 50));
		zolty.setFillColor(sf::Color(255, 255, 0, 255));
		czerwony.setFillColor(sf::Color(255, 0, 0, 50));
	}
	else if (kolor == 3)
	{
		zielony.setFillColor(sf::Color(0, 255, 0, 50));
		zolty.setFillColor(sf::Color(255, 255, 0, 50));
		czerwony.setFillColor(sf::Color(255, 0, 0, 255));
	}
	window->draw(podstawa);
	window->draw(zielony);
	window->draw(zolty);
	window->draw(czerwony);
	
}
