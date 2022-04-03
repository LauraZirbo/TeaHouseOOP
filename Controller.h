#pragma once
#include <string>
#include <vector>
#include "Repository.h"
#include "BlackTea.h"
#include "FruitTea.h"
#include "GreenTea.h"
#include <stack>;

class Controller
{
private:
	Repository repo;
	///std::stack<std::pair<int, Tea*>> undostack;
public:
	Controller();
	~Controller();
	/// Returns all the elements in the data, that is, al the teas in the inventory
	std::vector<Tea*> getAll() const;
	/// Adds a black tea to the inventory. The separation of teas whan it comes to adding them is done so that each privet object of the subclass be added apropriately
	/// Raises exception if the caffeine content is not inbetween the correct boundies for the tea or if the id is already found in the inventory
	void addBlackTea(int identifier, std::string type, int caffeine, int cookingTime, float price, std::string ExtraAroma);
	/// Adds a fruit tea to the inventory. Raises exception if the caffeine content is not inbetween the correct boundies for the tea or if the id is already found in the inventory
	void addFruitTea(int identifier, std::string type, int caffeine, int cookingTime, float price, int nrFr, std::vector <std::string> Fruits);
	/// Adds a green tea to the inventory. Raises exception if the caffeine content is not inbetween the correct boundies for the tea or if the id is already found in the inventory
	void addGreenTea(int identifier, std::string type, int caffeine, int cookingTime, float price, std::string ExtraAroma);
	/// Returns the removeById function from the repository where it has been implemented
	void removeById(int id);
	/// Return the pair found by the searchById function from the repository
	std::pair<Tea*,int> searchById(int id);
	/// Returns the vector returned by the filterByTipe funtion from the repository
	std::vector<Tea*> filterByType(std::string type);
	/// Returns the vector found by the filterLessCaffeine function from the repository
	std::vector<Tea*> filterLessCaffeine(int c);
	/// Undoes the last operation which changes the data inventory (add, remone)
	void undo(std::vector<int>& op, std::vector<std::pair<Tea*, int>>& fd, std::vector<int>& op2, std::vector<std::pair<Tea*, int>>& fd2, std::vector<int>& ids);
	/// Redoes the last operation which changes the data inventory (add, remone)
	void redo(std::vector<int>& op, std::vector<std::pair<Tea*, int>>& fd, std::vector<int>& op2, std::vector<std::pair<Tea*, int>>& fd2, std::vector<int>& ids);
	/// Loads a whole invetory from a csv file 
	void loadFromCSV();
	/// Saves the data of the teas that we have to a csv file
	void saveToCSV();
};

