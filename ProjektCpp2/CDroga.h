#pragma once
class CDroga
{
private:
	int ID;
	int id_Sk[2];
	int dlugosc;
	double kat;
	double sinus;
	double cosinus;
	int szerokosc = 20;
public:
	CDroga(int id, int sk1, int sk2, int dl, double s, double c);
	int getID();
	int getDlugosc();
	int getIdSk1();
	int getIdSk2();
	float getKat();
	double getSinus();
	double getCosinus();
	int getSzerokosc();
};

