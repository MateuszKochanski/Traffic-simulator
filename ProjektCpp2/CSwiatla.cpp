#include "CSwiatla.h"

CSwiatla::CSwiatla(int sq, int czZ, int czCZ)
{
	seq = sq;
	czasZielone = czZ;
	czasCzerwone = czCZ;
	zegar = 0;
}



void CSwiatla::odswierz(double czestotliwosc)
{

	zegar += (1 / czestotliwosc);
	int help = licznik;

	if (licznik == 0 && zegar >= czasZielone - 1)
	{
		licznik = 1;
		zegar = 0;
	}
	else if (licznik == 1 && zegar >= 0.5)
	{
		licznik = 2;
		zegar = 0;
	}
	else if (licznik == 2 && zegar >= czasCzerwone)
	{
		licznik = 3;
		zegar = 0;
	}
	else if (licznik == 3 && zegar >= 0.5)
	{
		licznik = 0;
		zegar = 0;
	}

	if (help != licznik)
	{
		if (licznik == 0)
		{
			kolor = 1;
		}
		else if (licznik == 1 || licznik == 3)
		{
			kolor = 2;
		}
		else if (licznik == 2 )
		{
			kolor = 3;
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
		licznik = 3;
	}
	else
	{
		kolor = 3;
		licznik = 2;
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