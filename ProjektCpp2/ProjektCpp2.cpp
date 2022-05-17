//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
#include "CMapa.h"
#include "CGrafika.h"
#include "CWczytywaczMapy.h"
#include "CSymulacja.h"
#include "CZarzadzanieGrafika.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 800), "Symulator ruchu drogowego",sf::Style::Close, sf::ContextSettings(24, 8, 4));
    //window.setFramerateLimit(100);
    

    CMapa mapa;
    CGrafika grafika(&window,&mapa);
    mapa.attach(&grafika); 
    CWczytywaczMapy wczytywacz(&mapa, "mapa.txt");
    CZarzadzanieGrafika zarzadzaczGrafika(&grafika);

    CSymulacja symulacja(&mapa, 100, &zarzadzaczGrafika);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        symulacja.uruchom();
        window.clear();
        grafika.rysuj();
        window.display();

    }
 
    return 0;
}