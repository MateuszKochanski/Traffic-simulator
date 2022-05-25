#include "CSwiatla.h"
#include <iostream>


/// @file CSwiatla.cpp
/// @brief Plik Ÿród³owy klasy CSwiatla

/// @brief Konstruktor klasy CSwiatla
/// @param sq Numer zbioru zsynchronizowanych œwiate³ do którego nale¿y sygnalizacja
/// @param czZ Czas œwiecenia œwiat³a zielonego
/// @param czCZ Czas œwiecenia œwiat³a czerwonego
CSwiatla::CSwiatla(int sq, int czZ, int czCZ)
{
	seq = sq;
	czasZielone = czZ;
	czasCzerwone = czCZ;
	zegar = 0;
}

/// @brief Aktualizuje stan œwiat³a
/// @param czestotliwosc Czêstotliwoœæ aktualizacji stanu œwiat³a
void CSwiatla::odswiez(double czestotliwosc)
{
	float zwZegara = (1.0 / czestotliwosc) * 100;
	zegar += zwZegara;
	int hStan = stan;
	
	if (stan == 0 && zegar >= (czasZielone - 1) * 100)
	{
		stan = 1;
		zegar = 0;
	}
	else if (stan == 1 && zegar >= 50)
	{
		stan = 2;
		zegar = 0;
	}
	else if (stan == 2 && zegar >= czasCzerwone * 100)
	{
		stan = 3;
		zegar = 0;
	}
	else if (stan == 3 && zegar >= 50)
	{
		stan = 0;
		zegar = 0;
	}

	if (hStan!= stan)
	{
		if (stan == 0)
		{
			kolor = 1;//zielony
		}
		else if (stan == 1 || stan == 3)
		{
			kolor = 2;//¿ólty
		}
		else if (stan == 2 )
		{
			kolor = 3;//czerwony
		}
		notify();
	}
}

/// @brief Zwraca Kolor aktualnie œwiec¹cego siê œwiat³a
/// @return Kolor aktualnego œwiat³a
int CSwiatla::getKolor()
{
	return kolor;
}

/// @brief Zwiêkszenie czasu œwiecenia czerwonego œwiat³a
/// @param czas Wartoœæ o jak¹ zwiêksza siê czas œwiecenia czerwonego œwiat³a
void CSwiatla::zwiekszCzasOczekiwania(int czas)
{
	czasCzerwone += czas;
}

/// @brief Ustawienie parametrów pocz¹tkowych sygnalizacji
/// @param sq Numer zbioru zsynchronizowanych œwiate³ do którego nale¿y sygnalizacja
/// @param czZ Czas trwania œwiat³a czerwonego
void CSwiatla::setParametry(int sq, int czZ)
{
	
	if (sq == 1)
	{
		kolor = 2;
		stan = 3;
	}
	else
	{
		kolor = 3;
		stan = 2;
	}
	seq = sq;
	czasZielone = czZ;
}


/// @brief Dodaje obserwatora do tablicy obserwatorów
/// @param obs Obserwator
void CSwiatla::attach(CObserwator* obs)
{
	obserwatorzy.push_back(obs);
}


/// @brief Usuwa obserwatora z tablicy obserwatorów
/// @param obs Obserwator
void CSwiatla::detach(CObserwator*)
{
}

/// @brief Powiadamia obserwatorów
void CSwiatla::notify()
{
	for (int i = 0; i < obserwatorzy.size(); i++)
	{
		obserwatorzy[i]->update(kolor);
	}
}