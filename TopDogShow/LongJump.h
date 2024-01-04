#pragma once

namespace TopDogShow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class LongJump : public System::Windows::Forms::Form
	{
	public:
		LongJump(void);

	protected:
		~LongJump();
	private:
		System::Windows::Forms::Label^ headerLabel;
		System::Windows::Forms::PictureBox^ dogPicture;
		System::Windows::Forms::Label^ attemptLabel;
		System::Windows::Forms::Label^ markLabel;
		System::Windows::Forms::Label^ attempt1Label;
		System::Windows::Forms::Label^ attempt2Label;
		System::Windows::Forms::Label^ attempt3Label;
		System::Windows::Forms::Label^ attempt4Label;
		System::Windows::Forms::Label^ attempt5Label;
		System::Windows::Forms::TextBox^ mark1Box;
		System::Windows::Forms::TextBox^ mark2Box;
		System::Windows::Forms::TextBox^ mark3Box;
		System::Windows::Forms::TextBox^ mark4Box;
		System::Windows::Forms::TextBox^ mark5Box;
		System::Windows::Forms::Panel^ markPanel;
		System::Windows::Forms::Button^ finishButton;
		System::Windows::Forms::Button^ cancelButton;		
	private: System::Windows::Forms::Label^ dogName;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void);
#pragma endregion
		System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e);
	
		System::Void finishButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
