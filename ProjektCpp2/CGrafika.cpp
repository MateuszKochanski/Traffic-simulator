#include "CGrafika.h"


CGrafika::CGrafika(sf::RenderWindow* w, CMapa* m)
{
	window = w;
	mapa = m;
	update(0);
}

void CGrafika::update(int arg)
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
				Z = new CZnakGrafika(x,y, kat, mapa->getSkrzyzowania()[i]->getZnaki()[j][k]->getTyp());
				grZnaki.push_back(Z);
					
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
			else if (mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getIdSk(1) == mapa->getSkrzyzowania()[i]->getID())//jeœli to 2 skrzyzowanie danej drogi
			{
				x = mapa->getSkrzyzowania()[i]->getX() - cosinus * (50) - sinus * 20;
				y = mapa->getSkrzyzowania()[i]->getY() - sinus * (50) + cosinus * 20;
				kat = mapa->getDrogi()[mapa->getSkrzyzowania()[i]->getIdDrogi()[j]]->getKat() + 180;
				Sw = new CSwiatlaGrafika(x, y, kat, mapa->getSkrzyzowania()[i]->getSwiatla()[j]->getKolor(), sinus, cosinus);
			}
			
			grSwiatla.push_back(Sw);
			
			mapa->getSkrzyzowania()[i]->getSwiatla()[j]->attach(grSwiatla[this->grSwiatla.size() - 1]);
		}
		S = new CSkrzyzowanieGrafika(mapa->getSkrzyzowania()[i]->getX(), mapa->getSkrzyzowania()[i]->getY(), czyRondo);
		grSkrzyzowania.push_back(S);
	}
	for (int i = 0; i < mapa->getDrogi().size(); i++)
	{
		x = mapa->getSkrzyzowania()[mapa->getDrogi()[i]->getIdSk(0)]->getX();
		y = mapa->getSkrzyzowania()[mapa->getDrogi()[i]->getIdSk(0)]->getY();
		dl = mapa->getDrogi()[i]->getDlugosc();
		kat = mapa->getDrogi()[i]->getKat();
		D = new CDrogaGrafika(x,y,dl,kat);
		grDrogi.push_back(D);
	}
}


CMapa* CGrafika::getMapa()
{
	return mapa;
}

void CGrafika::rysuj()
{
	for (int i = 0; i < grDrogi.size(); i++)
	{
		grDrogi[i]->rysuj(window);
	}
	for (int i = 0; i < grSkrzyzowania.size(); i++)
	{
		grSkrzyzowania[i]->rysuj(window);
	}
	for (int i = 0; i < grZnaki.size(); i++)
	{
		grZnaki[i]->rysuj(window);
	}
	for (int i = 0; i < grSwiatla.size(); i++)
	{
		grSwiatla[i]->rysuj(window);
	}
	for (int i = 0; i < grPojazdy.size(); i++)
	{
		grPojazdy[i]->rysuj(window);
	}
}

void CGrafika::dodajGrPojazdu(CPojazd* pojazd)
{
	CPojazdGrafika* PJG = new CPojazdGrafika(pojazd);
	grPojazdy.push_back(PJG);
	pojazd->attach(grPojazdy[grPojazdy.size() - 1]);
}


