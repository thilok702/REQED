#include "nfAnfGUI.h"
#include <msclr\marshal_cppstd.h>
#include <string>
using namespace REQED;
using namespace System;
using namespace std;

Void nfAnfGUI::nfAnfGUI_Load(Object^ sender, EventArgs^ e) {
	if(bearbeiten == true) {
		const shared_ptr<NichtFunktionaleAnforderung>& anf = projekt->getNFanf(index);
		bedingungBox->Text = gcnew String(anf->getBedingung().c_str());
		verbindlichkeitCombobox->Text = gcnew String(verbindlichkeitToString(anf->getVerbindlichkeit()).c_str());
		eigenschaftBox->Text = gcnew String(anf->getEigenschaft().c_str());
		gegenstandBox->Text = gcnew String(anf->getGegenstand().c_str());
		operatorBox->Text = gcnew String(anf->getOperator().c_str());
		wertBox->Text = gcnew String(anf->getWert().c_str());
	}
}

Void nfAnfGUI::changed(Object^ sender, EventArgs^ e) {
	String^ anf;
	if(bedingungBox->TextLength == 0) {
		anf += eigenschaftBox->Text + " ";
		anf += gegenstandBox->Text + " ";
		anf += verbindlichkeitCombobox->Text + " ";
		anf += operatorBox->Text + " ";
		if(wertBox->TextLength != 0) {
			anf += wertBox->Text + " sein.";
		}
	} else {
		anf += bedingungBox->Text + " ";
		anf += verbindlichkeitCombobox->Text + " ";
		anf += eigenschaftBox->Text + " ";
		anf += gegenstandBox->Text + " ";
		anf += operatorBox->Text + " ";
		if(wertBox->TextLength != 0) {
			anf += wertBox->Text + " sein.";
		}
	}
	anforderung->Text = anf;
}

Void nfAnfGUI::okButton_Click(Object^ sender, EventArgs^ e) {
	if(eigenschaftBox->TextLength == 0) {
		fehler->Text = "'Eigenschaft' darf nicht leer sein!";
	} else if(gegenstandBox->TextLength == 0) {
		fehler->Text = "'Betrachtungsgegenstand' darf nicht leer sein!";
	} else if(operatorBox->TextLength == 0) {
		fehler->Text = "'Vergleichsoperator' darf nicht leer sein!";
	} else if(wertBox->TextLength == 0) {
		fehler->Text = "'Wert' darf nicht leer sein!";
	} else {
		if(bearbeiten == true) {
			string anf[7] = {to_string(index), msclr::interop::marshal_as<string>(bedingungBox->Text), msclr::interop::marshal_as<string>(gegenstandBox->Text),
						msclr::interop::marshal_as<string>(eigenschaftBox->Text), msclr::interop::marshal_as<string>(operatorBox->Text),
						msclr::interop::marshal_as<string>(wertBox->Text), msclr::interop::marshal_as<string>(verbindlichkeitCombobox->Text)};
			controller->processInput(6, anf);
		} else {
			string anf[6] = {msclr::interop::marshal_as<string>(bedingungBox->Text), msclr::interop::marshal_as<string>(gegenstandBox->Text),
						msclr::interop::marshal_as<string>(eigenschaftBox->Text), msclr::interop::marshal_as<string>(operatorBox->Text),
						msclr::interop::marshal_as<string>(wertBox->Text), msclr::interop::marshal_as<string>(verbindlichkeitCombobox->Text)};
			controller->processInput(4, anf);
		}
		this->Close();
	}
}

Void nfAnfGUI::abbrechenButton_Click(Object^ sender, EventArgs^ e) {
	this->Close();
}