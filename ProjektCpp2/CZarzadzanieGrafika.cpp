#include "CZarzadzanieGrafika.h"

/// @file CZarzadzanieGrafika.cpp
/// @brief Plik Ÿród³owy klasy CZarzadzanieGrafika

/// @brief Konstruktor klasy CZarzadzanieGrafika
/// @param gr WskaŸnik do obiektu przechowywuj¹cego wszystkie wyswietlane obiekty graficze
CZarzadzanieGrafika::CZarzadzanieGrafika(CGrafika* gr, CMapa*m)
{
	grafika = gr;
	mapa = m;
}

/// @brief Aktualizuje grafikê
/// @param arg Jeœli 0 to pojazdy jeœli 1 to ca³a mapa
void CZarzadzanieGrafika::update(int arg)
{
	CPojazdGrafika* P;
	if (arg == 0)
	{
		for (int i = 0; i < mapa->getPojazdy().size(); i++)
		{
			P = new CPojazdGrafika(mapa->getPojazdy()[i]);
			grafika->dodajGrPojazdu(P);
		}
	}	
	else
	{
		int x;
		int y;
		int dl;
		double kat;
		bool czyRondo;

		double sinus;
		double cosinus;

		CSkrzyzowanieGrafika* S;
		CDrogaGrafika* D;
		CZnakGrafika* Z;
		CSwiatlaGrafika* Sw;

		for (int i = 0; i < mapa->getSkrzyzowania().size(); i++)
		{
			czyRondo = false;
			for (int j = 0; j < mapa->getSkrzyzowania()[i]->getZnaki().size(); j++)
			{
				for (int k = 0; k < mapa->getSkrzyzowania()[i]->getZnaki()[j].size(); k++)
				{
					sinus = mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getSinus();
					cosinus = mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getCosinus();

					if (mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getIdSk(0) == mapa->getSkrzyzowania()[i]->getID())//jeœli to 1 skrzyzowanie danej drogi
					{
						x = mapa->getSkrzyzowania()[i]->getX() + cosinus * (50 + k * 15) + sinus * 20;
						y = mapa->getSkrzyzowania()[i]->getY() + sinus * (50 + k * 15) - cosinus * 20;
						kat = mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getKat();
					}
					else if (mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getIdSk(1) == mapa->getSkrzyzowania()[i]->getID())//jeœli to 2 skrzyzowanie danej drogi
					{
						x = mapa->getSkrzyzowania()[i]->getX() - cosinus * (50 + k * 15) - sinus * 20;
						y = mapa->getSkrzyzowania()[i]->getY() - sinus * (50 + k * 15) + cosinus * 20;
						kat = mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getKat() + 180;
					}
					Z = new CZnakGrafika(x, y, kat, mapa->getSkrzyzowania()[i]->getZnaki()[j][k]->getTyp());
					grafika->dodajGrZnaku(Z);

					if (mapa->getSkrzyzowania()[i]->getZnaki()[j][k]->getTyp() == 'R')
					{
						czyRondo = true;
					}
				}
			}

			for (int j = 0; j < mapa->getSkrzyzowania()[i]->getSwiatla().size(); j++)
			{
				sinus = mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getSinus();
				cosinus = mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getCosinus();
				if (mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getIdSk(0) == mapa->getSkrzyzowania()[i]->getID())//jeœli to 1 skrzyzowanie danej drogi
				{
					x = mapa->getSkrzyzowania()[i]->getX() + cosinus * (50) + sinus * 20;
					y = mapa->getSkrzyzowania()[i]->getY() + sinus * (50) - cosinus * 20;
					kat = mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getKat();
					Sw = new CSwiatlaGrafika(x, y, kat, mapa->getSkrzyzowania()[i]->getSwiatla()[j]->getKolor(), -sinus, -cosinus);
				}
				else
				{
					x = mapa->getSkrzyzowania()[i]->getX() - cosinus * (50) - sinus * 20;
					y = mapa->getSkrzyzowania()[i]->getY() - sinus * (50) + cosinus * 20;
					kat = mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getKat() + 180;
					Sw = new CSwiatlaGrafika(x, y, kat, mapa->getSkrzyzowania()[i]->getSwiatla()[j]->getKolor(), sinus, cosinus);
				}
				grafika->dodajGrSwiatla(Sw);
				mapa->getSkrzyzowania()[i]->getSwiatla()[j]->attach(Sw);///////////////////////////////?????????????
			}
			S = new CSkrzyzowanieGrafika(mapa->getSkrzyzowania()[i]->getX(), mapa->getSkrzyzowania()[i]->getY(), czyRondo);
			grafika->dodajGrSkrzyzowania(S);
		}
		for (int i = 0; i < mapa->getDrogi().size(); i++)
		{
			x = mapa->getSkrzyzowania()[mapa->getDrogi()[i]->getIdSk(0)]->getX();
			y = mapa->getSkrzyzowania()[mapa->getDrogi()[i]->getIdSk(0)]->getY();
			dl = mapa->getDrogi()[i]->getDlugosc();
			kat = mapa->getDrogi()[i]->getKat();
			D = new CDrogaGrafika(x, y, dl, kat);
			grafika->dodajGrDrogi(D);
		}
	}
}
