#include "CPojazdGrafika.h"
#include <math.h>

/// @file CPojazdGrafika.cpp
/// @brief Plik Ÿród³owy klasy CPojazdGrafika

/// @brief Konstruktor klasy CPojazdGrafika
/// @param poj WskaŸnik do pojazdu, który jest reprezentowany przez dan¹ grafikê
CPojazdGrafika::CPojazdGrafika(CPojazd* poj)
{
	pojazd = poj;
	x = pojazd->getX();
	y = pojazd->getY();
	kat = pojazd->getKat();
	trybSkretu = false;
	pojazd->attach(this);

	if (pojazd->getCzyUprzywilejowany())
	{
		Kolor = sf::Color(255, 255, 255, 255);
	}
	else
	{
		Kolor = sf::Color(255, 0, 0, 255);
	}
}

/// @brief Aktualizuje parametry na podstawie obiektu klasy CPojazd
/// @param arg Je¿eli równe 1 to przechodzi w tryb skrêtu
void CPojazdGrafika::update(int arg)
{
	if (arg == 0)
	{
		x = pojazd->getX();
		y = pojazd->getY();
		kat = pojazd->getKat();
		trybSkretu = false;
	}
	else
	{
		if (!trybSkretu) 
		{
			trybSkretu = true;
			promien = pojazd->getPromien();
			kierunekSkretu = pojazd->getKierunekSkretu();
			sx = pojazd->getSx();
			sy = pojazd->getSy();

		}
		kat = pojazd->getKat();	
	}

}

/// @brief Rysuje pojazd w oknie programu
/// @param window Okno programu

void CPojazdGrafika::rysuj(sf::RenderWindow* window)
{
	
	sf::RectangleShape prostokat;
	prostokat.setFillColor(Kolor);
	prostokat.setSize(sf::Vector2f(14, 6));
	if (!trybSkretu)
	{
		prostokat.setOrigin(sf::Vector2f(7, 3));
		prostokat.setPosition(sf::Vector2f(x, y));
	}
	else
	{
		if (kierunekSkretu)
		{
			prostokat.setOrigin(sf::Vector2f(7, promien - 5));
		}
		else
		{
			prostokat.setOrigin(sf::Vector2f(7, -promien - 6));
		}
		prostokat.setPosition(sf::Vector2f(sx, sy));

		sf::CircleShape zielony;
		zielony.setRadius(2);
		zielony.setOrigin(sf::Vector2f(1, 1));
		zielony.setPosition(sf::Vector2f(sx, sy));
		//window->draw(zielony);
	}
	prostokat.setRotation(kat);
	window->draw(prostokat);
	
}