#pragma once
#include <vector>
#include <iostream>
using namespace std;
class CSkrzyzowanie
{
protected:
	int ID;
	int x;
	int y;
	vector <int> id_dorogi;
	int typ;
public:
	int getID();
	int getX();
	int getY();
	void set(int, int, int,int);
	virtual void co() = 0;
	virtual void update(int, int) = 0;
	int getTyp();
	vector <int> getIdDrogi();
};

