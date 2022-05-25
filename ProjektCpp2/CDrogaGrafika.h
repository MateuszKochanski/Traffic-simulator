#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
* @file CDrogaGrafika.h
* @brief Plik nag��wkowy klasy CDrogaGrafika
*/

/**
* @brief Klasa s�u��ca do rysowania obiekt�w klasy CDroga
*/
class CDrogaGrafika
{
	/// Wsp�rz�dna X pocz�tku drogi
	int x;
	/// Wsp�rz�dna Y pocz�tku drogi
	int y;
	/// D�ugo�� drogi
	int dlugosc;
	/// K�t drogi
	double kat;
public:
	CDrogaGrafika(int a, int b, int dl, double katt);
	void rysuj(sf::RenderWindow* window);
};

