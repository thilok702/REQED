#pragma once

namespace REQED {
	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI: public System::Windows::Forms::Form {
	public:
		GUI(void) {
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI() {
			if(components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownButton1;

	private: System::Windows::Forms::ToolStripMenuItem^ öffnenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ speichernToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ neuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownButton2;
	private: System::Windows::Forms::ToolStripMenuItem^ textDateiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ jSONDateiToolStripMenuItem;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GUI::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->neuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->öffnenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speichernToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripDropDownButton2 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->textDateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->jSONDateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(70, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"funktionale Anforderungen:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(74, 91);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 30);
			this->button1->TabIndex = 1;
			this->button1->Text = L"neu";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::Color::White;
			this->toolStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripDropDownButton1,
					this->toolStripDropDownButton2
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(890, 27);
			this->toolStrip1->TabIndex = 3;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->neuToolStripMenuItem,
					this->öffnenToolStripMenuItem, this->speichernToolStripMenuItem
			});
			this->toolStripDropDownButton1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripDropDownButton1->ForeColor = System::Drawing::Color::Black;
			this->toolStripDropDownButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton1.Image")));
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->ShowDropDownArrow = false;
			this->toolStripDropDownButton1->Size = System::Drawing::Size(49, 24);
			this->toolStripDropDownButton1->Text = L"Datei";
			// 
			// neuToolStripMenuItem
			// 
			this->neuToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->neuToolStripMenuItem->Name = L"neuToolStripMenuItem";
			this->neuToolStripMenuItem->Size = System::Drawing::Size(140, 24);
			this->neuToolStripMenuItem->Text = L"neu";
			this->neuToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::neuToolStripMenuItem_Click);
			// 
			// öffnenToolStripMenuItem
			// 
			this->öffnenToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->öffnenToolStripMenuItem->Name = L"öffnenToolStripMenuItem";
			this->öffnenToolStripMenuItem->Size = System::Drawing::Size(140, 24);
			this->öffnenToolStripMenuItem->Text = L"öffnen";
			this->öffnenToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::öffnenToolStripMenuItem_Click);
			// 
			// speichernToolStripMenuItem
			// 
			this->speichernToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->speichernToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"speichernToolStripMenuItem.Image")));
			this->speichernToolStripMenuItem->Name = L"speichernToolStripMenuItem";
			this->speichernToolStripMenuItem->Size = System::Drawing::Size(180, 24);
			this->speichernToolStripMenuItem->Text = L"speichern";
			this->speichernToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::speichernToolStripMenuItem_Click);
			// 
			// toolStripDropDownButton2
			// 
			this->toolStripDropDownButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripDropDownButton2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->textDateiToolStripMenuItem,
					this->jSONDateiToolStripMenuItem
			});
			this->toolStripDropDownButton2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripDropDownButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton2.Image")));
			this->toolStripDropDownButton2->Name = L"toolStripDropDownButton2";
			this->toolStripDropDownButton2->ShowDropDownArrow = false;
			this->toolStripDropDownButton2->Size = System::Drawing::Size(56, 24);
			this->toolStripDropDownButton2->Text = L"Export";
			// 
			// textDateiToolStripMenuItem
			// 
			this->textDateiToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textDateiToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"textDateiToolStripMenuItem.Image")));
			this->textDateiToolStripMenuItem->Name = L"textDateiToolStripMenuItem";
			this->textDateiToolStripMenuItem->Size = System::Drawing::Size(180, 24);
			this->textDateiToolStripMenuItem->Text = L"Text-Datei";
			this->textDateiToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::textDateiToolStripMenuItem_Click);
			// 
			// jSONDateiToolStripMenuItem
			// 
			this->jSONDateiToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->jSONDateiToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"jSONDateiToolStripMenuItem.Image")));
			this->jSONDateiToolStripMenuItem->Name = L"jSONDateiToolStripMenuItem";
			this->jSONDateiToolStripMenuItem->Size = System::Drawing::Size(180, 24);
			this->jSONDateiToolStripMenuItem->Text = L"JSON-Datei";
			this->jSONDateiToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::jSONDateiToolStripMenuItem_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(70, 203);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(266, 19);
			this->label2->TabIndex = 4;
			this->label2->Text = L"nicht funktionale Anfortderungen:";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(74, 225);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 30);
			this->button2->TabIndex = 5;
			this->button2->Text = L"neu";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &GUI::button2_Click);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(890, 613);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"GUI";
			this->Text = L"REQED";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

	private: System::Void GUI_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Click(System::Object^ sender, System::EventArgs ^ e);
	private: System::Void neuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void öffnenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void speichernToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textDateiToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void jSONDateiToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	};
}