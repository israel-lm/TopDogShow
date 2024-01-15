#include "Login.h"
#include "Home.h"
#include "DBHandler.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace TopDogShow;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Login^ loginScreen = gcnew Login();
	Home^ homeScreen = gcnew Home();
	DBHandler* dbHandler = DBHandler::getInstance();

	loginScreen->ShowDialog();

	if (loginScreen->isLoginSuccessful())
	{
		loginScreen->Close();
		Application::Run(homeScreen);
	}

	if (dbHandler)
		delete dbHandler;
}