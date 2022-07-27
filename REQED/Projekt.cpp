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

}

void Projekt::nichtFuntkionaleAnforderungHinzu(NichtFunktionaleAnforderung anf) {

}

std::shared_ptr<FunktionaleAnforderung> Projekt::funktionaleAnforderungBearbeiten(int index) {

}

std::shared_ptr<NichtFunktionaleAnforderung> Projekt::nichtFunktionaleAnforderungBearbeiten(int index) {

}

void Projekt::funktionaleAnforderungloeschen(int index) {

}

void Projekt::nichtFunktionaleAnforderungloeschen(int index) {

}