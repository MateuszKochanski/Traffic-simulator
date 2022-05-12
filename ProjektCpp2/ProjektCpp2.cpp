//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
#include "CMapa.h"
#include "CGrafika.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 800), "Symulator ruchu drogowego",sf::Style::Close, sf::ContextSettings(24, 8, 4));
    window.setFramerateLimit(100);
    
    CMapa mapa;
    mapa.wczytajMape("mapa.txt");
    CGrafika grafika(&window,&mapa);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        grafika.rysuj();
        window.display();
    }

    return 0;
}