#include "Controller.h"
#include "FunktionaleAnforderung.h"
#include "NichtFunktionaleAnforderung.h"
#include "ArtFunktionalitaet.h"
#include <string>
#include <memory>
using namespace std;

Controller::Controller() {
	aktProjekt = nullptr;
}

shared_ptr<Projekt>& Controller::openProject(string pfad, View^ gui) {
	aktProjekt = make_shared<Projekt>(pfad, gui);
	return aktProjekt;
}

void Controller::processInput(int methode, string args[]) {
	switch(methode) {
	case 0:
		aktProjekt->projektSpeichern();
		break;
	case 1:
		aktProjekt->exportTXT(args[0]);
		break;
	case 2:
		aktProjekt->exportJSON(args[0]);
		break;
	case 3:
		aktProjekt->funktionaleAnforderungHinzu(make_shared<FunktionaleAnforderung>(args[0], args[1], args[2], args[3], getFunktionalitaet(args[4]), getVerbindlichkeit(args[5]), args[6]));
		break;
	case 4:
		aktProjekt->nichtFuntkionaleAnforderungHinzu(make_shared<NichtFunktionaleAnforderung>(args[0], args[1], args[2], args[3], args[4], getVerbindlichkeit(args[5])));
		break;
	case 5:
		aktProjekt->funktionaleAnforderungBearbeiten(stoi(args[0]), args[1], args[2], args[3], args[4], getFunktionalitaet(args[5]), getVerbindlichkeit(args[6]), args[7]);
		break;
	case 6:
		aktProjekt->nichtFunktionaleAnforderungBearbeiten(stoi(args[0]), args[1], args[2], args[3], args[4], args[5], getVerbindlichkeit(args[6]));
		break;
	case 7:
		aktProjekt->funktionaleAnforderungloeschen(stoi(args[0]));
		break;
	case 8:
		aktProjekt->nichtFunktionaleAnforderungloeschen(stoi(args[0]));
		break;
	case 9:
		aktProjekt->load();
		break;
	}
}

bool Controller::projektSaved() {
	return aktProjekt->isSaved();
}