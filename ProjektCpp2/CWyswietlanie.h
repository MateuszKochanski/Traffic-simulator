#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CGrafika.h"

/// @file CWyswietlanie.h
/// @brief Plik nag³ówkowy klasy CWyswietlanie

/// @brief Klasa wyœwietlaj¹ca wszystkie obiekty przechowywane przez obiekt grafika
class CWyswietlanie
{
	/// @brief Okno programu
	sf::RenderWindow* window;
public:
	CWyswietlanie();
	void wyswietl(CGrafika* grafika);
	bool czyJestOtwarte();
};

