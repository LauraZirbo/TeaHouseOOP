#pragma once
#include "Controller.h"
class UI
{
private:
	Controller ctrl;
	void showMenu();
public:
	UI();
	~UI();
	void run();
};
