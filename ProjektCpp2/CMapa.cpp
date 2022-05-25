#include "CMapa.h"
#include<iostream>

/// @file CMapa.cpp
/// @brief Plik Ÿród³owy klasy CMapa

/// @brief Destruktor klasy CMapa
CMapa::~CMapa()
{
	for (int i = 0; i < drogi.size(); i++)
	{
		delete drogi[i];
	}
	drogi.clear();

	for (int i = 0; i < skrzyzowania.size(); i++)
	{
		delete skrzyzowania[i];
	}
	skrzyzowania.clear();

	for (int i = 0; i < pojazdy.size(); i++)
	{
		delete pojazdy[i];
	}
	pojazdy.clear();

}

/// @brief Zwraca drogi
/// @return Tablica dróg
vector <CDroga*> CMapa::getDrogi()
{
	return drogi;
}

/// @brief Zwraca skrzy¿owania
/// @return Tablica skrzy¿owañ
vector <CSkrzyzowanie*> CMapa::getSkrzyzowania()
{
	return skrzyzowania;
}

/// @brief Zwraca pojazdy
/// @return Tablica pojazdów
vector<CPojazd*> CMapa::getPojazdy()
{
	return pojazdy;
}

/// @brief Dodaje nowe skrzy¿owanie do mapy
void CMapa::dodajSkrzyzowanie(CSkrzyzowanie* S)
{
	skrzyzowania.push_back(S);
}

/// @brief Dodaje now¹ drogê do mapy
void CMapa::dodajDroge(CDroga* D)
{
	drogi.push_back(D);
}

/// @brief Dodaje nowy pojazd do mapy
void CMapa::dodajPojazd(CPojazd* p)
{
	pojazdy.push_back(p);
}

/// @brief Dodaje obserwatora
/// @param obs Obserwator 
void CMapa::attach(CObserwator* obs)
{
	obserwator.push_back(obs);
}

	/// @brief Usuwa obserwatora
	/// @param obs Obserwator 
void CMapa::detach(CObserwator*)
{

}


/// @brief Powiadamia obserwatorów
void CMapa::notify()
{
	for (int i = 0; i < obserwator.size(); i++)
	{
		obserwator[i]->update(1);
	}
}


