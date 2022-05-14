#pragma once
#include "CObserwowana.h"

class CPojazd : public CObserwowana
{
private:
	int ID;
	int x;
	int y;
	int idDrogi;
	int odleglosc;
public:
	int getID();
	int getX();
	int getY();
	int getIDDrogi();
	int getOdleglosc();

	void attach(CObserwator*);
	void detach(CObserwator*);
	void notify();
};

