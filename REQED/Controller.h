#pragma once
#include "Projekt.h"
#include <memory>
#include <string>

class Controller {
private:
	std::unique_ptr<Projekt> aktProjekt;
public:
	Controller();
	void openProject(std::string pfad);
	void processInput(int methode, std::string args[]);
};
