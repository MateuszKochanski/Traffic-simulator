#pragma once
#include <vector>
using namespace std;

class CDroga
{
private:
	int ID;
	int id_Sk[2];
	double dlugosc;
	double kat;
	double sinus;
	double cosinus;
	int szerokosc = 20;
	vector <int> pojazdyK1;
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

