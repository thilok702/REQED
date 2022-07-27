#include "fAnfGUI.h"
using namespace REQED;
using namespace System;

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
	controller->
}

Void fAnfGUI::abbrechenButton_Click(Object^ sender, EventArgs^ e) {

}