#pragma once
#include "Tea.h"
#include <vector>
class Repository
{
private:
	std::vector<Tea*> data;
public:
	Repository();
	~Repository();
	/// Retruns all of the elements in the data that we have
	std::vector<Tea*> getData() const;
	/// Adds a new tea to the inventory
	void add(Tea* newTea);
	/// Searches for the element with the gien id and returns it. If there is no such element than the function throws an exception
	void removeById(int id);
	/// Returns a pair formed by the Tea (if it is to be found) and the position at whcih it is found. This is also usefull for checking if the id is already in the inventory
	std::pair<Tea*,int> searchById(int id);
	/// Returns a copy of the data that has a certain type (All the Black/Fruit/Green teas)
	std::vector<Tea*> filterByType(std::string type);
	/// Returns a copy of the data whcih has the caffeine content smaller than a given number and theowsa an exeption if the given number is not positive
	std::vector<Tea*> filterLessCaffeine(int c);
	/// Undoes the last operation which changes the data inventory (add, remone)
	void undo(std::vector<int>& op, std::vector<std::pair<Tea*, int>>& fd, std::vector<int>& op2, std::vector<std::pair<Tea*, int>>& fd2, std::vector<int>& ids);
	/// Redoes the last operation which changes the data inventory (add, remone)
	void redo(std::vector<int>& op, std::vector<std::pair<Tea*, int>>& fd, std::vector<int>& op2, std::vector<std::pair<Tea*, int>>& fd2, std::vector<int>& ids);
	/// Loads a whole invetory from a csv file 
	void loadFromCSV(std::string file);
	/// Saves the data of the teas that we have to a csv file
	void saveToCSV(std::string file);
};

