#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
* @file CSkrzyzowanieGrafika.h
* @brief Plik nag³ówkowy klasy CSkrzyzowanie
*/

/// @brief Klasa s³u¿¹ca do rysowania obiektów klasy CSkrzyzowanie
class CSkrzyzowanieGrafika
{
	/// @brief Wspó³rzêdna X po³o¿enia skrzy¿owania
	int x;
	/// @brief Wspó³rzêdna Y po³o¿enia skrzy¿owania
	int y;
	/// @brief Czy dane skrzyzowanie jest rondem
	bool czyRondo;
public:
	CSkrzyzowanieGrafika(int a, int b, bool rond = false);
	void rysuj(sf::RenderWindow* w);
};

