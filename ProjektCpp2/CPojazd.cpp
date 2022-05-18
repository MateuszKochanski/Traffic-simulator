#include "CPojazd.h"

CPojazd::CPojazd(int id, vector <CSkrzyzowanie*> skrzyzowania, CDroga* droga, int odl, int kier)
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
}

int CPojazd::getID()
{
	return ID;
}

int CPojazd::getX()
{
	return x;
}

int CPojazd::getY()
{
	return y;
}

int CPojazd::getIDDrogi()
{
	return idDrogi;
}

int CPojazd::getOdleglosc()
{
	return odleglosc;
}

double CPojazd::getKat()
{
	return kat;
}

void CPojazd::odswierz(vector<CDroga*> drogi, vector<CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc)
{
	if (kierunek == 0)
		nieKierunek = 1;
	else
		nieKierunek = 0;
	bool czyMogeJechac = true;



	if (!jestNastDroga)
	{
		do
		{
			idNastDrogi = skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[rand() % skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size()];
		} while (idNastDrogi == idDrogi && skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() != 1);
		jestNastDroga = true;
		odswierzKolejnoscDrog(drogi, skrzyzowania);
	}


	if (odleglosc < drogi[idDrogi]->getDlugosc())
	{

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





		if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getSwiatla().size() != 0 && odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)/////////////////////œwiatla
		{
			int i = 0;
			while (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i] != idDrogi)
			{
				i++;
			}
			if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getSwiatla()[i]->getKolor() != 1)
				czyMogeJechac = false;
			/*else
			{
				int i = 0;
				while (kolejnoscDrog[i] != idNastDrogi)
				{
					i++;
				}
				i++;
				if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > i)
				{
					for (int j = i; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); j++)
					{
						int l = 0;
						while (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[l] != kolejnoscDrog[j])
						{
							l++;
						}
						if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getSwiatla()[l]->getKolor() == 1)
						{
							if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[kolejnoscDrog[j]]->getIdSk(0))
							{

								for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(1).size(); k++)
								{
									if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 30)
									{
										czyMogeJechac = false;
									}
								}
							}
						
							else
							{
								for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(0).size(); k++)
								{
									if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 30)
									{
										czyMogeJechac = false;
									}
								}
							}
						}
					}
				}
			}*/
		}
		else if (odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20 && skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > 2)/////////////////////ZPR
		{
			int i = 0;
			while (kolejnoscDrog[i] != idNastDrogi)
			{
				i++;
			}
			i++;
			if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > i)
			{
				for (int j = i; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); j++)
				{
					if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[kolejnoscDrog[j]]->getIdSk(0))
					{
						for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(1).size(); k++)
						{
							if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 30)
							{
								czyMogeJechac = false;
							}
						}
					}
					else
					{
						for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(0).size(); k++)
						{
							if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 30)
							{
								czyMogeJechac = false;
							}
						}
					}
				}	
			}

			
		}
		
		if (czyMogeJechac)
		{
			odleglosc += predkosc / czestotliwosc;
			if (trybSkretu)
			{
				odlSkretu += predkosc / czestotliwosc;
			}
		}

		if (!czyGotowyDoSkretu)
		{
			katPoczatkowy = kat;
			int i = 0;
			while (kolejnoscDrog[i] != idNastDrogi)
			{
				i++;
			}
			katNastDrogi = katy[i];

			if (katNastDrogi > 180)
			{
				kierunekSkretu = 1;
				odlegloscRozpoczeciaSkretu = promien / tan(((360.0 - double(katNastDrogi)) * (3.14 / 180.0)) / 2.0);
			}
			else
			{
				kierunekSkretu = 0;
				odlegloscRozpoczeciaSkretu = (promien + 10.0) / tan((double(katNastDrogi) / 2.0) * (3.14 / 180.0));
			}
			cout << "//////////" << katNastDrogi  << "  " << odlegloscRozpoczeciaSkretu << endl;
			odlSkretu = 0;
			czyGotowyDoSkretu = 1;
		}

		if (odleglosc > drogi[idDrogi]->getDlugosc() - odlegloscRozpoczeciaSkretu  &&  czyGotowyDoSkretu || wlasnieZmienionoDroge)
		{
			trybSkretu = true;
		}	


		
		if (odlSkretu > 2.0 * odlegloscRozpoczeciaSkretu)
		{
			trybSkretu = false;
			czyGotowyDoSkretu = false;
			if (kierunek == 0)
			{
				kat = drogi[idDrogi]->getKat();
			}
			else
			{
				kat = drogi[idDrogi]->getKat() + 180.0;
			}
		}



		if (trybSkretu)
		{
			kat = katPoczatkowy - ((180.0 - katNastDrogi) * odlSkretu) / (2.0 * odlegloscRozpoczeciaSkretu);
			cout << "aaaaa" << odlSkretu << endl;
			
		}
		else
		{
			if (kierunek == 0)
			{
				x = skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getX() + drogi[idDrogi]->getCosinus() * odleglosc - drogi[idDrogi]->getSinus() * 5.0;
				y = skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getY() + drogi[idDrogi]->getSinus() * odleglosc + drogi[idDrogi]->getCosinus() * 5.0;
			}
			else
			{
				x = skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getX() - drogi[idDrogi]->getCosinus() * odleglosc + drogi[idDrogi]->getSinus() * 5.0;
				y = skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getY() - drogi[idDrogi]->getSinus() * odleglosc - drogi[idDrogi]->getCosinus() * 5.0;
			}
		}
		wlasnieZmienionoDroge = false;
	}
	else
	{

		if (jestNastDroga)
		{

			odleglosc = 0;
			drogi[idDrogi]->usunPojazd(ID, kierunek);

			if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[idNastDrogi]->getIdSk(0))
				kierunek = 0;
			else
				kierunek = 1;

			idDrogi = idNastDrogi;

			if (kierunek == 0)
			{
				kat = drogi[idDrogi]->getKat();
			}
			else
			{
				kat = drogi[idDrogi]->getKat() + 180.0;
			}
			drogi[idDrogi]->dodajPojazd(ID, kierunek);
		}
		jestNastDroga = false;
		wlasnieZmienionoDroge = true;
	}

	notify();
}

double CPojazd::getPromien()
{
	return promien;
}

bool CPojazd::getKierunekSkretu()
{
	return kierunekSkretu;
}

void CPojazd::odswierzKolejnoscDrog(vector<CDroga*> drogi, vector<CSkrzyzowanie*> skrzyzowania)
{
	delete[] kolejnoscDrog;
	delete[] katy;
	kolejnoscDrog = new int[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size()];
	katy = new int[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size()];

	int hKat;
	for (int i = 0; i < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); i++)
	{
		if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i]]->getIdSk(0))
			hKat = drogi[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i]]->getKat();
		else
			hKat = drogi[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i]]->getKat() + 180;

		katy[i] = (hKat + 360 - (int(kat + 180) % 360)) % 360;//daje k¹t wzglêdem danej drogi 0 360 stopni
		kolejnoscDrog[i] = skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i];
	}
	for (int i = 0; i < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); i++)//sortowanie babelkowe
	{
		for (int j = 0; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() - 1; j++)
		{
			if (katy[j] > katy[j + 1])
			{
				swap(katy[j], katy[j + 1]);
				swap(kolejnoscDrog[j], kolejnoscDrog[j + 1]);
			}
		}
	}
	cout << "--------------"<< endl;
	for (int j = 0; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); j++)///wyswietlenie
	{
		cout << kolejnoscDrog[j]<<"  "<<katy[j] << endl;
	}
}

void CPojazd::attach(CObserwator* obs)
{
	obserwatorzy.push_back(obs);
}

void CPojazd::detach(CObserwator*)
{

}

void CPojazd::notify()
{
	for (int i = 0; i < obserwatorzy.size(); i++)
	{
		if (trybSkretu)
		{
			obserwatorzy[i]->update(1);
		}
		else
		{
			obserwatorzy[i]->update(0);
		}	
	}
}