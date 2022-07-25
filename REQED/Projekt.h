#pragma once
#include "FunktionaleAnforderung.h"
#include "NichtFunktionaleAnforderung.h"
#include <string>

class Projekt {
private:
	std::string pfad;
public:
	Projekt(std::string pfad);
	void projektSpeichern();
	void exportTXT(std::string pfad);
	void exportJSON(std::string pfad);
	void funktionaleAnforderungHinzu(FunktionaleAnforderung anf);
	void nichtFuntkionaleAnforderungHinzu(NichtFunktionaleAnforderung anf);
	std::shared_ptr<FunktionaleAnforderung> funktionaleAnforderungBearbeiten(int index);
	std::shared_ptr<NichtFunktionaleAnforderung> nichtFunktionaleAnforderungBearbeiten(int index);
	void funktionaleAnforderungloeschen(int index);
	void nichtFunktionaleAnforderungloeschen(int index);
};

