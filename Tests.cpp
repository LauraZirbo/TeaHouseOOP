#include "Tests.h"
#include "Tea.h"
#include <assert.h>
#include "Controller.h"
using namespace std;

void testAll()
{
	Controller ctrl;
	std::vector<Tea*> allTeas;
	assert(allTeas.size() == 0);
	ctrl.addBlackTea(123, "Black", 43, 4, 6.2, "Orange");
	allTeas = ctrl.getAll();
	assert(allTeas.size() == 1);
	ctrl.addFruitTea(123, "Fruit", 0, 5, 4, 3, { "Aplle","Berry","BlackCurrent" });
	allTeas = ctrl.getAll();
	assert(allTeas.size() == 1);
	ctrl.addBlackTea(13, "Black", 33, 4, 6.2, "Orange");
	allTeas = ctrl.getAll();
	assert(allTeas.size() == 1);
	ctrl.addGreenTea(123, "Green", 33, 4, 6.2, "Orange");
	allTeas = ctrl.getAll();
	assert(allTeas.size() == 1);
	ctrl.addFruitTea(122, "Fruit", 0, 5, 4, 3, { "Aplle","Berry","BlackCurrent" });
	allTeas = ctrl.getAll();
	assert(allTeas.size() == 2);
	ctrl.addBlackTea(13, "Black", 45, 4, 6.2, "Lemon");
	allTeas = ctrl.getAll();
	assert(allTeas.size() == 3);
	ctrl.addGreenTea(121, "Green", 33, 4, 6.2, "Mango");
	allTeas = ctrl.getAll();
	assert(allTeas.size() == 4);
	ctrl.removeById(123);
	std::pair<Tea*, int> t1;
	t1.second = -1;
	assert(ctrl.searchById('k').second == -1);
	assert(ctrl.searchById(123).second == -1);
	allTeas = ctrl.getAll();
	assert(allTeas.size() == 3);
	ctrl.removeById(888);
	allTeas = ctrl.getAll();
	assert(allTeas.size() == 3);
	std::vector<Tea*>  m = { allTeas[2] };
	assert(m == ctrl.filterByType("Green"));
	m = { allTeas[0], allTeas[2] };
	assert(m == ctrl.filterLessCaffeine(34));
	assert(m != ctrl.filterLessCaffeine(33));
	assert(allTeas.size() == 3);
	
	



}
