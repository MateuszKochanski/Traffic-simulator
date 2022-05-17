#pragma once
#include "CDroga.h"
#include "CSkrzyzowanie.h"
#include "CPojazd.h"
#include "CObserwowana.h"
//#include "CObserwator.h"

#include <string> 
#include <vector>
#include <fstream>
#include "COsobowy.h"


using namespace std;

class CMapa : public CObserwowana
{
private:
	vector <CDroga*> drogi;
	vector <CSkrzyzowanie*> skrzyzowania;
	vector <CPojazd*> pojazdy;
	vector <CObserwator*> obserwator;
public:
	void odswierz(double czestotliwosc);
	vector <CDroga*> getDrogi();
	vector <CSkrzyzowanie*> getSkrzyzowania();
	vector <CPojazd*> getPojazdy();
	void dodajSkrzyzowanie(int id, int x, int y);
	void dodajDroge(int id, int ns1, int ns2, int dl, double sinus, double cosinus);
	void dodajDrDoSkrzyzowania(int idSkrzyzownia, int idDrogi, vector <CZnak*> zn);
	void dodajSwiatla(int idSkrzyzowania, vector <int> drogi, int czas);
	void dodajPojazd(CDroga*d, int odl, int kier);
	void attach(CObserwator*);
	void detach(CObserwator*);
	void notify();
};

