#pragma once
#include <stdio.h>
#include <time.h>
#include "CMapa.h"
#include "CZarzadzaniePojazdami.h"

/// @file CSymulacja.h
/// @brief Plik nag��wkowy klasy CSymulacja

/// @brief Klasa symulacji
class CSymulacja
{
	/// @brief Pocz�tkowy czas
	clock_t start;
	/// @brief Aktualny czas
	clock_t now;
	/// @brief R�nica pomi�dzy czasem aktualnym, a pocz�tkowym
	double elapsed;
	/// @brief Cz�stotliwo�� od�wierzania symulacji
	int czestotliwosc;
	/// @brief Obiekt przechowywuj�cy wszystkie elementy znajduj�ce si� na mapie
	CMapa* mapa;
	/// @brief Obiekt tworz�cy i usuwaj�cy pojazdy z mapy
	CZarzadzaniePojazdami* zarzadaniePojazdami;
public:
	CSymulacja();
	CSymulacja(CMapa* m, int cz, CObserwator* obs, int liczbaPojazdow);
	void uruchom();
	void odswiez();
};

