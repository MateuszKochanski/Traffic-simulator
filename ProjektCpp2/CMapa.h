#pragma once
#include "CDroga.h"
#include "CSkrzyzowanie.h"
#include "CPojazd.h"
#include "CObserwowana.h"
#include <string> 
#include <vector>
#include <fstream>
#include "COsobowy.h"
#include "CUprzywilejowany.h"

/// @file CMapa.h
/// @brief Plik nagłówkowy klasy CMapa

using namespace std;

/// @brief Klasa obiektu przechowywującego wszystkie obiekty znajdujące się na mapie
class CMapa : public CObserwowana
{
private:
	/// @brief Tablica przechowywująca drogi
	vector <CDroga*> drogi;
	/// @brief Tablica przechowywująca skrzyżowania
	vector <CSkrzyzowanie*> skrzyzowania;
	/// @brief Tablica przechowywująca pojazdy
	vector <CPojazd*> pojazdy;
	/// @brief Tablica przechowywująca obserwatorów
	vector <CObserwator*> obserwator;
public:
	~CMapa();
	vector <CDroga*> getDrogi();
	vector <CSkrzyzowanie*> getSkrzyzowania();
	vector <CPojazd*> getPojazdy();
	void dodajSkrzyzowanie(CSkrzyzowanie *S);
	void dodajDroge(CDroga *D);
	void dodajPojazd(CPojazd *P);
	void attach(CObserwator*);
	void detach(CObserwator*);
	void notify();
};

