#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
* @file CDrogaGrafika.h
* @brief Plik nag³ówkowy klasy CDrogaGrafika
*/

/**
* @brief Klasa s³u¿¹ca do rysowania obiektów klasy CDroga
*/
class CDrogaGrafika
{
	/// Wspó³rzêdna X pocz¹tku drogi
	int x;
	/// Wspó³rzêdna Y pocz¹tku drogi
	int y;
	/// D³ugoœæ drogi
	int dlugosc;
	/// K¹t drogi
	double kat;
public:
	CDrogaGrafika(int a, int b, int dl, double katt);
	void rysuj(sf::RenderWindow* window);
};

