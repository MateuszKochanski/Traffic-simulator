#include "CSkrzyzowanie.h"

/// @file CSkrzyzowanie.cpp
/// @brief Plik �r�d�owy klasy CSkrzyzowanie

/// @brief 

/// @brief Konstruktor klasy CSkrzyzowanie
/// @param id Numer ID nowego skrzy�ania
/// @param a Wsp�rz�dna X nowego skrzy�owania
/// @param b Wsp�rz�dna Y nowego skrzy�owania
CSkrzyzowanie::CSkrzyzowanie(int id, int a, int b)
{
	ID = id;
	x = a;
	y = b;
	sekwencjeSwiatel = 0;
	bufor = -1;
}

/// @brief Destruktor klasy CSkrzyzowanie
CSkrzyzowanie::~CSkrzyzowanie()
{
	for (int i = 0; i < znaki.size(); i++)
	{
		for (int j = 0; j < znaki[i].size();j++)
		{
			delete znaki[i][j];
		}
		znaki[i].clear();
	}
	znaki.clear();

	for (int i = 0; i < swiatla.size(); i++)
	{
		delete swiatla[i];
	}
	znaki.clear();
	id_drogi.clear();
}

/// @brief Zwraca numer ID skrzy�owania
/// @return Numer ID
int CSkrzyzowanie::getID()
{
	return ID;
}

/// @brief Zwraca wsp�rz�dn� X skrzy�owania
/// @return Wsp�rz�dna X
int CSkrzyzowanie::getX()
{
	return x;
}

/// @brief Zwraca wsp�rz�dn� Y skrzy�owania
/// @return Wsp�rz�dna Y
int CSkrzyzowanie::getY()
{
	return y;
}

/// @brief Ustawia parametry skrzy�owania
/// @param id Numer ID
/// @param ix Wsp�rz�dna X
/// @param iy Wsp�rz�dna Y
void CSkrzyzowanie::set(int id, int ix, int iy)
{
	ID = id;
	x = ix;
	y = iy;
}

/// @brief Zwraca tablic� dr�g, kt�re ��cz� si� na danym skrzy�owniu
/// @return Tablica dr�g
vector <int> CSkrzyzowanie::getIdDrogi()
{
	return id_drogi;
}

/// @brief Zwraca tablic� znak�w
/// @return Tablica znak�w
vector<vector<CZnak*>> CSkrzyzowanie::getZnaki()
{
	return znaki;
}

/// @brief Zwraca tablic� �wiate�
/// @return Tablica �wiate�
vector<CSwiatla*> CSkrzyzowanie::getSwiatla()
{
	return swiatla;
}

/// @brief Dodaje drog� do skrzyzowania
/// @param idDrogi Numer ID drogi
/// @param zn Tablica znak�w dla danej drogi
void CSkrzyzowanie::dodajDroge(int idDrogi, vector <CZnak*> zn)
{
	id_drogi.push_back(idDrogi);
	znaki.push_back(zn);
}

/// @brief Zwraca przez jaki pojazd skrzy�owanie jest zaj�te
/// @return zaj�to�� skrzy�owania
int CSkrzyzowanie::getBufor()
{
	return bufor;
}

/// @brief Ustawienie warto�ci bufora
/// @param id Numer ID pojazdu
void CSkrzyzowanie::setBufor(int id)
{
	bufor = id;
}


/// @brief Dodaje sygnalizacj� �wietln� do skrzyzowania
/// @param drogi Tablica zestawu dr�g
/// @param czas Czas �wiecenia �wiat�a zielonego dla danego zestawu dr�g
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
