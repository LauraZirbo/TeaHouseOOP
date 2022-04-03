#include "FruitTea.h"
#include <iostream>
FruitTea::FruitTea()
{
	this->nrFruits = 0;
	this->Fruits[0] = "None";
}

FruitTea::~FruitTea()
{
}

FruitTea::FruitTea(int nrFruits, std::vector<std::string> Fruits)
{
	this->nrFruits = nrFruits;
	for(int i =0 ;i< this->nrFruits;i++)
		this->Fruits.push_back(Fruits[i]);
}

std::string FruitTea::convFruits()
{
	std::string fr;
	if (this->nrFruits > 0)
	{
		fr = this->Fruits[0];
		for (int i = 0; i < this->nrFruits; i++)
		{
			fr = fr + ", " + this->Fruits[i];
		}
	}
	else
		fr = "None";
	return fr;
}


std::string FruitTea::toString()
{
	return Tea::toString() + "Fruits: " + convFruits() + ".\n";
}

std::string FruitTea::toCSV()
{
	return Tea::toCSV() + std::to_string(this->nrFruits) + ", " + convFruits() + "\n";
}
