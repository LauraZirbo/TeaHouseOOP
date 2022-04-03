#pragma once
#include <string>
class Tea
{
private:
	int identifier;
	std::string type;
	int caffeine;
	int cookingTime;
	float price;
public:
	Tea();
	Tea(int identifier, std::string type, int caffenine, int cookingTime, float price);
	~Tea();
	int getId();
	void setId(int id);
	std::string getType();
	void setType(std::string t);
	int getCaffeine();
	void setCaffeine(int c);
	int getcookingTime();
	void setCookingTime(int ct);
	float getPrice();
	void setPrice(float price);

	virtual std::string toString();
	virtual std::string toCSV();

};

