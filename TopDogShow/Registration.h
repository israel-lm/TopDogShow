#pragma once

namespace TopDogShow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Registration
	/// </summary>
	public ref class Registration : public System::Windows::Forms::Form
	{
	public:
		Registration(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Registration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ headerLabel;
	private: System::Windows::Forms::Button^ saveButton;
	protected:



	private: System::Windows::Forms::Button^ cancelButton;

	private: System::Windows::Forms::Label^ ownerLabel;

	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::TextBox^ ownerBox;


	private: System::Windows::Forms::TextBox^ nameBox;

	private: System::Windows::Forms::Label^ weightLabel;
	private: System::Windows::Forms::TextBox^ weghtBox;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ dogPicture;

	protected:

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
			this->headerLabel = (gcnew System::Windows::Forms::Label());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->ownerLabel = (gcnew System::Windows::Forms::Label());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->ownerBox = (gcnew System::Windows::Forms::TextBox());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->weightLabel = (gcnew System::Windows::Forms::Label());
			this->weghtBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dogPicture = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->BeginInit();
			this->SuspendLayout();
			// 
			// headerLabel
			// 
			this->headerLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->headerLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->headerLabel->ForeColor = System::Drawing::Color::White;
			this->headerLabel->Location = System::Drawing::Point(314, 58);
			this->headerLabel->Name = L"headerLabel";
			this->headerLabel->Size = System::Drawing::Size(358, 44);
			this->headerLabel->TabIndex = 1;
			this->headerLabel->Text = L"Dog Registration";
			this->headerLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->headerLabel->Click += gcnew System::EventHandler(this, &Registration::loginLabel_Click);
			// 
			// saveButton
			// 
			this->saveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->saveButton->BackColor = System::Drawing::Color::White;
			this->saveButton->Location = System::Drawing::Point(501, 710);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(171, 72);
			this->saveButton->TabIndex = 0;
			this->saveButton->Text = L"Save";
			this->saveButton->UseVisualStyleBackColor = false;
			// 
			// cancelButton
			// 
			this->cancelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->cancelButton->AutoSize = true;
			this->cancelButton->BackColor = System::Drawing::Color::White;
			this->cancelButton->Location = System::Drawing::Point(753, 710);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(171, 72);
			this->cancelButton->TabIndex = 1;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = false;
			// 
			// ownerLabel
			// 
			this->ownerLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ownerLabel->AutoSize = true;
			this->ownerLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ownerLabel->ForeColor = System::Drawing::Color::White;
			this->ownerLabel->Location = System::Drawing::Point(23, 310);
			this->ownerLabel->Name = L"ownerLabel";
			this->ownerLabel->Size = System::Drawing::Size(102, 29);
			this->ownerLabel->TabIndex = 9;
			this->ownerLabel->Text = L"Owner";
			// 
			// nameLabel
			// 
			this->nameLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->nameLabel->AutoSize = true;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->nameLabel->ForeColor = System::Drawing::Color::White;
			this->nameLabel->Location = System::Drawing::Point(23, 195);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(90, 29);
			this->nameLabel->TabIndex = 8;
			this->nameLabel->Text = L"Name";
			// 
			// ownerBox
			// 
			this->ownerBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ownerBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ownerBox->Location = System::Drawing::Point(20, 353);
			this->ownerBox->Name = L"ownerBox";
			this->ownerBox->Size = System::Drawing::Size(396, 35);
			this->ownerBox->TabIndex = 7;
			// 
			// nameBox
			// 
			this->nameBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->nameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameBox->Location = System::Drawing::Point(20, 240);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(396, 35);
			this->nameBox->TabIndex = 6;
			// 
			// weightLabel
			// 
			this->weightLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->weightLabel->AutoSize = true;
			this->weightLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->weightLabel->ForeColor = System::Drawing::Color::White;
			this->weightLabel->Location = System::Drawing::Point(23, 431);
			this->weightLabel->Name = L"weightLabel";
			this->weightLabel->Size = System::Drawing::Size(176, 29);
			this->weightLabel->TabIndex = 12;
			this->weightLabel->Text = L"Weight (kg)";
			// 
			// weghtBox
			// 
			this->weghtBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->weghtBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->weghtBox->Location = System::Drawing::Point(20, 475);
			this->weghtBox->Name = L"weghtBox";
			this->weghtBox->Size = System::Drawing::Size(396, 35);
			this->weghtBox->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(496, 195);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 29);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Photo";
			// 
			// dogPicture
			// 
			this->dogPicture->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dogPicture->Location = System::Drawing::Point(501, 240);
			this->dogPicture->Name = L"dogPicture";
			this->dogPicture->Size = System::Drawing::Size(423, 440);
			this->dogPicture->TabIndex = 14;
			this->dogPicture->TabStop = false;
			// 
			// Registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(948, 794);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->dogPicture);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->weightLabel);
			this->Controls->Add(this->weghtBox);
			this->Controls->Add(this->ownerLabel);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->ownerBox);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->headerLabel);
			this->MinimumSize = System::Drawing::Size(970, 850);
			this->Name = L"Registration";
			this->Text = L"Top Dog Show";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loginLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
