#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
* @file CSkrzyzowanieGrafika.h
* @brief Plik nag��wkowy klasy CSkrzyzowanie
*/

/// @brief Klasa s�u��ca do rysowania obiekt�w klasy CSkrzyzowanie
class CSkrzyzowanieGrafika
{
	/// @brief Wsp�rz�dna X po�o�enia skrzy�owania
	int x;
	/// @brief Wsp�rz�dna Y po�o�enia skrzy�owania
	int y;
	/// @brief Czy dane skrzyzowanie jest rondem
	bool czyRondo;
public:
	CSkrzyzowanieGrafika(int a, int b, bool rond = false);
	void rysuj(sf::RenderWindow* w);
};

