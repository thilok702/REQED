#include "fAnfGUI.h"
#include <msclr\marshal_cppstd.h>
#include <string>
#include <memory>
using namespace REQED;
using namespace System;
using namespace std;

Void fAnfGUI::fAnfGUI_Load(Object^ sender, EventArgs^ e) {
	if(bearbeiten == true) {
		const shared_ptr<FunktionaleAnforderung>& anf = projekt->getFanf(index);
		bedingungBox->Text = gcnew String(anf->getBedingung().c_str());
		verbindlichkeitCombobox->Text = gcnew String(verbindlichkeitToString(anf->getVerbindlichkeit()).c_str());
		systemBox->Text = gcnew String(anf->getSystem().c_str());
		funktionalitaetCombobox->SelectedIndex = getIndexFromFunkt(funktionalitaetToString(anf->getFunktionalitaet()));
		if(anf->getAkteur().length() != 0) {
			akteur->Enabled = true;
			akteurBox->Enabled = true;
			akteurBox->Text = gcnew String(anf->getAkteur().c_str());
		} else {
			akteur->Enabled = false;
			akteurBox->Enabled = false;
		}
		objektBox->Text = gcnew String(anf->getObjekt().c_str());
		prozesswortBox->Text = gcnew String(anf->getProzesswort().c_str());
	}
}

Void fAnfGUI::changed(Object^ sender, EventArgs^ e) {
	String^ anf;
	if(bedingungBox->TextLength == 0) {
		anf += systemBox->Text + " ";
		anf += verbindlichkeitCombobox->Text + " ";
		if(getFunktionalitaet(funktionalitaetCombobox->SelectedIndex)->Length != 0) {
			if(funktionalitaetCombobox->SelectedIndex == 1) {
				akteur->Enabled = true;
				akteurBox->Enabled = true;
				anf += akteurBox->Text + " ";
			} else {
				akteur->Enabled = false;
				akteurBox->Enabled = false;
			}
			anf += getFunktionalitaet(funktionalitaetCombobox->SelectedIndex) + " ";
		}
		anf += objektBox->Text + " ";
		if(prozesswortBox->TextLength != 0) {
			anf += prozesswortBox->Text + ".";
		}
	} else {
		anf += bedingungBox->Text + " ";
		anf += verbindlichkeitCombobox->Text + " ";
		anf += systemBox->Text + " ";
		if(getFunktionalitaet(funktionalitaetCombobox->SelectedIndex)->Length != 0) {
			if(funktionalitaetCombobox->SelectedIndex == 1) {
				akteur->Enabled = true;
				akteurBox->Enabled = true;
				anf += akteurBox->Text + " ";
			} else {
				akteur->Enabled = false;
				akteurBox->Enabled = false;
			}
			anf += getFunktionalitaet(funktionalitaetCombobox->SelectedIndex) + " ";
		}
		anf += objektBox->Text + " ";
		if(prozesswortBox->TextLength != 0) {
			anf += prozesswortBox->Text + ".";
		}
	}
	anforderung->Text = anf;
}

String^ fAnfGUI::getFunktionalitaet(int index) {
	switch(index) {
	case 1:
		return "die Möglichkeit bieten";
	case 2:
		return "fähig sein";
	}
	return "";
}

int fAnfGUI::getIndexFromFunkt(string funkt) {
	if(funkt == "die Möglichkeit bieten") {
		return 1;
	} else if(funkt == "fähig sein") {
		return 2;
	} else {
		return 0;
	}
}

Void fAnfGUI::okButton_Click(Object^ sender, EventArgs^ e) {
	if(systemBox->TextLength == 0) {
		fehler->Text = "'System' darf nicht leer sein!";
	} else if(objektBox->TextLength == 0) {
		fehler->Text = "'Objekt' darf nicht leer sein!";
	} else if(prozesswortBox->TextLength == 0) {
		fehler->Text = "'Prozesswort' darf nicht leer sein!";
	} else if(akteur->Enabled && akteurBox->TextLength == 0) {
		fehler->Text = "'Akteur' darf nicht leer sein!";
	} else {
		if(bearbeiten == true) {
			string anf[8] = {to_string(index), msclr::interop::marshal_as<string>(bedingungBox->Text), msclr::interop::marshal_as<string>(systemBox->Text),
						msclr::interop::marshal_as<string>(objektBox->Text), msclr::interop::marshal_as<string>(prozesswortBox->Text),
						msclr::interop::marshal_as<string>(funktionalitaetCombobox->Text), msclr::interop::marshal_as<string>(verbindlichkeitCombobox->Text),
						msclr::interop::marshal_as<string>(akteurBox->Text)};
			controller->processInput(5, anf);
		} else {
			string anf[7] = {msclr::interop::marshal_as<string>(bedingungBox->Text), msclr::interop::marshal_as<string>(systemBox->Text),
						msclr::interop::marshal_as<string>(objektBox->Text), msclr::interop::marshal_as<string>(prozesswortBox->Text),
						msclr::interop::marshal_as<string>(funktionalitaetCombobox->Text), msclr::interop::marshal_as<string>(verbindlichkeitCombobox->Text),
						msclr::interop::marshal_as<string>(akteurBox->Text)};
			controller->processInput(3, anf);
		}
		this->Close();
	}
}

Void fAnfGUI::abbrechenButton_Click(Object^ sender, EventArgs^ e) {
	this->Close();
}