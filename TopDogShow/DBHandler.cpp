#include "DBHandler.h"

using namespace System;
using namespace Collections::Generic;
using namespace TopDogShow;


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
			float weight = reader->GetFloat(2);

			dog->setName(name);
			dog->setOwner(owner);
			dog->setWeight(weight);
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
			"INSERT INTO dogs (name, owner, weight, category) VALUES ('{0}', '{1}', {2}, {3})",
			(dog->getName()),
			(dog->getOwner()),
			dog->getWeight(),
			(int)dog->getCategory()
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
			float weight = (float)reader->GetDouble(2);

			Dog^ dog = gcnew Dog(name, owner, weight);
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

bool DBHandler::checkEntryExists(String^ searchName, String^ tableName)
{
	String^ sqlOperation = String::Format(
		"SELECT * FROM {0} WHERE name LIKE '{1}'",
		tableName,
		searchName
	);


	SqlConnection sqlConnection(DBHandler::connectionString);
	SqlCommand command(sqlOperation, % sqlConnection);

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

bool DBHandler::checkDogExists(String^ dogName)
{
	return DBHandler::checkEntryExists(dogName, "dogs");	
}
bool DBHandler::checkUserExists(String^ username)
{
	return DBHandler::checkEntryExists(username, "users");
}

