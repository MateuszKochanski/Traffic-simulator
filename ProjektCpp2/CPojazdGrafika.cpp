#include "CPojazdGrafika.h"


CPojazdGrafika::CPojazdGrafika(CPojazd* poj)
{
	pojazd = poj;
	x = pojazd->getX();
	y = pojazd->getY();
	kat = pojazd->getKat();
	trybSkretu == false;
}

void CPojazdGrafika::update(int arg)
{
	if (arg == 0)
	{
		x = pojazd->getX();
		y = pojazd->getY();
		kat = pojazd->getKat();
		trybSkretu = false;
	}
	else
	{
		if (!trybSkretu) 
		{
			liczSrodekObrotu(1);
			trybSkretu = true;
		}
		kat = pojazd->getKat();
	}

}

void CPojazdGrafika::liczSrodekObrotu(bool kierunek)//kierunek==1 to prawa, kierunek 0 to lewa
{
	if (kierunek)
	{
		sx = x - sin(kat) * promien;
		sy = y + cos(kat) * promien;
	}
	else
	{
		sx = x + sin(kat) * (promien + 10);
		sy = y - cos(kat) * (promien + 10);
	}
}

void CPojazdGrafika::rysuj(sf::RenderWindow* window)
{
	sf::RectangleShape prostokat;
	prostokat.setFillColor(sf::Color(255, 50, 0, 255));
	prostokat.setSize(sf::Vector2f(15, 7));
	if (!trybSkretu)
	{
		prostokat.setOrigin(sf::Vector2f(7.5, 3.5));
	}
	else
	{
		if (kierunekSkretu)
		{
			prostokat.setOrigin(sf::Vector2f(7.5, 3.5 + promien));
		}
		else
		{
			prostokat.setOrigin(sf::Vector2f(7.5, 3.5 - (promien + 10)));
		}
	}
	prostokat.setPosition(sf::Vector2f(x, y));
	prostokat.setRotation(kat);
	window->draw(prostokat);
}