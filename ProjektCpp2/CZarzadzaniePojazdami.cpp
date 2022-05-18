#include "CZarzadzaniePojazdami.h"

CZarzadzaniePojazdami::CZarzadzaniePojazdami(CMapa* m, int ile)
{
	mapa = m;
	ilePojazdow = ile;

	this->utworzPojazdy();
}

void CZarzadzaniePojazdami::utworzPojazdy()
{
	srand(time(NULL));
	for (int i = 0; i < ilePojazdow; i++)
	{
		dodajPojazd();
	}
	notify();
}

void CZarzadzaniePojazdami::odswierz()
{

}

void CZarzadzaniePojazdami::dodajPojazd()
{
	int a;
	int b;
	int k;
	bool ok = true;
	do
	{
		ok = true;
		a = rand() % mapa->getDrogi().size();
		b = rand() % (int(mapa->getDrogi()[a]->getDlugosc()) - 60) + 30;
		k = rand() % 2;

		for (int i = 0; i < mapa->getDrogi()[a]->getPojazdy(k).size(); i++)
		{
			if (mapa->getPojazdy()[mapa->getDrogi()[a]->getPojazdy(k)[i]]->getOdleglosc() > b - 15 && mapa->getPojazdy()[mapa->getDrogi()[a]->getPojazdy(k)[i]]->getOdleglosc() < b + 15)
			{
				ok = false;
			}
		}
	} while (!ok);
	mapa->dodajPojazd(mapa->getDrogi()[a], b, k);
}

void CZarzadzaniePojazdami::attach(CObserwator* obs)
{
	obserwatorzy.push_back(obs);
	notify();
}

void CZarzadzaniePojazdami::detach(CObserwator*)
{

}

void CZarzadzaniePojazdami::notify()
{
	for (int i = 0; i < obserwatorzy.size(); i++)
	{
		obserwatorzy[i]->update(0);
	}
}