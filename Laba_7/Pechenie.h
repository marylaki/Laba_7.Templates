#pragma once
#include <string>

using namespace std;

class Pechenie 
{
	int cost;
	string tip;
public:
	void setCost(int);
	int getCost();
	void setTip(string);
	string getTip();
	Pechenie();
	Pechenie(int, string);
	~Pechenie();
	friend istream& operator>>(istream& ist, Pechenie & pech)
	{
		cout << "Введите цену :";
		ist >> pech.cost;
		cout << "Введите тип :";
		ist >> pech.tip;
		return ist;
	}
	friend ostream& operator<<(ostream& ost, Pechenie & pech)
	{
		ost << pech.cost << "-" << pech.tip;
		return ost;
	}
	void operator=(int i)
	{
		if (i < 0) i = 1 + rand() % 16;
		cost = i;
		
	}
	void operator+=(double i)
	{
		switch (rand() % 8)
		{
		case 1:tip = "Песочное"; break;
		case 2:tip = "Овсяное"; break;
		case 3:tip = "Сахарное"; break;
		case 4:tip = "Шоколадное"; break;
		case 5:tip = "Cлоеное"; break;
		case 6:tip = "Бисквитное"; break;
		case 7:tip = "Сдобное"; break;
		default: tip = "Вкусное"; break;
		}
	}
	Pechenie operator+(Pechenie& p)
	{
		Pechenie sum;
		sum.cost = cost + p.cost;
		sum.tip = tip + "+" + p.tip;
		return sum;
	}
	double operator*(double p)
	{
		return (cost*p);
	}
	bool operator>(Pechenie& p)
	{
		return (this->cost > p.cost);
	}
};