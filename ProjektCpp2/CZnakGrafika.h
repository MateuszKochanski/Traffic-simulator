#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
* @file CZnakGrafika.h
* @brief Plik nag��wkowy klasy CZnakGrafika
*/

/// @brief  Klasa s�u��ca do rysowania obiekt�w klasy CZnak
class CZnakGrafika
{
	/// @brief Wsp�rz�dna X po�o�enia znaku
	int x;
	/// @brief Wsp�rz�dna Y po�o�enia znaku
	int y;
	/// @brief K�t znaku
	double kat;
	/// @brief Typ znaku (U - ust�p pierwsze�stwo, P - droga z pierwszenstwem, R - rondo)
	char typ;
public:
	CZnakGrafika(int a, int  b, double katt, char tp);
	void rysuj(sf::RenderWindow* w);
};

