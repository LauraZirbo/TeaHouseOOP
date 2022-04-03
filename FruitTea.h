#pragma once
#include "Tea.h"
#include <string>
#include <vector>
class FruitTea: public Tea
{
private:
	int nrFruits;
	std::vector<std::string> Fruits;
public:
	FruitTea();
	~FruitTea();
	void setnrFruits(int n) { this->nrFruits = n; };
	int getnrFruits() { return this->nrFruits; };
	void setFruits(std::vector<std::string> Fruits) { this->Fruits = Fruits; };
	std::vector<std::string> getFruits() { return this->Fruits; };
	FruitTea(int nrFruits, std::vector<std::string> Fruits);
	std::string convFruits();
	std::string toString();
	std::string toCSV();
};

