#include "CSwiatla.h"
#include <iostream>


/// @file CSwiatla.cpp
/// @brief Plik �r�d�owy klasy CSwiatla

/// @brief Konstruktor klasy CSwiatla
/// @param sq Numer zbioru zsynchronizowanych �wiate� do kt�rego nale�y sygnalizacja
/// @param czZ Czas �wiecenia �wiat�a zielonego
/// @param czCZ Czas �wiecenia �wiat�a czerwonego
CSwiatla::CSwiatla(int sq, int czZ, int czCZ)
{
	seq = sq;
	czasZielone = czZ;
	czasCzerwone = czCZ;
	zegar = 0;
}

/// @brief Aktualizuje stan �wiat�a
/// @param czestotliwosc Cz�stotliwo�� aktualizacji stanu �wiat�a
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
			kolor = 2;//��lty
		}
		else if (stan == 2 )
		{
			kolor = 3;//czerwony
		}
		notify();
	}
}

/// @brief Zwraca Kolor aktualnie �wiec�cego si� �wiat�a
/// @return Kolor aktualnego �wiat�a
int CSwiatla::getKolor()
{
	return kolor;
}

/// @brief Zwi�kszenie czasu �wiecenia czerwonego �wiat�a
/// @param czas Warto�� o jak� zwi�ksza si� czas �wiecenia czerwonego �wiat�a
void CSwiatla::zwiekszCzasOczekiwania(int czas)
{
	czasCzerwone += czas;
}

/// @brief Ustawienie parametr�w pocz�tkowych sygnalizacji
/// @param sq Numer zbioru zsynchronizowanych �wiate� do kt�rego nale�y sygnalizacja
/// @param czZ Czas trwania �wiat�a czerwonego
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


/// @brief Dodaje obserwatora do tablicy obserwator�w
/// @param obs Obserwator
void CSwiatla::attach(CObserwator* obs)
{
	obserwatorzy.push_back(obs);
}


/// @brief Usuwa obserwatora z tablicy obserwator�w
/// @param obs Obserwator
void CSwiatla::detach(CObserwator*)
{
}

/// @brief Powiadamia obserwator�w
void CSwiatla::notify()
{
	for (int i = 0; i < obserwatorzy.size(); i++)
	{
		obserwatorzy[i]->update(kolor);
	}
}