#pragma once
#include <string>
#include "Tea.h"
class GreenTea : public Tea
{
private:
	std::string ExtraAroma;
public:
	GreenTea();
	~GreenTea();
	std::string getExtraAroma();
	GreenTea(std::string ExtraAroma);
	std::string toString();
	std::string toCSV();
};

