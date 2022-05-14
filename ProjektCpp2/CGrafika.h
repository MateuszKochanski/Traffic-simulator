#pragma once
#include "CMapa.h"
#include "CObserwator.h"

#include "CDrogaGrafika.h"
#include "CSkrzyzowanieGrafika.h"
#include "CZnakGrafika.h"
#include "CSwiatlaGrafika.h"

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
public:
	void rysuj();
	CGrafika(sf::RenderWindow*, CMapa*);
	void update(int arg);
};

