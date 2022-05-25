#pragma once
#include <vector>
using namespace std;

/// @file CDroga.h
/// @brief Plik nag��wkowy klasy CDroga

/// @brief Klasa obiektu przechowywuj�cego drog�
class CDroga
{
private:
	/// @brief Numer ID
	int ID;
	/// @brief Skrzy�owania kt�re ��czy
	int id_Sk[2];
	/// @brief D�ugo�� drogi
	double dlugosc;
	/// @brief K�t drogi
	double kat;
	/// @brief sinus k�ta drogi
	double sinus;
	/// @brief cosinus k�ta drogi
	double cosinus;
	/// @brief Pojazdy, kt�re jad� po danej drodze w kierunku 1
	vector <int> pojazdyK1;
	/// @brief Pojaddy, kt�re jad� po danej drodze w kierunku 2
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

