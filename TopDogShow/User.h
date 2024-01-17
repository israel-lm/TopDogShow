#pragma once
#include <string>

namespace TopDogShow
{
	using namespace System;

	public ref class User
	{
	private:
		String^ name;
		String^ passHash;
	public:
		User() {}
		User(String^ name, String^ password)
		{
			this->name = name;
			this->passHash = password;
		}
		String^ getName() { return name; }
		String^ getPassword() { return passHash; }

		void setName(String^ name) { this->name = name; }
		void setPassword(String^ password) { this->passHash = password; }
	};
}


