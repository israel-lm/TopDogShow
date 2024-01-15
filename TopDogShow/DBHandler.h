#pragma once
#include <msclr\marshal_cppstd.h>

#include "Dog.h"
#include "User.h"




namespace TopDogShow
{
	using namespace System;
	using namespace System::Data::SqlClient;
	using namespace msclr::interop;
	using namespace System::Windows::Forms;

	typedef enum
	{
		UNKNOWN = -1,
		OK = 1,
		USER_ALREADY_EXISTS = 10,
		USER_DOESNT_EXIST,
		DOG_ALREADY_EXISTS,
		DOG_DOESNT_EXIST
	} DBErrorType;

	class DBHandler
	{
	public:
		~DBHandler();
		static DBHandler* getInstance();

		DBErrorType getDogInfo(std::string dogName, Dog& dog);
		DBErrorType saveDogInfo(Dog& dog);

		DBErrorType getUserInfo(std::string username, User& user);
		DBErrorType saveUserInfo(User& user);

	private:
		static std::string connectionString;
		static DBHandler* instance;

		DBHandler();
	};
}
