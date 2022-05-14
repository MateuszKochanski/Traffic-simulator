#pragma once
#include "CDroga.h"
#include "CSkrzyzowanie.h"
#include "CPojazd.h"
#include "CObserwowana.h"
//#include "CObserwator.h"

#include <string> 
#include <vector>
#include <fstream>


using namespace std;

class CMapa : public CObserwowana
{
private:
	vector <CDroga*> drogi;
	vector <CSkrzyzowanie*> skrzyzowania;
	vector <CObserwator*> obserwator;
public:
	void odswierz(double czestotliwosc);
	vector <CDroga*> getDrogi();
	vector <CSkrzyzowanie*> getSkrzyzowania();
	void dodajSkrzyzowanie(int id, int x, int y);
	void dodajDroge(int id, int ns1, int ns2, int dl, double sinus, double cosinus);
	void dodajDrDoSkrzyzowania(int idSkrzyzownia, int idDrogi, vector <CZnak*> zn);
	void dodajSwiatla(int idSkrzyzowania, vector <int> drogi, int czas);

	void attach(CObserwator*);
	void detach(CObserwator*);
	void notify();
};

