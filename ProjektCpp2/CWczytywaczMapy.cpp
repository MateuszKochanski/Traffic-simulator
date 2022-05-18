#include "CWczytywaczMapy.h"

using namespace std;

CWczytywaczMapy::CWczytywaczMapy()
{

}

CWczytywaczMapy::CWczytywaczMapy(CMapa* mapa, string sciezka)
{
	wczytajMape(mapa, sciezka);
}

void CWczytywaczMapy::setMapa(CMapa* mapa, string sciezka)
{
	wczytajMape(mapa, sciezka);
}

void CWczytywaczMapy::wczytajMape(CMapa* mapa, string sciezka)
{
	ifstream plik("mapa2.txt");

	string line;
	string liczba;
	CZnak* znak;
	vector <CZnak*> znakiS1;
	vector <CZnak*> znakiS2;
	int licznikD = 0;
	int licznikS = 0;
	int x, y;
	int ns1, ns2;
	double sinus;
	double cosinus;
	CSkrzyzowanie* s1, * s2;
	double dl;

	vector <int> drogiSw;
	int czasSw = 0;

	if (plik.good())
	{
		do
		{
			
			getline(plik, line);
			cout << line << endl;

			if (line[0] == 'S')
			{
				liczba = "";
				do {
					line.erase(0, 1);
				} while (line[0] != 'X');
				line.erase(0, 1);

				cout << line << endl;
				while (line[0] >= '0' && line[0] <= '9')
				{
					liczba += line[0];
					line.erase(0, 1);
				}
				x = stoi(liczba);
				liczba.clear();
				line.erase(0, 2);
				while (line[0] >= '0' && line[0] <= '9')
				{
					liczba += line[0];
					line.erase(0, 1);
				}
				y = stoi(liczba);
				liczba.clear();

				mapa->dodajSkrzyzowanie(licznikS, x, y);
				licznikS++;

			}
			else if (line[0] == 'D')
			{
				znakiS1.clear();
				znakiS2.clear();

				while (line[0] != 'S')
					line.erase(0, 1);
				line.erase(0, 1);

				cout << line << endl;
				while (line[0] >= '0' && line[0] <= '9')
				{
					liczba += line[0];
					line.erase(0, 1);
				}
				ns1 = stoi(liczba);
				liczba.clear();
				while (line[0] != 'S' && line[0] != 'Z')
					line.erase(0, 1);
				cout << line << endl;
				if (line[0] == 'Z')/////////////////////znaki na s1
				{
					line.erase(0, 1);
					do
					{
						znak = new CZnak(line[0]);
						znakiS1.push_back(znak);
						line.erase(0, 1);
					} while (line[0] != ':');	
					
					while (line[0] != 'S')
						line.erase(0, 1);
					line.erase(0,1);

				}
				else
					line.erase(0, 1);

				cout << line << endl;

				while (line[0] >= '0' && line[0] <= '9')
				{
					liczba += line[0];
					line.erase(0, 1);
				}
				ns2 = stoi(liczba);
				liczba.clear();

				while (line[0] != NULL && line[0] != 'Z')
					line.erase(0, 1);

				if (line[0] == 'Z')/////////////////////znaki na s2
				{
					line.erase(0, 1);
					do
					{
						znak = new CZnak(line[0]);
						znakiS2.push_back(znak);
						line.erase(0, 1);
					} while (line[0] != ':');
				}

				s1 = mapa->getSkrzyzowania()[ns1];
				s2 = mapa->getSkrzyzowania()[ns2];

				dl = sqrt((s1->getX() - s2->getX()) * (s1->getX() - s2->getX()) + (s1->getY() - s2->getY()) * (s1->getY() - s2->getY()));
				sinus = (s2->getY() - s1->getY()) / dl;
				cosinus = (s2->getX() - s1->getX()) / dl;
				mapa->dodajDroge(licznikD, ns1, ns2, dl, sinus, cosinus);
				mapa->dodajDrDoSkrzyzowania(ns1, licznikD, znakiS1);
				mapa->dodajDrDoSkrzyzowania(ns2, licznikD, znakiS2);
				licznikD++;
			}
			else if (line[0] == 'W')
			{
				while (line[0] != 'S')
					line.erase(0, 1);
				line.erase(0, 1);

				while (line[0] >= '0' && line[0] <= '9')
				{
					liczba += line[0];
					line.erase(0, 1);
				}
				ns1 = stoi(liczba);
				liczba.clear();
				///////////////////////////////////////////////
				bool a;
				do
				{
					a = false;
					do
					{
						while (line[0] != 'D' && !a)
						{
							line.erase(0, 1);
							if (line[0] == 'T')
								a = true;
						}
						cout << "terrrr" << line << endl;
						line.erase(0, 1);

						while (line[0] >= '0' && line[0] <= '9')
						{
							liczba += line[0];
							line.erase(0, 1);
						}
						if (!a)
						{
							drogiSw.push_back(stoi(liczba));
							liczba.clear();
						}
						else
						{
							czasSw = stoi(liczba);
							liczba.clear();
						}
					} while (!a);
					line.erase(0, 1);
					cout << line << endl;
					//tutaj dodaæcwiatla jako 1 etap sekwencji
					mapa->dodajSwiatla(ns1, drogiSw, czasSw);

					drogiSw.clear();
				}while (line[0] != NULL);
			}
				
		} while (!plik.eof());
	}
	plik.close();

	mapa->notify();
}