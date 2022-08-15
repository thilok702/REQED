#include "NichtFunktionaleAnforderung.h"
#include "Verbindlichkeit.h"
#include <string>
using namespace std;

NichtFunktionaleAnforderung::NichtFunktionaleAnforderung(string bed, string geg, string eig, string oper, string wert, Verbindlichkeit verb) {
	bedingung = bed;
	betrachtungsgegenstand = geg;
	eigenschaft = eig;
	vergleichsoperator = oper;
	this->wert = wert;
	verbindlichkeit = verb;
}

string NichtFunktionaleAnforderung::toString() {
	string anf;
	if(bedingung.length() == 0) {
		anf += eigenschaft + " ";
		anf += betrachtungsgegenstand + " ";
		anf += verbindlichkeitToString(verbindlichkeit) + " ";
		anf += vergleichsoperator + " ";
		anf += wert + " sein.";
	} else {
		anf += bedingung + " ";
		anf += verbindlichkeitToString(verbindlichkeit) + " ";
		anf += eigenschaft + " ";
		anf += vergleichsoperator + " ";
		anf += wert + " sein.";
	}
	return anf;
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
