#include "CGrafika.h"


CGrafika::CGrafika(sf::RenderWindow* w, CMapa* m)
{
	window = w;
	mapa = m;
}


void CGrafika::rysuj()
{
	rysujDrogi();
}

void CGrafika::rysujDrogi()
{
	/*sf::RectangleShape tlo;
	tlo.setFillColor(sf::Color(0, 30, 0, 255));
	tlo.setSize(sf::Vector2f(1500, 800));
	window->draw(tlo);
	*/
	int typ;

	vector <CSkrzyzowanie*> skrzyzowania = mapa->getSkrzyzowania();
	vector <CDroga*> drogi = mapa->getDrogi();
	sf::RectangleShape linia;
	linia.setFillColor(sf::Color(50, 50, 50, 255));

	for (int i = 0; i < drogi.size(); i++)
	{
		linia.setSize(sf::Vector2f(drogi[i]->getDlugosc(), drogi[i]->getSzerokosc()));
		linia.setOrigin(sf::Vector2f(0, drogi[i]->getSzerokosc()/2));
		linia.setPosition(sf::Vector2f(skrzyzowania[drogi[i]->getIdSk1()]->getX(), skrzyzowania[drogi[i]->getIdSk1()]->getY() ));
		linia.setRotation(drogi[i]->getKat());
		window->draw(linia);
	}
	
	sf::CircleShape kolo1;
	kolo1.setFillColor(sf::Color(50, 50, 50, 255));
	kolo1.setRadius(drogi[0]->getSzerokosc()*0.5);
	kolo1.setOrigin(sf::Vector2f(drogi[0]->getSzerokosc() * 0.5, drogi[0]->getSzerokosc() * 0.5));

	sf::CircleShape kolo2;
	kolo2.setFillColor(sf::Color(50, 50, 50, 255));
	kolo2.setRadius(drogi[0]->getSzerokosc()*1.5);
	kolo2.setOrigin(sf::Vector2f(drogi[0]->getSzerokosc() * 1.5, drogi[0]->getSzerokosc() * 1.5));

	for (int i = 0; i < skrzyzowania.size(); i++)
	{
		typ = skrzyzowania[i]->getTyp();
		
		if (typ == 1)
		{
			kolo2.setPosition(sf::Vector2f(skrzyzowania[i]->getX(), skrzyzowania[i]->getY()));
			
			kolo1.setPosition(sf::Vector2f(skrzyzowania[i]->getX(), skrzyzowania[i]->getY()));
			kolo1.setFillColor(sf::Color(0, 0, 0, 255));
			window->draw(kolo2);
			window->draw(kolo1);
			kolo1.setFillColor(sf::Color(50, 50, 50, 255));
		}
		else if (typ == 2)
		{
			kolo1.setPosition(sf::Vector2f(skrzyzowania[i]->getX(), skrzyzowania[i]->getY()));
			kolo1.setRadius(drogi[0]->getSzerokosc() * 0.5);
			window->draw(kolo1);
		}
		else if (typ == 3)
		{
			kolo1.setPosition(sf::Vector2f(skrzyzowania[i]->getX(), skrzyzowania[i]->getY()));
			kolo1.setRadius(drogi[0]->getSzerokosc() * 0.5);
			window->draw(kolo1);
		}
		else if (typ == 4)
		{
			kolo1.setPosition(sf::Vector2f(skrzyzowania[i]->getX(), skrzyzowania[i]->getY()));
			kolo1.setRadius(drogi[0]->getSzerokosc() * 0.5);
			window->draw(kolo1);
		}
			sf::CircleShape znak;
			znak.setFillColor(sf::Color(0, 255, 0, 255));
			znak.setRadius(5);
			znak.setOrigin(sf::Vector2f(5,5));

			sf::RectangleShape pierw;
			pierw.setFillColor(sf::Color(255, 255, 10, 255));
			pierw.setSize(sf::Vector2f(10,10));
			pierw.setOrigin(sf::Vector2f(5, 5));

			sf::CircleShape podp(7, 3);
			podp.setOrigin(sf::Vector2f(7, 7));
			podp.setFillColor(sf::Color(255, 150, 0, 255));

			for (int j = 0; j < skrzyzowania[i]->getIdDrogi().size(); j++)
			{
				if (drogi[skrzyzowania[i]->getIdDrogi()[j]]->getIdSk1() == skrzyzowania[i]->getID())//jeœli to 1 skrzyzowanie danej drogi
				{
					podp.setPosition(sf::Vector2f(skrzyzowania[i]->getX() + drogi[skrzyzowania[i]->getIdDrogi()[j]]->getCosinus() * 50.0 + drogi[skrzyzowania[i]->getIdDrogi()[j]]->getSinus() * 20.0, skrzyzowania[i]->getY() + drogi[skrzyzowania[i]->getIdDrogi()[j]]->getSinus() * 50.0 - drogi[skrzyzowania[i]->getIdDrogi()[j]]->getCosinus() * 20));
					podp.setRotation(drogi[skrzyzowania[i]->getIdDrogi()[j]]->getKat() + 90);
				}
				else if (drogi[skrzyzowania[i]->getIdDrogi()[j]]->getIdSk2() == skrzyzowania[i]->getID())//jeœli to 2 skrzyzowanie danej drogi
				{
					podp.setPosition(sf::Vector2f(skrzyzowania[i]->getX() - drogi[skrzyzowania[i]->getIdDrogi()[j]]->getCosinus() * 50.0 - drogi[skrzyzowania[i]->getIdDrogi()[j]]->getSinus() * 20.0, skrzyzowania[i]->getY() - drogi[skrzyzowania[i]->getIdDrogi()[j]]->getSinus() * 50.0 + drogi[skrzyzowania[i]->getIdDrogi()[j]]->getCosinus() * 20)) ;
					podp.setRotation(drogi[skrzyzowania[i]->getIdDrogi()[j]]->getKat() + 270);
				}
				//pierw.setRotation(drogi[skrzyzowania[i]->getIdDrogi()[j]]->getKat() + 45);
				window->draw(podp);
			}

	}
}

void CGrafika::rysujSkrzyzowania()
{

}
