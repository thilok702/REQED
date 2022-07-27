#pragma once
#include "Projekt.h"
#include "ArtFunktionalitaet.h"
#include <memory>
#include <string>

class Controller {
private:
	std::unique_ptr<Projekt> aktProjekt;
public:
	Controller();
	void schliessen();
	void start();
	void processInput(int methode, std::string args[]);
private:
	ArtFunktionalitaet getFunktionalitaet(std::string funkt);
	Verbindlichkeit getVerbindlichkeit(std::string verb);
};
