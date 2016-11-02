#include "stdafx.h"
#include <iostream>
#include "Pechenie.h"
void Pechenie::setCost(int c)
{
	cost = c;
}

int Pechenie::getCost()
{
	std::cout << "Цена " << cost << " коп.";
	return cost;

}

void Pechenie::setTip(string t)
{
	tip = t;
}

string Pechenie::getTip()
{
	std::cout << "Тип печенья: " << tip << std::endl;
	return tip;
}

Pechenie::Pechenie()
{
	
}
Pechenie::Pechenie(int c,string s)
{
	setCost(c);
	setTip(s);
}

Pechenie::~Pechenie()
{
	
}