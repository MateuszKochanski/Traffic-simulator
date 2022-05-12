#pragma once
#include "CDroga.h"
#include "CSkrzyzowanie.h"
#include "CPojazd.h"
#include <string> 
#include <vector>
#include <fstream>

#include "CRondo.h"
#include "CSkKierowane.h"
#include "CSkRownorzed.h"
#include "CSkNRownorzed.h"

using namespace std;

class CMapa
{
private:
	vector <CDroga*> drogi;
	vector <CSkrzyzowanie*> skrzyzowania;

public:
	void wczytajMape(string);
	void wczytajSkrzyzowania(string);
	void wczytajDrogi(string);
	void odswierz();
	vector <CDroga*> getDrogi();
	vector <CSkrzyzowanie*> getSkrzyzowania();
};

