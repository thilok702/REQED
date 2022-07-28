#include "startGUI.h"
#include <msclr\marshal_cppstd.h>
#include <string>
using namespace REQED;
using namespace System;
using namespace System::IO;
using namespace std;

Void startGUI::oeffnenButton_Click(Object^ sender, EventArgs^ e) {
    OpenFileDialog^ ofd = gcnew OpenFileDialog;
    ofd->Filter = "REQED (*.RQ)|*.RQ";
    ofd->FilterIndex = 2;
    if(ofd->ShowDialog() == Windows::Forms::DialogResult::OK) {
        controller->openProject(msclr::interop::marshal_as<string>(ofd->FileName));
        this->Close();
    }
}

Void startGUI::neuButton_Click(Object^ sender, EventArgs^ e) {
    SaveFileDialog^ sfd = gcnew SaveFileDialog;
    sfd->FileName = "Projekt1";
    sfd->DefaultExt = "RQ";
    sfd->Filter = "REQED (*.RQ)|*.RQ";
    sfd->OverwritePrompt = true;
    if(sfd->ShowDialog() == Windows::Forms::DialogResult::OK) {
        StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
        sw->WriteLine("");
        sw->Close();
        this->Close();
    }
}

Void startGUI::startGUI_FormClosed(Object^ sender, FormClosedEventArgs^ e) {
    Application::Exit();
}


//StreamReader^ sr;
//if((sr = gcnew StreamReader(ofd->FileName)) != nullptr) {
//    label1->Text = sr->ReadLine();
//    sr->Close();
//}