#include "Tea.h"
#include <string>
Tea::Tea()
{
    this->caffeine = 0;
    this->cookingTime = 0;
    this->identifier = 0;
    this->type = "-";
    this->price = 0;
}

Tea::Tea(int identifier, std::string type, int caffenine, int cookingTime, float price)
{
    this->identifier = identifier;
    this->type = type;
    this->caffeine = caffeine;
    this->cookingTime = cookingTime;
    this->price = price;
}

Tea::~Tea()
{
}

int Tea::getId()
{
    return this->identifier;
}

void Tea::setId(int id)
{
    if (id < 0)
        throw std::exception::exception("The id must be a positive number\n");
    this->identifier = id;
}

std::string Tea::getType()
{
    return this->type;
}

void Tea::setType(std::string t)
{
    this->type = t;
}


int Tea::getCaffeine()
{
    return this->caffeine;
}

void Tea::setCaffeine(int c)
{
    this->caffeine = c;
}

int Tea::getcookingTime()
{
    return this->cookingTime;
}

void Tea::setCookingTime(int ct)
{
    this->cookingTime = ct;
}

float Tea::getPrice()
{
    return this->price;
}

void Tea::setPrice(float price)
{
    this->price = price;
}

std::string Tea::toString()
{
    return std::to_string(this->identifier) + ": " + this->type + " tea, caffeine: " + std::to_string(this->caffeine) + " gr, cooking time: " + std::to_string(this->cookingTime)+" minutes, price: " + std::to_string(this->price) + " ";
}

std::string Tea::toCSV()
{
    return std::to_string(this->identifier) + ", " + this->type + ", " + std::to_string(this->caffeine) + ", " + std::to_string(this->cookingTime) + ", " + std::to_string(this->price) + " , ";
}
