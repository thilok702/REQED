#pragma once
#include "Controller.h"
#include "Projekt.h"

namespace REQED {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for nnfAnfGUI
	/// </summary>
	public ref class nfAnfGUI : public System::Windows::Forms::Form 
	{
	private: Controller* controller;
	private: System::Windows::Forms::TextBox^ gegenstandBox;
	private: Projekt* projekt;
	private: bool bearbeiten;
	private: int index;
	public:
		nfAnfGUI(Controller* contr, Projekt* pr, bool bearb, int ind)
		{
			projekt = pr;
			controller = contr;
			bearbeiten = bearb;
			index = ind;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
		~nfAnfGUI()
		{
			if(components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ bedingung;
	private: System::Windows::Forms::Label^ verbindlichkeit;
	private: System::Windows::Forms::Label^ eigenschaft;

	private: System::Windows::Forms::ComboBox^ verbindlichkeitCombobox;
	private: System::Windows::Forms::Label^ funktionalitaet;
	private: System::Windows::Forms::Label^ oper;
	private: System::Windows::Forms::Label^ wert;


	private: System::Windows::Forms::TextBox^ bedingungBox;
	private: System::Windows::Forms::TextBox^ eigenschaftBox;
	private: System::Windows::Forms::TextBox^ operatorBox;
	private: System::Windows::Forms::TextBox^ wertBox;




	private: System::Windows::Forms::Label^ anforderung;
	private: System::Windows::Forms::Button^ okButton;
	private: System::Windows::Forms::Button^ abbrechenButton;
	private: System::Windows::Forms::Label^ fehler;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bedingung = (gcnew System::Windows::Forms::Label());
			this->verbindlichkeit = (gcnew System::Windows::Forms::Label());
			this->eigenschaft = (gcnew System::Windows::Forms::Label());
			this->verbindlichkeitCombobox = (gcnew System::Windows::Forms::ComboBox());
			this->funktionalitaet = (gcnew System::Windows::Forms::Label());
			this->oper = (gcnew System::Windows::Forms::Label());
			this->wert = (gcnew System::Windows::Forms::Label());
			this->bedingungBox = (gcnew System::Windows::Forms::TextBox());
			this->eigenschaftBox = (gcnew System::Windows::Forms::TextBox());
			this->operatorBox = (gcnew System::Windows::Forms::TextBox());
			this->wertBox = (gcnew System::Windows::Forms::TextBox());
			this->anforderung = (gcnew System::Windows::Forms::Label());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->abbrechenButton = (gcnew System::Windows::Forms::Button());
			this->fehler = (gcnew System::Windows::Forms::Label());
			this->gegenstandBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// bedingung
			// 
			this->bedingung->AutoSize = true;
			this->bedingung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bedingung->Location = System::Drawing::Point(17, 106);
			this->bedingung->Name = L"bedingung";
			this->bedingung->Size = System::Drawing::Size(81, 16);
			this->bedingung->TabIndex = 1;
			this->bedingung->Text = L"Bedingung";
			// 
			// verbindlichkeit
			// 
			this->verbindlichkeit->AutoSize = true;
			this->verbindlichkeit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->verbindlichkeit->Location = System::Drawing::Point(153, 106);
			this->verbindlichkeit->Name = L"verbindlichkeit";
			this->verbindlichkeit->Size = System::Drawing::Size(110, 16);
			this->verbindlichkeit->TabIndex = 2;
			this->verbindlichkeit->Text = L"Verbindlichkeit";
			// 
			// eigenschaft
			// 
			this->eigenschaft->AutoSize = true;
			this->eigenschaft->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eigenschaft->Location = System::Drawing::Point(313, 106);
			this->eigenschaft->Name = L"eigenschaft";
			this->eigenschaft->Size = System::Drawing::Size(88, 16);
			this->eigenschaft->TabIndex = 3;
			this->eigenschaft->Text = L"Eigenschaft";
			// 
			// verbindlichkeitCombobox
			// 
			this->verbindlichkeitCombobox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->verbindlichkeitCombobox->FormattingEnabled = true;
			this->verbindlichkeitCombobox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"muss", L"sollte", L"wird" });
			this->verbindlichkeitCombobox->Location = System::Drawing::Point(156, 131);
			this->verbindlichkeitCombobox->Name = L"verbindlichkeitCombobox";
			this->verbindlichkeitCombobox->Size = System::Drawing::Size(121, 24);
			this->verbindlichkeitCombobox->TabIndex = 1;
			this->verbindlichkeitCombobox->Text = L"muss";
			this->verbindlichkeitCombobox->SelectedIndexChanged += gcnew System::EventHandler(this, &nfAnfGUI::changed);
			this->verbindlichkeitCombobox->TextUpdate += gcnew System::EventHandler(this, &nfAnfGUI::changed);
			// 
			// funktionalitaet
			// 
			this->funktionalitaet->AutoSize = true;
			this->funktionalitaet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->funktionalitaet->Location = System::Drawing::Point(447, 90);
			this->funktionalitaet->Name = L"funktionalitaet";
			this->funktionalitaet->Size = System::Drawing::Size(102, 32);
			this->funktionalitaet->TabIndex = 5;
			this->funktionalitaet->Text = L"Betrachtungs-\r\ngegenstand";
			// 
			// oper
			// 
			this->oper->AutoSize = true;
			this->oper->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->oper->Location = System::Drawing::Point(596, 90);
			this->oper->Name = L"oper";
			this->oper->Size = System::Drawing::Size(86, 32);
			this->oper->TabIndex = 6;
			this->oper->Text = L"Vergleichs-\r\noperator";
			// 
			// wert
			// 
			this->wert->AutoSize = true;
			this->wert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wert->Location = System::Drawing::Point(746, 106);
			this->wert->Name = L"wert";
			this->wert->Size = System::Drawing::Size(39, 16);
			this->wert->TabIndex = 7;
			this->wert->Text = L"Wert";
			// 
			// bedingungBox
			// 
			this->bedingungBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bedingungBox->Location = System::Drawing::Point(20, 131);
			this->bedingungBox->Name = L"bedingungBox";
			this->bedingungBox->Size = System::Drawing::Size(100, 22);
			this->bedingungBox->TabIndex = 0;
			this->bedingungBox->TextChanged += gcnew System::EventHandler(this, &nfAnfGUI::changed);
			// 
			// eigenschaftBox
			// 
			this->eigenschaftBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eigenschaftBox->Location = System::Drawing::Point(316, 131);
			this->eigenschaftBox->Name = L"eigenschaftBox";
			this->eigenschaftBox->Size = System::Drawing::Size(100, 22);
			this->eigenschaftBox->TabIndex = 2;
			this->eigenschaftBox->TextChanged += gcnew System::EventHandler(this, &nfAnfGUI::changed);
			// 
			// operatorBox
			// 
			this->operatorBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->operatorBox->Location = System::Drawing::Point(599, 131);
			this->operatorBox->Name = L"operatorBox";
			this->operatorBox->Size = System::Drawing::Size(100, 22);
			this->operatorBox->TabIndex = 4;
			this->operatorBox->TextChanged += gcnew System::EventHandler(this, &nfAnfGUI::changed);
			// 
			// wertBox
			// 
			this->wertBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wertBox->Location = System::Drawing::Point(749, 131);
			this->wertBox->Name = L"wertBox";
			this->wertBox->Size = System::Drawing::Size(100, 22);
			this->wertBox->TabIndex = 5;
			this->wertBox->TextChanged += gcnew System::EventHandler(this, &nfAnfGUI::changed);
			// 
			// anforderung
			// 
			this->anforderung->AutoSize = true;
			this->anforderung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->anforderung->Location = System::Drawing::Point(39, 201);
			this->anforderung->Name = L"anforderung";
			this->anforderung->Size = System::Drawing::Size(0, 18);
			this->anforderung->TabIndex = 12;
			// 
			// okButton
			// 
			this->okButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->okButton->FlatAppearance->BorderSize = 0;
			this->okButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->okButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->okButton->ForeColor = System::Drawing::Color::White;
			this->okButton->Location = System::Drawing::Point(298, 326);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(100, 30);
			this->okButton->TabIndex = 6;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = false;
			this->okButton->Click += gcnew System::EventHandler(this, &nfAnfGUI::okButton_Click);
			// 
			// abbrechenButton
			// 
			this->abbrechenButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->abbrechenButton->FlatAppearance->BorderSize = 0;
			this->abbrechenButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->abbrechenButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->abbrechenButton->ForeColor = System::Drawing::Color::White;
			this->abbrechenButton->Location = System::Drawing::Point(460, 326);
			this->abbrechenButton->Name = L"abbrechenButton";
			this->abbrechenButton->Size = System::Drawing::Size(100, 30);
			this->abbrechenButton->TabIndex = 7;
			this->abbrechenButton->Text = L"abbrechen";
			this->abbrechenButton->UseVisualStyleBackColor = false;
			this->abbrechenButton->Click += gcnew System::EventHandler(this, &nfAnfGUI::abbrechenButton_Click);
			// 
			// fehler
			// 
			this->fehler->AutoSize = true;
			this->fehler->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fehler->ForeColor = System::Drawing::Color::Red;
			this->fehler->Location = System::Drawing::Point(153, 37);
			this->fehler->Name = L"fehler";
			this->fehler->Size = System::Drawing::Size(0, 16);
			this->fehler->TabIndex = 13;
			// 
			// gegenstandBox
			// 
			this->gegenstandBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gegenstandBox->Location = System::Drawing::Point(450, 133);
			this->gegenstandBox->Name = L"gegenstandBox";
			this->gegenstandBox->Size = System::Drawing::Size(100, 22);
			this->gegenstandBox->TabIndex = 3;
			// 
			// nfAnfGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(897, 396);
			this->Controls->Add(this->gegenstandBox);
			this->Controls->Add(this->fehler);
			this->Controls->Add(this->abbrechenButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->anforderung);
			this->Controls->Add(this->wertBox);
			this->Controls->Add(this->operatorBox);
			this->Controls->Add(this->eigenschaftBox);
			this->Controls->Add(this->wert);
			this->Controls->Add(this->oper);
			this->Controls->Add(this->funktionalitaet);
			this->Controls->Add(this->verbindlichkeitCombobox);
			this->Controls->Add(this->eigenschaft);
			this->Controls->Add(this->verbindlichkeit);
			this->Controls->Add(this->bedingung);
			this->Controls->Add(this->bedingungBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"nfAnfGUI";
			this->Text = L"nfAnfGUI";
			this->Load += gcnew System::EventHandler(this, &nfAnfGUI::nfAnfGUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void nfAnfGUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void changed(System::Object^ sender, System::EventArgs^ e);
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void abbrechenButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
