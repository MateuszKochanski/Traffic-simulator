#pragma once
#include "CMapa.h"
#include "CObserwator.h"
#include "CDrogaGrafika.h"
#include "CSkrzyzowanieGrafika.h"
#include "CZnakGrafika.h"
#include "CSwiatlaGrafika.h"
#include "CPojazdGrafika.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


/**
* @file CGrafika.h
* @brief Plik nagłówkowy klasy CGrafika
*/


/// @brief Klasa przechowująca grafiki wszystkich wyswietlanych elementów
class CGrafika
{
private:
	/// @brief Obiekt przechowywujący wszystkie elementy znajdujące się na mapie
	/// @brief Tablica przechowywująca grafiki dróg
	vector <CDrogaGrafika*> grDrogi;
	/// @brief Tablica przechowywująca grafiki skrzyzowań
	vector <CSkrzyzowanieGrafika*> grSkrzyzowania;
	/// @brief Tablica przechowywująca grafiki znaków
	vector <CZnakGrafika*> grZnaki;
	/// @brief Tablica przechowywująca grafiki świateł
	vector <CSwiatlaGrafika*> grSwiatla;
	/// @brief Tablica przechowywująca grafiki pojazdów
	vector <CPojazdGrafika*> grPojazdy;

public:
	~CGrafika();
	void dodajGrPojazdu(CPojazdGrafika* pojazd);
	void dodajGrDrogi(CDrogaGrafika* D);
	void dodajGrSkrzyzowania(CSkrzyzowanieGrafika* S);
	void dodajGrSwiatla(CSwiatlaGrafika* Sw);
	void dodajGrZnaku(CZnakGrafika* Z);

	vector <CDrogaGrafika*> getGrDrogi();
	vector <CSkrzyzowanieGrafika*> getGrSkrzyzowania();
	vector <CZnakGrafika*> getGrZnaki();
	vector <CSwiatlaGrafika*> getGrSwiatla();
	vector <CPojazdGrafika*> getGrPojazdy();
};

