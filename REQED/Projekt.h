#pragma once
#include "FunktionaleAnforderung.h"
#include "NichtFunktionaleAnforderung.h"
#include "Verbindlichkeit.h"
#include "ArtFunktionalitaet.h"
#include <string>
#include <vector>
#include <memory>
#include <vcclr.h>
#include "View.h"

class Projekt {
private:
	std::string pfad;
	std::vector<std::shared_ptr<FunktionaleAnforderung>> F_anf;
	std::vector<std::shared_ptr<NichtFunktionaleAnforderung>> NF_anf;
	bool saved = true;
	gcroot<View^> view;
public:
	Projekt(std::string pfad, View^ view);
	void projektSpeichern();
	void exportTXT(std::string pfad);
	void exportJSON(std::string pfad);
	void funktionaleAnforderungHinzu(std::shared_ptr<FunktionaleAnforderung> anf);
	void nichtFuntkionaleAnforderungHinzu(std::shared_ptr<NichtFunktionaleAnforderung> anf);
	void funktionaleAnforderungBearbeiten(int index, std::string bed, std::string sys, std::string obj, std::string proz, ArtFunktionalitaet funkt, Verbindlichkeit verb);
	void nichtFunktionaleAnforderungBearbeiten(int index, std::string bed, std::string geg, std::string eig, std::string oper, std::string wert, Verbindlichkeit verb);
	void funktionaleAnforderungloeschen(int index);
	void nichtFunktionaleAnforderungloeschen(int index);
	bool isSaved();
	std::string getPfad();
	const std::shared_ptr<FunktionaleAnforderung>& getFanf(int index);
	const std::shared_ptr<NichtFunktionaleAnforderung>& getNFanf(int index);
	int anzFanf();
	int anzNFanf();
};

