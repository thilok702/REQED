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
	/// Summary for fAnfGUI
	/// </summary>
	public ref class fAnfGUI : public System::Windows::Forms::Form {
	private: Controller* controller;
	private: Projekt* projekt;
	private: bool bearbeiten;
	private: int index;
	public:
		fAnfGUI(Controller* contr, Projekt* pr, bool bearb, int ind)
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
		~fAnfGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ bedingung;
	private: System::Windows::Forms::Label^ verbindlichkeit;
	private: System::Windows::Forms::Label^ system;
	private: System::Windows::Forms::ComboBox^ verbindlichkeitCombobox;
	private: System::Windows::Forms::Label^ funktionalitaet;
	private: System::Windows::Forms::Label^ objekt;
	private: System::Windows::Forms::Label^ prozesswort;
	private: System::Windows::Forms::TextBox^ bedingungBox;
	private: System::Windows::Forms::TextBox^ systemBox;
	private: System::Windows::Forms::TextBox^ objektBox;
	private: System::Windows::Forms::TextBox^ prozesswortBox;
	private: System::Windows::Forms::ComboBox^ funktionalitaetCombobox;
	private: System::Windows::Forms::Label^ anforderung;
	private: System::Windows::Forms::Button^ okButton;
	private: System::Windows::Forms::Button^ abbrechenButton;
	private: System::Windows::Forms::Label^ fehler;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bedingung = (gcnew System::Windows::Forms::Label());
			this->verbindlichkeit = (gcnew System::Windows::Forms::Label());
			this->system = (gcnew System::Windows::Forms::Label());
			this->verbindlichkeitCombobox = (gcnew System::Windows::Forms::ComboBox());
			this->funktionalitaet = (gcnew System::Windows::Forms::Label());
			this->objekt = (gcnew System::Windows::Forms::Label());
			this->prozesswort = (gcnew System::Windows::Forms::Label());
			this->bedingungBox = (gcnew System::Windows::Forms::TextBox());
			this->systemBox = (gcnew System::Windows::Forms::TextBox());
			this->objektBox = (gcnew System::Windows::Forms::TextBox());
			this->prozesswortBox = (gcnew System::Windows::Forms::TextBox());
			this->funktionalitaetCombobox = (gcnew System::Windows::Forms::ComboBox());
			this->anforderung = (gcnew System::Windows::Forms::Label());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->abbrechenButton = (gcnew System::Windows::Forms::Button());
			this->fehler = (gcnew System::Windows::Forms::Label());
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
			this->verbindlichkeit->Location = System::Drawing::Point(150, 106);
			this->verbindlichkeit->Name = L"verbindlichkeit";
			this->verbindlichkeit->Size = System::Drawing::Size(110, 16);
			this->verbindlichkeit->TabIndex = 2;
			this->verbindlichkeit->Text = L"Verbindlichkeit";
			// 
			// system
			// 
			this->system->AutoSize = true;
			this->system->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->system->Location = System::Drawing::Point(304, 106);
			this->system->Name = L"system";
			this->system->Size = System::Drawing::Size(58, 16);
			this->system->TabIndex = 3;
			this->system->Text = L"System";
			// 
			// verbindlichkeitCombobox
			// 
			this->verbindlichkeitCombobox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->verbindlichkeitCombobox->FormattingEnabled = true;
			this->verbindlichkeitCombobox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"muss", L"sollte", L"wird" });
			this->verbindlichkeitCombobox->Location = System::Drawing::Point(153, 131);
			this->verbindlichkeitCombobox->Name = L"verbindlichkeitCombobox";
			this->verbindlichkeitCombobox->Size = System::Drawing::Size(121, 24);
			this->verbindlichkeitCombobox->TabIndex = 1;
			this->verbindlichkeitCombobox->Text = L"muss";
			this->verbindlichkeitCombobox->SelectedIndexChanged += gcnew System::EventHandler(this, &fAnfGUI::changed);
			this->verbindlichkeitCombobox->TextUpdate += gcnew System::EventHandler(this, &fAnfGUI::changed);
			// 
			// funktionalitaet
			// 
			this->funktionalitaet->AutoSize = true;
			this->funktionalitaet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->funktionalitaet->Location = System::Drawing::Point(434, 106);
			this->funktionalitaet->Name = L"funktionalitaet";
			this->funktionalitaet->Size = System::Drawing::Size(99, 16);
			this->funktionalitaet->TabIndex = 5;
			this->funktionalitaet->Text = L"Funktionalität";
			// 
			// objekt
			// 
			this->objekt->AutoSize = true;
			this->objekt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->objekt->Location = System::Drawing::Point(625, 106);
			this->objekt->Name = L"objekt";
			this->objekt->Size = System::Drawing::Size(52, 16);
			this->objekt->TabIndex = 6;
			this->objekt->Text = L"Objekt";
			// 
			// prozesswort
			// 
			this->prozesswort->AutoSize = true;
			this->prozesswort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->prozesswort->Location = System::Drawing::Point(762, 106);
			this->prozesswort->Name = L"prozesswort";
			this->prozesswort->Size = System::Drawing::Size(91, 16);
			this->prozesswort->TabIndex = 7;
			this->prozesswort->Text = L"Prozesswort";
			// 
			// bedingungBox
			// 
			this->bedingungBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bedingungBox->Location = System::Drawing::Point(20, 131);
			this->bedingungBox->Name = L"bedingungBox";
			this->bedingungBox->Size = System::Drawing::Size(100, 22);
			this->bedingungBox->TabIndex = 0;
			this->bedingungBox->TextChanged += gcnew System::EventHandler(this, &fAnfGUI::changed);
			// 
			// systemBox
			// 
			this->systemBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->systemBox->Location = System::Drawing::Point(307, 133);
			this->systemBox->Name = L"systemBox";
			this->systemBox->Size = System::Drawing::Size(100, 22);
			this->systemBox->TabIndex = 2;
			this->systemBox->TextChanged += gcnew System::EventHandler(this, &fAnfGUI::changed);
			// 
			// objektBox
			// 
			this->objektBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->objektBox->Location = System::Drawing::Point(628, 131);
			this->objektBox->Name = L"objektBox";
			this->objektBox->Size = System::Drawing::Size(100, 22);
			this->objektBox->TabIndex = 4;
			this->objektBox->TextChanged += gcnew System::EventHandler(this, &fAnfGUI::changed);
			// 
			// prozesswortBox
			// 
			this->prozesswortBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->prozesswortBox->Location = System::Drawing::Point(765, 131);
			this->prozesswortBox->Name = L"prozesswortBox";
			this->prozesswortBox->Size = System::Drawing::Size(100, 22);
			this->prozesswortBox->TabIndex = 5;
			this->prozesswortBox->TextChanged += gcnew System::EventHandler(this, &fAnfGUI::changed);
			// 
			// funktionalitaetCombobox
			// 
			this->funktionalitaetCombobox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->funktionalitaetCombobox->FormattingEnabled = true;
			this->funktionalitaetCombobox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Systemaktivität", L"Benutzerinteraktion",
					L"Schnittstellenanforderung"
			});
			this->funktionalitaetCombobox->Location = System::Drawing::Point(437, 131);
			this->funktionalitaetCombobox->Name = L"funktionalitaetCombobox";
			this->funktionalitaetCombobox->Size = System::Drawing::Size(155, 24);
			this->funktionalitaetCombobox->TabIndex = 3;
			this->funktionalitaetCombobox->Text = L"Systemaktivität";
			this->funktionalitaetCombobox->SelectedIndexChanged += gcnew System::EventHandler(this, &fAnfGUI::changed);
			// 
			// anforderung
			// 
			this->anforderung->AutoSize = true;
			this->anforderung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->anforderung->Location = System::Drawing::Point(17, 200);
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
			this->okButton->Click += gcnew System::EventHandler(this, &fAnfGUI::okButton_Click);
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
			this->abbrechenButton->Click += gcnew System::EventHandler(this, &fAnfGUI::abbrechenButton_Click);
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
			// fAnfGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(897, 396);
			this->Controls->Add(this->fehler);
			this->Controls->Add(this->abbrechenButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->anforderung);
			this->Controls->Add(this->funktionalitaetCombobox);
			this->Controls->Add(this->prozesswortBox);
			this->Controls->Add(this->objektBox);
			this->Controls->Add(this->systemBox);
			this->Controls->Add(this->prozesswort);
			this->Controls->Add(this->objekt);
			this->Controls->Add(this->funktionalitaet);
			this->Controls->Add(this->verbindlichkeitCombobox);
			this->Controls->Add(this->system);
			this->Controls->Add(this->verbindlichkeit);
			this->Controls->Add(this->bedingung);
			this->Controls->Add(this->bedingungBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"fAnfGUI";
			this->Text = L"fAnfGUI";
			this->Load += gcnew System::EventHandler(this, &fAnfGUI::fAnfGUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void fAnfGUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void changed(System::Object^ sender, System::EventArgs^ e);
	private: System::String^ getFunktionalitaet(int index);
	private: int getIndexFromFunkt(std::string funkt);
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void abbrechenButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
