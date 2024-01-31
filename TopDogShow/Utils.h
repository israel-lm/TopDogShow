#pragma once

using namespace System;
using namespace System::Windows::Forms;

static System::Void showMessage(String^ errorMessage, String^ title)
{
	MessageBox::Show(
		errorMessage,
		title,
		MessageBoxButtons::OK
	);
}