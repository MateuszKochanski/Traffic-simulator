#pragma once
#include "CObserwowana.h"
#include "CObserwator.h"
#include "CDroga.h"
#include "CSkrzyzowanie.h"
#include <cstdlib>
#include <ctime>

/// @file CPojazd.h
/// @brief Plik nag��wkowy klasy CPojazd

/// @brief Wirtualna klasa pojazd�w
class CPojazd : public CObserwowana
{
protected:
	/// @brief Numer ID pojazdu
	int ID;
	/// @brief Wsp�rz�dna X pojazdu
	double x;
	/// @brief Wsp�rz�dna Y pojazdu
	double y;
	/// @brief Odleg�o�� pojadu od pocz�tku drogi
	double odleglosc;
	/// @brief Numer ID drogi po kt�rej porusza si� pojazd
	int idDrogi;
	/// @brief Numer ID nast�pnej drogi po kt�rej b�dzie porusza� si� pojazd
	int idNastDrogi;
	/// @brief Kierunek poruszania si� pojazdu
	int kierunek;
	/// @brief Odwrotno�� kierunku poruszania si� pojadu, 
	int nieKierunek;
	/// @brief K�t pojazdu
	double kat;
	/// @brief Tablica przechowywuj�ca obserwator�w
	vector <CObserwator*> obserwatorzy;
	/// @brief Pr�dko�� pojazdu
	double predkosc;
	/// @brief Czy wylosowano ju� nast�pn� drog�
	bool jestNastDroga;
	/// @brief Wsp�rz�dna X �rodka obrotu grafiki pojazdu przy skr�cie
	double sx;
	/// @brief Wsp�rz�dna Y �rodka obrotu grafiki pojazdu przy skr�cie
	double sy;
	/// @brief Tablica dynamiczna posortowanych dr�g na ko�cowym skrzy�owaniu drogi pod wzgl�dem k�ta
	int* kolejnoscDrog;	
	/// @brief Tablica dynamiczna posortowanych k�t�w dr�g na ko�cowym skrzy�owaniu drog
	double* katy;
	/// @brief Czy pojazd jest w trybie skr�tu
	bool trybSkretu;
	/// @brief Promie� skr�tu
	double promien;
	/// @brief Kierunek skr�tu: 1 - skr�t w prawo, 0 - skr�t w lewo
	bool kierunekSkretu;
	/// @brief Czy wyznaczono parametry potrzebne do skr�tu
	bool czyGotowyDoSkretu;
	/// @brief Odleg�o�� od ko�ca drogi, przy kt�rej pojazd przechodzi w tryb skr�tu
	double odlegloscRozpoczeciaSkretu;
	/// @brief Odleg�o�� jak� pojazd pokona� w trybie skr�tu
	double odlSkretu;
	/// @brief K�t nast�pnej drogi wzgl�dem k�ta pojazdu
	double katNastDrogi;
	/// @brief Zapami�tana warto�� k�ta pojazdu przed rozpocz�ciem skr�tu
	double katPoczatkowy;
	/// @brief Prawdziwy tylko w jednym cyklu od�wierzenia po zmianie drogi
	bool wlasnieZmienionoDroge;
	/// @brief Licznik jak d�ugo pojazd czeka na skrzy�owaniu r�wnorz�dnym
	double licznikCzekania;
	/// @brief Czy dany pojazd jest pojazdem uprzywilejowanym
	bool czyUprzywilejowany;

	void odswiezKolejnoscDrog(vector <CDroga*> drogi, vector <CSkrzyzowanie*> skrzyzowania);
public:
	int getID();
	int getX();
	int getY();
	int getIDDrogi();
	int getOdleglosc();
	double getKat();
	void odswiez(vector <CDroga*> drogi, vector <CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc);
	double getPromien();
	bool getKierunekSkretu();
	double getSx();
	double getSy();
	double getKatNastDrogi();
	virtual bool sprawdzCzyMogeJechac(vector <CDroga*> drogi, vector <CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc) = 0;
	bool getCzyUprzywilejowany();

	void attach(CObserwator*);
	void detach(CObserwator*);
	void notify();
};

