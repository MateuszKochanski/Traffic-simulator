#include "CPojazd.h"

/// @file CPojazd.cpp
/// @brief Plik �r�dowy klasy CPojazd

/// @brief Zwraca numer ID pojazdu
/// @return Numer ID pojazdu
int CPojazd::getID()
{
	return ID;
}

/// @brief Zwraca wsp�rz�dn� X pojazdu
/// @return Wsp�rz�dna X pojazdu
int CPojazd::getX()
{
	return x;
}

/// @brief Zwraca wsp�rz�dn� Y pojazdu
/// @return Wsp�rz�dna Y pojazdu
int CPojazd::getY()
{
	return y;
}
/// @brief Zwraca numer ID drogi po kt�rej jedzie pojazd
/// @return Numer ID drogi
int CPojazd::getIDDrogi()
{
	return idDrogi;
}

/// @brief Zwraca odleg�o�� pojazdu od pocz�tku drogi
/// @return Odleg�o�� pojazdu
int CPojazd::getOdleglosc()
{
	return odleglosc;
}

/// @brief Zwraca k�t pojazdu
/// @return K�t pojazdu
double CPojazd::getKat()
{
	return kat;
}

/// @brief Od�wierza pozycje pojazdu
/// @param drogi Tablica dr�g
/// @param skrzyzowania Tablica skrzy�owa�
/// @param pojazdy Tablica pojazd�w
/// @param czestotliwosc Cz�stotliwo�� od�wie�ania pozycji pojazdu
void CPojazd::odswiez(vector<CDroga*> drogi, vector<CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc)
{
	if (kierunek == 0)
		nieKierunek = 1;
	else
		nieKierunek = 0;
	
	if (!jestNastDroga)
	{
		do
		{
			idNastDrogi = skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[rand() % skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size()];
		} while (idNastDrogi == idDrogi && skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() != 1);
		jestNastDroga = true;
		odswiezKolejnoscDrog(drogi, skrzyzowania);
	}


	if (odleglosc < drogi[idDrogi]->getDlugosc())
	{
		
		if (sprawdzCzyMogeJechac(drogi, skrzyzowania, pojazdy, czestotliwosc))
		{
			odleglosc += predkosc / czestotliwosc;
			if (trybSkretu)
			{
				odlSkretu += predkosc / czestotliwosc;
			}
		}

		if (!czyGotowyDoSkretu )
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
				odlegloscRozpoczeciaSkretu = (promien - 5.0) / tan(((360.0 - katNastDrogi) * (3.1416 / 180.0)) / 2.0);
				sx = double(skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getX()) + cos(katPoczatkowy * (3.1416 / 180.0)) * (drogi[idDrogi]->getDlugosc() - odlegloscRozpoczeciaSkretu) - sin(katPoczatkowy * (3.1416 / 180.0)) * (promien - 5.0);
				sy = double(skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getY()) + sin(katPoczatkowy * (3.1416 / 180.0)) * (drogi[idDrogi]->getDlugosc() - odlegloscRozpoczeciaSkretu) + cos(katPoczatkowy * (3.1416 / 180.0)) * (promien - 5.0);
				
			}
			else
			{
				kierunekSkretu = 0;
				odlegloscRozpoczeciaSkretu = (promien + 5.0) / tan((katNastDrogi / 2.0) * (3.1416 / 180.0));
				sx = double(skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getX()) + cos(katPoczatkowy * (3.1416 / 180.0)) * (drogi[idDrogi]->getDlugosc() - odlegloscRozpoczeciaSkretu) + sin(katPoczatkowy * (3.1416 / 180.0)) * (promien + 5.0);
				sy = double(skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getY()) + sin(katPoczatkowy * (3.1416 / 180.0)) * (drogi[idDrogi]->getDlugosc() - odlegloscRozpoczeciaSkretu) - cos(katPoczatkowy * (3.1416 / 180.0)) * (promien + 5.0);
			}
			odlSkretu = 0;
			czyGotowyDoSkretu = 1;
			
		}

		if (odleglosc > drogi[idDrogi]->getDlugosc() - odlegloscRozpoczeciaSkretu && czyGotowyDoSkretu )
		{
			trybSkretu = true;
		}
		if (wlasnieZmienionoDroge && katNastDrogi > 178 && katNastDrogi < 182)
		{
			trybSkretu = false;
			czyGotowyDoSkretu = false;
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

			drogi[idDrogi]->dodajPojazd(ID, kierunek);
		}
		jestNastDroga = false;
		wlasnieZmienionoDroge = true;
		licznikCzekania = 0;
		
	}

	notify();
}

/// @brief Zwraca promie� skr�tu pojazdu
/// @return Promie� skr�tu
double CPojazd::getPromien()
{
	return promien;
}

/// @brief Zwraca kierunek skr�tu pojazdu
/// @return Kierunek skr�tu
bool CPojazd::getKierunekSkretu()
{
	return kierunekSkretu;
}

/// @brief Zwraca wsp�rz�dn� X �rodka obrotu grafiki przy skr�cie
/// @return Wsp�rz�dna X �rodka obrotu
double CPojazd::getSx()
{
	return sx;
}

/// @brief Zwraca wsp�rz�dn� Y �rodka obrotu grafiki przy skr�cie
/// @return Wsp�rz�dna Y �rodka obrotu
double CPojazd::getSy()
{
	return sy;
}

/// @brief Ponownie wyznacza tablice "kolejnoscDrog" i "katy"
/// @param drogi Tablica dr�g
/// @param skrzy�owania Tablica skrzy�owa�
void CPojazd::odswiezKolejnoscDrog(vector<CDroga*> drogi, vector<CSkrzyzowanie*> skrzyzowania)
{
	delete[] kolejnoscDrog;
	delete[] katy;
	kolejnoscDrog = new int[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size()];
	katy = new double[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size()];

	double hKat;
	for (int i = 0; i < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); i++)
	{
		if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i]]->getIdSk(0))
			hKat = drogi[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i]]->getKat();
		else
			hKat = drogi[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i]]->getKat() + 180;

		if (kierunek == 0)
		{
			katy[i] = drogi[idDrogi]->getKat() + 180;
			
		}
		else
		{
			katy[i] = drogi[idDrogi]->getKat();
		}

		//katy[i] = kat + 180;//daje k�t wzgl�dem danej drogi 0 360 stopni
		while (katy[i] >= 360)
			katy[i] -= 360.0;
		katy[i] = hKat + 360 - katy[i];
		while (katy[i] >= 360)
			katy[i] -= 360.0;

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
}

/// @brief Zwraca k�t nast�pnej drogi
/// @return K�t nast�pnej drogi
double CPojazd::getKatNastDrogi()
{
	return katNastDrogi;
}

/// @brief Zwraca czy dany dany pojazd jest uprzywilejowany
/// @return Czy pojazd jest uprzywilejowany
bool CPojazd::getCzyUprzywilejowany()
{
	return czyUprzywilejowany;
}

/// @brief Dodaje obserwatora do tablicy obserwator�w
/// @param obs Obserwator
void CPojazd::attach(CObserwator* obs)
{
	obserwatorzy.push_back(obs);
}

/// @brief Usuwa obserwatora z tablicy obserwator�w
/// @param obs Obserwator
void CPojazd::detach(CObserwator* obs)
{

}

/// @brief Powiadamia obserwator�w
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