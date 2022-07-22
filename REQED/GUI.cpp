#include "GUI.h"
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace REQED;

void GUI::button1_Click(Object^ sender, EventArgs^ e) {
    //SaveFileDialog^ sfd = gcnew SaveFileDialog;
    //sfd->FileName = "test";
    //sfd->DefaultExt = ".RQ";
    //sfd->Filter = "REQED (*.RQ)|*.RQ";
    //if(sfd->ShowDialog() == Windows::Forms::DialogResult::OK) {
    //    StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
    //    sw->WriteLine("Hallo");
    //    sw->Close();
    //}

    //OpenFileDialog^ ofd = gcnew OpenFileDialog;
    ////ofd->InitialDirectory = "c:\\";
    //ofd->Filter = "REQED (*.RQ)|*.RQ";
    //ofd->FilterIndex = 2;
    //ofd->RestoreDirectory = true;

    //if(ofd->ShowDialog() == Windows::Forms::DialogResult::OK) {
    //    label1->Text = gcnew String(ofd->FileName);
    //    StreamReader^ sr;
    //    if((sr = gcnew StreamReader(ofd->FileName)) != nullptr) {
    //        label1->Text = sr->ReadLine();
    //        sr->Close();
    //    }
    //}

    //MessageBox::Show("hallo");
    /*FolderBrowserDialog^ obd = gcnew FolderBrowserDialog;
    obd->Description = "Test";
    if(obd->ShowDialog() == Windows::Forms::DialogResult::OK) {
        label1->Text = gcnew String(obd->SelectedPath);
    }*/

    int top = 50;
    int left = 100;
    for(int i = 0; i < 5; i++) {
        Button^ button = gcnew Button;
        button->Left = left;
        button->Top = top;
        button->Click += gcnew EventHandler(this, &GUI::button_Click);
        this->Controls->Add(button);
        top += button->Height + 2;
    }
    
}

Void GUI::button_Click(Object^ sender, EventArgs^ e) {
    for each(Control^ c in this->Controls) {
        if(c->GetHashCode() == sender->GetHashCode()) {
            this->Controls->Remove(c);
        }
    }
    
}