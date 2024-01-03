#pragma once

namespace TopDogShow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Treadmil
	/// </summary>
	public ref class Treadmil : public System::Windows::Forms::Form
	{
	public:
		Treadmil(void)
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
		~Treadmil()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ headerLabel;
	private: System::Windows::Forms::ComboBox^ dogCombo;
	private: System::Windows::Forms::Label^ dogLabel;
	private: System::Windows::Forms::PictureBox^ dogPicture;
	private: System::Windows::Forms::Label^ markLabel;
	private: System::Windows::Forms::TextBox^ markBox;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::Button^ finishButton;
	private: System::Windows::Forms::Button^ cancelButton;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Treadmil::typeid));
			this->headerLabel = (gcnew System::Windows::Forms::Label());
			this->dogCombo = (gcnew System::Windows::Forms::ComboBox());
			this->dogLabel = (gcnew System::Windows::Forms::Label());
			this->dogPicture = (gcnew System::Windows::Forms::PictureBox());
			this->markLabel = (gcnew System::Windows::Forms::Label());
			this->markBox = (gcnew System::Windows::Forms::TextBox());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->finishButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->BeginInit();
			this->SuspendLayout();
			// 
			// headerLabel
			// 
			this->headerLabel->AutoSize = true;
			this->headerLabel->Location = System::Drawing::Point(238, 24);
			this->headerLabel->Name = L"headerLabel";
			this->headerLabel->Size = System::Drawing::Size(131, 29);
			this->headerLabel->TabIndex = 0;
			this->headerLabel->Text = L"Treadmil";
			// 
			// dogCombo
			// 
			this->dogCombo->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->dogCombo->FormattingEnabled = true;
			this->dogCombo->Location = System::Drawing::Point(21, 129);
			this->dogCombo->Name = L"dogCombo";
			this->dogCombo->Size = System::Drawing::Size(338, 37);
			this->dogCombo->TabIndex = 6;
			// 
			// dogLabel
			// 
			this->dogLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->dogLabel->AutoSize = true;
			this->dogLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dogLabel->Location = System::Drawing::Point(18, 108);
			this->dogLabel->Name = L"dogLabel";
			this->dogLabel->Size = System::Drawing::Size(43, 18);
			this->dogLabel->TabIndex = 5;
			this->dogLabel->Text = L"Dog";
			// 
			// dogPicture
			// 
			this->dogPicture->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dogPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dogPicture.Image")));
			this->dogPicture->Location = System::Drawing::Point(377, 108);
			this->dogPicture->Name = L"dogPicture";
			this->dogPicture->Size = System::Drawing::Size(255, 306);
			this->dogPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->dogPicture->TabIndex = 7;
			this->dogPicture->TabStop = false;
			// 
			// markLabel
			// 
			this->markLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->markLabel->AutoSize = true;
			this->markLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->markLabel->Location = System::Drawing::Point(18, 185);
			this->markLabel->Name = L"markLabel";
			this->markLabel->Size = System::Drawing::Size(52, 18);
			this->markLabel->TabIndex = 8;
			this->markLabel->Text = L"Mark";
			// 
			// markBox
			// 
			this->markBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->markBox->Location = System::Drawing::Point(21, 215);
			this->markBox->Name = L"markBox";
			this->markBox->Size = System::Drawing::Size(100, 37);
			this->markBox->TabIndex = 9;
			// 
			// saveButton
			// 
			this->saveButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->saveButton->BackColor = System::Drawing::Color::White;
			this->saveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->saveButton->Location = System::Drawing::Point(21, 296);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(133, 43);
			this->saveButton->TabIndex = 10;
			this->saveButton->Text = L"Save";
			this->saveButton->UseVisualStyleBackColor = false;
			// 
			// finishButton
			// 
			this->finishButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->finishButton->BackColor = System::Drawing::Color::White;
			this->finishButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->finishButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->finishButton->Location = System::Drawing::Point(499, 467);
			this->finishButton->Name = L"finishButton";
			this->finishButton->Size = System::Drawing::Size(133, 43);
			this->finishButton->TabIndex = 11;
			this->finishButton->Text = L"Finish";
			this->finishButton->UseVisualStyleBackColor = false;
			// 
			// cancelButton
			// 
			this->cancelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->cancelButton->BackColor = System::Drawing::Color::White;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->cancelButton->Location = System::Drawing::Point(341, 467);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(133, 43);
			this->cancelButton->TabIndex = 12;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = false;
			// 
			// Treadmil
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(17, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(650, 528);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->finishButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->markBox);
			this->Controls->Add(this->markLabel);
			this->Controls->Add(this->dogPicture);
			this->Controls->Add(this->dogCombo);
			this->Controls->Add(this->dogLabel);
			this->Controls->Add(this->headerLabel);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->MinimumSize = System::Drawing::Size(665, 565);
			this->Name = L"Treadmil";
			this->Text = L"Top Dog Show";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion





};
}
