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
		DOG_DOESNT_EXIST,
		NO_TABLE,
		NO_DOG
	};

	static std::map<DBErrorType, std::string> DBErrorString = {
			{DBErrorType::UNKNOWN, "Unknown"},
			{DBErrorType::USER_ALREADY_EXISTS, "User already exists."},
			{DBErrorType::USER_DOESNT_EXIST, "User doesn't exist."},
			{DBErrorType::DOG_ALREADY_EXISTS, "Dog already registered."},
			{DBErrorType::DOG_DOESNT_EXIST, "Dog not registered."},
			{DBErrorType::NO_TABLE, "Table does not exist"},
			{DBErrorType::NO_DOG, "Dog does not exist"}
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
		DBErrorType saveTreadmilllResults(TreadmilllPerformanceData^ data);

		Dictionary<String^, MarkTablePerformanceData^>^ getWallClimbResults();
		Dictionary<String^, MarkTablePerformanceData^>^ getHighJumpResults();
		Dictionary<String^, LongJumpPerformanceData^>^ getLongJumpResults();
		Dictionary<String^, TreadmilllPerformanceData^>^ getTreadmillResults();

		static property DBHandler^ Instance 
		{ 
			DBHandler^ get() 
			{ 
				return instance; 
			}
		}		
		
	private:	
		literal String^ LONG_JUMP_TABLE_NAME = "LongJumpResults";
		literal String^ TREADMILL_TABLE_NAME = "TreadmillResults";
		literal String^ WALL_CLIMB_TABLE_NAME = "WallClimbResults";
		literal String^ HIGH_JUMP_TABLE_NAME = "HighJumpResults";
		literal String^ REGISTRATION_TABLE_NAME = "dogs";
		literal String^ USERS_TABLE_NAME = "users";

		static String^ connectionString = "Data Source=.\\SQLEXPRESS;Initial Catalog=top_dog_show;Integrated Security=True;Encrypt=False";

		static DBHandler^ instance = gcnew DBHandler;
		static DBErrorType executeNonQuery(String^ operation);

		static bool checkEntryExists(String^ query);
		static bool checkDogExists(String^ dogName, String^ tableName);
		static bool checkUserExists(String^ username);
		static bool checkTableExists(String^ tableName);
		DBErrorType createMarkTable(String^ tableName);
		DBErrorType createTableLongJump();
		DBErrorType createTableTreadmill();
		DBErrorType deleteTable(String^ tableName);
		DBErrorType checkTableAndCreate(String^ tableName);
		DBErrorType saveMarkTableResults(String^ tableName, MarkTablePerformanceData^ data);
		MarkTablePerformanceData^ getMarkTableResults(String^ tableName);

		DBHandler();
	};
}
