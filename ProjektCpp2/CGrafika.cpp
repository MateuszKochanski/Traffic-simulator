#include "CGrafika.h"

///@file CGrafika.cpp
///@brief Plik �r�d�owy klasy CGrafika


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


/// @brief Dodaje now� grafik� pojazdu
void CGrafika::dodajGrPojazdu(CPojazdGrafika* P)
{
	grPojazdy.push_back(P);
}

/// @brief Dodaje now� grafik� pojazdu
void CGrafika::dodajGrDrogi(CDrogaGrafika* D)
{
	grDrogi.push_back(D);
}

/// @brief Dodaje now� grafik� pojazdu
void CGrafika::dodajGrSkrzyzowania(CSkrzyzowanieGrafika* S)
{
	grSkrzyzowania.push_back(S);
}

/// @brief Dodaje now� grafik� pojazdu
void CGrafika::dodajGrSwiatla(CSwiatlaGrafika* Sw)
{
	grSwiatla.push_back(Sw);
}

/// @brief Dodaje now� grafik� pojazdu
void CGrafika::dodajGrZnaku(CZnakGrafika *Z)
{
	grZnaki.push_back(Z);
}
/// @brief Zwraca grafiki pojazd�w
/// @return Grafiki pojazd�w
vector<CDrogaGrafika*> CGrafika::getGrDrogi()
{
	return grDrogi;
}

/// @brief Zwraca grafiki skrzy�owa�
/// @return Grafiki skrzy�owa�
vector<CSkrzyzowanieGrafika*> CGrafika::getGrSkrzyzowania()
{
	return grSkrzyzowania;
}

/// @brief Zwraca grafiki znak�w
/// @return Grafiki znak�w
vector<CZnakGrafika*> CGrafika::getGrZnaki()
{
	return grZnaki;
}

/// @brief Zwraca grafiki �wiate�
/// @return Grafiki �wiate�
vector<CSwiatlaGrafika*> CGrafika::getGrSwiatla()
{
	return grSwiatla;
}

/// @brief Zwraca grafiki pojazd�w
/// @return Grafiki pojazd�w
vector<CPojazdGrafika*> CGrafika::getGrPojazdy()
{
	return grPojazdy;
}

