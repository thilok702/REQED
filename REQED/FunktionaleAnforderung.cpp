#include "FunktionaleAnforderung.h"
#include "Verbindlichkeit.h"
#include "ArtFunktionalitaet.h"
#include <string>
using namespace std;

FunktionaleAnforderung::FunktionaleAnforderung(string bed, string sys, string obj, string proz, ArtFunktionalitaet funkt, Verbindlichkeit verb) {
	bedingung = bed;
	system = sys;
	objekt = obj;
	prozesswort = proz;
	funktionalitaet = funkt;
	verbindlichkeit = verb;
}

string FunktionaleAnforderung::toString() {
	string anf;
	if(bedingung.length() == 0) {
		anf += system + " ";
		anf += getVerbindlichkeit(verbindlichkeit) + " ";
		anf += getFunktionalitaet(funktionalitaet) + " ";
		anf += objekt + " ";
		anf += prozesswort + ".";
	} else {
		anf += bedingung + " ";
		anf += getVerbindlichkeit(verbindlichkeit) + " ";
		anf += system + " ";
		anf += getFunktionalitaet(funktionalitaet) + " ";
		anf += objekt + " ";
		anf += prozesswort + ".";
	}
	return anf;
}

string FunktionaleAnforderung::getVerbindlichkeit(Verbindlichkeit verb) {
	switch(verb) {
	case muss:
		return "muss";
	case sollte:
		return "soltte";
	case wird:
		return "wird";
	}
	return "";
}

string FunktionaleAnforderung::getFunktionalitaet(ArtFunktionalitaet funk) {
	switch(funk) {
	case Benutzerinteraktion:
		return "dem/der Benutzer/-in die Möglichkeit bieten";
	case Schnittstellenanforderung:
		return "fähig sein";
	}
	return "";
}

string FunktionaleAnforderung::getBedingung() {
	return bedingung;
}

void FunktionaleAnforderung::setBedingung(string bed) {
	bedingung = bed;
}

string FunktionaleAnforderung::getSystem() {
	return system;
}

void FunktionaleAnforderung::setSystem(string sys) {
	system = sys;
}

string FunktionaleAnforderung::getObjekt() {
	return objekt;
}

void FunktionaleAnforderung::setObjekt(string obj) {
	objekt = obj;
}

string FunktionaleAnforderung::getProzesswort() {
	return prozesswort;
}

void FunktionaleAnforderung::setProzesswort(string proz) {
	prozesswort = proz;
}

ArtFunktionalitaet FunktionaleAnforderung::getFunktionalitaet() {
	return funktionalitaet;
}

void FunktionaleAnforderung::setFunktionalitaet(ArtFunktionalitaet funkt) {
	funktionalitaet = funkt;
}

Verbindlichkeit FunktionaleAnforderung::getVerbindlichkeit() {
	return verbindlichkeit;
}

void FunktionaleAnforderung::setVerbindlichkeit(Verbindlichkeit verb) {
	verbindlichkeit = verb;
}