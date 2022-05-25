#pragma once
#include "CObserwowana.h"
#include "CObserwator.h"
#include "CDroga.h"
#include "CSkrzyzowanie.h"
#include <cstdlib>
#include <ctime>

/// @file CPojazd.h
/// @brief Plik nag³ówkowy klasy CPojazd

/// @brief Wirtualna klasa pojazdów
class CPojazd : public CObserwowana
{
protected:
	/// @brief Numer ID pojazdu
	int ID;
	/// @brief Wspó³rzêdna X pojazdu
	double x;
	/// @brief Wspó³rzêdna Y pojazdu
	double y;
	/// @brief Odleg³oœæ pojadu od pocz¹tku drogi
	double odleglosc;
	/// @brief Numer ID drogi po której porusza siê pojazd
	int idDrogi;
	/// @brief Numer ID nastêpnej drogi po której bêdzie porusza³ siê pojazd
	int idNastDrogi;
	/// @brief Kierunek poruszania siê pojazdu
	int kierunek;
	/// @brief Odwrotnoœæ kierunku poruszania siê pojadu, 
	int nieKierunek;
	/// @brief K¹t pojazdu
	double kat;
	/// @brief Tablica przechowywuj¹ca obserwatorów
	vector <CObserwator*> obserwatorzy;
	/// @brief Prêdkoœæ pojazdu
	double predkosc;
	/// @brief Czy wylosowano ju¿ nastêpn¹ drogê
	bool jestNastDroga;
	/// @brief Wspó³rzêdna X œrodka obrotu grafiki pojazdu przy skrêcie
	double sx;
	/// @brief Wspó³rzêdna Y œrodka obrotu grafiki pojazdu przy skrêcie
	double sy;
	/// @brief Tablica dynamiczna posortowanych dróg na koñcowym skrzy¿owaniu drogi pod wzglêdem k¹ta
	int* kolejnoscDrog;	
	/// @brief Tablica dynamiczna posortowanych k¹tów dróg na koñcowym skrzy¿owaniu drog
	double* katy;
	/// @brief Czy pojazd jest w trybie skrêtu
	bool trybSkretu;
	/// @brief Promieñ skrêtu
	double promien;
	/// @brief Kierunek skrêtu: 1 - skrêt w prawo, 0 - skrêt w lewo
	bool kierunekSkretu;
	/// @brief Czy wyznaczono parametry potrzebne do skrêtu
	bool czyGotowyDoSkretu;
	/// @brief Odleg³oœæ od koñca drogi, przy której pojazd przechodzi w tryb skrêtu
	double odlegloscRozpoczeciaSkretu;
	/// @brief Odleg³oœæ jak¹ pojazd pokona³ w trybie skrêtu
	double odlSkretu;
	/// @brief K¹t nastêpnej drogi wzglêdem k¹ta pojazdu
	double katNastDrogi;
	/// @brief Zapamiêtana wartoœæ k¹ta pojazdu przed rozpoczêciem skrêtu
	double katPoczatkowy;
	/// @brief Prawdziwy tylko w jednym cyklu odœwierzenia po zmianie drogi
	bool wlasnieZmienionoDroge;
	/// @brief Licznik jak d³ugo pojazd czeka na skrzy¿owaniu równorzêdnym
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

