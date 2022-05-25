#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CObserwator.h"
#include "CPojazd.h"

/**
* @file CPojazdGrafika.h
* @brief Plik nag��wkowy klasy CPojazdGrafika
*/


///@brief Klasa s�u��ca do rysowania obiekt�w klasy CPojazd

class CPojazdGrafika : public CObserwator
{
	/// @brief Wsp�rz�dna X po�o�enia pojazdu
	double x;
	/// @brief Wsp�rz�dna Y po�o�enia pojazdu
	double y;
	/// @brief K�t pojazdu
	double kat;
	/// @brief Wska�nik do pojazdu, kt�ry jest reprezentowany przez dan� grafik�
	CPojazd* pojazd;
	/// @brief Wsp�rz�dna X �rodka obrotu grafiki pojazdu przy pokonywaniu zakr�t�w
	double sx;
	/// @brief Wsp�rz�dna Y �rodka obrotu grafiki pojazdu przy pokonywaniu zakr�t�w
	double sy;
	/// @brief Promie� po kt�rym porusza si� skr�caj�cy pojazd
	double promien;
	/// @brief Czy pojazd jest w trybie skr�tu
	bool trybSkretu;
	/// @brief Kierunek skr�tu: 1 - prawa, 0 - lewa
	bool kierunekSkretu;
	/// @brief Kolor pojazdu (inny dla pojazd�w uprzywilejowanych)
	sf::Color Kolor;
public:
	CPojazdGrafika(CPojazd* poj);
	void update(int arg = 0);
	void rysuj(sf::RenderWindow* w);
};

