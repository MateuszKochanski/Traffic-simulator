#include "CSkrzyzowanie.h"

CSkrzyzowanie::CSkrzyzowanie()
{
	sekwencjeSwiatel = 0;
}

int CSkrzyzowanie::getID()
{
	return ID;
}

int CSkrzyzowanie::getX()
{
	return x;
}

int CSkrzyzowanie::getY()
{
	return y;
}

void CSkrzyzowanie::set(int id, int ix, int iy,int t)
{
	ID = id;
	x = ix;
	y = iy;
	typ = t;
}

int CSkrzyzowanie::getTyp()
{
	return typ;
}

vector <int> CSkrzyzowanie::getIdDrogi()
{
	return id_drogi;
}

vector<vector<CZnak*>> CSkrzyzowanie::getZnaki()
{
	return znaki;
}


vector<CSwiatla*> CSkrzyzowanie::getSwiatla()
{
	return swiatla;
}


void CSkrzyzowanie::dodajDroge(int idDrogi, vector <CZnak*> zn)
{
	id_drogi.push_back(idDrogi);
	znaki.push_back(zn);
}

void CSkrzyzowanie::dodajSwiatla(vector<int> drogi, int czas)
{
	bool ok;
	CSwiatla* sw;
	if (swiatla.size() == 0)
	{
		for (int i = 0; i < id_drogi.size(); i++)
		{
			sw = new CSwiatla;
			swiatla.push_back(sw);
		}
	}
	sekwencjeSwiatel++;
	for (int i = 0; i < id_drogi.size(); i++)
	{
		ok = false;
		for (int j = 0; j < drogi.size(); j++)
		{
			if (id_drogi[i] == drogi[j])
			{
				swiatla[i]->setParametry(sekwencjeSwiatel, czas);
				ok = true;
			}
		}
		if (!ok)
		{
			swiatla[i]->zwiekszCzasOczekiwania(czas);
		}
	}

}
