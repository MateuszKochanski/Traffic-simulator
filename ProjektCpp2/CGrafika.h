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
* @brief Plik nag��wkowy klasy CGrafika
*/


/// @brief Klasa przechowuj�ca grafiki wszystkich wyswietlanych element�w
class CGrafika
{
private:
	/// @brief Obiekt przechowywuj�cy wszystkie elementy znajduj�ce si� na mapie
	/// @brief Tablica przechowywuj�ca grafiki dr�g
	vector <CDrogaGrafika*> grDrogi;
	/// @brief Tablica przechowywuj�ca grafiki skrzyzowa�
	vector <CSkrzyzowanieGrafika*> grSkrzyzowania;
	/// @brief Tablica przechowywuj�ca grafiki znak�w
	vector <CZnakGrafika*> grZnaki;
	/// @brief Tablica przechowywuj�ca grafiki �wiate�
	vector <CSwiatlaGrafika*> grSwiatla;
	/// @brief Tablica przechowywuj�ca grafiki pojazd�w
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

