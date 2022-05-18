#include "CDroga.h"
#include <cmath>
#include "iostream"

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

int CDroga::getID()
{
	return ID;
}
double CDroga::getDlugosc()
{
	return dlugosc;
}


double CDroga::getKat()
{
	return kat;
}

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

double CDroga::getSinus()
{
	return sinus;
}

double CDroga::getCosinus()
{
	return cosinus;
}

int CDroga::getSzerokosc()
{
	return szerokosc;
}

int CDroga::getIdSk(int i)
{
	return id_Sk[i];
}
