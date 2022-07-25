#pragma once
#include "Verbindlichkeit.h"
#include <string>

class NichtFunktionaleAnforderung {
private:
	std::string bedingung;
	std::string betrachtungsgegenstand;
	std::string objekt;
	std::string eigenschaft;
	std::string vergleichsoperator;
	std::string wert;
	Verbindlichkeit verbindlichkeit;
public:
	NichtFunktionaleAnforderung(std::string bed, std::string geg, std::string obj, std::string eig, std::string oper, std::string wert, Verbindlichkeit verb);
	void toString();
	std::string getBedingung();
	void setBedingung(std::string bed);
	std::string getGegenstand();
	void setGegenstand(std::string geg);
	std::string getObjekt();
	void setObjekt(std::string obj);
	std::string getEigenschaft();
	void setEigenschaft(std::string eig);
	std::string getOperator();
	void setOperator(std::string oper);
	std::string getWert();
	void setWert(std::string wert);
	Verbindlichkeit getVerbindlichkeit();
	void setVerbindlichkeit(Verbindlichkeit verb);
};

