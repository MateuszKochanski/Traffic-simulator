#pragma once
#include "CObserwator.h"
#include "CGrafika.h"

/// @file CZarzadzanieGrafika.h
/// @brief Plik nag��wkowy klasy CZarzadzanieGrafika

/// @brief Klasa s�u��ca do dodawania obiekt�w klasy CPojazdGrafika do obiektu klasy CGrafika
class CZarzadzanieGrafika : public CObserwator
{
	/// @brief Wska�nik do obiektu przechowywuj�cego wszystkie wyswietlane obiekty graficze
	CGrafika* grafika;
	/// @brief Wska�nik do obiektu przechuwywuj�cego ca�� map�
	CMapa* mapa;
public:
	CZarzadzanieGrafika(CGrafika* gr, CMapa* m);
	void update(int arg);
};
