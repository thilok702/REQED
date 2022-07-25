#pragma once
#include "Projekt.h"
#include <memory>

class Controller {
private:
	std::unique_ptr<Projekt> aktProjekt;
public:
	Controller();
	void schliessen();
	void start();
};
