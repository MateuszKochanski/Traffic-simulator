#include "CGrafika.h"

///@file CGrafika.cpp
///@brief Plik Ÿród³owy klasy CGrafika


/// @brief Destruktor klasy CGrafika
CGrafika::~CGrafika()
{
	for (int i = 0; i < grDrogi.size(); i++)
	{
		delete grDrogi[i];
	}
	grDrogi.clear();

	for (int i = 0; i < grSkrzyzowania.size(); i++)
	{
		delete grSkrzyzowania[i];
	}
	grSkrzyzowania.clear();

	for (int i = 0; i < grZnaki.size(); i++)
	{
		delete grZnaki[i];
	}
	grZnaki.clear();

	for (int i = 0; i < grSwiatla.size(); i++)
	{
		delete grSwiatla[i];
	}
	grSwiatla.clear();

	for (int i = 0; i < grPojazdy.size(); i++)
	{
		delete grPojazdy[i];
	}
	grPojazdy.clear();
}


/// @brief Dodaje now¹ grafikê pojazdu
void CGrafika::dodajGrPojazdu(CPojazdGrafika* P)
{
	grPojazdy.push_back(P);
}

/// @brief Dodaje now¹ grafikê pojazdu
void CGrafika::dodajGrDrogi(CDrogaGrafika* D)
{
	grDrogi.push_back(D);
}

/// @brief Dodaje now¹ grafikê pojazdu
void CGrafika::dodajGrSkrzyzowania(CSkrzyzowanieGrafika* S)
{
	grSkrzyzowania.push_back(S);
}

/// @brief Dodaje now¹ grafikê pojazdu
void CGrafika::dodajGrSwiatla(CSwiatlaGrafika* Sw)
{
	grSwiatla.push_back(Sw);
}

/// @brief Dodaje now¹ grafikê pojazdu
void CGrafika::dodajGrZnaku(CZnakGrafika *Z)
{
	grZnaki.push_back(Z);
}
/// @brief Zwraca grafiki pojazdów
/// @return Grafiki pojazdów
vector<CDrogaGrafika*> CGrafika::getGrDrogi()
{
	return grDrogi;
}

/// @brief Zwraca grafiki skrzy¿owañ
/// @return Grafiki skrzy¿owañ
vector<CSkrzyzowanieGrafika*> CGrafika::getGrSkrzyzowania()
{
	return grSkrzyzowania;
}

/// @brief Zwraca grafiki znaków
/// @return Grafiki znaków
vector<CZnakGrafika*> CGrafika::getGrZnaki()
{
	return grZnaki;
}

/// @brief Zwraca grafiki œwiate³
/// @return Grafiki œwiate³
vector<CSwiatlaGrafika*> CGrafika::getGrSwiatla()
{
	return grSwiatla;
}

/// @brief Zwraca grafiki pojazdów
/// @return Grafiki pojazdów
vector<CPojazdGrafika*> CGrafika::getGrPojazdy()
{
	return grPojazdy;
}

