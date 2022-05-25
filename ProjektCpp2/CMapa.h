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
/// @brief Plik nag��wkowy klasy CMapa

using namespace std;

/// @brief Klasa obiektu przechowywuj�cego wszystkie obiekty znajduj�ce si� na mapie
class CMapa : public CObserwowana
{
private:
	/// @brief Tablica przechowywuj�ca drogi
	vector <CDroga*> drogi;
	/// @brief Tablica przechowywuj�ca skrzy�owania
	vector <CSkrzyzowanie*> skrzyzowania;
	/// @brief Tablica przechowywuj�ca pojazdy
	vector <CPojazd*> pojazdy;
	/// @brief Tablica przechowywuj�ca obserwator�w
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

