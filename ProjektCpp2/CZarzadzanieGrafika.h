#pragma once
#include "CObserwator.h"
#include "CGrafika.h"

/// @file CZarzadzanieGrafika.h
/// @brief Plik nag³ówkowy klasy CZarzadzanieGrafika

/// @brief Klasa s³u¿¹ca do dodawania obiektów klasy CPojazdGrafika do obiektu klasy CGrafika
class CZarzadzanieGrafika : public CObserwator
{
	/// @brief WskaŸnik do obiektu przechowywuj¹cego wszystkie wyswietlane obiekty graficze
	CGrafika* grafika;
	/// @brief WskaŸnik do obiektu przechuwywuj¹cego ca³¹ mapê
	CMapa* mapa;
public:
	CZarzadzanieGrafika(CGrafika* gr, CMapa* m);
	void update(int arg);
};
