#include "CSkrzyzowanieGrafika.h"

/// @file CSkrzyzowanieGrafika.cpp
/// @brief Plik �r�d�owy klasy CSkrzyzowanieGrafika

/// @brief Konstruktor klasy CSkrzyzowanieGrafika
/// @param a Wsp�rz�dna X po�o�enia skrzy�owania
/// @param b Wspo�rz�dna Y po�o�ania skrzy�owania
/// @param rondo Czy dane skrzyzowanie jest rondem
CSkrzyzowanieGrafika::CSkrzyzowanieGrafika(int a, int b, bool rondo)
{
	x = a;
	y = b;
	czyRondo = rondo;
}

/// @brief Rysuje skrzyzowanie w oknie programu
/// @param window Okno programu
void CSkrzyzowanieGrafika::rysuj(sf::RenderWindow* window)
{
	if (!czyRondo)
	{
		sf::CircleShape kolo;
		kolo.setFillColor(sf::Color(50, 50, 50, 255));
		kolo.setRadius(10);
		kolo.setOrigin(sf::Vector2f(10, 10));
		kolo.setPosition(sf::Vector2f(x, y));
		window->draw(kolo);
	}
	else
	{
		sf::CircleShape kolo1;
		kolo1.setFillColor(sf::Color(50, 50, 50, 255));
		kolo1.setRadius(30);
		kolo1.setOrigin(sf::Vector2f(30, 30));
		kolo1.setPosition(sf::Vector2f(x, y));

		sf::CircleShape kolo2;
		kolo2.setFillColor(sf::Color(0, 0, 0, 255));
		kolo2.setRadius(10);
		kolo2.setOrigin(sf::Vector2f(10, 10));
		kolo2.setPosition(sf::Vector2f(x, y));
		window->draw(kolo1);
		window->draw(kolo2);
	}
}
