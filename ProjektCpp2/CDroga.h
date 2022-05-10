#pragma once
class CDroga
{
private:
	int ID;
	int id_Sk[2];
	int dlugosc;
public:
	CDroga(int id, int sk1, int sk2, int dlugosc);
	int getID();
	int getDlugosc();
};

