#include "BlackTea.h"
#include <string>
BlackTea::BlackTea()
{
	this->ExtraAroma = "None";
}

BlackTea::~BlackTea()
{
}

std::string BlackTea::getExtraAroma()
{
	return this->ExtraAroma;
}

BlackTea::BlackTea(std::string ExtraAroma)
{
	this->ExtraAroma = ExtraAroma;
}

std::string BlackTea::toString()
{
	return Tea::toString() + "Aroma: " + this->ExtraAroma + ".\n";
}

std::string BlackTea::toCSV()
{
	return Tea::toCSV() + this->ExtraAroma + "\n";
}

