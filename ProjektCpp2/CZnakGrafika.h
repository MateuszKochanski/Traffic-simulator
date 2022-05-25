#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
* @file CZnakGrafika.h
* @brief Plik nag³ówkowy klasy CZnakGrafika
*/

/// @brief  Klasa s³u¿¹ca do rysowania obiektów klasy CZnak
class CZnakGrafika
{
	/// @brief Wspó³rzêdna X po³o¿enia znaku
	int x;
	/// @brief Wspó³rzêdna Y po³o¿enia znaku
	int y;
	/// @brief K¹t znaku
	double kat;
	/// @brief Typ znaku (U - ust¹p pierwszeñstwo, P - droga z pierwszenstwem, R - rondo)
	char typ;
public:
	CZnakGrafika(int a, int  b, double katt, char tp);
	void rysuj(sf::RenderWindow* w);
};

