#include "CUprzywilejowany.h"

/// @file CUprzywilejowany.cpp
/// @brief Plik Ÿród³owy klasy CUprzywilejowany

/// @brief Konstruktor klasy CUprzywilejowany
/// @param id Numer ID nowo tworzonego pojazdu
/// @param skrzyzowania Tablica skrzy¿owañ
/// @param droga Tablica dróg
/// @param odl Odleg³oœæ pojazdu od pocz¹tku drogi
/// @param kier Kierunek poruszania siê pojazdu po drodze 
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

/// @brief Sprawdza czy pojazd mo¿e siê dalej poruszaæ
/// @param drogi Tablica dróg
/// @param skrzyzowania Tablica Skrzy¿owañ 
/// @param pojazdy Tablica pojazdów
/// @param czestotliwosc Czêstotlioœæ odœwie¿ania pozycji pojazdu
/// @return Czy pojazd mo¿e siê poruszaæ
bool CUprzywilejowany::sprawdzCzyMogeJechac(vector<CDroga*> drogi, vector<CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc)
{

	bool czyMogeJechac = true;

	if (drogi[idDrogi]->getPojazdy(kierunek).size() != 1)///////////////////////////samochod przed tob¹
	{
		for (int j = 0; j < drogi[idDrogi]->getPojazdy(kierunek).size(); j++)
		{
			if (pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getID() != ID && pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getOdleglosc() < odleglosc + 25 && pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getOdleglosc() > odleglosc)
			{
				czyMogeJechac = false;
			}
		}
	}


	if (odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)////////////////////////////////////////////////////czy nie ma samochodu w³aœnie zje¿dzaj¹cego ze skrzyzowania
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
