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
* @brief Plik nag³ówkowy klasy CGrafika
*/


/// @brief Klasa przechowuj¹ca grafiki wszystkich wyswietlanych elementów
class CGrafika
{
private:
	/// @brief Obiekt przechowywuj¹cy wszystkie elementy znajduj¹ce siê na mapie
	/// @brief Tablica przechowywuj¹ca grafiki dróg
	vector <CDrogaGrafika*> grDrogi;
	/// @brief Tablica przechowywuj¹ca grafiki skrzyzowañ
	vector <CSkrzyzowanieGrafika*> grSkrzyzowania;
	/// @brief Tablica przechowywuj¹ca grafiki znaków
	vector <CZnakGrafika*> grZnaki;
	/// @brief Tablica przechowywuj¹ca grafiki œwiate³
	vector <CSwiatlaGrafika*> grSwiatla;
	/// @brief Tablica przechowywuj¹ca grafiki pojazdów
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

