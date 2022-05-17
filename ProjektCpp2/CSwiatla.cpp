#include "CSwiatla.h"
#include <iostream>

CSwiatla::CSwiatla(int sq, int czZ, int czCZ)
{
	seq = sq;
	czasZielone = czZ;
	czasCzerwone = czCZ;
	zegar = 0;
}

void CSwiatla::odswierz(double czestotliwosc)
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

int CSwiatla::getKolor()
{
	return kolor;
}

void CSwiatla::zwiekszCzasOczekiwania(int czas)
{
	czasCzerwone += czas;
}

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



void CSwiatla::attach(CObserwator* obs)
{
	obserwatorzy.push_back(obs);
}

void CSwiatla::detach(CObserwator*)
{
}

void CSwiatla::notify()
{
	for (int i = 0; i < obserwatorzy.size(); i++)
	{
		obserwatorzy[i]->update(kolor);
	}
}