#pragma once
#include "CObserwowana.h"
#include <vector>
using namespace std;

/// @file CSwiatla.h
/// @brief Plik nag³ówkowy klasy CSwiatla

/// @brief Klasa sygnalizacji œwietlnej
class CSwiatla : public CObserwowana
{
private:
	/// @brief Kolor aktualnie œwiec¹cego siê œwiat³a
	int kolor;
	/// @brief Numer ID drogi przy której stoi sygnalizacja
	int idDrogi;
	/// @brief Czas trwania œwiat³a zielonego
	int czasZielone;
	/// @brief Czas trwania œwiat³a czerwonego
	int czasCzerwone;
	/// @brief Numer zbioru zsynchronizowanych œwiate³ do którego nale¿y sygnalizacja
	int seq;
	/// @brief Licznik zliczaj¹cy wywo³ania funkcji odœwierz s³u¿¹cy do pomiaru czasu œwiecenia danego œwiat³a
	int zegar;
	/// @brief Numer stanu w którym znajduje siê sygnalizacja (¿ó³ty -> zielony -> ¿ó³ty -> czerwony ->)
	int stan;
	/// @brief Tablica obserwatorów
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

