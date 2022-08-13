#include "FunktionaleAnforderung.h"
#include "Verbindlichkeit.h"
#include "ArtFunktionalitaet.h"
#include <string>
using namespace std;

FunktionaleAnforderung::FunktionaleAnforderung(string bed, string sys, string obj, string proz, ArtFunktionalitaet funkt, Verbindlichkeit verb, string akt) {
	bedingung = bed;
	system = sys;
	objekt = obj;
	prozesswort = proz;
	funktionalitaet = funkt;
	verbindlichkeit = verb;
	akteur = akt;
}

string FunktionaleAnforderung::toString() {
	string anf;
	if(bedingung.length() == 0) {
		anf += system + " ";
		anf += verbindlichkeitToString(verbindlichkeit) + " ";
		if(funktionalitaet == ArtFunktionalitaet::Benutzerinteraktion) {
			anf += akteur + " ";
		}
		anf += funktionalitaetToString(funktionalitaet) + " ";
		anf += objekt + " ";
		anf += prozesswort + ".";
	} else {
		anf += bedingung + " ";
		anf += verbindlichkeitToString(verbindlichkeit) + " ";
		anf += system + " ";
		if(funktionalitaet == ArtFunktionalitaet::Benutzerinteraktion) {
			anf += akteur + " ";
		}
		anf += funktionalitaetToString(funktionalitaet) + " ";
		anf += objekt + " ";
		anf += prozesswort + ".";
	}
	return anf;
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

string FunktionaleAnforderung::getAkteur() {
	return akteur;
}

void FunktionaleAnforderung::setAkteur(string akt) {
	akteur = akt;
}