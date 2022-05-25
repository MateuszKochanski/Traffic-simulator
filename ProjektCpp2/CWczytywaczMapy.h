#pragma once
#include "CMapa.h"
#include <fstream>

/// @file CWczytywaczMapy.h
/// @brief Plik nag��wkowy klasy CWczytywaczMapy

/// @brief Klasa do wczytywania mapy z pliku
class CWczytywaczMapy
{
	void wczytajMape(CMapa*, string);
public:

	CWczytywaczMapy(CMapa*, string);
};
