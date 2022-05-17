#pragma once
#include "CMapa.h"
#include "CObserwator.h"

#include "CDrogaGrafika.h"
#include "CSkrzyzowanieGrafika.h"
#include "CZnakGrafika.h"
#include "CSwiatlaGrafika.h"
#include "CPojazdGrafika.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CGrafika : public CObserwator
{
private:
	sf::RenderWindow* window;
	CMapa* mapa;
	vector <CDrogaGrafika*> grDrogi;
	vector <CSkrzyzowanieGrafika*> grSkrzyzowania;
	vector <CZnakGrafika*> grZnaki;
	vector <CSwiatlaGrafika*> grSwiatla;
	vector <CPojazdGrafika*> grPojazdy;

public:
	CMapa* getMapa();
	void rysuj();
	void dodajGrPojazdu(CPojazd* pojazd);
	CGrafika(sf::RenderWindow*, CMapa*);
	void update(int arg);
};

