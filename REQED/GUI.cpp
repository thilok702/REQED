#include "GUI.h"
#include "fAnfGUI.h"
#include <msclr\marshal_cppstd.h>
#include "startGUI.h"
#include "nfAnfGUI.h"
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace REQED;

void GUI::setProjekt(Projekt* proj) {
    projekt = proj;
}

void GUI::modelChanged() {
    show();
}

void GUI::show() {

}

Void GUI::GUI_Load(System::Object^ sender, System::EventArgs^ e) {
    StreamReader^ sr;
    if((sr = gcnew StreamReader("letztesProjekt.txt")) != nullptr) {
        String^ tmp = sr->ReadLine();
        sr->Close();
        if(tmp != nullptr) {
            projekt = controller->openProject(msclr::interop::marshal_as<string>(tmp), this).get();
        } else {
            startGUI start(this, controller);
            start.ShowDialog();
        }
    } else {
        sr->Close();
    }
}

Void GUI::GUI_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
    StreamWriter^ sw;
    if((sw = gcnew StreamWriter("letztesProjekt.txt")) != nullptr) {
        sw->WriteLine(gcnew String(projekt->getPfad().c_str()));
        sw->Close();
    } else {
        sw->Close();
    }
}

void GUI::fAnfButton_Click(Object^ sender, EventArgs^ e) {
    fAnfGUI fAnf(controller, projekt, false, 0);
    fAnf.ShowDialog();
}

//Void GUI::button_Click(Object^ sender, EventArgs^ e) {
//    for each(Control^ c in this->Controls) {
//        if(c->GetHashCode() == sender->GetHashCode()) {
//            this->Controls->Remove(c);
//        }
//    }
//    
//}

Void GUI::nfAnfButton_Click(Object^ sender, EventArgs^ e) {
    nfAnfGUI nfAnf(controller, projekt, false, 0);
    nfAnf.ShowDialog();
}

Void GUI::neuToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
    if(!controller->projektSaved()) {
        if(MessageBox::Show("Projekt nicht gespeichert, wollen sie fortfahren", "hui", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) != Windows::Forms::DialogResult::OK) {
            return;
        }
    }
    SaveFileDialog^ sfd = gcnew SaveFileDialog;
    sfd->FileName = "Projekt1";
    sfd->DefaultExt = "RQ";
    sfd->Filter = "REQED (*.RQ)|*.RQ";
    sfd->OverwritePrompt = true;
    sfd->AddExtension = true;
    if(sfd->ShowDialog() == Windows::Forms::DialogResult::OK) {
        StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
        sw->WriteLine("");
        sw->Close();
        projekt = controller->openProject(msclr::interop::marshal_as<string>(sfd->FileName), this).get();
    }
}

Void GUI::öffnenToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
    if(!controller->projektSaved()) {
        if(MessageBox::Show("Projekt nicht gespeichert, wollen sie fortfahren", "hui", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) != Windows::Forms::DialogResult::OK) {
            return;
        }
    }
    OpenFileDialog^ ofd = gcnew OpenFileDialog;
    ofd->Filter = "REQED (*.RQ)|*.RQ";
    if(ofd->ShowDialog() == Windows::Forms::DialogResult::OK) {
        projekt = controller->openProject(msclr::interop::marshal_as<string>(ofd->FileName), this).get();
    }
}

Void GUI::speichernToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {}

Void GUI::textDateiToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {}

Void GUI::jSONDateiToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {}

    //MessageBox::Show("hallo");
    /*FolderBrowserDialog^ obd = gcnew FolderBrowserDialog;
    obd->Description = "Test";
    if(obd->ShowDialog() == Windows::Forms::DialogResult::OK) {
        label1->Text = gcnew String(obd->SelectedPath);
    }*/

    //int top = 50;
    //int left = 100;
    //for(int i = 0; i < 5; i++) {
    //    Button^ button = gcnew Button;
    //    button->Left = left;
    //    button->Top = top;
    //    button->Click += gcnew EventHandler(this, &GUI::button_Click);
    //    this->Controls->Add(button);
    //    top += button->Height + 2;
    //}