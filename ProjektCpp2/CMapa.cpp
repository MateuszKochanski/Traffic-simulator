#include "CMapa.h"
#include<iostream>



using namespace std;

void CMapa::wczytajMape(string sciezka)
{

	wczytajSkrzyzowania(sciezka);

}

void CMapa::wczytajSkrzyzowania(string sciezka)
{
	ifstream plik("mapa.txt");
	string line;
	char typ;
	int licznik = 0;
	int x, y;
	CSkrzyzowanie* S = nullptr;
	CDroga* D = nullptr;

	int ns1, ns2;
	CSkrzyzowanie* s1, * s2;
	int pierw;

	int odl;


	if (plik.good())
	{
		do
		{
			getline(plik,line);
			cout << line;
			typ = line[0];
			
			if (typ >= '0' && typ <= '4')
			{
				if (typ == '1')//RONDO
				{
					S = new CRondo;
				}
				else if (typ == '2')//ROWNORZED
				{
					S = new CSkRownorzed;
				}
				else if (typ == '3')//NIEROWNORZEDNE
				{
					S = new CSkNRownorzed;
				}
				else// if (typ == "4")
				{
					S = new CSkKierowane;
				}
				x = stoi(line.substr(1, 5));
				y = stoi(line.substr(6, 5));

				S->set(licznik, x, y);
				skrzyzowania.push_back(S);

				licznik++;
			}
		} while (line != "DROGI" && !plik.eof());

		licznik = 0;
		
		while (!plik.eof())
		{		
			getline(plik, line);
			cout << line << endl;
			ns1 = stoi(line.substr(0, 3));
			ns2 = stoi(line.substr(3, 3));
			pierw = stoi(line.substr(6, 2);
			s1 = skrzyzowania[ns1];
			s2 = skrzyzowania[ns2];
			odl = sqrt((s1->getX() - s2->getX()) * (s1->getX() - s2->getX()) + (s1->getY() - s2->getY()) * (s1->getY() - s2->getY()));
			D = new CDroga(licznik, ns1, ns2, odl);

			skrzyzowania[ns1]->update(licznik, pierw / 10);
			skrzyzowania[ns1]->update(licznik, pierw % 10);

			drogi.push_back(D);
			licznik++;
		}
/*
		for (int i = 0; i < licznik; i++)
		{
			skrzyzowania[i]->co();
		}*/
		
	}
	delete S, D;


}

void CMapa::wczytajDrogi(string sciezka)
{
	ifstream plik(sciezka);
}

void CMapa::odswierz()
{

}