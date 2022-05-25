#pragma once
#include "CObserwator.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
* @file CSwiatlaGrafika.h
* @brief Plik nag��wkowy klasy CSwiatlaGrafika
*/

/// @brief Klasa s�u��ca do rysowania obiekt�w klasy CSwiatla

class CSwiatlaGrafika : public CObserwator
{
	/// @brief Wsp�rz�dna X �rodka sygnalizacji
	float x;
	/// @brief Wsp�rz�dna Y �rodka sygnalizacji
	float y;
	/// @brief Wsp�rz�dna X �wiat�a zielonego
	float xz;
	/// @brief Wsp�rz�dna Y �wiat�a zielonego
	float yz;
	/// @brief Wsp�rz�dna X �wiat�a czerwonego
	float xcz;
	/// @brief Wsp�rz�dna Y �wiat�a czerwonego
	float ycz;
	/// @brief K�t sygnalizacji
	double kat;
	/// @brief Aktualnie �wiec�ce si� �wiat�o
	int kolor;
public:
	void update(int kol);
	CSwiatlaGrafika(int a, int  b, double katt, int kol, double sinus, double cosinus);
	void rysuj(sf::RenderWindow* w);
};

