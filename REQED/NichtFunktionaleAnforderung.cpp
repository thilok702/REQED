#include "NichtFunktionaleAnforderung.h"
#include "Verbindlichkeit.h"
#include <string>
using namespace std;

NichtFunktionaleAnforderung::NichtFunktionaleAnforderung(string bed, string geg, string obj, string eig, string oper, string wert, Verbindlichkeit verb) {

}

void NichtFunktionaleAnforderung::toString() {

}

string NichtFunktionaleAnforderung::getBedingung() {
	return bedingung;
}

void NichtFunktionaleAnforderung::setBedingung(string bed) {
	bedingung = bed;
}
string NichtFunktionaleAnforderung::getGegenstand() {
	return betrachtungsgegenstand;
}

void NichtFunktionaleAnforderung::setGegenstand(string geg) {
	betrachtungsgegenstand = geg;
}

string NichtFunktionaleAnforderung::getObjekt() {
	return objekt;
}

void NichtFunktionaleAnforderung::setObjekt(string obj) {
	objekt = obj;
}

string NichtFunktionaleAnforderung::getEigenschaft() {
	return eigenschaft;
}

void NichtFunktionaleAnforderung::setEigenschaft(string eig) {
	eigenschaft = eig;
}

string NichtFunktionaleAnforderung::getOperator() {
	return vergleichsoperator;
}

void NichtFunktionaleAnforderung::setOperator(string oper) {
	vergleichsoperator = oper;
}

string NichtFunktionaleAnforderung::getWert() {
	return wert;
}

void NichtFunktionaleAnforderung::setWert(string wert) {
	this->wert = wert;
}

Verbindlichkeit NichtFunktionaleAnforderung::getVerbindlichkeit() {
	return verbindlichkeit;
}

void NichtFunktionaleAnforderung::setVerbindlichkeit(Verbindlichkeit verb) {
	verbindlichkeit = verb;
}
