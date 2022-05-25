#pragma once
#include "CObserwowana.h"
#include <vector>
using namespace std;

/// @file CSwiatla.h
/// @brief Plik nag��wkowy klasy CSwiatla

/// @brief Klasa sygnalizacji �wietlnej
class CSwiatla : public CObserwowana
{
private:
	/// @brief Kolor aktualnie �wiec�cego si� �wiat�a
	int kolor;
	/// @brief Numer ID drogi przy kt�rej stoi sygnalizacja
	int idDrogi;
	/// @brief Czas trwania �wiat�a zielonego
	int czasZielone;
	/// @brief Czas trwania �wiat�a czerwonego
	int czasCzerwone;
	/// @brief Numer zbioru zsynchronizowanych �wiate� do kt�rego nale�y sygnalizacja
	int seq;
	/// @brief Licznik zliczaj�cy wywo�ania funkcji od�wierz s�u��cy do pomiaru czasu �wiecenia danego �wiat�a
	int zegar;
	/// @brief Numer stanu w kt�rym znajduje si� sygnalizacja (��ty -> zielony -> ��ty -> czerwony ->)
	int stan;
	/// @brief Tablica obserwator�w
	vector <CObserwator*> obserwatorzy;

public:
	CSwiatla(int sq=0, int czZ=0, int czCZ=0);
	void odswiez(double czestotliwosc);
	int getKolor();
	void zwiekszCzasOczekiwania(int czas);
	void setParametry(int sq, int czZ);

	void attach(CObserwator*);
	void detach(CObserwator*);
	void notify();
};

