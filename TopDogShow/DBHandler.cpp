#include "DBHandler.h"

TopDogShow::DBHandler* TopDogShow::DBHandler::instance = nullptr;
std::string TopDogShow::DBHandler::connectionString = "Data Source=.\\SQLEXPRESS;Initial Catalog=top_dog_show;Integrated Security=True;Encrypt=False";

TopDogShow::DBHandler::DBHandler(){}

TopDogShow::DBHandler::~DBHandler()
{
}

TopDogShow::DBHandler* TopDogShow::DBHandler::getInstance()
{
	if (!instance)
		instance = new DBHandler();

	return instance;
}

TopDogShow::DBErrorType TopDogShow::DBHandler::getUserInfo(std::string username, User& user)
{
	try
	{
		SqlConnection sqlConnection(marshal_as<String^>(connectionString));
		sqlConnection.Open();

		String^ sqlQuery = String::Format("SELECT * from users WHERE name='{0}'", marshal_as<String^>(username));
		SqlCommand command(sqlQuery, % sqlConnection);

		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read())
		{
			String^ name = reader->GetString(0);
			String^ password = reader->GetString(1);
			user.setName(marshal_as<std::string>(name));
			user.setPassword(marshal_as<std::string>(password));
			return DBErrorType::OK;
		}
		else
		{
			//TODO: log error
			return DBErrorType::USER_DOESNT_EXIST;
		}
	}
	catch (Exception^ e){}
	return DBErrorType::UNKNOWN;
}

TopDogShow::DBErrorType TopDogShow::DBHandler::getDogInfo(std::string dogName, Dog& dog)
{
	try
	{
		SqlConnection sqlConnection(marshal_as<String^>(connectionString));
		sqlConnection.Open();

		String^ sqlQuery = String::Format("SELECT * from dogs WHERE name='{0}'", marshal_as<String^>(dogName));
		SqlCommand command(sqlQuery, % sqlConnection);

		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read())
		{
			String^ name = reader->GetString(0);
			String^ owner = reader->GetString(1);
			float weight = reader->GetFloat(2);

			dog.setName(marshal_as<std::string>(name));
			dog.setOwner(marshal_as<std::string>(owner));
			dog.setWeight(weight);
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
	return DBErrorType::UNKNOWN;
}

TopDogShow::DBErrorType TopDogShow::DBHandler::saveDogInfo(Dog& dog)
{
	try
	{
		SqlConnection sqlConnection(marshal_as<String^>(connectionString));
		sqlConnection.Open();

		String^ sqlOperation = String::Format(
			"INSERT INTO dogs (name, owner, weight, category) VALUES ('{0}', '{1}', {2}, {3})", 
			marshal_as<String^>(dog.getName()),
			marshal_as<String^>(dog.getOwner()),
			dog.getWeight(), 
			(int)dog.getCategory()
		);

		SqlCommand command(sqlOperation, % sqlConnection);

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

TopDogShow::DBErrorType TopDogShow::DBHandler::saveUserInfo(User& user)
{
	try
	{
		SqlConnection sqlConnection(marshal_as<String^>(connectionString));
		sqlConnection.Open();

		String^ sqlOperation = String::Format(
			"INSERT INTO users (name, password) VALUES ('{0}', '{1}')",
			marshal_as<String^>(user.getName()),
			marshal_as<String^>(user.getPassword())
		);

		SqlCommand command(sqlOperation, % sqlConnection);

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