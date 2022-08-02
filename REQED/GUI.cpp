#include "GUI.h"
#include "fAnfGUI.h"
#include <msclr\marshal_cppstd.h>
#include "startGUI.h"
#include "nfAnfGUI.h"
#include <fstream>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Drawing;
using namespace REQED;

void GUI::setProjekt(Projekt* proj) {
    projekt = proj;
}

void GUI::modelChanged() {
    show();
}

void GUI::show() {
    if(projekt->isSaved()) {
        this->Text = "REQED";
    } else {
        this->Text = "REQED *";
    }
    this->Controls->Clear();
    this->Controls->Add(this->toolStrip1);
    this->Controls->Add(this->fAnf);
    this->Controls->Add(this->fAnfButton);
    this->Controls->Add(this->nfAnf);
    this->Controls->Add(this->nfAnfButton);
    int xAnf = this->fAnf->Location.X;
    int yAnf = this->fAnf->Location.Y + 20;
    int tabindex = 0;
    for(int i = 0; i < projekt->anzFanf(); i++) {
        string anf = "";
        string tmp = projekt->getFanf(i)->toString();
        while(tmp.size() > 80) {
            size_t pos = tmp.rfind(" ", 80);
            anf += tmp.substr(0, pos) + "\r\n";
            tmp = tmp.substr(pos+1);
        }
        anf += tmp;
        //Anforderung
        Label^ label = gcnew Label;
        label->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 11, FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(0)));
        label->Location = Point(xAnf, yAnf);
        label->AutoSize = true;
        label->Name = L"lf_" + i;
        label->Text = gcnew String(anf.c_str());
        this->Controls->Add(label);
        //bearbeiten-button
        Button^ button1 = gcnew Button;
        button1->BackColor = Color::FromArgb(static_cast<Int32>(static_cast<Byte>(192)), static_cast<Int32>(static_cast<Byte>(0)), static_cast<Int32>(static_cast<Byte>(0)));
        button1->FlatAppearance->BorderSize = 0;
        button1->FlatStyle = FlatStyle::Flat;
        button1->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 10, FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(0)));
        button1->ForeColor = Color::White;
        button1->Location = Point(xAnf + 610, yAnf);
        button1->Size = Drawing::Size(85, 25);
        button1->Name = L"bf_" + i;
        button1->TabIndex = tabindex;
        button1->Text = L"bearbeiten";
        button1->Click += gcnew EventHandler(this, &GUI::buttonBearbeiten_Click);
        this->Controls->Add(button1);
        //loeschen-button
        Button^ button2 = gcnew Button;
        button2->BackColor = Color::FromArgb(static_cast<Int32>(static_cast<Byte>(192)), static_cast<Int32>(static_cast<Byte>(0)), static_cast<Int32>(static_cast<Byte>(0)));
        button2->FlatAppearance->BorderSize = 0;
        button2->FlatStyle = FlatStyle::Flat;
        button2->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 10, FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(0)));
        button2->ForeColor = Color::White;
        button2->Location = Point(xAnf + 610 + 86, yAnf);
        button2->Size = Drawing::Size(85, 25);
        button2->Name = L"lbf_" + i;
        button2->TabIndex = tabindex + 1;
        button2->Text = L"löschen";
        button2->Click += gcnew EventHandler(this, &GUI::buttonLoeschen_Click);
        this->Controls->Add(button2);
        tabindex += 2;
        if(label->Height > 20) {
            yAnf += label->Height + 2;
        } else {
            yAnf += 27;
        }
    }
    this->fAnfButton->Location = Point(xAnf, yAnf + 3);
    this->fAnfButton->TabIndex = tabindex;
    this->nfAnf->Location = Point(xAnf, yAnf + 3 + 30 + 80);
    tabindex++;
    yAnf = this->nfAnf->Location.Y + 20;
    for(int i = 0; i < projekt->anzNFanf(); i++) {
        string anf = "";
        string tmp = projekt->getFanf(i)->toString();
        while(tmp.size() > 80) {
            size_t pos = tmp.rfind(" ", 80);
            anf += tmp.substr(0, pos) + "\r\n";
            tmp = tmp.substr(pos + 1);
        }
        anf += tmp;
        //Anforderung
        Label^ label = gcnew Label;
        label->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 11, FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(0)));
        label->Location = Point(xAnf, yAnf);
        label->AutoSize = true;
        label->Name = L"lnf_" + i;
        label->Text = gcnew String(anf.c_str());
        this->Controls->Add(label);
        //bearbeiten-button
        Button^ button1 = gcnew Button;
        button1->BackColor = Color::FromArgb(static_cast<Int32>(static_cast<Byte>(192)), static_cast<Int32>(static_cast<Byte>(0)), static_cast<Int32>(static_cast<Byte>(0)));
        button1->FlatAppearance->BorderSize = 0;
        button1->FlatStyle = FlatStyle::Flat;
        button1->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 10, FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(0)));
        button1->ForeColor = Color::White;
        button1->Location = Point(xAnf + 610, yAnf);
        button1->Size = Drawing::Size(85, 25);
        button1->Name = L"bnf_" + i;
        button1->TabIndex = tabindex;
        button1->Text = L"bearbeiten";
        button1->Click += gcnew EventHandler(this, &GUI::buttonBearbeiten_Click);
        this->Controls->Add(button1);
        //loeschen-button
        Button^ button2 = gcnew Button;
        button2->BackColor = Color::FromArgb(static_cast<Int32>(static_cast<Byte>(192)), static_cast<Int32>(static_cast<Byte>(0)), static_cast<Int32>(static_cast<Byte>(0)));
        button2->FlatAppearance->BorderSize = 0;
        button2->FlatStyle = FlatStyle::Flat;
        button2->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 10, FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(0)));
        button2->ForeColor = Color::White;
        button2->Location = Point(xAnf + 610 + 86, yAnf);
        button2->Size = Drawing::Size(85, 25);
        button2->Name = L"lbnf_" + i;
        button2->TabIndex = tabindex + 1;
        button2->Text = L"löschen";
        button2->Click += gcnew EventHandler(this, &GUI::buttonLoeschen_Click);
        this->Controls->Add(button2);
        tabindex += 2;
        if(label->Height > 20) {
            yAnf += label->Height + 2;
        } else {
            yAnf += 27;
        }
    }
    this->nfAnfButton->Location = Point(xAnf, yAnf + 3);
    this->nfAnfButton->TabIndex = tabindex;
}

Void GUI::buttonBearbeiten_Click(Object^ sender, EventArgs^ e) {
    Button^ button = safe_cast<Button^>(sender);
    auto tmp = button->Name->Split('_');
    int num = Int32::Parse(tmp[1]);
    if(tmp[0][tmp->Length - 2] != 'n') {
        fAnfGUI^ fAnf = gcnew fAnfGUI(controller, projekt, true, num);
        fAnf->ShowDialog();
    } else {
        nfAnfGUI^ nfAnf = gcnew nfAnfGUI(controller, projekt, true, num);
        nfAnf->ShowDialog();
    }
}
Void GUI::buttonLoeschen_Click(Object^ sender, EventArgs^ e) {
    Button^ button = safe_cast<Button^>(sender);
    auto tmp = button->Name->Split('_');
    String^ num = tmp[1];
    if(tmp[0][tmp->Length - 2] != 'n') {
        this->Controls->Remove(button);
        this->Controls->Remove(this->Controls->Find("lf_" + num, false)[0]);
        this->Controls->Remove(this->Controls->Find("bf_" + num, false)[0]);
        string ind[1] = {msclr::interop::marshal_as<string>(num) };
        controller->processInput(7, ind);
    } else {
        this->Controls->Remove(button);
        this->Controls->Remove(this->Controls->Find("lnf_" + num, false)[0]);
        this->Controls->Remove(this->Controls->Find("bnf_" + num, false)[0]);
        string ind[1] = {msclr::interop::marshal_as<string>(num)};
        controller->processInput(8, ind);
    }
}
    

Void GUI::GUI_Load(System::Object^ sender, System::EventArgs^ e) {
    StreamReader^ sr;
    if((sr = gcnew StreamReader("letztesProjekt.txt")) != nullptr) {
        String^ tmp = sr->ReadLine();
        sr->Close();
        if(tmp != nullptr && tmp->Length > 0) {
            ifstream f(msclr::interop::marshal_as<string>(tmp).c_str());
            f.close();
            if(f.good()) {
                projekt = controller->openProject(msclr::interop::marshal_as<string>(tmp), this).get();
            } else {
                StreamWriter^ sw;
                if((sw = gcnew StreamWriter("letztesProjekt.txt")) != nullptr) {
                    sw->WriteLine("");
                    sw->Close();
                }
                startGUI^ start = gcnew startGUI(this, controller);
                start->ShowDialog();
            }
        } else {
            startGUI^ start = gcnew startGUI(this, controller);
            start->ShowDialog();
        }
    }
}

Void GUI::GUI_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
    if(projekt != NULL) {
        if(!controller->projektSaved()) {
            if(MessageBox::Show("Projekt nicht gespeichert, wollen sie fortfahren?", "Programm schließen", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) != Windows::Forms::DialogResult::OK) {
                e->Cancel = true;
                return;
            }
        }
        StreamWriter^ sw;
        if((sw = gcnew StreamWriter("letztesProjekt.txt")) != nullptr) {
            sw->WriteLine(gcnew String(projekt->getPfad().c_str()));
            sw->Close();
        }
    }
}

void GUI::fAnfButton_Click(Object^ sender, EventArgs^ e) {
    fAnfGUI^ fAnf = gcnew fAnfGUI(controller, projekt, false, 0);
    fAnf->ShowDialog();
}

Void GUI::nfAnfButton_Click(Object^ sender, EventArgs^ e) {
    nfAnfGUI^ nfAnf = gcnew nfAnfGUI(controller, projekt, false, 0);
    nfAnf->ShowDialog();
}

Void GUI::neuToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
    if(!controller->projektSaved()) {
        if(MessageBox::Show("Projekt nicht gespeichert, wollen sie fortfahren?", "neues Projekt", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) != Windows::Forms::DialogResult::OK) {
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
        StreamWriter^ sw;
        if((sw = gcnew StreamWriter(sfd->FileName)) != nullptr) {
            sw->WriteLine("");
            sw->Close();
        }
        projekt = controller->openProject(msclr::interop::marshal_as<string>(sfd->FileName), this).get();
    }
}

Void GUI::öffnenToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
    if(!controller->projektSaved()) {
        if(MessageBox::Show("Projekt nicht gespeichert, wollen sie fortfahren?", "Projekt öfnnen", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) != Windows::Forms::DialogResult::OK) {
            return;
        }
    }
    OpenFileDialog^ ofd = gcnew OpenFileDialog;
    ofd->Filter = "REQED (*.RQ)|*.RQ";
    if(ofd->ShowDialog() == Windows::Forms::DialogResult::OK) {
        projekt = controller->openProject(msclr::interop::marshal_as<string>(ofd->FileName), this).get();
    }
}

Void GUI::speichernToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
    string leer[1] = {""};
    controller->processInput(0, leer);
}

Void GUI::textDateiToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
    SaveFileDialog^ sfd = gcnew SaveFileDialog;
    sfd->FileName = "Anforderungen";
    sfd->DefaultExt = "txt";
    sfd->Filter = "Text (*.txt)|*.txt";
    sfd->OverwritePrompt = true;
    sfd->AddExtension = true;
    if(sfd->ShowDialog() == Windows::Forms::DialogResult::OK) {
        string pfad[1] = {msclr::interop::marshal_as<string>(sfd->FileName)};
        controller->processInput(1, pfad);
    }
}

Void GUI::jSONDateiToolStripMenuItem_Click(Object^ sender, EventArgs^ e) { 
    SaveFileDialog^ sfd = gcnew SaveFileDialog;
    sfd->FileName = "Anforderungen";
    sfd->DefaultExt = "JSON";
    sfd->Filter = "JSON (*.JSON)|*.JSON";
    sfd->OverwritePrompt = true;
    sfd->AddExtension = true;
    if(sfd->ShowDialog() == Windows::Forms::DialogResult::OK) {
        string pfad[1] = {msclr::interop::marshal_as<string>(sfd->FileName)};
        controller->processInput(2, pfad);
    }
}