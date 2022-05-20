#include "CPojazd.h"

CPojazd::CPojazd(int id, vector <CSkrzyzowanie*> skrzyzowania, CDroga* droga, int odl, int kier)
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
	boPojazdyNaSkrzyzowaniu = false;
	cierpliwosc = 5 + rand() % 10;
}

int CPojazd::getID()
{
	return ID;
}

int CPojazd::getX()
{
	return x;
}

int CPojazd::getY()
{
	return y;
}

int CPojazd::getIDDrogi()
{
	return idDrogi;
}

int CPojazd::getOdleglosc()
{
	return odleglosc;
}

double CPojazd::getKat()
{
	return kat;
}

void CPojazd::odswierz(vector<CDroga*> drogi, vector<CSkrzyzowanie*> skrzyzowania, vector<CPojazd*> pojazdy, double czestotliwosc)
{
	if (kierunek == 0)
		nieKierunek = 1;
	else
		nieKierunek = 0;
	czyMogeJechac = true;



	if (!jestNastDroga)
	{
		do
		{
			idNastDrogi = skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[rand() % skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size()];
		} while (idNastDrogi == idDrogi && skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() != 1);
		jestNastDroga = true;
		odswierzKolejnoscDrog(drogi, skrzyzowania);
	}


	if (odleglosc < drogi[idDrogi]->getDlugosc())
	{

		if (drogi[idDrogi]->getPojazdy(kierunek).size() != 1)///////////////////////////samochod przed tob¹
		{
			for (int j = 0; j < drogi[idDrogi]->getPojazdy(kierunek).size(); j++)
			{
				if (pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getID() != ID && pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getOdleglosc() < odleglosc + 25 && pojazdy[drogi[idDrogi]->getPojazdy(kierunek)[j]]->getOdleglosc() > odleglosc)
				{
					czyMogeJechac = false;
				}
			}
		}





		if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getSwiatla().size() != 0 && odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)/////////////////////œwiatla
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
										if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 40)
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
										if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 40)
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
			while (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[z] != idDrogi)//szukam nr drogi który odpowiada za drogê po której jadê
			{
				z++;
			}
			bool pierwszenstwo = false;//zak³adam ¿e nie mam pierwszenstwa chyba ¿e któryœ ze znaków mówi inaczej
			for (int i = 0; i < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getZnaki()[z].size(); i++)
			{
				if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getZnaki()[z][i]->getTyp() == 'P')
				{
					pierwszenstwo = true;
				}
			}

			if (pierwszenstwo)																									//jeœli to droga z pierwszenstwem
			{
				int i = 0;
				while (kolejnoscDrog[i] != idNastDrogi)
				{
					i++;
				}
				i++;																											//lecê od lewej do prawej a¿ do drogi gdzie chcê jechaæ i jeszcze o jedn¹ dalej
				if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() > i)								//je¿eli nie przesz³em przez wszystkie drogi, tzn. s¹ jakieœ drogi jeszcze do sprawdzenia
				{
					for (int j = i; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); j++)			//iteracja po pozosta³ych drogach
					{
						if (idDrogi != kolejnoscDrog[j])																		//jeœli to nie jest droga po której jadê
						{
							int l = 0;
							while (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[l] != kolejnoscDrog[j])		// szukam wartoœci która odpowiada numerowi kolejnej drogi w skrzyzowaniu 
							{
								l++;
							}
							for (int m = 0; m < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getZnaki()[l].size(); m++)	//iterujê po wszystkich znakach na danej drodze
							{
								if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getZnaki()[l][m]->getTyp() == 'P')		//je¿eli jest znak droga z pierwszenstwem
								{
									if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[kolejnoscDrog[j]]->getIdSk(0))			//je¿eli to jest 0 skrzyzowanie danej drogi
									{

										for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(1).size(); k++)					//iteruje po liœcie pojazdów nr1.
										{
											if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 40)//je¿eli na danej drodze jest pojazd bli¿ej ni¿ 40 jednostek
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
											if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 40)
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
											if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 40)
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
											if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 40)
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
										if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(1)[k]]->getOdleglosc() < 40)
										{
											czyMogeJechac = false;
										}
									}
								}
								else
								{
									for (int k = 0; k < drogi[kolejnoscDrog[j]]->getPojazdy(0).size(); k++)
									{
										if (drogi[kolejnoscDrog[j]]->getDlugosc() - pojazdy[drogi[kolejnoscDrog[j]]->getPojazdy(0)[k]]->getOdleglosc() < 40)
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

				if (licznikCzekania > cierpliwosc && (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() == 0 || skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() == ID))
				{
					czyMogeJechac = true;
				}
			}
			

				
			////////////////////////////////////////////////////czy nie ma samochodu w³aœnie zje¿dzaj¹cego ze skrzyzowania
			
		}
		if (odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)
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
		

		if (licznikCzekania > cierpliwosc && (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() == 0) && czyMogeJechac)
		{
			skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->setBufor(ID);
		}

		if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() == ID && !czyMogeJechac)
		{
			skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->setBufor(0);
			licznikCzekania = 0;
		}

		if (skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() != ID && skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getBufor() != 0 && odleglosc > drogi[idDrogi]->getDlugosc() - 30 && odleglosc < drogi[idDrogi]->getDlugosc() - 20)
		{
			czyMogeJechac = false;
		}
		
		if (skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getBufor() == ID && odleglosc > 30)
		{
			skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->setBufor(0);	
		}

		if (czyMogeJechac)
		{
			odleglosc += predkosc / czestotliwosc;
			if (trybSkretu)
			{
				odlSkretu += predkosc / czestotliwosc;
			}
		}

		if (!czyGotowyDoSkretu )
		{
			katPoczatkowy = kat;
			int i = 0;
			while (kolejnoscDrog[i] != idNastDrogi)
			{
				i++;
			}
			katNastDrogi = katy[i];

			if (katNastDrogi > 180)
			{
				kierunekSkretu = 1;
				odlegloscRozpoczeciaSkretu = (promien - 5.0) / tan(((360.0 - katNastDrogi) * (3.1416 / 180.0)) / 2.0);
				sx = double(skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getX()) + cos(katPoczatkowy * (3.1416 / 180.0)) * (drogi[idDrogi]->getDlugosc() - odlegloscRozpoczeciaSkretu) - sin(katPoczatkowy * (3.1416 / 180.0)) * (promien - 5.0);
				sy = double(skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getY()) + sin(katPoczatkowy * (3.1416 / 180.0)) * (drogi[idDrogi]->getDlugosc() - odlegloscRozpoczeciaSkretu) + cos(katPoczatkowy * (3.1416 / 180.0)) * (promien - 5.0);
				
			}
			else
			{
				kierunekSkretu = 0;
				odlegloscRozpoczeciaSkretu = (promien + 5.0) / tan((katNastDrogi / 2.0) * (3.1416 / 180.0));
				sx = double(skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getX()) + cos(katPoczatkowy * (3.1416 / 180.0)) * (drogi[idDrogi]->getDlugosc() - odlegloscRozpoczeciaSkretu) + sin(katPoczatkowy * (3.1416 / 180.0)) * (promien + 5.0);
				sy = double(skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getY()) + sin(katPoczatkowy * (3.1416 / 180.0)) * (drogi[idDrogi]->getDlugosc() - odlegloscRozpoczeciaSkretu) - cos(katPoczatkowy * (3.1416 / 180.0)) * (promien + 5.0);
			}
			//cout << "//////////" << kat  << "  " <<  katPoczatkowy<< endl;
			odlSkretu = 0;
			czyGotowyDoSkretu = 1;
			
		}

		if (odleglosc > drogi[idDrogi]->getDlugosc() - odlegloscRozpoczeciaSkretu && czyGotowyDoSkretu )
		{
			trybSkretu = true;
		}
		if (wlasnieZmienionoDroge && katNastDrogi > 178 && katNastDrogi < 182)
		{
			trybSkretu = false;
			czyGotowyDoSkretu = false;
		}


		if (odlSkretu > 2.0 * odlegloscRozpoczeciaSkretu)
		{
			trybSkretu = false;
			czyGotowyDoSkretu = false;
			if (kierunek == 0)
			{
				kat = drogi[idDrogi]->getKat();
			}
			else
			{
				kat = drogi[idDrogi]->getKat() + 180.0;
			}
		}



		if (trybSkretu)
		{

			kat = katPoczatkowy - ((180.0 - katNastDrogi) * odlSkretu) / (2.0 * odlegloscRozpoczeciaSkretu);
			
			//cout << kat <<"   " << katPoczatkowy << endl;

		}
		else
		{
			if (kierunek == 0)
			{
				x = skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getX() + drogi[idDrogi]->getCosinus() * odleglosc - drogi[idDrogi]->getSinus() * 5.0;
				y = skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getY() + drogi[idDrogi]->getSinus() * odleglosc + drogi[idDrogi]->getCosinus() * 5.0;
			}
			else
			{
				x = skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getX() - drogi[idDrogi]->getCosinus() * odleglosc + drogi[idDrogi]->getSinus() * 5.0;
				y = skrzyzowania[drogi[idDrogi]->getIdSk(kierunek)]->getY() - drogi[idDrogi]->getSinus() * odleglosc - drogi[idDrogi]->getCosinus() * 5.0;
			}
		}
		
		wlasnieZmienionoDroge = false;
	}
	else
	{

		if (jestNastDroga)
		{

			odleglosc = 0;
			drogi[idDrogi]->usunPojazd(ID, kierunek);

			if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[idNastDrogi]->getIdSk(0))
				kierunek = 0;
			else
				kierunek = 1;

			idDrogi = idNastDrogi;

			//if (kierunek == 0)
			//{
			//	kat = drogi[idDrogi]->getKat();
			//}
			//else
			//{
			//	kat = drogi[idDrogi]->getKat() + 180.0;
			//}
			drogi[idDrogi]->dodajPojazd(ID, kierunek);
		}
		jestNastDroga = false;
		wlasnieZmienionoDroge = true;
		licznikCzekania = 0;
		
	}

	notify();
}

double CPojazd::getPromien()
{
	return promien;
}

bool CPojazd::getKierunekSkretu()
{
	return kierunekSkretu;
}

double CPojazd::getSx()
{
	return sx;
}

double CPojazd::getSy()
{
	return sy;
}

bool CPojazd::czyStoi()
{
	return !czyMogeJechac;
}

void CPojazd::odswierzKolejnoscDrog(vector<CDroga*> drogi, vector<CSkrzyzowanie*> skrzyzowania)
{
	delete[] kolejnoscDrog;
	delete[] katy;
	kolejnoscDrog = new int[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size()];
	katy = new double[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size()];

	double hKat;
	for (int i = 0; i < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); i++)
	{
		if (drogi[idDrogi]->getIdSk(nieKierunek) == drogi[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i]]->getIdSk(0))
			hKat = drogi[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i]]->getKat();
		else
			hKat = drogi[skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i]]->getKat() + 180;

		if (kierunek == 0)
		{
			katy[i] = drogi[idDrogi]->getKat() + 180;
			
		}
		else
		{
			katy[i] = drogi[idDrogi]->getKat();
		}

		//katy[i] = kat + 180;//daje k¹t wzglêdem danej drogi 0 360 stopni
		while (katy[i] >= 360)
			katy[i] -= 360.0;
		katy[i] = hKat + 360 - katy[i];
		while (katy[i] >= 360)
			katy[i] -= 360.0;

		kolejnoscDrog[i] = skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi()[i];
	}
	for (int i = 0; i < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); i++)//sortowanie babelkowe
	{
		for (int j = 0; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size() - 1; j++)
		{
			if (katy[j] > katy[j + 1])
			{
				swap(katy[j], katy[j + 1]);
				swap(kolejnoscDrog[j], kolejnoscDrog[j + 1]);
			}
		}
	}
	cout << "--------------" << kat << endl;
	for (int j = 0; j < skrzyzowania[drogi[idDrogi]->getIdSk(nieKierunek)]->getIdDrogi().size(); j++)///wyswietlenie
	{
		cout << kolejnoscDrog[j] << "  " << katy[j] << endl;
	}
}



double CPojazd::getKatNastDrogi()
{
	return katNastDrogi;
}

void CPojazd::attach(CObserwator* obs)
{
	obserwatorzy.push_back(obs);
}

void CPojazd::detach(CObserwator*)
{

}

void CPojazd::notify()
{
	for (int i = 0; i < obserwatorzy.size(); i++)
	{
		if (trybSkretu)
		{
			obserwatorzy[i]->update(1);
		}
		else
		{
			obserwatorzy[i]->update(0);
		}
	}
}