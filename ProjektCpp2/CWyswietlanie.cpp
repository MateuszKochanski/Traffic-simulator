#include "CWyswietlanie.h"

/// @file CWyswietlanie.cpp
/// @brief Plik Ÿród³owy klasy CWyswietlanie

/// @brief Konstruktor klasy CWyswietlanie
CWyswietlanie::CWyswietlanie()
{
	window = new sf::RenderWindow(sf::VideoMode(1500, 800), "Symulator ruchu drogowego", sf::Style::Default, sf::ContextSettings(24, 8, 4));
}

/// @brief Wyœwietlenie wszystkich obiektów przechowywanych w obiekcie grafika
/// @param grafika Obiekt przechowywuj¹cy wszystkie obiekty graficzne
void CWyswietlanie::wyswietl(CGrafika* grafika)
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
    if (window->isOpen())
    {
        window->clear();
        //grafika->rysuj(window);
		for (int i = 0; i < grafika->getGrDrogi().size(); i++)
		{
			grafika->getGrDrogi()[i]->rysuj(window);
		}
		for (int i = 0; i < grafika->getGrSkrzyzowania().size(); i++)
		{
			grafika->getGrSkrzyzowania()[i]->rysuj(window);
		}
		for (int i = 0; i < grafika->getGrZnaki().size(); i++)
		{
			grafika->getGrZnaki()[i]->rysuj(window);
		}
		for (int i = 0; i < grafika->getGrSwiatla().size(); i++)
		{
			grafika->getGrSwiatla()[i]->rysuj(window);
		}
		for (int i = 0; i < grafika->getGrPojazdy().size(); i++)
		{
			grafika->getGrPojazdy()[i]->rysuj(window);
		}
        window->display();
    }
}

/// @brief Zwraca czy okno programu jest wci¹¿ otwarte
/// @return Czy okno programu jest otwarte
bool CWyswietlanie::czyJestOtwarte()
{
	return window->isOpen();
}