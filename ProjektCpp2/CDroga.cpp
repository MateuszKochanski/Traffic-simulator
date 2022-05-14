#include "CDroga.h"
#include <cmath>

CDroga::CDroga(int id, int s1, int s2, int dl, double s, double c)
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
int CDroga::getDlugosc()
{
	return dlugosc;
}

int CDroga::getIdSk1()
{
	return id_Sk[0];
}

int CDroga::getIdSk2()
{
	return id_Sk[1];
}

float CDroga::getKat()
{
	return kat;
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