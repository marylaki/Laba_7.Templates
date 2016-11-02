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
		cout << "������� ���� :";
		ist >> pech.cost;
		cout << "������� ��� :";
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
		case 1:tip = "��������"; break;
		case 2:tip = "�������"; break;
		case 3:tip = "��������"; break;
		case 4:tip = "����������"; break;
		case 5:tip = "C������"; break;
		case 6:tip = "����������"; break;
		case 7:tip = "�������"; break;
		default: tip = "�������"; break;
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