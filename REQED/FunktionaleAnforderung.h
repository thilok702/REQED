#pragma once
#include "Verbindlichkeit.h"
#include "ArtFunktionalitaet.h"
#include <string>

class FunktionaleAnforderung {
private:
	std::string bedingung;
	std::string system;
	std::string objekt;
	std::string prozesswort;
	ArtFunktionalitaet funktionalitaet;
	Verbindlichkeit verbindlichkeit;
public:
	FunktionaleAnforderung(std::string bed, std::string sys, std::string obj, std::string proz, ArtFunktionalitaet funkt, Verbindlichkeit verb);
	std::string toString();
	std::string getBedingung();
	void setBedingung(std::string bed);
	std::string getSystem();
	void setSystem(std::string sys);
	std::string getObjekt();
	void setObjekt(std::string obj);
	std::string getProzesswort();
	void setProzesswort(std::string proz);
	ArtFunktionalitaet getFunktionalitaet();
	void setFunktionalitaet(ArtFunktionalitaet funkt);
	Verbindlichkeit getVerbindlichkeit();
	void setVerbindlichkeit(Verbindlichkeit verb);
};

