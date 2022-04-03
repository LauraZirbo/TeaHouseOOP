#include "Controller.h"
#include <string>
#include <iostream>
using namespace std;
Controller::Controller()
{
}

Controller::~Controller()
{
}

std::vector<Tea*> Controller::getAll() const
{
	return this->repo.getData();
}

void Controller::addBlackTea(int identifier, std::string type, int caffeine, int cookingTime, float price, std::string ExtraAroma)
{
	int ok = 0;
	Tea* newTea = new BlackTea(ExtraAroma);
	try 
	{
		if (caffeine < 40 || caffeine>50)
			throw (caffeine);
		newTea->setCaffeine(caffeine);
	}
	catch(...)
	{
		cout << "The caffeine content must be between 40-50 mg in a black tea\n";
		ok = 1;
	}
	newTea->setCookingTime(cookingTime);
	try
	{
		std::pair<Tea*, int> t1;
		t1 = this->repo.searchById(identifier);
		if (t1.second != -1)
			throw (identifier);
		newTea->setId(identifier);
	}
	catch(...)
	{
		cout << "There is already a tea with this id. The id must be unique\n";
		ok = 1;
	}
	newTea->setType(type);
	newTea->setPrice(price);
	if (ok == 0)
		this->repo.add(newTea);
}

void Controller::addFruitTea(int identifier, std::string type, int caffeine, int cookingTime, float price, int nrFr, std::vector<std::string> Fruits)
{
	int ok = 0;
	Tea* newTea = new FruitTea(nrFr, Fruits);
	newTea->setCaffeine(caffeine);
	newTea->setCookingTime(cookingTime);
	try
	{
		std::pair<Tea*, int> t1;
		t1 = this->repo.searchById(identifier);
		if (t1.second != -1)
			throw (identifier);
		newTea->setId(identifier);
	}
	catch (...)
	{
		cout << "There is already a tea with this id. The id must be unique\n";
		ok = 1;
	}
	newTea->setType(type);
	newTea->setPrice(price);
	if(ok == 0)
		this->repo.add(newTea);
}

void Controller::addGreenTea(int identifier, std::string type, int caffeine, int cookingTime, float price, std::string ExtraAroma)
{
	int ok = 0;
	Tea* newTea = new GreenTea(ExtraAroma);
	try
	{
		if (caffeine < 20 || caffeine>40)
			throw (caffeine);
		newTea->setCaffeine(caffeine);
	}
	catch (...)
	{
		cout << "The caffeine content must be between 20-40 mg in a green tea\n";
		ok = 1;
	}
	newTea->setCookingTime(cookingTime);
	std::pair<Tea*, int> t1;
	t1 = this->repo.searchById(identifier);
	try
	{
		std::pair<Tea*, int> t1;
		t1 = this->repo.searchById(identifier);
		if (t1.second != -1)
			throw (identifier);
		newTea->setId(identifier);
	}
	catch (...)
	{
		cout << "There is already a tea with this id. The id must be unique\n";
		ok = 1;
	}
	newTea->setType(type);
	newTea->setPrice(price);
	if (ok == 0)
		this->repo.add(newTea);
}

void Controller::removeById(int id)
{	
	this->repo.removeById(id);
}

std::pair<Tea*,int> Controller::searchById(int id)
{
	return this->repo.searchById(id);
}

std::vector<Tea*> Controller::filterByType (std::string type)
{
	return this->repo.filterByType(type);
}

std::vector<Tea*> Controller::filterLessCaffeine(int c)
{
	return this->repo.filterLessCaffeine(c);
}

void Controller::undo(std::vector<int> &op, std::vector<std::pair<Tea*,int>> &fd, std::vector<int> &op2, std::vector<std::pair<Tea*,int>>&fd2, std::vector<int>& ids)
{

	return this->repo.undo(op,fd,op2,fd2,ids);
}

void Controller::redo(std::vector<int> &op, std::vector<std::pair<Tea*, int>> &fd, std::vector<int> &op2, std::vector<std::pair<Tea*, int>> &fd2, std::vector<int>& ids)
{
	this->repo.redo(op, fd, op2, fd2,ids);
}

void Controller::loadFromCSV()
{
	std::string file = "TeaLoad.csv";
	this->repo.loadFromCSV(file);
}

void Controller::saveToCSV()
{
	std::string file = "TeaSave.csv";
	this->repo.saveToCSV(file);
}



