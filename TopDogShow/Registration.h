#pragma once
#include <msclr\marshal_cppstd.h>
#include "Constants.h"
#include "DBHandler.h"
#include "Utils.h"


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
			dbHandler = DBHandler::Instance;
			setCategories();
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



	private: System::Windows::Forms::Button^ cancelButton;

	private: System::Windows::Forms::Label^ ownerLabel;

	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::TextBox^ ownerBox;


	private: System::Windows::Forms::TextBox^ nameBox;
	private: System::Windows::Forms::Label^ categoryLabel;


	private: System::Windows::Forms::PictureBox^ dogPicture;
	private: System::ComponentModel::IContainer^ components;
		   System::Windows::Forms::ComboBox^ categoryCombo;

	

	private:		
		String^ dogPictureFile = "";
	private: System::Windows::Forms::Label^ photoLabel;

		   DBHandler^ dbHandler;

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
			this->categoryLabel = (gcnew System::Windows::Forms::Label());
			this->dogPicture = (gcnew System::Windows::Forms::PictureBox());
			this->categoryCombo = (gcnew System::Windows::Forms::ComboBox());
			this->photoLabel = (gcnew System::Windows::Forms::Label());
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
			this->cancelButton->Click += gcnew System::EventHandler(this, &Registration::cancelButton_Click);
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
			// categoryLabel
			// 
			this->categoryLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->categoryLabel->AutoSize = true;
			this->categoryLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->categoryLabel->ForeColor = System::Drawing::Color::White;
			this->categoryLabel->Location = System::Drawing::Point(23, 331);
			this->categoryLabel->Name = L"categoryLabel";
			this->categoryLabel->Size = System::Drawing::Size(134, 29);
			this->categoryLabel->TabIndex = 12;
			this->categoryLabel->Text = L"Category";
			// 
			// dogPicture
			// 
			this->dogPicture->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dogPicture->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dogPicture->Location = System::Drawing::Point(499, 140);
			this->dogPicture->Name = L"dogPicture";
			this->dogPicture->Size = System::Drawing::Size(242, 270);
			this->dogPicture->TabIndex = 14;
			this->dogPicture->TabStop = false;
			this->dogPicture->DoubleClick += gcnew System::EventHandler(this, &Registration::dogPicture_DoubleClick);
			// 
			// categoryCombo
			// 
			this->categoryCombo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->categoryCombo->FormattingEnabled = true;
			this->categoryCombo->Location = System::Drawing::Point(20, 372);
			this->categoryCombo->Name = L"categoryCombo";
			this->categoryCombo->Size = System::Drawing::Size(396, 37);
			this->categoryCombo->TabIndex = 15;
			// 
			// photoLabel
			// 
			this->photoLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->photoLabel->AutoSize = true;
			this->photoLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->photoLabel->ForeColor = System::Drawing::Color::White;
			this->photoLabel->Location = System::Drawing::Point(495, 95);
			this->photoLabel->Name = L"photoLabel";
			this->photoLabel->Size = System::Drawing::Size(91, 29);
			this->photoLabel->TabIndex = 16;
			this->photoLabel->Text = L"Photo";
			// 
			// Registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(778, 594);
			this->Controls->Add(this->photoLabel);
			this->Controls->Add(this->categoryCombo);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->dogPicture);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->categoryLabel);
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
	
	void setCategories()
	{
		array<String^>^ categoryList = gcnew array<String^>(3);
		categoryList[0] = Categories::LIGHT_WEIGHT;
		categoryList[1] = Categories::MIDDLE_WEIGHT;
		categoryList[2] = Categories::HEAVY_WEIGHT;

		if (categoryCombo)
		{
			categoryCombo->Items->Clear();
			categoryCombo->Items->AddRange(categoryList);
		}
	}
	void resetFields()
	{
		if (nameBox)
			nameBox->Text = "";
		if (ownerBox)
			ownerBox->Text = "";
		if (categoryCombo)
			categoryCombo->SelectedIndex = -1;
	}


private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ dogName = nameBox->Text;
	String^ ownerName = ownerBox->Text;
	String^ category = (String^)categoryCombo->SelectedItem;
	
	if (dogName->Length == 0 || ownerName->Length == 0 || category->Length == 0)
	{
		showMessage("Fill all fields", "Registration process");
		return;
	}

	Dog^ dog = gcnew Dog(
		dogName, 
		ownerName, 
		category,
		dogPictureFile
	);
	
	DBErrorType result = dbHandler->saveDogInfo(dog);

	if (result == DBErrorType::OK)
	{
		resetFields();
		showMessage("Dog succesfully registered", "Registration process");
	}
	else
	{
		resetFields();
		showMessage(marshal_as<String^>(DBErrorString.at(result)), "Registration process");
	}
		
}	
	
	
	System::Void dogPicture_DoubleClick(System::Object^ sender, System::EventArgs^ e) 
	{
		OpenFileDialog^ fileDialog = gcnew OpenFileDialog();

		fileDialog->InitialDirectory = "c:\\";
		fileDialog->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.gif;*.tif;...";
		fileDialog->FilterIndex = 2;
		fileDialog->RestoreDirectory = true;

		dogPictureFile = nullptr;

		if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			dogPictureFile = fileDialog->FileName;
			if (dogPictureFile)
			{
				try
				{
					dogPicture->Image = Image::FromFile(dogPictureFile);
				}
				catch (const std::exception&)
				{
					showMessage("Error loading image", "Registration process");
				}
			}
			
		}
	}

private: System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
