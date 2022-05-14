#include "CMapa.h"
#include<iostream>



using namespace std;

void CMapa::odswierz(double czestotliwosc)
{
	for (int i = 0; i < skrzyzowania.size(); i++)
	{
		for (int j = 0; j < skrzyzowania[i]->getSwiatla().size(); j++)
		{
			skrzyzowania[i]->getSwiatla()[j]->odswierz(czestotliwosc);
		}
	}
}

vector <CDroga*> CMapa::getDrogi()
{
	return drogi;
}

vector <CSkrzyzowanie*> CMapa::getSkrzyzowania()
{
	return skrzyzowania;
}

void CMapa::dodajSkrzyzowanie(int id, int x, int y)
{
	CSkrzyzowanie* S = new CSkrzyzowanie;
	S->set(id, x, y, 0);
	skrzyzowania.push_back(S);
}

void CMapa::dodajDroge(int id, int ns1, int ns2, int dl, double sinus, double cosinus)
{
	CDroga* D = new CDroga(id, ns1, ns2, dl, sinus, cosinus);
	drogi.push_back(D);
}

void CMapa::dodajDrDoSkrzyzowania(int idSkrzyzownia, int idDrogi, vector <CZnak*> zn)
{
	skrzyzowania[idSkrzyzownia]->dodajDroge(idDrogi, zn);
}

void CMapa::dodajSwiatla(int idSkrzyzowania, vector<int> drogi, int czas)
{
	skrzyzowania[idSkrzyzowania]->dodajSwiatla(drogi, czas);
}

void CMapa::attach(CObserwator* obs)
{
	obserwator.push_back(obs);
}

void CMapa::detach(CObserwator* obs)
{

}

void CMapa::notify()
{
	for (int i = 0; i < obserwator.size(); i++)
	{
		obserwator[i]->update(0);
	}
}


