#include "fAnfGUI.h"
#include <msclr\marshal_cppstd.h>
#include <string>
using namespace REQED;
using namespace System;
using namespace std;

Void fAnfGUI::changed(Object^ sender, EventArgs^ e) {
	String^ anf;
	if(bedingungBox->TextLength == 0) {
		anf += systemBox->Text + " ";
		anf += verbindlichkeitCombobox->Text + " ";
		if(getFunktionalitaet(funktionalitaetCombobox->SelectedIndex)->Length != 0) {
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
		return "dem/der Benutzer/-in die Möglichkeit bieten";
	case 2:
		return "fähig sein";
	}
	return "";
}

Void fAnfGUI::okButton_Click(Object^ sender, EventArgs^ e) {
	if(systemBox->TextLength == 0) {
		fehler->Text = "'System' darf nicht leer sein!";
	} else if(objektBox->TextLength == 0) {
		fehler->Text = "'Objekt' darf nicht leer sein!";
	} else if(prozesswortBox->TextLength == 0) {
		fehler->Text = "'Prozesswort' darf nicht leer sein!";
	} else {
		string anf[6] = {msclr::interop::marshal_as<string>(bedingungBox->Text), msclr::interop::marshal_as<string>(systemBox->Text),
						msclr::interop::marshal_as<string>(objektBox->Text), msclr::interop::marshal_as<string>(prozesswortBox->Text),
						msclr::interop::marshal_as<string>(funktionalitaetCombobox->Text), msclr::interop::marshal_as<string>(verbindlichkeitCombobox->Text)};
		bedingung->Text = gcnew String(anf[0].c_str());
		controller->processInput(3, anf);
		this->Close();
	}
}

Void fAnfGUI::abbrechenButton_Click(Object^ sender, EventArgs^ e) {
	this->Close();
}