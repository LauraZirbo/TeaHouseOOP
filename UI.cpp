#include "UI.h"
#include <iostream>
using namespace std;
#include <string>
#include <vector>

/// These are all the options that are availabele to a user to use
void UI::showMenu()
{
	cout << "\t1  - SHOW ALL TEAS \n";
	cout << "\t2  - ADD TEA\n";
	cout << "\t3  - REMOVE TEA BY ID\n";
	cout << "\t4  - SEARCH BY ID\n";
	cout << "\t5  - FILTER TEAS BY TYPE\n";
	cout << "\t6  - FILTER TEAS THAT HAVE LESSER COFFEINE THAN A GIVEN VALUE\n";
	cout << "\t7  - UNDO THE LAST COMMAND WHICH CHANGED THE DATABASE\n";
	cout << "\t8  - REDO WHAT HAS BEEN UNDONE\n";
	cout << "\t9  - LOAD FROM A CSV FILE\n";
	cout << "\t10 - SAVE TO A CSV FILE\n";
	cout << "\t0  - EXIT\n";

}

UI::UI()
{
}

UI::~UI()
{
}


///  The main part of the UI that that enanbles the user to operate the commands
void UI::run()
{
	this->showMenu();
	int op;
	std::vector<int> options;
	std::vector<int> ids;
	std::vector<int> options2;
	std::vector<std::pair<Tea*,int>> deleted2;
	std::vector<std::pair<Tea*,int>> deleted;
	while (1)
	{
		cout << "YOUR OPTION: ";
		cin >> op;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "The variable must be an integer\n";
		}
		else
			break;
	}
	cout << endl;
	while (op != 0)
	{
		if (op == 1)
		{
			std::vector<Tea*> allTeas = this->ctrl.getAll();
			if (allTeas.size() == 0)
				cout << "There are no teas in the shop\n";
			for (int i = 0; i < allTeas.size(); i++)
				cout << allTeas[i]->toString() << endl;
		}
		if (op == 2)
		{
				int l, c, ct, id; float p;
				cout << "Choose from:\n1.Black Tea\n2.Fruit Tea\n3.Green Tea\n";
				try
				{
					cin >> l;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						throw 1;
					}
					cout << "The cooking time: \n";
					cin >> ct;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						throw 1;
					}
					cout << "The tea identifier: \n";
					cin >> id;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						throw 1;
					}

					cout << "Price: \n";
					cin >> p;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						throw 'a';
					}
				}
				catch (int)
				{
					cout << "The value must be an integer\n";
				}
				catch (char)
				{
					cout << "The value must be a real number\n";
				}
				if (l == 1)
				{

					try
					{
						cout << "Black tea caffeine content has to be between 40 - 50 mg\nThe caffeine content: ";
						cin >> c;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							throw (c);
						}
						string ea, t;
						cout << "Extra aroma:\n";
						cin >> ea;
						t = "Black";
						int s = this->ctrl.getAll().size();
						this->ctrl.addBlackTea(id, t, c, ct, p, ea);
						if(this->ctrl.getAll().size() == s+1)
							options.push_back(op);
					}
					catch (...)
					{
						cout << "The variable must be a real number\n";
					}

				}
				if (l == 2)
				{
					try
					{
						cout << "Fruit tea caffeine content is always 0 mg\n";
						c = 0;
						int nr;
						cout << "Number of fruits in tea:\n";
						cin >> nr;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							throw (nr);
						}
						string t = "Fruit";
						string fr;
						vector<string> fruits;
						cout << "List of fruits:\n";
						for (int i = 0; i < nr; i++)
						{
							cin >> fr;
							fruits.push_back(fr);
						}
						int s = this->ctrl.getAll().size();
						this->ctrl.addFruitTea(id, t, c, ct, p, nr, fruits);
						this->ctrl.addFruitTea(id, t, c, ct, p, nr, fruits);
						if (this->ctrl.getAll().size() == s + 1)
							options.push_back(op);
					}
					catch (...)
					{
						cout << "The variable must be a real number\n";
					}
				}
				if (l == 3)
				{
					try
					{
						cout << "\tGreen tea caffeine content has to be between 20 - 40 mg\nThe caffeine content: ";
						cin >> c;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							throw (c);
						}
						string ea, t;
						cout << "Extra aroma:\n";
						cin >> ea;
						t = "Green";
						int s = this->ctrl.getAll().size();
						this->ctrl.addGreenTea(id, t, c, ct, p, ea);
						if (this->ctrl.getAll().size() == s + 1)
							options.push_back(op);
					}
					catch (...)
					{
						cout << "The variable must be a real number\n";
					}
				}
		
		}
		if (op == 3)
		{
			int id;
			try
			{
				cout << "Give id of the tea which is to be removed: ";
				cin >> id;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw(id);
				}
				std::pair<Tea*, int> r;
				r.second = this->ctrl.searchById(id).second;
				std::vector<Tea*> allTeas = this->ctrl.getAll();
				if (dynamic_cast<BlackTea*>(allTeas[r.second]) != nullptr)
				{
					BlackTea* t = dynamic_cast<BlackTea*>(allTeas[r.second]);
					r.first = new BlackTea(t->getExtraAroma());
					r.first->setCaffeine(t->getCaffeine());
					r.first->setCookingTime(t->getcookingTime());
					r.first->setId(t->getId());
					r.first->setPrice(t->getPrice());
					r.first->setType(t->getType());

				}
				else
				{
					if (dynamic_cast<GreenTea*>(allTeas[r.second]) != nullptr)
					{
						GreenTea* t = dynamic_cast<GreenTea*>(allTeas[r.second]);
						r.first = new GreenTea(t->getExtraAroma());
						r.first->setCaffeine(t->getCaffeine());
						r.first->setCookingTime(t->getcookingTime());
						r.first->setId(t->getId());
						r.first->setPrice(t->getPrice());
						r.first->setType(t->getType());
					}
					else
					{
						if (dynamic_cast<FruitTea*>(allTeas[r.second]) != nullptr)
						{
							FruitTea* t = dynamic_cast<FruitTea*>(allTeas[r.second]);
							r.first = new FruitTea(t->getnrFruits(), t->getFruits());
							r.first->setCaffeine(t->getCaffeine());
							r.first->setCookingTime(t->getcookingTime());
							r.first->setId(t->getId());
							r.first->setPrice(t->getPrice());
							r.first->setType(t->getType());
						}

					}
				}
				deleted.push_back(r);
				int s = this->ctrl.getAll().size();
				this->ctrl.removeById(id);
				if (this->ctrl.getAll().size() == s - 1)
					options.push_back(op);
				else
					cout << "There is no tea with this id\n";
			}
			catch (...)
			{
				cout<< "The variable must be an integer\n";
			}

		}
		if (op == 4)
		{
			std::pair<Tea*, int> t1;
			int id;
			try
			{
				cout << "Give id of the tea you want to see";
				cin >> id;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw (1);
				}
				t1 = this->ctrl.searchById(id);
				if (t1.second == -1)
					throw('a');
				cout << t1.first->toString() << endl;
			}
			catch (int)
			{
				cout << "The variable must be an integer\n";
			}
			catch (char)
			{
				cout << "There is no tea with this id in our inventory\n";
			}
		}
		if (op == 5)
		{
			string t;
			cout << "Give type of teas that you want (Black/Fruit/Green): \n";
			cin >> t;
			if (t[0] >= 'a' && t[0] <= 'z')
				t[0] = t[0] - 32;
			for (int i = 1; i < t.size(); i++)
			{
				if (t[i] >= 'A' && t[i] <= 'Z')
					t[i] = t[i] + 32;
			}
			std::vector<Tea*> filteredTeas = this->ctrl.filterByType(t);
			cout << "All the " + t + " teas are: \n";
			for (int i = 0; i < filteredTeas.size(); i++)
				cout << filteredTeas[i]->toString() << endl;
		}
		if (op == 6)
		{
			int c;
			try
			{
				cout << "Give the maximum nr of gr of caffeine that you want:\n";
				cin >> c;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw (c);
				}
			}
			catch(...)
			{
				cout << "The variable must be an integer\n";
			}
			std::vector<Tea*> filteredTeas = this->ctrl.filterLessCaffeine(c);
			cout << "All the teas with less than " + to_string(c) + " gr of caffeine are: \n";
			for (int i = 0; i < filteredTeas.size(); i++)
				cout << filteredTeas[i]->toString() << endl;
		}
		if (op == 7)
		{
			this->ctrl.undo(options, deleted, options2, deleted2, ids);
			std::vector<Tea*> allTeas = this->ctrl.getAll();
			for (int i = 0; i < allTeas.size(); i++)
				cout << allTeas[i]->toString() << endl;

		}
		if (op == 8)
		{
			this->ctrl.redo(options, deleted, options2, deleted2, ids);
			std::vector<Tea*> allTeas = this->ctrl.getAll();
			for (int i = 0; i < allTeas.size(); i++)
				cout << allTeas[i]->toString() << endl;
		}
		if (op == 9)
		{
			this->ctrl.loadFromCSV();
		}
		if (op == 10)
		{
			this->ctrl.saveToCSV();
		}
		this->showMenu();
		while (1)
		{
			cout << "YOUR OPTION: ";
			cin >> op;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "The variable must be an integer\n";
			}
			else
				break;
		}
	}
}
