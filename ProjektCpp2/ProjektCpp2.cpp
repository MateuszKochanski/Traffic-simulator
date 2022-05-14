//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
#include "CMapa.h"
#include "CGrafika.h"
#include "CWczytywaczMapy.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 800), "Symulator ruchu drogowego",sf::Style::Close, sf::ContextSettings(24, 8, 4));
    window.setFramerateLimit(50);
    

    CMapa mapa;
    CGrafika grafika(&window,&mapa);
    mapa.attach(&grafika); 
    CWczytywaczMapy wczytywacz(&mapa, "mapa.txt");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        mapa.odswierz(50);
        grafika.rysuj();
        window.display();
    }
 
    return 0;
}