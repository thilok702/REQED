#include "Projekt.h"
#include <string>
#include <memory>
using namespace std;

Projekt::Projekt(string pfad_in) {
	pfad = pfad_in;
}

void Projekt::projektSpeichern() {

}

void Projekt::exportTXT(string pfad) {

}

void Projekt::exportJSON(string pfad) {

}

void Projekt::funktionaleAnforderungHinzu(FunktionaleAnforderung anf) {
	F_anf.push_back(shared_ptr<FunktionaleAnforderung>(new FunktionaleAnforderung(anf)));
}

void Projekt::nichtFuntkionaleAnforderungHinzu(NichtFunktionaleAnforderung anf) {
	NF_anf.push_back(shared_ptr<NichtFunktionaleAnforderung> (new NichtFunktionaleAnforderung(anf)));
}

std::shared_ptr<FunktionaleAnforderung> Projekt::funktionaleAnforderungBearbeiten(int index) {
	return F_anf[index];
}

std::shared_ptr<NichtFunktionaleAnforderung> Projekt::nichtFunktionaleAnforderungBearbeiten(int index) {
	return NF_anf[index];
}

void Projekt::funktionaleAnforderungloeschen(int index) {

}

void Projekt::nichtFunktionaleAnforderungloeschen(int index) {

}