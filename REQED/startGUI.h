#pragma once
#include "Controller.h"
#include "GUI.h"

namespace REQED {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for startGUI
	/// </summary>
	public ref class startGUI : public System::Windows::Forms::Form
	{
	private: Controller* controller;
	private: GUI^ main;
	private: bool gueltig;
	public:
		startGUI(GUI^ gui, Controller* contr)
		{
			main = gui;
			controller = contr;
			gueltig = false;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~startGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ message;
	protected:
	private: System::Windows::Forms::Button^ oeffnenButton;
	private: System::Windows::Forms::Button^ neuButton;

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
			this->message = (gcnew System::Windows::Forms::Label());
			this->oeffnenButton = (gcnew System::Windows::Forms::Button());
			this->neuButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// message
			// 
			this->message->AutoSize = true;
			this->message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->message->Location = System::Drawing::Point(160, 81);
			this->message->Name = L"message";
			this->message->Size = System::Drawing::Size(356, 20);
			this->message->TabIndex = 0;
			this->message->Text = L"Es wurde kein zuletztgeöffntes Projekt gefunden!";
			// 
			// oeffnenButton
			// 
			this->oeffnenButton->BackColor = System::Drawing::Color::Maroon;
			this->oeffnenButton->FlatAppearance->BorderSize = 0;
			this->oeffnenButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->oeffnenButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->oeffnenButton->ForeColor = System::Drawing::Color::White;
			this->oeffnenButton->Location = System::Drawing::Point(272, 145);
			this->oeffnenButton->Name = L"oeffnenButton";
			this->oeffnenButton->Size = System::Drawing::Size(90, 38);
			this->oeffnenButton->TabIndex = 1;
			this->oeffnenButton->Text = L"öffnen";
			this->oeffnenButton->UseVisualStyleBackColor = false;
			this->oeffnenButton->Click += gcnew System::EventHandler(this, &startGUI::oeffnenButton_Click);
			// 
			// neuButton
			// 
			this->neuButton->BackColor = System::Drawing::Color::Maroon;
			this->neuButton->FlatAppearance->BorderSize = 0;
			this->neuButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->neuButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->neuButton->ForeColor = System::Drawing::Color::White;
			this->neuButton->Location = System::Drawing::Point(272, 227);
			this->neuButton->Name = L"neuButton";
			this->neuButton->Size = System::Drawing::Size(90, 38);
			this->neuButton->TabIndex = 2;
			this->neuButton->Text = L"neu";
			this->neuButton->UseVisualStyleBackColor = false;
			this->neuButton->Click += gcnew System::EventHandler(this, &startGUI::neuButton_Click);
			// 
			// startGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(718, 505);
			this->Controls->Add(this->neuButton);
			this->Controls->Add(this->oeffnenButton);
			this->Controls->Add(this->message);
			this->Name = L"startGUI";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"REQED";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &startGUI::startGUI_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void oeffnenButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void neuButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void startGUI_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	};
}
