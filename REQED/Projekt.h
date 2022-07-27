#pragma once
#include "FunktionaleAnforderung.h"
#include "NichtFunktionaleAnforderung.h"
#include <string>
#include <vector>
#include <memory>

class Projekt {
private:
	std::string pfad;
	std::vector<std::shared_ptr<FunktionaleAnforderung>> F_anf;
	std::vector<std::shared_ptr<NichtFunktionaleAnforderung>> NF_anf;
public:
	Projekt(std::string pfad);
	void projektSpeichern();
	void exportTXT(std::string pfad);
	void exportJSON(std::string pfad);
	void funktionaleAnforderungHinzu(std::shared_ptr<FunktionaleAnforderung> anf);
	void nichtFuntkionaleAnforderungHinzu(std::shared_ptr<NichtFunktionaleAnforderung> anf);
	void funktionaleAnforderungBearbeiten(int index, std::string bed, std::string sys, std::string obj, std::string proz, ArtFunktionalitaet funkt, Verbindlichkeit verb);
	void nichtFunktionaleAnforderungBearbeiten(int index, std::string bed, std::string geg, std::string obj, std::string eig, std::string oper, std::string wert, Verbindlichkeit verb);
	void funktionaleAnforderungloeschen(int index);
	void nichtFunktionaleAnforderungloeschen(int index);
};

