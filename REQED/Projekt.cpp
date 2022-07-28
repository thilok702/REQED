#include "Projekt.h"
#include "Verbindlichkeit.h"
#include "ArtFunktionalitaet.h"
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

void Projekt::funktionaleAnforderungHinzu(shared_ptr<FunktionaleAnforderung> anf) {
	F_anf.push_back(anf);
}

void Projekt::nichtFuntkionaleAnforderungHinzu(shared_ptr<NichtFunktionaleAnforderung> anf) {
	NF_anf.push_back(anf);
}

void Projekt::funktionaleAnforderungBearbeiten(int index, string bed, string sys, string obj, string proz, ArtFunktionalitaet funkt, Verbindlichkeit verb) {
	
}

void Projekt::nichtFunktionaleAnforderungBearbeiten(int index, string bed, string geg, string eig, string oper, string wert, Verbindlichkeit verb) {
	
}

void Projekt::funktionaleAnforderungloeschen(int index) {
	
}

void Projekt::nichtFunktionaleAnforderungloeschen(int index) {

}