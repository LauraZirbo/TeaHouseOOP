#pragma once
#include <string>
#include "Tea.h"

class BlackTea : public Tea
{
private:
	std::string ExtraAroma;
public:
	BlackTea();
	~BlackTea();
	std::string getExtraAroma();
	BlackTea(std::string ExtraAroma);
	std::string toString();
	std::string toCSV();
};

