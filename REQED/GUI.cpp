#include "GUI.h"
#include "fAnfGUI.h"
#include <msclr\marshal_cppstd.h>
#include "startGUI.h"
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace REQED;

Void GUI::GUI_Load(System::Object^ sender, System::EventArgs^ e) {
    StreamReader^ sr;
    if((sr = gcnew StreamReader("letztesProjekt.txt")) != nullptr) {
        String^ tmp = sr->ReadLine();
        if(tmp != nullptr) {
            controller->openProject(msclr::interop::marshal_as<string>(tmp));
        } else {
            startGUI start(controller);
            start.ShowDialog();
        }
        sr->Close();
    } 
}

void GUI::fAnfButton_Click(Object^ sender, EventArgs^ e) {
    fAnfGUI fAnf(controller);
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
    
}

Void GUI::neuToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {}

Void GUI::öffnenToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {}

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