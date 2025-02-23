#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CGrafika.h"

/// @file CWyswietlanie.h
/// @brief Plik nagłówkowy klasy CWyswietlanie

/// @brief Klasa wyświetlająca wszystkie obiekty przechowywane przez obiekt grafika
class CWyswietlanie
{
	/// @brief Okno programu
	sf::RenderWindow* window;
public:
	CWyswietlanie();
	void wyswietl(CGrafika* grafika);
	bool czyJestOtwarte();
};

