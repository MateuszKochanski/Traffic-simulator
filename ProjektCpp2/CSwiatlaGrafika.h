#pragma once
#include "CObserwator.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
* @file CSwiatlaGrafika.h
* @brief Plik nag³ówkowy klasy CSwiatlaGrafika
*/

/// @brief Klasa s³u¿¹ca do rysowania obiektów klasy CSwiatla

class CSwiatlaGrafika : public CObserwator
{
	/// @brief Wspó³rzêdna X œrodka sygnalizacji
	float x;
	/// @brief Wspó³rzêdna Y œrodka sygnalizacji
	float y;
	/// @brief Wspó³rzêdna X œwiat³a zielonego
	float xz;
	/// @brief Wspó³rzêdna Y œwiat³a zielonego
	float yz;
	/// @brief Wspó³rzêdna X œwiat³a czerwonego
	float xcz;
	/// @brief Wspó³rzêdna Y œwiat³a czerwonego
	float ycz;
	/// @brief K¹t sygnalizacji
	double kat;
	/// @brief Aktualnie œwiec¹ce siê œwiat³o
	int kolor;
public:
	void update(int kol);
	CSwiatlaGrafika(int a, int  b, double katt, int kol, double sinus, double cosinus);
	void rysuj(sf::RenderWindow* w);
};

