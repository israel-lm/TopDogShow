#pragma once

namespace TopDogShow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LongJump
	/// </summary>
	public ref class LongJump : public System::Windows::Forms::Form
	{
	public:
		LongJump(void)
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
		~LongJump()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ headerLabel;
	private: System::Windows::Forms::PictureBox^ dogPicture;

	private: System::Windows::Forms::Label^ attemptLabel;
	private: System::Windows::Forms::Label^ markLabel;
	private: System::Windows::Forms::Label^ attempt1Label;
	private: System::Windows::Forms::Label^ attempt2Label;
	private: System::Windows::Forms::Label^ attempt3Label;
	private: System::Windows::Forms::Label^ attempt4Label;
	private: System::Windows::Forms::Label^ attempt5Label;
	private: System::Windows::Forms::TextBox^ mark1Box;
	private: System::Windows::Forms::TextBox^ mark2Box;
	private: System::Windows::Forms::TextBox^ mark3Box;
	private: System::Windows::Forms::TextBox^ mark4Box;
	private: System::Windows::Forms::TextBox^ mark5Box;
	private: System::Windows::Forms::Panel^ markPanel;

	private: System::Windows::Forms::Button^ finishButton;
	private: System::Windows::Forms::Button^ cancelButton;





	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LongJump::typeid));
			this->headerLabel = (gcnew System::Windows::Forms::Label());
			this->dogPicture = (gcnew System::Windows::Forms::PictureBox());
			this->attemptLabel = (gcnew System::Windows::Forms::Label());
			this->markLabel = (gcnew System::Windows::Forms::Label());
			this->attempt1Label = (gcnew System::Windows::Forms::Label());
			this->attempt2Label = (gcnew System::Windows::Forms::Label());
			this->attempt3Label = (gcnew System::Windows::Forms::Label());
			this->attempt4Label = (gcnew System::Windows::Forms::Label());
			this->attempt5Label = (gcnew System::Windows::Forms::Label());
			this->mark1Box = (gcnew System::Windows::Forms::TextBox());
			this->mark2Box = (gcnew System::Windows::Forms::TextBox());
			this->mark3Box = (gcnew System::Windows::Forms::TextBox());
			this->mark4Box = (gcnew System::Windows::Forms::TextBox());
			this->mark5Box = (gcnew System::Windows::Forms::TextBox());
			this->markPanel = (gcnew System::Windows::Forms::Panel());
			this->finishButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->BeginInit();
			this->markPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// headerLabel
			// 
			this->headerLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->headerLabel->AutoSize = true;
			this->headerLabel->Location = System::Drawing::Point(307, 47);
			this->headerLabel->Name = L"headerLabel";
			this->headerLabel->Size = System::Drawing::Size(158, 29);
			this->headerLabel->TabIndex = 0;
			this->headerLabel->Text = L"Long Jump";
			// 
			// dogPicture
			// 
			this->dogPicture->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dogPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dogPicture.Image")));
			this->dogPicture->Location = System::Drawing::Point(440, 126);
			this->dogPicture->Name = L"dogPicture";
			this->dogPicture->Size = System::Drawing::Size(255, 306);
			this->dogPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->dogPicture->TabIndex = 1;
			this->dogPicture->TabStop = false;
			// 
			// attemptLabel
			// 
			this->attemptLabel->AutoSize = true;
			this->attemptLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->attemptLabel->Location = System::Drawing::Point(-1, 12);
			this->attemptLabel->Name = L"attemptLabel";
			this->attemptLabel->Size = System::Drawing::Size(79, 18);
			this->attemptLabel->TabIndex = 2;
			this->attemptLabel->Text = L"Attempt";
			// 
			// markLabel
			// 
			this->markLabel->AutoSize = true;
			this->markLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->markLabel->Location = System::Drawing::Point(-1, 51);
			this->markLabel->Name = L"markLabel";
			this->markLabel->Size = System::Drawing::Size(52, 18);
			this->markLabel->TabIndex = 3;
			this->markLabel->Text = L"Mark";
			// 
			// attempt1Label
			// 
			this->attempt1Label->BackColor = System::Drawing::Color::White;
			this->attempt1Label->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->attempt1Label->ForeColor = System::Drawing::SystemColors::ControlText;
			this->attempt1Label->Location = System::Drawing::Point(84, 12);
			this->attempt1Label->Name = L"attempt1Label";
			this->attempt1Label->Size = System::Drawing::Size(60, 20);
			this->attempt1Label->TabIndex = 4;
			this->attempt1Label->Text = L"1";
			this->attempt1Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// attempt2Label
			// 
			this->attempt2Label->BackColor = System::Drawing::Color::White;
			this->attempt2Label->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->attempt2Label->ForeColor = System::Drawing::SystemColors::ControlText;
			this->attempt2Label->Location = System::Drawing::Point(147, 12);
			this->attempt2Label->Name = L"attempt2Label";
			this->attempt2Label->Size = System::Drawing::Size(60, 20);
			this->attempt2Label->TabIndex = 5;
			this->attempt2Label->Text = L"2";
			this->attempt2Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// attempt3Label
			// 
			this->attempt3Label->BackColor = System::Drawing::Color::White;
			this->attempt3Label->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->attempt3Label->ForeColor = System::Drawing::SystemColors::ControlText;
			this->attempt3Label->Location = System::Drawing::Point(210, 12);
			this->attempt3Label->Name = L"attempt3Label";
			this->attempt3Label->Size = System::Drawing::Size(60, 20);
			this->attempt3Label->TabIndex = 6;
			this->attempt3Label->Text = L"3";
			this->attempt3Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// attempt4Label
			// 
			this->attempt4Label->BackColor = System::Drawing::Color::White;
			this->attempt4Label->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->attempt4Label->ForeColor = System::Drawing::SystemColors::ControlText;
			this->attempt4Label->Location = System::Drawing::Point(273, 12);
			this->attempt4Label->Name = L"attempt4Label";
			this->attempt4Label->Size = System::Drawing::Size(60, 20);
			this->attempt4Label->TabIndex = 7;
			this->attempt4Label->Text = L"4";
			this->attempt4Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// attempt5Label
			// 
			this->attempt5Label->BackColor = System::Drawing::Color::White;
			this->attempt5Label->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->attempt5Label->ForeColor = System::Drawing::SystemColors::ControlText;
			this->attempt5Label->Location = System::Drawing::Point(336, 12);
			this->attempt5Label->Name = L"attempt5Label";
			this->attempt5Label->Size = System::Drawing::Size(60, 20);
			this->attempt5Label->TabIndex = 8;
			this->attempt5Label->Text = L"5";
			this->attempt5Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// mark1Box
			// 
			this->mark1Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark1Box->Location = System::Drawing::Point(84, 39);
			this->mark1Box->Name = L"mark1Box";
			this->mark1Box->Size = System::Drawing::Size(60, 26);
			this->mark1Box->TabIndex = 9;
			// 
			// mark2Box
			// 
			this->mark2Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark2Box->Location = System::Drawing::Point(147, 39);
			this->mark2Box->Name = L"mark2Box";
			this->mark2Box->Size = System::Drawing::Size(60, 26);
			this->mark2Box->TabIndex = 10;
			// 
			// mark3Box
			// 
			this->mark3Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark3Box->Location = System::Drawing::Point(210, 39);
			this->mark3Box->Name = L"mark3Box";
			this->mark3Box->Size = System::Drawing::Size(60, 26);
			this->mark3Box->TabIndex = 11;
			// 
			// mark4Box
			// 
			this->mark4Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark4Box->Location = System::Drawing::Point(273, 39);
			this->mark4Box->Name = L"mark4Box";
			this->mark4Box->Size = System::Drawing::Size(60, 26);
			this->mark4Box->TabIndex = 12;
			// 
			// mark5Box
			// 
			this->mark5Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark5Box->Location = System::Drawing::Point(336, 39);
			this->mark5Box->Name = L"mark5Box";
			this->mark5Box->Size = System::Drawing::Size(60, 26);
			this->mark5Box->TabIndex = 13;
			// 
			// markPanel
			// 
			this->markPanel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->markPanel->Controls->Add(this->attempt1Label);
			this->markPanel->Controls->Add(this->mark5Box);
			this->markPanel->Controls->Add(this->attemptLabel);
			this->markPanel->Controls->Add(this->mark4Box);
			this->markPanel->Controls->Add(this->markLabel);
			this->markPanel->Controls->Add(this->mark3Box);
			this->markPanel->Controls->Add(this->attempt2Label);
			this->markPanel->Controls->Add(this->mark2Box);
			this->markPanel->Controls->Add(this->attempt3Label);
			this->markPanel->Controls->Add(this->mark1Box);
			this->markPanel->Controls->Add(this->attempt4Label);
			this->markPanel->Controls->Add(this->attempt5Label);
			this->markPanel->Location = System::Drawing::Point(12, 126);
			this->markPanel->Name = L"markPanel";
			this->markPanel->Size = System::Drawing::Size(403, 93);
			this->markPanel->TabIndex = 14;
			// 
			// finishButton
			// 
			this->finishButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->finishButton->BackColor = System::Drawing::Color::White;
			this->finishButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->finishButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->finishButton->Location = System::Drawing::Point(545, 449);
			this->finishButton->Name = L"finishButton";
			this->finishButton->Size = System::Drawing::Size(150, 30);
			this->finishButton->TabIndex = 16;
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
			this->cancelButton->Location = System::Drawing::Point(338, 449);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(150, 30);
			this->cancelButton->TabIndex = 15;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = false;
			// 
			// LongJump
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(17, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(714, 491);
			this->Controls->Add(this->finishButton);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->markPanel);
			this->Controls->Add(this->dogPicture);
			this->Controls->Add(this->headerLabel);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->MinimumSize = System::Drawing::Size(730, 530);
			this->Name = L"LongJump";
			this->Text = L"Top Dog Show";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->EndInit();
			this->markPanel->ResumeLayout(false);
			this->markPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
