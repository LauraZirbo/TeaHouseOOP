#include "Repository.h"
#include "BlackTea.h"
#include "GreenTea.h"
#include "FruitTea.h"
#include <iostream>
#include <fstream>
using namespace std;

Repository::Repository()
{
}

Repository::~Repository()
{
    for (int i = 0; i < this->data.size(); i++)
        delete this->data[i];
}

std::vector<Tea*> Repository::getData() const
{
    return data;
}

void Repository::add(Tea* newTea)
{
    this->data.push_back(newTea);
}

void Repository::removeById(int id)
{
    for (std::vector<Tea*>::iterator it = this->data.begin(); it != this->data.end(); it++)
    {
        if ((*it)->getId() == id)
        {
            Tea* item = (*it);
            this->data.erase(it);
            delete item;
            break;
        }
    }
}

std::pair<Tea*, int> Repository::searchById(int id)
{
    std::pair<Tea*, int> f;
    f.second = -1;
    for (int i = 0; i < this->data.size(); i++)
    {
        if (this->data[i]->getId() == id)
        {
            f.first = this->data[i];
            f.second = i;
            return f;
        }
    }
    return f;
}

std::vector<Tea*> Repository::filterByType(std::string type)
{
    std::vector<Tea*> filteredlist;
    try
    {
        if (type != "Black" && type != "Fruit" && type != "Green")
            throw (type);
        for (std::vector<Tea*>::iterator it = this->data.begin(); it != this->data.end(); it++)
        {
            if ((*it)->getType() == type)
            {
                Tea* item = (*it);
                filteredlist.push_back(item);
            }
        }
    }
    catch (...)
    {
        cout << "The type must be either black, green or fruit - it is not case sensitive \n";
    }
    return filteredlist;
}

std::vector<Tea*> Repository::filterLessCaffeine(int c)
{
    std::vector<Tea*> filteredlist;
    try
    {
        if (c < 0)
            throw (c);
        for (std::vector<Tea*>::iterator it = this->data.begin(); it != this->data.end(); it++)
        {
            if ((*it)->getCaffeine() < c)
            {
                Tea* item = (*it);
                filteredlist.push_back(item);
            }
        }
    }
    catch (...)
    {
        cout << "The caffeine must be greater or equal to 0\n";
    }
    return filteredlist;
}

void Repository::undo(std::vector<int> &op, std::vector<std::pair<Tea*, int>> &fd, std::vector<int> &op2,std::vector<std::pair<Tea*, int>>&fd2, std::vector <int>& ids)
{
    try
    {
        if (op.size() == 0)
            throw (op);
        int option = op[op.size() - 1];
        if (option == 2)
        {
            if (this->data.size() == 0)
                throw(this->data);
            op2.push_back(2);
            std::pair<Tea*, int> r;
            r.second = this->data.size() - 1;
            if (dynamic_cast<BlackTea*>(this->data[this->data.size() - 1]) != nullptr)
            {
                BlackTea* t = dynamic_cast<BlackTea*>(this->data[this->data.size() - 1]);
                r.first = new BlackTea(t->getExtraAroma());
                r.first->setCaffeine(t->getCaffeine());
                r.first->setCookingTime(t->getcookingTime());
                r.first->setId(t->getId());
                r.first->setPrice(t->getPrice());
                r.first->setType(t->getType());
                
            }
            else
            {
                if (dynamic_cast<GreenTea*>(this->data[this->data.size() - 1]) != nullptr)
                {
                    GreenTea* t = dynamic_cast<GreenTea*>(this->data[this->data.size() - 1]);
                    r.first = new GreenTea(t->getExtraAroma());
                    r.first->setCaffeine(t->getCaffeine());
                    r.first->setCookingTime(t->getcookingTime());
                    r.first->setId(t->getId());
                    r.first->setPrice(t->getPrice());
                    r.first->setType(t->getType());
                }
                else
                {
                    if (dynamic_cast<FruitTea*>(this->data[this->data.size() - 1]) != nullptr)
                    {
                        FruitTea* t = dynamic_cast<FruitTea*>(this->data[this->data.size() - 1]);
                        r.first = new FruitTea(t->getnrFruits(), t->getFruits());
                        r.first->setCaffeine(t->getCaffeine());
                        r.first->setCookingTime(t->getcookingTime());
                        r.first->setId(t->getId());
                        r.first->setPrice(t->getPrice());
                        r.first->setType(t->getType());
                    }

                }
            }            
            int id = this->data[this->data.size() - 1]->getId();
            this->removeById(id);
            fd2.push_back(r);
            op.pop_back();
        }
        else
        {
            if (fd.size() == 0)
                throw(fd);
            op2.push_back(3);
            int pos = fd[fd.size() - 1].second;
            Tea* t = fd[fd.size() - 1].first;
            ids.push_back(t->getId());
            this->data.insert(data.begin() + pos, t);
            op.pop_back();
        }
    }
    catch (...)
    {
        cout << "There is nothing do be undone\n";
    }
    
}

void Repository::redo(std::vector<int> &op, std::vector<std::pair<Tea*, int>> &fd, std::vector<int> &op2,std::vector<std::pair<Tea*, int>>&fd2, std::vector<int>& ids)
{   
    try
    {
        if (op2.size() == 0)
            throw (op2);
        int option = op2[op2.size() - 1];
        if (option == 2)
        {
            op.push_back(2);
            int pos = fd2[fd2.size() - 1].second;
            Tea* t = fd2[fd2.size() - 1].first;
            this->data.insert(data.begin() + pos, t);
            op2.pop_back();

        }
        if (option == 3)
        {
            op.push_back(3);
            if (ids.size() == 0)
                throw(ids);
            int id = ids[ids.size() - 1];
            std::pair<Tea*, int> r;
            r.second = this->searchById(id).second;
            if (dynamic_cast<BlackTea*>(this->data[r.second]) != nullptr)
            {
                BlackTea* t = dynamic_cast<BlackTea*>(this->data[r.second]);
                r.first = new BlackTea(t->getExtraAroma());
                r.first->setCaffeine(t->getCaffeine());
                r.first->setCookingTime(t->getcookingTime());
                r.first->setId(t->getId());
                r.first->setPrice(t->getPrice());
                r.first->setType(t->getType());

            }
            else
            {
                if (dynamic_cast<GreenTea*>(this->data[r.second]) != nullptr)
                {
                    GreenTea* t = dynamic_cast<GreenTea*>(this->data[r.second]);
                    r.first = new GreenTea(t->getExtraAroma());
                    r.first->setCaffeine(t->getCaffeine());
                    r.first->setCookingTime(t->getcookingTime());
                    r.first->setId(t->getId());
                    r.first->setPrice(t->getPrice());
                    r.first->setType(t->getType());
                }
                else
                {
                    if (dynamic_cast<FruitTea*>(this->data[r.second]) != nullptr)
                    {
                        FruitTea* t = dynamic_cast<FruitTea*>(this->data[r.second]);
                        r.first = new FruitTea(t->getnrFruits(), t->getFruits());
                        r.first->setCaffeine(t->getCaffeine());
                        r.first->setCookingTime(t->getcookingTime());
                        r.first->setId(t->getId());
                        r.first->setPrice(t->getPrice());
                        r.first->setType(t->getType());
                    }

                }
            }
            fd.push_back(r);
            this->removeById(id);
            op2.pop_back();
        }
    }
    catch (...)
    {
        cout << "There is nothing to be redone\n";
    }
  
}

void Repository::loadFromCSV(std::string file)
{
    ifstream f;
    f.open(file);
    if (!f.is_open())
    {
        throw 1;
    }
    while (!f.eof())
    {
        int pos = 0;
        string d = ",";
        string line;
        while (getline(f, line))
        {
            pos = line.find(d);
            int id = stoi(line.substr(0,pos));
            line.erase(0, pos + 2);
            pos = line.find(d);
            string type = line.substr(0, pos);
            line = line.erase(0, pos + 2);
            pos = line.find(d);
            int caffeine = stoi(line.substr(0, pos));
            line.erase(0, pos + 2);
            pos = line.find(d);
            int cookingTime = stoi(line.substr(0, pos));
            line.erase(0, pos + 2);
            pos = line.find(d);
            float price = stof(line.substr(0, pos));
            line.erase(0, pos + 2);
            if (type == "Black")
            {
                pos = line.find(d);
                string ExtraAroma = line.substr(0, pos);
                line = line.erase(0, pos + 1);
                Tea* t = new BlackTea(ExtraAroma);
                t->setCaffeine(caffeine);
                t->setCookingTime(cookingTime);
                t->setId(id);
                t->setPrice(price);
                this->data.push_back(t);
            }
            if (type == "Green")
            {
                pos = line.find(d);
                string ExtraAroma = line.substr(0, pos);
                line = line.erase(0, pos + 1);
                Tea* t = new GreenTea(ExtraAroma);
                t->setCaffeine(caffeine);
                t->setCookingTime(cookingTime);
                t->setId(id);
                t->setPrice(price);
                this->data.push_back(t);
            }
            if (type == "Fruit")
            {
                pos = line.find(d);
                int nrFruits = stoi(line.substr(0, pos));
                line.erase(0, pos + 1);
                std::vector<std::string> Fruits;
                for (int i = 0; i < nrFruits; i++)
                {
                    pos = line.find(d);
                    string ExtraFruit = line.substr(0, pos);
                    line = line.erase(0, pos + 1);
                    Fruits.push_back(ExtraFruit);
                }
                Tea* t = new FruitTea(nrFruits, Fruits);
                t->setCaffeine(caffeine);
                t->setCookingTime(cookingTime);
                t->setId(id);
                t->setPrice(price);
                this->data.push_back(t);
            }
        }
    }
    f.close();
}

void Repository::saveToCSV(std::string file)
{
    ofstream g;
    g.open(file);
    for (int i = 0; i < this->data.size(); i++)
    {
        g<<this->data[i]->toCSV();
    }
    g.close();
}


