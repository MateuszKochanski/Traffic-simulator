#pragma once
#include <vector>
using namespace std;

/// @file CDroga.h
/// @brief Plik nag³ówkowy klasy CDroga

/// @brief Klasa obiektu przechowywuj¹cego drogê
class CDroga
{
private:
	/// @brief Numer ID
	int ID;
	/// @brief Skrzy¿owania które ³¹czy
	int id_Sk[2];
	/// @brief D³ugoœæ drogi
	double dlugosc;
	/// @brief K¹t drogi
	double kat;
	/// @brief sinus k¹ta drogi
	double sinus;
	/// @brief cosinus k¹ta drogi
	double cosinus;
	/// @brief Pojazdy, które jad¹ po danej drodze w kierunku 1
	vector <int> pojazdyK1;
	/// @brief Pojaddy, które jad¹ po danej drodze w kierunku 2
	vector <int> pojazdyK2;
public:
	CDroga(int id, int sk1, int sk2, double dl, double s, double c);
	int getID();
	double getDlugosc();
	int getIdSk(int i);
	double getKat();
	double getSinus();
	double getCosinus();
	int getSzerokosc();
	void dodajPojazd(int id, int kierunek);
	void usunPojazd(int id, int kierunek);
	vector <int> getPojazdy(int kierunek);
};

