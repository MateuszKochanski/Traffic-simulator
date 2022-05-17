#pragma once
#include "CObserwowana.h"
#include <vector>
using namespace std;

class CSwiatla : public CObserwowana
{
private:
	int kolor;
	int idDrogi;
	int czasZielone;
	int czasCzerwone;
	int seq;
	int zegar;
	int stan;
	vector <CObserwator*> obserwatorzy;

public:
	CSwiatla(int sq=0, int czZ=0, int czCZ=0);
	void odswierz(double czestotliwosc);
	int getKolor();
	void zwiekszCzasOczekiwania(int czas);
	void setParametry(int sq, int czZ);

	void attach(CObserwator*);
	void detach(CObserwator*);
	void notify();
};

