#include "CZarzadzaniePojazdami.h"

/// @file CZarzadzaniePojazdami.cpp
/// @brief Plik Ÿród³owy klasy CZarzadzaniePojazdami


/// @brief Konstruktor klasy CZarzadzaniePojazdami
/// @param m 
/// @param ile 
CZarzadzaniePojazdami::CZarzadzaniePojazdami(CMapa* m, int ile)
{
	mapa = m;
	ilePojazdow = ile;

	this->utworzPojazdy();
}

/// @brief Tworzenie zadanej liczby pojazdów
void CZarzadzaniePojazdami::utworzPojazdy()
{
	srand(time(NULL));
	for (int i = 0; i < ilePojazdow; i++)
	{
		dodajPojazd();
	}
	notify();
}

/// @brief Tworzenie nowego pojazdu
void CZarzadzaniePojazdami::dodajPojazd()
{
	int a;
	int b;
	int k;
	int losowanie;
	bool czyUprzywilejowany = false;
	bool ok = true;
	CPojazd* p;
	do
	{
		ok = true;
		a = rand() % mapa->getDrogi().size();
		b = rand() % (int(mapa->getDrogi()[a]->getDlugosc()) - 60) + 30;
		k = rand() % 2;
		losowanie = rand() % 100;
		if (losowanie < 10)
		{
			czyUprzywilejowany = true;
		}

		for (int i = 0; i < mapa->getDrogi()[a]->getPojazdy(k).size(); i++)
		{
			if (mapa->getPojazdy()[mapa->getDrogi()[a]->getPojazdy(k)[i]]->getOdleglosc() > b - 15 && mapa->getPojazdy()[mapa->getDrogi()[a]->getPojazdy(k)[i]]->getOdleglosc() < b + 15)
			{
				ok = false;
			}
		}
	} while (!ok);


	if (czyUprzywilejowany)
	{
		p = new CUprzywilejowany(mapa->getPojazdy().size(), mapa->getSkrzyzowania(), mapa->getDrogi()[a], b, k);
	}
	else
	{
		p = new COsobowy(mapa->getPojazdy().size(), mapa->getSkrzyzowania(), mapa->getDrogi()[a], b, k);
	}
	
	mapa->dodajPojazd(p);
}

/// @brief Dodanie obserwatora
/// @param obs Obserwator
void CZarzadzaniePojazdami::attach(CObserwator* obs)
{
	obserwatorzy.push_back(obs);
	notify();
}

/// @brief Usuniêcie obserwatora
/// @param obs Obserwator
void CZarzadzaniePojazdami::detach(CObserwator*)
{

}

/// @brief Powiadamia obserwatorów
void CZarzadzaniePojazdami::notify()
{
	for (int i = 0; i < obserwatorzy.size(); i++)
	{
		obserwatorzy[i]->update(0);
	}
}