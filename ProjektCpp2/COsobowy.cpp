#include "COsobowy.h"

/// @file COsobowy.cpp
/// @brief Plik �r�d�owy klasy COsobowy

/// @brief Konstruktor klasy COsobowy
/// @param id Numer ID pojazdu
/// @param skrzyzowania Tablica skrzy�owa� 
/// @param droga Tablica dr�g
/// @param odl Pocz�tkowa odleg�o�� pojazdu od pocz�tku drogi
/// @param kier Pocz�tkowy kierunek poruszania si� pojazdu
COsobowy::COsobowy(int id, vector <CSkrzyzowanie*> skrzyzowania, CDroga* droga, int odl, int kier)
{
	ID = id;
	odleglosc = odl;
	kierunek = kier;
	idDrogi = droga->getID();
	droga->dodajPojazd(ID, kierunek);

	predkosc = 50;

	if (kierunek == 0)
	{
		x = skrzyzowania[droga->getIdSk(kierunek)]->getX() + droga->getCosinus() * odleglosc - droga->getSinus() * 5.0;
		y = skrzyzowania[droga->getIdSk(kierunek)]->getY() + droga->getSinus() * odleglosc + droga->getCosinus() * 5.0;
		kat = droga->getKat();
	}
	else
	{
		x = skrzyzowania[droga->getIdSk(kierunek)]->getX() - droga->getCosinus() * odleglosc + droga->getSinus() * 5.0;
		y = skrzyzowania[droga->getIdSk(kierunek)]->getY() - droga->getSinus() * odleglosc - droga->getCosinus() * 5.0;
		kat = droga->getKat() + 180.0;
	}
	trybSkretu = false;
	czyGotowyDoSkretu = false;
	jestNastDroga = false;
	promien = 10;
	odlSkretu = 0;
	wlasnieZmienionoDroge = false;
	cierpliwosc = 5 + rand() % 10;
	czyUprzywilejowany = false;
}

/// @brief Destruktor klasy COsobowy
COsobowy::~COsobowy()
{
	delete[] katy;
	delete[] kolejnoscDrog;
}

/// @brief Sprawdza czy pojazd mo�e jecha�
/// @param drogi Tabloca drog
/// @param skrzyzowania Tablica skrzyzowan
/// @param pojazdy Tablica pojazd�w
/// @param czestotliwosc Cz�stotliwo�� od�wierzania pozycji pojazdu
/// @return Czy pojazd mo�e jecha�
bool COsobowy::sprawdzCzyMogeJechac(vector<CDroga*> drogi, vector<CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc)
{
	bool czyMogeJechac = true;

	if (drogi[idDrogi]->getPojazdy(kierunek).size() != 1)///////////////////////////samochod przed tob�
	{
		for (int j = 0; j < drogi[idDrogi]->getPojazdy(kierunek).size(); j++)
		{
			if (pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getID() != ID && pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getOdleglosc() < odleglosc + 25 && pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getOdleglosc() > odleglosc)
			{
				czyMogeJechac = false;
			}
		}
	}

	if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getSwiatla().size() != 0 && odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)/////////////////////�wiatla
	{
		int i = 0;
		while (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i] != idDrogi)
		{
			i++;
		}
		if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getSwiatla()[i]->getKolor() != 1)
			czyMogeJechac = false;
		else
		{
			int i = 0;
			while (kolejnoscDrog[i] != idNastDrogi)
			{
				i++;
			}
			i++;
			if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > i)
			{
				for (int j = i; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); j++)
				{
					if (idDrogi != kolejnoscDrog[j])
					{
						int l = 0;
						while (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[l] != kolejnoscDrog[j])
						{
							l++;
						}
						if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getSwiatla()[l]->getKolor() == 1)
						{
							if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[kolejnoscDrog[j]]->getIdSk(0))
							{

								for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(1).size(); k++)
								{
									if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 50)
									{
										if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getKatNastDrogi() > 140)
										{
											czyMogeJechac = false;
										}
									}
								}
							}
							else
							{
								for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(0).size(); k++)
								{
									if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 50)
									{
										if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getKatNastDrogi() > 140)
										{
											czyMogeJechac = false;
										}
									}
								}
							}
						}
					}

				}
			}
		}
	}
	else if (!skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getZnaki()[0].empty() && odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)//znaki
	{

		int z = 0;
		while (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[z] != idDrogi)//szukam nr drogi kt�ry odpowiada za drog� po kt�rej jad�
		{
			z++;
		}
		bool pierwszenstwo = false;//zak�adam �e nie mam pierwszenstwa chyba �e kt�ry� ze znak�w m�wi inaczej
		for (int i = 0; i < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getZnaki()[z].size(); i++)
		{
			if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getZnaki()[z][i]->getTyp() == 'P')
			{
				pierwszenstwo = true;
			}
		}

		if (pierwszenstwo)																									//je�li to droga z pierwszenstwem
		{
			int i = 0;
			while (kolejnoscDrog[i] != idNastDrogi)
			{
				i++;
			}
			i++;																											//lec� od lewej do prawej a� do drogi gdzie chc� jecha� i jeszcze o jedn� dalej
			if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > i)								//je�eli nie przesz�em przez wszystkie drogi, tzn. s� jakie� drogi jeszcze do sprawdzenia
			{
				for (int j = i; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); j++)			//iteracja po pozosta�ych drogach
				{
					if (idDrogi != kolejnoscDrog[j])																		//je�li to nie jest droga po kt�rej jad�
					{
						int l = 0;
						while (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[l] != kolejnoscDrog[j])		// szukam warto�ci kt�ra odpowiada numerowi kolejnej drogi w skrzyzowaniu 
						{
							l++;
						}
						for (int m = 0; m < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getZnaki()[l].size(); m++)	//iteruj� po wszystkich znakach na danej drodze
						{
							if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getZnaki()[l][m]->getTyp() == 'P')		//je�eli jest znak droga z pierwszenstwem
							{
								if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[kolejnoscDrog[j]]->getIdSk(0))			//je�eli to jest 0 skrzyzowanie danej drogi
								{

									for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(1).size(); k++)					//iteruje po li�cie pojazd�w nr1.
									{
										if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 50)//je�eli na danej drodze jest pojazd bli�ej ni� 40 jednostek
										{
											if (j + 1 < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size())
											{
												if (idDrogi != kolejnoscDrog[j + 1])
												{
													if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getKatNastDrogi() > 140)
													{
														czyMogeJechac = false;
													}
												}
											}
											else
												czyMogeJechac = false;
										}
									}
								}
								else
								{
									for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(0).size(); k++)
									{
										if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 50)
										{

											if (j + 1 < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size())
											{
												if (idDrogi != kolejnoscDrog[j + 1])
												{
													if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getKatNastDrogi() > 140)
													{
														czyMogeJechac = false;
													}
												}
											}
											else
												czyMogeJechac = false;

										}
									}
								}
							}
						}
					}

				}
			}
		}
		else
		{
			for (int i = 0; i < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); i++)
			{

				if (idDrogi != kolejnoscDrog[i])
				{
					int l = 0;
					while (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[l] != kolejnoscDrog[i])
					{
						l++;
					}
					for (int m = 0; m < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getZnaki()[l].size(); m++)
					{
						if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getZnaki()[l][m]->getTyp() == 'P')
						{
							if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[kolejnoscDrog[i]]->getIdSk(0))
							{

								for (int k = 0; k < drogi[kolejnoscDrog[i]]->getPojazdy(1).size(); k++)
								{
									if (drogi[kolejnoscDrog[i]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[i]]->getPojazdy(1)[k]]->getOdleglosc() < 60)
									{
										czyMogeJechac = false;
									}
								}
							}
							else
							{
								for (int k = 0; k < drogi[kolejnoscDrog[i]]->getPojazdy(0).size(); k++)
								{
									if (drogi[kolejnoscDrog[i]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[i]]->getPojazdy(0)[k]]->getOdleglosc() < 60)
									{

										czyMogeJechac = false;
									}
								}
							}
						}
					}
				}
			}
			int i = 0;
			if (czyMogeJechac)
			{

				if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > 2)
				{
					while (kolejnoscDrog[i] != idNastDrogi)
					{
						i++;
					}
					i++;
					if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > i)
					{
						for (int j = i; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); j++)
						{
							if (idDrogi != kolejnoscDrog[j])
							{
								if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[kolejnoscDrog[j]]->getIdSk(0))
								{
									for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(1).size(); k++)
									{
										if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 50)
										{
											if (j + 1 < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size())
											{
												if (idDrogi != kolejnoscDrog[j + 1])
												{
													if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getKatNastDrogi() > 140)
													{
														czyMogeJechac = false;
													}
												}
											}
											else
												czyMogeJechac = false;

										}
									}
								}
								else
								{
									for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(0).size(); k++)
									{
										if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 50)
										{
											if (j + 1 < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size())
											{
												if (idDrogi != kolejnoscDrog[j + 1])
												{
													if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getKatNastDrogi() > 140)
													{
														czyMogeJechac = false;
													}
												}
											}
											else
												czyMogeJechac = false;
										}
									}
								}
							}

						}
					}
				}
			}

		}

	}
	else if (odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)/////////////////////ZPR
	{
		int i = 0;
		if (czyMogeJechac)
		{

			if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > 2)
			{
				while (kolejnoscDrog[i] != idNastDrogi)
				{
					i++;
				}
				i++;
				if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > i)
				{
					for (int j = i; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); j++)
					{
						if (idDrogi != kolejnoscDrog[j])
						{
							if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[kolejnoscDrog[j]]->getIdSk(0))
							{
								for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(1).size(); k++)
								{
									if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 50)
									{
										czyMogeJechac = false;
									}
								}
							}
							else
							{
								for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(0).size(); k++)
								{
									if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 50)
									{
										czyMogeJechac = false;
									}
								}
							}
						}

					}
				}
			}

			if (!czyMogeJechac)
				licznikCzekania += 1.0 / czestotliwosc;

			if (licznikCzekania > cierpliwosc && (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() == -1 || skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() == ID))
			{
				czyMogeJechac = true;
			}
		}



		

	}
	if (odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)////////////////////////////////////////////////////czy nie ma samochodu w�a�nie zje�dzaj�cego ze skrzyzowania
	{
		int i = 0;
		while (kolejnoscDrog[i] != idNastDrogi)
		{
			i++;
		}

		if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > i)
		{
			for (int j = i; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); j++)
			{
				if (idDrogi != kolejnoscDrog[j])
				{
					if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[kolejnoscDrog[j]]->getIdSk(0))
					{
						for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(0).size(); k++)
						{
							if (kolejnoscDrog[j] == idNastDrogi)
							{
								if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 40)
								{
									czyMogeJechac = false;
								}
							}
							else
							{
								if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 25)
								{
									czyMogeJechac = false;
								}
							}

						}
					}
					else
					{
						for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(1).size(); k++)
						{
							if (kolejnoscDrog[j] == idNastDrogi)
							{
								if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 40)
								{
									czyMogeJechac = false;
								}
							}
							else
							{
								if (pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 25)
								{
									czyMogeJechac = false;
								}
							}

						}
					}
				}
			}
		}
	}


	if (licznikCzekania > cierpliwosc && (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() == -1) && czyMogeJechac)
	{
		skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->setBufor(ID);
	}

	if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() == ID && !czyMogeJechac)
	{
		skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->setBufor(-1);
		licznikCzekania = 0;
	}

	if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() != ID && skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() != -1 && odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)
	{
		czyMogeJechac = false;
	}

	if (skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getBufor() == ID && odleglosc > 30)
	{
		skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->setBufor(-1);
	}

	return czyMogeJechac;
}