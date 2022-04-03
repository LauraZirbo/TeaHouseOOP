#include "GreenTea.h"

GreenTea::GreenTea()
{	
	this->ExtraAroma = "None";
}

GreenTea::~GreenTea()
{
}

std::string GreenTea::getExtraAroma()
{
	return this->ExtraAroma;
}

GreenTea::GreenTea(std::string ExtraAroma)
{
	this->ExtraAroma = ExtraAroma;
}

std::string GreenTea::toString()
{
	return Tea::toString() + "Aroma: " + this->ExtraAroma + ".\n";
}

std::string GreenTea::toCSV()
{
	return Tea::toCSV() + this->ExtraAroma + "\n";
}
