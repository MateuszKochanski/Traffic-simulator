#pragma once
#include <stdio.h>
#include <time.h>
#include "CMapa.h"
#include "CZarzadzaniePojazdami.h"

/// @file CSymulacja.h
/// @brief Plik nag³ówkowy klasy CSymulacja

/// @brief Klasa symulacji
class CSymulacja
{
	/// @brief Pocz¹tkowy czas
	clock_t start;
	/// @brief Aktualny czas
	clock_t now;
	/// @brief Ró¿nica pomiêdzy czasem aktualnym, a pocz¹tkowym
	double elapsed;
	/// @brief Czêstotliwoœæ odœwierzania symulacji
	int czestotliwosc;
	/// @brief Obiekt przechowywuj¹cy wszystkie elementy znajduj¹ce siê na mapie
	CMapa* mapa;
	/// @brief Obiekt tworz¹cy i usuwaj¹cy pojazdy z mapy
	CZarzadzaniePojazdami* zarzadaniePojazdami;
public:
	CSymulacja();
	CSymulacja(CMapa* m, int cz, CObserwator* obs, int liczbaPojazdow);
	void uruchom();
	void odswiez();
};

