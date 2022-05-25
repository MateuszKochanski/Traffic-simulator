#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CObserwator.h"
#include "CPojazd.h"

/**
* @file CPojazdGrafika.h
* @brief Plik nag³ówkowy klasy CPojazdGrafika
*/


///@brief Klasa s³u¿¹ca do rysowania obiektów klasy CPojazd

class CPojazdGrafika : public CObserwator
{
	/// @brief Wspó³rzêdna X po³o¿enia pojazdu
	double x;
	/// @brief Wspó³rzêdna Y po³o¿enia pojazdu
	double y;
	/// @brief K¹t pojazdu
	double kat;
	/// @brief WskaŸnik do pojazdu, który jest reprezentowany przez dan¹ grafikê
	CPojazd* pojazd;
	/// @brief Wspó³rzêdna X œrodka obrotu grafiki pojazdu przy pokonywaniu zakrêtów
	double sx;
	/// @brief Wspó³rzêdna Y œrodka obrotu grafiki pojazdu przy pokonywaniu zakrêtów
	double sy;
	/// @brief Promieñ po którym porusza siê skrêcaj¹cy pojazd
	double promien;
	/// @brief Czy pojazd jest w trybie skrêtu
	bool trybSkretu;
	/// @brief Kierunek skrêtu: 1 - prawa, 0 - lewa
	bool kierunekSkretu;
	/// @brief Kolor pojazdu (inny dla pojazdów uprzywilejowanych)
	sf::Color Kolor;
public:
	CPojazdGrafika(CPojazd* poj);
	void update(int arg = 0);
	void rysuj(sf::RenderWindow* w);
};

