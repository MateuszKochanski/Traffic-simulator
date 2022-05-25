#include "CDroga.h"
#include <cmath>
#include "iostream"

/// @file CDroga.cpp
/// @brief Plik Ÿród³owy klasy CDroga

/// @brief Konstruktor klasy CDroga
/// @param id Numer ID drogi
/// @param s1 Numer id 1 skrzyzowania
/// @param s2 Numer id 2 skrzyzowania
/// @param dl D³ugoœæ drogi
/// @param s Sinus k¹ta drogi
/// @param c Cosinus k¹ta drogi
CDroga::CDroga(int id, int s1, int s2, double dl, double s, double c)
{
	ID = id;
	id_Sk[0] = s1;
	id_Sk[1] = s2;
	dlugosc = dl;
	
	sinus = s;
	cosinus = c;

	if (sinus >= 0 && cosinus >= 0)
		kat = asin(sinus) * (180.0 / 3.14);
	else if (sinus >= 0 && cosinus < 0)
		kat = 180.0 - asin(sinus) * (180.0 / 3.14);
	else if (sinus < 0 && cosinus >= 0)
		kat = 360 + asin(sinus) * (180.0 / 3.14);
	else
		kat = 180.0 - asin(sinus) * (180.0 / 3.14);
}


/// @brief Zwraca ID drogi
/// @return Numer ID
int CDroga::getID()
{
	return ID;
}
/// @brief Zwraca d³ugoœæ drogi
/// @return D³ugoœæ drogi
double CDroga::getDlugosc()
{
	return dlugosc;
}

/// @brief Zwraca k¹t drogi
/// @return K¹t drogi
double CDroga::getKat()
{
	return kat;
}

/// @brief Dodaje pojazd do tablicy pojazdów
/// @param id Numer ID pojazdu
/// @param kierunek Kierunek w którym porusza siê pojazd
void CDroga::dodajPojazd(int id, int kierunek)
{
	if (kierunek == 0)
	{
		pojazdyK1.push_back(id);
	}
	else if (kierunek == 1)
	{
		pojazdyK2.push_back(id);
	}
}

/// @brief Zwraca tablicê pojazdów poruszaj¹cych siê po danej drodze w danym kierunku
/// @param kierunek Kierunek poruszania siê pojazdu
/// @return Tablica pojazdów
vector<int> CDroga::getPojazdy(int kierunek)
{
	if (kierunek == 0)
	{
		return pojazdyK1;
	}
	else if (kierunek == 1)
	{
		return pojazdyK2;
	}
}

/// @brief Usuwa pojazd z drogi
/// @param id Numer ID pojazdu
/// @param kierunek Kierunek poruszania siê pojazdu
void CDroga::usunPojazd(int id, int kierunek)
{
	vector <int>::iterator it;
	int i = 0;
	if (kierunek == 0)
	{
		while (pojazdyK1[i] != id && i < pojazdyK1.size())
			i++;
		if (pojazdyK1[i] == id)
		{
			it = pojazdyK1.begin() + i;
			pojazdyK1.erase(it);
		}
	}
	else
	{
		while (pojazdyK2[i] != id && i < pojazdyK2.size())
			i++;
		if (pojazdyK2[i] == id)
		{
			it = pojazdyK2.begin() + i;
			pojazdyK2.erase(it);
		}
	}
}

/// @brief Zwraca wartoœæ sinusa k¹ta drogi
/// @return Sinus k¹ta drogi
double CDroga::getSinus()
{
	return sinus;
}

/// @brief Zwraca wartoœæ cosinusa k¹ta drogi
/// @return Cosinus k¹ta drogi
double CDroga::getCosinus()
{
	return cosinus;
}

/// @brief Zwraca numer ID jednego ze skrzy¿owañ, które ³¹czy droga
/// @param i Numer skrzy¿owania
/// @return Numer ID skrzy¿owania
int CDroga::getIdSk(int i)
{
	return id_Sk[i];
}
