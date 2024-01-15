#pragma once
#include <msclr\marshal_cppstd.h>
#include "Constants.h"
#include "DBHandler.h"


namespace TopDogShow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for Registration
	/// </summary>
	public ref class Registration : public System::Windows::Forms::Form
	{
	public:
		Registration(void)
		{
			InitializeComponent();
			dbHandler = DBHandler::getInstance();
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
	private: System::Windows::Forms::TextBox^ weightBox;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ dogPicture;

	

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		DBHandler* dbHandler;

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
			this->weightBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dogPicture = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->BeginInit();
			this->SuspendLayout();
			// 
			// headerLabel
			// 
			this->headerLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->headerLabel->AutoSize = true;
			this->headerLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->headerLabel->ForeColor = System::Drawing::Color::White;
			this->headerLabel->Location = System::Drawing::Point(227, 35);
			this->headerLabel->Name = L"headerLabel";
			this->headerLabel->Size = System::Drawing::Size(358, 44);
			this->headerLabel->TabIndex = 1;
			this->headerLabel->Text = L"Dog Registration";
			this->headerLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// saveButton
			// 
			this->saveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->saveButton->BackColor = System::Drawing::Color::White;
			this->saveButton->Location = System::Drawing::Point(577, 534);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(164, 48);
			this->saveButton->TabIndex = 0;
			this->saveButton->Text = L"Save";
			this->saveButton->UseVisualStyleBackColor = false;
			this->saveButton->Click += gcnew System::EventHandler(this, &Registration::saveButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->cancelButton->BackColor = System::Drawing::Color::White;
			this->cancelButton->Location = System::Drawing::Point(379, 534);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(164, 48);
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
			this->ownerLabel->Location = System::Drawing::Point(23, 210);
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
			this->nameLabel->Location = System::Drawing::Point(23, 95);
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
			this->ownerBox->Location = System::Drawing::Point(20, 253);
			this->ownerBox->Name = L"ownerBox";
			this->ownerBox->Size = System::Drawing::Size(396, 35);
			this->ownerBox->TabIndex = 7;
			// 
			// nameBox
			// 
			this->nameBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->nameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameBox->Location = System::Drawing::Point(20, 140);
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
			this->weightLabel->Location = System::Drawing::Point(23, 331);
			this->weightLabel->Name = L"weightLabel";
			this->weightLabel->Size = System::Drawing::Size(176, 29);
			this->weightLabel->TabIndex = 12;
			this->weightLabel->Text = L"Weight (kg)";
			// 
			// weightBox
			// 
			this->weightBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->weightBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->weightBox->Location = System::Drawing::Point(20, 375);
			this->weightBox->Name = L"weightBox";
			this->weightBox->Size = System::Drawing::Size(396, 35);
			this->weightBox->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(494, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 29);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Photo";
			// 
			// dogPicture
			// 
			this->dogPicture->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dogPicture->Location = System::Drawing::Point(499, 140);
			this->dogPicture->Name = L"dogPicture";
			this->dogPicture->Size = System::Drawing::Size(242, 270);
			this->dogPicture->TabIndex = 14;
			this->dogPicture->TabStop = false;
			// 
			// Registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(778, 594);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->dogPicture);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->weightLabel);
			this->Controls->Add(this->weightBox);
			this->Controls->Add(this->ownerLabel);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->ownerBox);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->headerLabel);
			this->MinimumSize = System::Drawing::Size(750, 650);
			this->Name = L"Registration";
			this->Text = L"Top Dog Show";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: 
	System::Void showError(String^ message)
	{
		MessageBox::Show(
			message,
			"Registration error",
			MessageBoxButtons::OK
		);
	}

	Categories getCategory(int weight)
	{
		Categories category;
		if (weight < 2000)
		{
			category = Categories::LIGHT_WEIGHT;
		}
		else if ((weight >= 2000) && (weight < 2500))
		{
			category = Categories::MEDIUM_WEIGHT;
		}
		else
			category = Categories::HEAVY_WEIGTH;

		return category;
	}


private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	float dogWeight = 0;
	String^ dogName = nameBox->Text;
	String^ ownerName = ownerBox->Text;
	
	try
	{
		dogWeight = (float)((Convert::ToDouble(weightBox->Text)));
	}
	catch (Exception^ e)
	{
		showError("Weight value not valid");
		return;
	}

	Dog dog{ marshal_as<std::string>(dogName), marshal_as<std::string>(ownerName), dogWeight };
	
	DBErrorType result = dbHandler->saveDogInfo(dog);

	if (result == DBErrorType::OK)
	{
		MessageBox::Show(
			"Dog succesfully registered",
			"Registration info",
			MessageBoxButtons::OK
		);
	}
	else
		MessageBox::Show(
			"Registration failed",
			"Registration error",
			MessageBoxButtons::OK
		);
}
};
}
