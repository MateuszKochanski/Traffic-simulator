#include "CZarzadzanieGrafika.h"

CZarzadzanieGrafika::CZarzadzanieGrafika(CGrafika* gr)
{
	grafika = gr;
}

void CZarzadzanieGrafika::update(int arg)
{
	for (int i = 0; i < grafika->getMapa()->getPojazdy().size(); i++)
	{
		grafika->dodajGrPojazdu(grafika->getMapa()->getPojazdy()[i]);
	}
	
}
