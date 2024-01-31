#include "DBHandler.h"

using namespace System;
using namespace Collections::Generic;
using namespace TopDogShow;
using namespace System::IO;
using namespace Newtonsoft::Json;


DBHandler::DBHandler(){}

DBHandler::~DBHandler(){}


DBErrorType DBHandler::getUserInfo(String^ username, User^ user)
{
	String^ sqlQuery = String::Format("SELECT * from users WHERE name='{0}'", username);
	SqlConnection sqlConnection(DBHandler::connectionString);
	SqlCommand command(sqlQuery, % sqlConnection);
	
	try
	{
		sqlConnection.Open();
		SqlDataReader^ reader = command.ExecuteReader();

		if (reader && reader->Read())
		{
			String^ name = reader->GetString(0);
			String^ password = reader->GetString(1);
			user->setName(name);
			user->setPassword(password);
			return DBErrorType::OK;
		}
		else
		{
			//TODO: log error
			return DBErrorType::USER_DOESNT_EXIST;
		}

	}
	catch (Exception^ e)
	{
		//TODO: log exception
	}	
	
}

DBErrorType DBHandler::getDogInfo(String^ dogName, Dog^ dog)
{
	String^ sqlQuery = String::Format("SELECT * from dogs WHERE name='{0}'", dogName);
	SqlConnection sqlConnection(DBHandler::connectionString);
	SqlCommand command(sqlQuery, % sqlConnection);

	try
	{
		sqlConnection.Open();		
		SqlDataReader^ reader = command.ExecuteReader();

		if (reader && reader->Read())
		{
			String^ name = reader->GetString(0);
			String^ owner = reader->GetString(1);
			String^ category = reader->GetString(2);
			String^ picture = reader->GetString(3);

			dog->setName(name);
			dog->setOwner(owner);
			dog->setCategory(category);
			dog->setPictureFile(picture);
			return DBErrorType::OK;
		}
		else
		{
			//TODO: log error
			return DBErrorType::DOG_DOESNT_EXIST;
		}

	}
	catch (Exception^ e) 
	{
		//TODO: log error
	}	
}

DBErrorType DBHandler::saveDogInfo(Dog^ dog)
{

	if (DBHandler::checkDogExists(dog->getName()))
	{
		return DBErrorType::DOG_ALREADY_EXISTS;
	}
	else
	{
		String^ sqlOperation = String::Format(
			"INSERT INTO dogs (name, owner, category, picturePath) VALUES ('{0}', '{1}', '{2}', '{3}')",
			dog->getName(),
			dog->getOwner(),
			dog->getCategory(),
			dog->getPictureFile()
		);

		return DBHandler::executeNonQuery(sqlOperation);
	}	
}

DBErrorType DBHandler::saveUserInfo(User^ user)
{
	if (DBHandler::checkUserExists(user->getName()))
	{
		return DBErrorType::USER_ALREADY_EXISTS;
	}
	else
	{
		String^ sqlOperation = String::Format(
			"INSERT INTO users (name, password) VALUES ('{0}', '{1}')",
			(user->getName()),
			(user->getPassword())
		);

		return DBHandler::executeNonQuery(sqlOperation);
	}		
}

DBErrorType DBHandler::getAllDogs(List<Dog^>^ dogs)
{
	String^ sqlQuery = "SELECT * from dogs";
	SqlConnection sqlConnection(DBHandler::connectionString);
	SqlCommand command(sqlQuery, % sqlConnection);

	try
	{
		sqlConnection.Open();
		SqlDataReader^ reader = command.ExecuteReader();

		while (reader->Read())
		{
			String^ name = reader->GetString(0);
			String^ owner = reader->GetString(1);
			String^ category = reader->GetString(2);
			String^ picture = reader->GetString(3);

			Dog^ dog = gcnew Dog(name, owner, category, picture);
			dogs->Add(dog);
		}

	}
	catch (Exception^ e)
	{
		//TODO: log error
		MessageBox::Show(
			e->StackTrace,
			e->Message,
			MessageBoxButtons::OK
		);
		return DBErrorType::UNKNOWN;
	}
	return DBErrorType::OK;
}

DBErrorType DBHandler::saveResults(PerformanceData^ data, String^ fileNameAppend)
{
	String^ filePath = String::Format("C:\\WINDOWS\\Temp\\{0}_{1}.json", data->dogName, fileNameAppend);
	
	try
	{
		String^ jsonData = JsonConvert::SerializeObject(data);
		File::WriteAllText(filePath, jsonData);
	}
	catch (Exception^ e)
	{
		return DBErrorType::UNKNOWN;
	}
	
	return DBErrorType::OK;
}

DBErrorType  DBHandler::saveWallClimbResults(MarkTablePerformanceData^ data)
{
	return this->saveResults(data, "WallClimbResults");
}

DBErrorType  DBHandler::saveHighJumpResults(MarkTablePerformanceData^ data)
{
	return this->saveResults(data, "HighJumpResults");
}

DBErrorType  DBHandler::saveLongJumpResults(LongJumpPerformanceData^ data)
{
	return this->saveResults(data, "LongJumpResults");
}

DBErrorType  DBHandler::saveTreadmilllResults(TreadmilllPerformanceData^ data)
{
	return this->saveResults(data, "TreadmilllResults");
}

DBErrorType DBHandler::createTableMarkTableResults(String^ tableName)
{
	String^ sqlOperation = String::Format(
		"CREATE TABLE {0} (\
			mark int,\
			attempts int,\
			result int\
		);",
		tableName
	);

	return DBHandler::executeNonQuery(sqlOperation);
}

 DBErrorType DBHandler::executeNonQuery(String^ operation)
{
	try
	{
		SqlConnection sqlConnection(DBHandler::connectionString);
		sqlConnection.Open();

		SqlCommand command(operation, % sqlConnection);

		int result = command.ExecuteNonQuery();

		if (result < 1)
		{
			//TODO: log error
			return DBErrorType::UNKNOWN;
		}

	}
	catch (Exception^ e)
	{
		//TODO: log error
		return DBErrorType::UNKNOWN;
	}
	return DBErrorType::OK;
}

bool DBHandler::checkEntryExists(String^ query)
{
	SqlConnection sqlConnection(DBHandler::connectionString);
	SqlCommand command(query, % sqlConnection);

	try
	{
		sqlConnection.Open();
		SqlDataReader^ reader = command.ExecuteReader();

		if (reader && reader->Read())
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	catch (Exception^ e)
	{
		//TODO: log error
	}
}

bool DBHandler::checkTableExists(String^ tableName)
{
	String^ operation = String::Format(
		"SELECT * FROM INFORMATION_SCHEMA.TABLES \
		WHERE TABLE_SCHEMA = 'dbo' AND TABLE_NAME = '{0}'",
		tableName);
	return DBHandler::checkEntryExists(operation);
}

bool DBHandler::checkDogExists(String^ dogName)
{
	String^ operation = String::Format("SELECT * FROM dogs WHERE name LIKE '{0}'", dogName);
	return DBHandler::checkEntryExists(operation);	
}

bool DBHandler::checkUserExists(String^ username)
{
	String^ operation = String::Format("SELECT * FROM users WHERE name LIKE '{0}'", username);
	return DBHandler::checkEntryExists(operation);
}

