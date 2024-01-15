#pragma once
#include <string>

namespace TopDogShow
{
	class User
	{
	private:
		std::string name;
		std::string passHash;
	public:
		User() {}
		User(std::string name, std::string password)
		{
			this->name = name;
			this->passHash = password;
		}
		std::string getName() { return name; }
		std::string getPassword() { return passHash; }

		void setName(std::string name) { this->name = name; }
		void setPassword(std::string password) { this->passHash = password; }
	};
}


