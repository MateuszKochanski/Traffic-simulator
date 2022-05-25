#include "CUprzywilejowany.h"

/// @file CUprzywilejowany.cpp
/// @brief Plik �r�d�owy klasy CUprzywilejowany

/// @brief Konstruktor klasy CUprzywilejowany
/// @param id Numer ID nowo tworzonego pojazdu
/// @param skrzyzowania Tablica skrzy�owa�
/// @param droga Tablica dr�g
/// @param odl Odleg�o�� pojazdu od pocz�tku drogi
/// @param kier Kierunek poruszania si� pojazdu po drodze 
CUprzywilejowany::CUprzywilejowany(int id, vector<CSkrzyzowanie*> skrzyzowania, CDroga* droga, int odl, int kier)
{
	ID = id;
	odleglosc = odl;
	kierunek = kier;
	idDrogi = droga->getID();
	droga->dodajPojazd(ID, kierunek);

	predkosc = 50;

	if (kierunek == 0)
	{
		x = skrzyzowania[droga->getIdSk(kierunek)]->getX() + droga->getCosinus() * odleglosc - droga->getSinus() * 5.0;
		y = skrzyzowania[droga->getIdSk(kierunek)]->getY() + droga->getSinus() * odleglosc + droga->getCosinus() * 5.0;
		kat = droga->getKat();
	}
	else
	{
		x = skrzyzowania[droga->getIdSk(kierunek)]->getX() - droga->getCosinus() * odleglosc + droga->getSinus() * 5.0;
		y = skrzyzowania[droga->getIdSk(kierunek)]->getY() - droga->getSinus() * odleglosc - droga->getCosinus() * 5.0;
		kat = droga->getKat() + 180.0;
	}
	trybSkretu = false;
	czyGotowyDoSkretu = false;
	jestNastDroga = false;
	promien = 10;
	odlSkretu = 0;
	wlasnieZmienionoDroge = false;
	czyUprzywilejowany = true;
}

/// @brief Destruktor klasy CUprzywilejowany
CUprzywilejowany::~CUprzywilejowany()
{
	delete[] katy;
	delete[] kolejnoscDrog;
}

/// @brief Sprawdza czy pojazd mo�e si� dalej porusza�
/// @param drogi Tablica dr�g
/// @param skrzyzowania Tablica Skrzy�owa� 
/// @param pojazdy Tablica pojazd�w
/// @param czestotliwosc Cz�stotlio�� od�wie�ania pozycji pojazdu
/// @return Czy pojazd mo�e si� porusza�
bool CUprzywilejowany::sprawdzCzyMogeJechac(vector<CDroga*> drogi, vector<CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc)
{

	bool czyMogeJechac = true;

	if (drogi[idDrogi]->getPojazdy(kierunek).size() != 1)///////////////////////////samochod przed tob�
	{
		for (int j = 0; j < drogi[idDrogi]->getPojazdy(kierunek).size(); j++)
		{
			if (pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getID() != ID && pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getOdleglosc() < odleglosc + 25 && pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getOdleglosc() > odleglosc)
			{
				czyMogeJechac = false;
			}
		}
	}


	if (odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)////////////////////////////////////////////////////czy nie ma samochodu w�a�nie zje�dzaj�cego ze skrzyzowania
	{
		int i = 0;
		while (kolejnoscDrog[i] != idNastDrogi)
		{
			i++;
		}

		if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > i)
		{
			for (int j = i; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); j++)
			{
				if (idDrogi != kolejnoscDrog[j])
				{
					if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[kolejnoscDrog[j]]->getIdSk(0))
					{
						for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(0).size(); k++)
						{
							if (kolejnoscDrog[j] == idNastDrogi)
							{
								if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 40)
								{
									czyMogeJechac = false;
								}
							}
							else
							{
								if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 25)
								{
									czyMogeJechac = false;
								}
							}

						}
					}
					else
					{
						for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(1).size(); k++)
						{
							if (kolejnoscDrog[j] == idNastDrogi)
							{
								if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 40)
								{
									czyMogeJechac = false;
								}
							}
							else
							{
								if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 25)
								{
									czyMogeJechac = false;
								}
							}

						}
					}
				}
			}
		}
	}

	if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() != ID && skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() != -1 && odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)
	{
		czyMogeJechac = false;
	}
	else if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() == -1 && odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)
	{
		skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->setBufor(ID);
	}

	if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() == ID && !czyMogeJechac)
	{
		skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->setBufor(-1);
	}

	if (skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getBufor() == ID && odleglosc > 30)
	{
		skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->setBufor(-1);
	}

	return czyMogeJechac;
}
