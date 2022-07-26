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
	saved = true;
	this->view = view;
}

void Projekt::load() {
	ifstream save_file(pfad);
	string line;
	int read_status = 0;
	if(save_file.is_open()) {
		while(getline(save_file, line)) {
			if(line == "F") {
				read_status = 1;
			} else if(line == "NF") {
				read_status = 2;
			} else if(read_status == 1) {
				std::stringstream line_stream(line);
				string bed;
				getline(line_stream, bed, '#');
				string sys;
				getline(line_stream, sys, '#');
				string obj;
				getline(line_stream, obj, '#');
				string proz;
				getline(line_stream, proz, '#');
				string funkt;
				getline(line_stream, funkt, '#');
				string verb;
				getline(line_stream, verb, '#');
				string akt;
				getline(line_stream, akt, '#');
				this->funktionaleAnforderungHinzu(make_shared<FunktionaleAnforderung>(bed, sys, obj, proz, getFunktionalitaetfromNumber(funkt), getVerbindlichkeitfromnumber(verb), akt));
			} else if(read_status == 2) {
				std::stringstream line_stream(line);
				string bed;
				getline(line_stream, bed, '#');
				string geg;
				getline(line_stream, geg, '#');
				string eig;
				getline(line_stream, eig, '#');
				string oper;
				getline(line_stream, oper, '#');
				string wert;
				getline(line_stream, wert, '#');
				string verb;
				getline(line_stream, verb, '#');
				string akt;
				getline(line_stream, akt, '#');
				this->nichtFuntkionaleAnforderungHinzu(make_shared<NichtFunktionaleAnforderung>(bed, geg, eig, oper, wert, getVerbindlichkeitfromnumber(verb)));
			}
		}
		save_file.close();
		saved = true;
		view->modelChanged();
	}
}

void Projekt::projektSpeichern() {
	ofstream save_file(pfad );
	if(save_file.is_open()) {
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
			save_file << verbindlichkeitToNumber( F_anf[i]->getVerbindlichkeit());
			save_file << "#";
			save_file << F_anf[i]->getAkteur();
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
			save_file << verbindlichkeitToNumber( NF_anf[i]->getVerbindlichkeit());
			save_file << "#";
			save_file << "\n";
		}
		save_file.close();
	}
	saved = true;
	view->modelChanged();
}

void Projekt::exportTXT(string pfad_in) {
	ofstream save_file(pfad_in);
	if(save_file.is_open()) {
		save_file << "Funktionale Anforderungen:" << "\n";
		for (int i = 0; i != F_anf.size(); i++) {
			save_file << F_anf[i]->toString();
			save_file << "\n";
		}
		save_file << "\nNicht Funktionsle Anforderungen:" << "\n";
		for (int i = 0; i != NF_anf.size(); i++) {
			save_file << NF_anf[i]->toString();
			save_file << "\n";
		}
		save_file.close();
	}
}

void Projekt::exportJSON(string pfad_in) {
	ofstream save_file(pfad_in);
	if (save_file.is_open()) {
		save_file << "{" << "\n";
		save_file << "\t\"reqed\" \t: \"1.0\"," << "\n";
		save_file << "\t\"system\" \t: \"" + F_anf[0]->getSystem() + "\"," << "\n";
		save_file << "\t\"requirements\" : [" << "\n";
		for (int i = 0; i != F_anf.size(); i++) {
			save_file << "\t\t{\n";
			
			save_file << "\t\t\t\"identifier\" : "+ to_string(i) + ",\n";
			if(F_anf[i]->getBedingung() != "") {
				save_file << "\t\t\t\"condition\"\t : \"" + F_anf[i]->getBedingung() + "\",\n";
			}
			save_file << "\t\t\t\"binding\"\t : " + verbindlichkeitToNumber(F_anf[i]->getVerbindlichkeit()) + ",\n";
			save_file << "\t\t\t\"type\"\t\t : " + funktionalitaetToNumber(F_anf[i]->getFunktionalitaet()) + ",\n";
			if(F_anf[i]->getFunktionalitaet() == Benutzerinteraktion) {
				save_file << "\t\t\t\"actor\"\t\t : \"" + F_anf[i]->getAkteur() + "\",\n";
			}
			save_file << "\t\t\t\"object\"\t : \"" + F_anf[i]->getObjekt() + "\",\n";
			save_file << "\t\t\t\"process\"\t : \"" + F_anf[i]->getProzesswort() + "\"\n";
			save_file << "\t\t}\n";
		}
		for (int i = 0; i != NF_anf.size(); i++) {
			save_file << "\t\t{\n";
			save_file << "\t\t\t\"identifier\"\t  : " + to_string(i+(F_anf.size())) + ",\n";
			if (NF_anf[i]->getBedingung() != "") {
				save_file << "\t\t\t\"condition\"\t\t  : \"" + NF_anf[i]->getBedingung() + "\",\n";
			}
			save_file << "\t\t\t\"binding\"\t\t  : " + verbindlichkeitToNumber(NF_anf[i]->getVerbindlichkeit()) + ",\n";
			save_file << "\t\t\t\"Property\"\t\t  : \"" + NF_anf[i]->getEigenschaft() + "\", \n";
			save_file << "\t\t\t\"observed object\" : \"" + NF_anf[i]->getGegenstand() + "\", \n";
			save_file << "\t\t\t\"Operator\"\t\t  : \"" + NF_anf[i]->getOperator() + "\", \n";
			save_file << "\t\t\t\"Value\"\t\t\t  : \"" + NF_anf[i]->getWert() + "\" \n";
			save_file << "\t\t}\n";

		}
		save_file << "\t]\n";
		save_file << "}" ;
		save_file.close();
	}
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

void Projekt::funktionaleAnforderungBearbeiten(int index, string bed, string sys, string obj, string proz, ArtFunktionalitaet funkt, Verbindlichkeit verb, string akt) {
	shared_ptr<FunktionaleAnforderung> anf = F_anf[index];
	anf->setBedingung(bed);
	anf->setSystem(sys);
	anf->setObjekt(obj);
	anf->setProzesswort(proz);
	anf->setFunktionalitaet(funkt);
	anf->setVerbindlichkeit(verb);
	anf->setAkteur(akt);
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