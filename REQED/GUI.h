#pragma once
#include "Controller.h"
#include "Projekt.h"
#include "View.h"
#include <memory>

namespace REQED {
	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI: public System::Windows::Forms::Form, public View {
	private: Controller* controller;
	private: Projekt* projekt;
	public:
		GUI() {
			projekt = NULL;
			controller = new Controller();
			InitializeComponent();
		}
		virtual void modelChanged();
		void setProjekt(Projekt* proj);
	private:
		
	   
		void show();
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI() {
			if(components) {
				delete components;
			}
			delete controller;
			//delete projekt; wuerde Exception produzieren, da per shared_ptr erstellt
		}
	private: System::Windows::Forms::Label^ fAnf;
	private: System::Windows::Forms::Button^ fAnfButton;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripDropDownButton^ DateiDropDown;
	private: System::Windows::Forms::ToolStripMenuItem^ öffnenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ speichernToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ neuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripDropDownButton^ exportDropDown;
	private: System::Windows::Forms::ToolStripMenuItem^ textDateiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ jSONDateiToolStripMenuItem;
	private: System::Windows::Forms::Label^ nfAnf;
	private: System::Windows::Forms::Button^ nfAnfButton;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::IContainer^ components;

	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GUI::typeid));
			this->fAnf = (gcnew System::Windows::Forms::Label());
			this->fAnfButton = (gcnew System::Windows::Forms::Button());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->DateiDropDown = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->neuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->öffnenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speichernToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportDropDown = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->textDateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->jSONDateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nfAnf = (gcnew System::Windows::Forms::Label());
			this->nfAnfButton = (gcnew System::Windows::Forms::Button());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// fAnf
			// 
			this->fAnf->AutoSize = true;
			this->fAnf->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fAnf->Location = System::Drawing::Point(23, 69);
			this->fAnf->Name = L"fAnf";
			this->fAnf->Size = System::Drawing::Size(219, 19);
			this->fAnf->TabIndex = 0;
			this->fAnf->Text = L"funktionale Anforderungen:";
			// 
			// fAnfButton
			// 
			this->fAnfButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->fAnfButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->fAnfButton->FlatAppearance->BorderSize = 0;
			this->fAnfButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->fAnfButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fAnfButton->ForeColor = System::Drawing::Color::White;
			this->fAnfButton->Location = System::Drawing::Point(27, 91);
			this->fAnfButton->Name = L"fAnfButton";
			this->fAnfButton->Size = System::Drawing::Size(70, 30);
			this->fAnfButton->TabIndex = 1;
			this->fAnfButton->Text = L"neu";
			this->fAnfButton->UseVisualStyleBackColor = false;
			this->fAnfButton->Click += gcnew System::EventHandler(this, &GUI::fAnfButton_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::Color::White;
			this->toolStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->DateiDropDown, this->exportDropDown });
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(834, 27);
			this->toolStrip1->TabIndex = 3;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// DateiDropDown
			// 
			this->DateiDropDown->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->DateiDropDown->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->neuToolStripMenuItem,
					this->öffnenToolStripMenuItem, this->speichernToolStripMenuItem
			});
			this->DateiDropDown->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DateiDropDown->ForeColor = System::Drawing::Color::Black;
			this->DateiDropDown->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DateiDropDown.Image")));
			this->DateiDropDown->Name = L"DateiDropDown";
			this->DateiDropDown->ShowDropDownArrow = false;
			this->DateiDropDown->Size = System::Drawing::Size(49, 24);
			this->DateiDropDown->Text = L"Datei";
			// 
			// neuToolStripMenuItem
			// 
			this->neuToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->neuToolStripMenuItem->Name = L"neuToolStripMenuItem";
			this->neuToolStripMenuItem->Size = System::Drawing::Size(141, 24);
			this->neuToolStripMenuItem->Text = L"neu";
			this->neuToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::neuToolStripMenuItem_Click);
			// 
			// öffnenToolStripMenuItem
			// 
			this->öffnenToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->öffnenToolStripMenuItem->Name = L"öffnenToolStripMenuItem";
			this->öffnenToolStripMenuItem->Size = System::Drawing::Size(141, 24);
			this->öffnenToolStripMenuItem->Text = L"öffnen";
			this->öffnenToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::öffnenToolStripMenuItem_Click);
			// 
			// speichernToolStripMenuItem
			// 
			this->speichernToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->speichernToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"speichernToolStripMenuItem.Image")));
			this->speichernToolStripMenuItem->Name = L"speichernToolStripMenuItem";
			this->speichernToolStripMenuItem->Size = System::Drawing::Size(141, 24);
			this->speichernToolStripMenuItem->Text = L"speichern";
			this->speichernToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::speichernToolStripMenuItem_Click);
			// 
			// exportDropDown
			// 
			this->exportDropDown->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->exportDropDown->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->textDateiToolStripMenuItem,
					this->jSONDateiToolStripMenuItem
			});
			this->exportDropDown->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exportDropDown->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exportDropDown.Image")));
			this->exportDropDown->Name = L"exportDropDown";
			this->exportDropDown->ShowDropDownArrow = false;
			this->exportDropDown->Size = System::Drawing::Size(56, 24);
			this->exportDropDown->Text = L"Export";
			// 
			// textDateiToolStripMenuItem
			// 
			this->textDateiToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textDateiToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textDateiToolStripMenuItem.Image")));
			this->textDateiToolStripMenuItem->Name = L"textDateiToolStripMenuItem";
			this->textDateiToolStripMenuItem->Size = System::Drawing::Size(155, 24);
			this->textDateiToolStripMenuItem->Text = L"Text-Datei";
			this->textDateiToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::textDateiToolStripMenuItem_Click);
			// 
			// jSONDateiToolStripMenuItem
			// 
			this->jSONDateiToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->jSONDateiToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"jSONDateiToolStripMenuItem.Image")));
			this->jSONDateiToolStripMenuItem->Name = L"jSONDateiToolStripMenuItem";
			this->jSONDateiToolStripMenuItem->Size = System::Drawing::Size(155, 24);
			this->jSONDateiToolStripMenuItem->Text = L"JSON-Datei";
			this->jSONDateiToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::jSONDateiToolStripMenuItem_Click);
			// 
			// nfAnf
			// 
			this->nfAnf->AutoSize = true;
			this->nfAnf->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nfAnf->Location = System::Drawing::Point(23, 200);
			this->nfAnf->Name = L"nfAnf";
			this->nfAnf->Size = System::Drawing::Size(266, 19);
			this->nfAnf->TabIndex = 4;
			this->nfAnf->Text = L"nicht funktionale Anfortderungen:";
			// 
			// nfAnfButton
			// 
			this->nfAnfButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->nfAnfButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->nfAnfButton->FlatAppearance->BorderSize = 0;
			this->nfAnfButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->nfAnfButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nfAnfButton->ForeColor = System::Drawing::Color::White;
			this->nfAnfButton->Location = System::Drawing::Point(27, 222);
			this->nfAnfButton->Name = L"nfAnfButton";
			this->nfAnfButton->Size = System::Drawing::Size(70, 30);
			this->nfAnfButton->TabIndex = 5;
			this->nfAnfButton->Text = L"neu";
			this->nfAnfButton->UseVisualStyleBackColor = false;
			this->nfAnfButton->Click += gcnew System::EventHandler(this, &GUI::nfAnfButton_Click);
			// 
			// GUI
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(834, 561);
			this->Controls->Add(this->fAnfButton);
			this->Controls->Add(this->nfAnfButton);
			this->Controls->Add(this->nfAnf);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->fAnf);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"GUI";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"REQED";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GUI::GUI_FormClosing);
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

	private: System::Void GUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonLoeschen_Click(System::Object^ sender, System::EventArgs ^ e);
	private: System::Void buttonBearbeiten_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void neuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void öffnenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void speichernToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textDateiToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void jSONDateiToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void fAnfButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nfAnfButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void GUI_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}