#include "Projekt.h"
#include "Verbindlichkeit.h"
#include "ArtFunktionalitaet.h"
#include <string>
#include <memory>
using namespace std;

Projekt::Projekt(string pfad_in, View^ view) {
	pfad = pfad_in;
	saved = true;
	this->view = view;
}

void Projekt::projektSpeichern() {
	saved = true;
}

void Projekt::exportTXT(string pfad) {

}

void Projekt::exportJSON(string pfad) {

}

void Projekt::funktionaleAnforderungHinzu(shared_ptr<FunktionaleAnforderung> anf) {
	F_anf.push_back(anf);
	saved = false;
}

void Projekt::nichtFuntkionaleAnforderungHinzu(shared_ptr<NichtFunktionaleAnforderung> anf) {
	NF_anf.push_back(anf);
	saved = false;
}

void Projekt::funktionaleAnforderungBearbeiten(int index, string bed, string sys, string obj, string proz, ArtFunktionalitaet funkt, Verbindlichkeit verb) {
	shared_ptr<FunktionaleAnforderung> anf = F_anf[index];
	anf->setBedingung(bed);
	anf->setSystem(sys);
	anf->setObjekt(obj);
	anf->setProzesswort(proz);
	anf->setFunktionalitaet(funkt);
	anf->setVerbindlichkeit(verb);
	saved = false;
}

void Projekt::nichtFunktionaleAnforderungBearbeiten(int index, string bed, string geg, string eig, string oper, string wert, Verbindlichkeit verb) {
	shared_ptr<NichtFunktionaleAnforderung> anf = NF_anf[index];
	anf->setBedingung(bed);
	anf->setGegenstand(geg);
	anf->setEigenschaft(eig);
	anf->setOperator(oper);
	anf->setWert(wert);
	anf->setVerbindlichkeit(verb);
	saved = false;
}

void Projekt::funktionaleAnforderungloeschen(int index) {
	F_anf.erase(F_anf.begin() + index);
	saved = false;
}

void Projekt::nichtFunktionaleAnforderungloeschen(int index) {
	NF_anf.erase(NF_anf.begin() + index);
	saved = false;
}

bool Projekt::isSaved() {
	return saved;
}

string Projekt::getPfad() {
	return pfad;
}

const std::shared_ptr<FunktionaleAnforderung>& Projekt::getFanf(int index) {
	return F_anf[index];
}

const std::shared_ptr<NichtFunktionaleAnforderung>& Projekt::getNFanf(int index) {
	return NF_anf[index];
}