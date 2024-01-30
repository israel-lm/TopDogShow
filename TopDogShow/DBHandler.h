#pragma once
#include <list>

#include "Dog.h"
#include "User.h"
#include "PerformanceData.h"


namespace TopDogShow
{
	using namespace System;
	using namespace System::Data::SqlClient;
	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;

	enum class DBErrorType
	{
		UNKNOWN = -1,
		OK = 1,
		USER_ALREADY_EXISTS = 10,
		USER_DOESNT_EXIST,
		DOG_ALREADY_EXISTS,
		DOG_DOESNT_EXIST
	};

	static std::map<DBErrorType, std::string> DBErrorString = {
			{DBErrorType::UNKNOWN, "Unknown"},
			{DBErrorType::USER_ALREADY_EXISTS, "User already exists."},
			{DBErrorType::USER_DOESNT_EXIST, "User doesn't exist."},
			{DBErrorType::DOG_ALREADY_EXISTS, "Dog already registered."},
			{DBErrorType::DOG_DOESNT_EXIST, "Dog not registered."}
	};

	
	public ref class DBHandler
	{
	public:
		~DBHandler();

		DBErrorType getDogInfo(String^ dogName, Dog^ dog);
		DBErrorType saveDogInfo(Dog^ dog);

		DBErrorType getUserInfo(String^ username, User^ user);
		DBErrorType saveUserInfo(User^ user);

		DBErrorType getAllDogs(List<Dog^>^ dogs);

		DBErrorType saveWallClimbResults(MarkTablePerformanceData^ data);
		DBErrorType saveHighJumpResults(MarkTablePerformanceData^ data);
		DBErrorType saveLongJumpResults(LongJumpPerformanceData^ data);
		DBErrorType saveTreadmillResults(TreadmillPerformanceData^ data);
		

		static property DBHandler^ Instance 
		{ 
			DBHandler^ get() 
			{ 
				return instance; 
			}
		}
		static String^ connectionString = "Data Source=.\\SQLEXPRESS;Initial Catalog=top_dog_show;Integrated Security=True;Encrypt=False";

	private:
		
		static DBHandler^ instance = gcnew DBHandler;

		static DBErrorType executeNonQuery(String^ operation);

		static bool checkEntryExists(String^ query);
		static bool checkDogExists(String^ dogName);
		static bool checkUserExists(String^ username);
		static bool checkTableExists(String^ tableName);
		DBErrorType createTableMarkTableResults(String^ tableName);
		DBErrorType saveResults(PerformanceData^ data, String^ fileNameAppend);

		DBHandler();
	};
}
