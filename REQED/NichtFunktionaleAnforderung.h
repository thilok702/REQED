#pragma once
#include "Verbindlichkeit.h"
#include <string>

class NichtFunktionaleAnforderung {
private:
	std::string bedingung;
	std::string betrachtungsgegenstand;
	std::string eigenschaft;
	std::string vergleichsoperator;
	std::string wert;
	Verbindlichkeit verbindlichkeit;
public:
	NichtFunktionaleAnforderung(std::string bed, std::string geg, std::string eig, std::string oper, std::string wert, Verbindlichkeit verb);
	std::string toString();
	std::string getBedingung();
	void setBedingung(std::string bed);
	std::string getGegenstand();
	void setGegenstand(std::string geg);
	std::string getEigenschaft();
	void setEigenschaft(std::string eig);
	std::string getOperator();
	void setOperator(std::string oper);
	std::string getWert();
	void setWert(std::string wert);
	Verbindlichkeit getVerbindlichkeit();
	void setVerbindlichkeit(Verbindlichkeit verb);
};

