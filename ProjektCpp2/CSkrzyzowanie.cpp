#include "CSkrzyzowanie.h"

/// @file CSkrzyzowanie.cpp
/// @brief Plik Ÿród³owy klasy CSkrzyzowanie

/// @brief 

/// @brief Konstruktor klasy CSkrzyzowanie
/// @param id Numer ID nowego skrzy¿ania
/// @param a Wspó³rzêdna X nowego skrzy¿owania
/// @param b Wspó³rzêdna Y nowego skrzy¿owania
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

/// @brief Zwraca numer ID skrzy¿owania
/// @return Numer ID
int CSkrzyzowanie::getID()
{
	return ID;
}

/// @brief Zwraca wspó³rzêdn¹ X skrzy¿owania
/// @return Wspó³rzêdna X
int CSkrzyzowanie::getX()
{
	return x;
}

/// @brief Zwraca wspó³rzêdn¹ Y skrzy¿owania
/// @return Wspó³rzêdna Y
int CSkrzyzowanie::getY()
{
	return y;
}

/// @brief Ustawia parametry skrzy¿owania
/// @param id Numer ID
/// @param ix Wspó³rzêdna X
/// @param iy Wspó³rzêdna Y
void CSkrzyzowanie::set(int id, int ix, int iy)
{
	ID = id;
	x = ix;
	y = iy;
}

/// @brief Zwraca tablicê dróg, które ³¹cz¹ siê na danym skrzy¿owniu
/// @return Tablica dróg
vector <int> CSkrzyzowanie::getIdDrogi()
{
	return id_drogi;
}

/// @brief Zwraca tablicê znaków
/// @return Tablica znaków
vector<vector<CZnak*>> CSkrzyzowanie::getZnaki()
{
	return znaki;
}

/// @brief Zwraca tablicê œwiate³
/// @return Tablica œwiate³
vector<CSwiatla*> CSkrzyzowanie::getSwiatla()
{
	return swiatla;
}

/// @brief Dodaje drogê do skrzyzowania
/// @param idDrogi Numer ID drogi
/// @param zn Tablica znaków dla danej drogi
void CSkrzyzowanie::dodajDroge(int idDrogi, vector <CZnak*> zn)
{
	id_drogi.push_back(idDrogi);
	znaki.push_back(zn);
}

/// @brief Zwraca przez jaki pojazd skrzy¿owanie jest zajête
/// @return zajêtoœæ skrzy¿owania
int CSkrzyzowanie::getBufor()
{
	return bufor;
}

/// @brief Ustawienie wartoœci bufora
/// @param id Numer ID pojazdu
void CSkrzyzowanie::setBufor(int id)
{
	bufor = id;
}


/// @brief Dodaje sygnalizacjê œwietln¹ do skrzyzowania
/// @param drogi Tablica zestawu dróg
/// @param czas Czas œwiecenia œwiat³a zielonego dla danego zestawu dróg
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
