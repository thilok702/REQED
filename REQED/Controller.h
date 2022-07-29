#pragma once
#include "Projekt.h"
#include <memory>
#include <string>
#include "View.h"

class Controller {
private:
	std::shared_ptr<Projekt> aktProjekt;
public:
	Controller();
	std::shared_ptr<Projekt>& openProject(std::string pfad, View^ gui);
	void processInput(int methode, std::string args[]);
	bool projektSaved();
};
