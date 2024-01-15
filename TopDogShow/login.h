#pragma once
#include <msclr\marshal_cppstd.h>

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


	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void);
		bool isLoginSuccessful();

	protected:

		~Login();

	private: 
		System::Windows::Forms::Label^ headerLabel;
		System::Windows::Forms::TextBox^ usernameText;
		System::Windows::Forms::TextBox^ passwordText;
		System::Windows::Forms::Label^ usernameLabel;
		System::Windows::Forms::Label^ passwordLabel;
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
		System::Windows::Forms::Button^ okButton;
		System::Windows::Forms::Button^ canecelButton;		
		System::ComponentModel::Container ^components;

		bool loginSuccessful = false;
		DBHandler* dbHandler;

		
		void InitializeComponent(void);
		System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void canecelButton_Click(System::Object^ sender, System::EventArgs^ e);

};
}
