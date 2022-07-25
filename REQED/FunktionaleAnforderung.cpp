#include "FunktionaleAnforderung.h"
#include "Verbindlichkeit.h"
#include "ArtFunktionalitaet.h"
#include <string>
using namespace std;

FunktionaleAnforderung::FunktionaleAnforderung(string bed, string sys, string obj, string proz, ArtFunktionalitaet funkt, Verbindlichkeit verb) {

}

void FunktionaleAnforderung::toString() {

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