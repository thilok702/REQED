#include "Projekt.h"
#include "Verbindlichkeit.h"
#include "ArtFunktionalitaet.h"
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Projekt::Projekt(string pfad_in, View^ view) {
	pfad = pfad_in;
	saved = true ;
	this->view = view;
	
	
	
}

void Projekt::load()
{

	ifstream save_file(pfad);
	string line;
	string item;
	int read_status = 0;
	ofstream save_file2("tempoutput.txt");
	if (save_file.is_open()) {
		while (getline(save_file, line)) {
			if (line == "F") { read_status = 1; }
			else if (line == "NF") { read_status = 2; }
			else if (read_status == 1) {
				std::stringstream line_stream(line);
				string bed;
				getline(line_stream, bed, '#'); save_file2 << bed;
				string sys;
				
				getline(line_stream, sys, '#');save_file2 << sys;
				string obj;

				getline(line_stream, obj, '#'); save_file2 << obj;
				string proz;

				getline(line_stream, proz, '#'); save_file2 << proz;
				string funkt;

				getline(line_stream, funkt, '#'); save_file2 << funkt;
				string verb;

				getline(line_stream, verb, '#'); save_file2 << verb;
				//shared_ptr<FunktionaleAnforderung> point (new FunktionaleAnforderung(bed,sys,obj,proz,getFunktionalitaet(funkt), getVerbindlichkeit(verb)));
				//this->funktionaleAnforderungHinzu(point);
			}
			else if (read_status == 2) {
				std::stringstream line_stream(line);
				string bed;
				getline(line_stream, bed, '#'); save_file2 << bed;
				string geg;

				getline(line_stream, geg, '#'); save_file2 << geg;
				string eig;

				getline(line_stream, eig, '#'); save_file2 << eig;
				string oper;

				getline(line_stream, oper, '#'); save_file2 << oper;
				string wert;

				getline(line_stream, wert, '#'); save_file2 << wert;
				string verb;

				getline(line_stream, verb, '#'); save_file2 << verb;
				shared_ptr<NichtFunktionaleAnforderung> point(new NichtFunktionaleAnforderung(bed, geg, eig, oper, wert, getVerbindlichkeit(verb)));
				this->nichtFuntkionaleAnforderungHinzu(point);
			}
			
			

		}
	}
}

void Projekt::projektSpeichern() {
	ofstream save_file(pfad );
	if (save_file.is_open()) {
		save_file << "F" << "\n";
		for (int i = 0; i != F_anf.size(); i++) {
			save_file << F_anf[i]->getBedingung();
			save_file << "#";
			save_file << F_anf[i]->getSystem();
			save_file << "#";
			save_file << F_anf[i]->getObjekt();
			save_file << "#";
			save_file << F_anf[i]->getProzesswort();
			save_file << "#";
			save_file << F_anf[i]->getFunktionalitaet();
			save_file << "#";
			save_file << F_anf[i]->getVerbindlichkeit();
			save_file << "#";
			save_file << "\n";
		}
		save_file << "NF" << "\n";
		for (int i = 0; i != NF_anf.size(); i++) {
			save_file << NF_anf[i]->getBedingung();
			save_file << "#";
			save_file << NF_anf[i]->getGegenstand();
			save_file << "#";
			save_file << NF_anf[i]->getEigenschaft();
			save_file << "#";
			save_file << NF_anf[i]->getOperator();
			save_file << "#";
			save_file << NF_anf[i]->getWert();
			save_file << "#";
			save_file << NF_anf[i]->getVerbindlichkeit();
			save_file << "#";
			save_file << "\n";
		}
	}
	saved = true;
	view->modelChanged();
}

void Projekt::exportTXT(string pfad_in) {
	ofstream save_file(pfad_in);
	if (save_file.is_open()) {
		save_file << "Funktionale Anforderungen:" << "\n";
		for (int i = 0; i != F_anf.size(); i++) {
			save_file << F_anf[i]->toString();
			save_file << "\n";
		}
		save_file << "Nicht Funktionsle Anforderungen:" << "\n";
		for (int i = 0; i != NF_anf.size(); i++) {
			save_file << NF_anf[i]->toString();
			save_file << "\n";
		}
	}
}

void Projekt::exportJSON(string pfad) {

}

void Projekt::funktionaleAnforderungHinzu(shared_ptr<FunktionaleAnforderung> anf) {
	F_anf.push_back(anf);
	saved = false;
	view->modelChanged();
}

void Projekt::nichtFuntkionaleAnforderungHinzu(shared_ptr<NichtFunktionaleAnforderung> anf) {
	NF_anf.push_back(anf);
	saved = false;
	view->modelChanged();
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
	view->modelChanged();
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
	view->modelChanged();
}

void Projekt::funktionaleAnforderungloeschen(int index) {
	F_anf.erase(F_anf.begin() + index);
	saved = false;
	view->modelChanged();
}

void Projekt::nichtFunktionaleAnforderungloeschen(int index) {
	NF_anf.erase(NF_anf.begin() + index);
	saved = false;
	view->modelChanged();
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

int Projekt::anzFanf() {
	return (int)F_anf.size();
}

int Projekt::anzNFanf() {
	return (int)NF_anf.size();
}