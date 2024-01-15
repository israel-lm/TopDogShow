#include "DBHandler.h"

TopDogShow::DBHandler* TopDogShow::DBHandler::instance = nullptr;

std::string TopDogShow::DBHandler::connectionString = "Data Source=.\\SQLEXPRESS;Initial Catalog=top_dog_show;Integrated Security=True;Encrypt=False";

std::map<TopDogShow::DBErrorType, std::string> TopDogShow::DBHandler::ErrorString = {
		{UNKNOWN, "Unknown"},
		{USER_ALREADY_EXISTS, "User already exists."},
		{USER_DOESNT_EXIST, "User doesn't exist."},
		{DOG_ALREADY_EXISTS, "Dog already registered."},
		{DOG_DOESNT_EXIST, "Dog not registered."}
};

TopDogShow::DBHandler::DBHandler(){}

TopDogShow::DBHandler::~DBHandler(){}

TopDogShow::DBHandler* TopDogShow::DBHandler::getInstance()
{
	if (!instance)
		instance = new DBHandler();

	return instance;
}

TopDogShow::DBErrorType TopDogShow::DBHandler::getUserInfo(std::string username, User& user)
{
	String^ sqlQuery = String::Format("SELECT * from users WHERE name='{0}'", marshal_as<String^>(username));
	SqlConnection sqlConnection(marshal_as<String^>(connectionString));
	SqlCommand command(sqlQuery, % sqlConnection);
	
	try
	{
		sqlConnection.Open();
		SqlDataReader^ reader = command.ExecuteReader();

		if (reader && reader->Read())
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
	catch (Exception^ e)
	{
		//TODO: log exception
	}	
	
}

TopDogShow::DBErrorType TopDogShow::DBHandler::getDogInfo(std::string dogName, Dog& dog)
{
	String^ sqlQuery = String::Format("SELECT * from dogs WHERE name='{0}'", marshal_as<String^>(dogName));
	SqlConnection sqlConnection(marshal_as<String^>(connectionString));
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
}

TopDogShow::DBErrorType TopDogShow::DBHandler::saveDogInfo(Dog& dog)
{

	if (DBHandler::checkDogExists(dog.getName()))
	{
		return DBErrorType::DOG_ALREADY_EXISTS;
	}
	else
	{
		String^ sqlOperation = String::Format(
			"INSERT INTO dogs (name, owner, weight, category) VALUES ('{0}', '{1}', {2}, {3})",
			marshal_as<String^>(dog.getName()),
			marshal_as<String^>(dog.getOwner()),
			dog.getWeight(),
			(int)dog.getCategory()
		);

		return DBHandler::executeNonQuery(sqlOperation);
	}	
}

TopDogShow::DBErrorType TopDogShow::DBHandler::saveUserInfo(User& user)
{
	if (DBHandler::checkUserExists(user.getName()))
	{
		return DBErrorType::USER_ALREADY_EXISTS;
	}
	else
	{
		String^ sqlOperation = String::Format(
			"INSERT INTO users (name, password) VALUES ('{0}', '{1}')",
			marshal_as<String^>(user.getName()),
			marshal_as<String^>(user.getPassword())
		);

		return DBHandler::executeNonQuery(sqlOperation);
	}		
}


 TopDogShow::DBErrorType TopDogShow::DBHandler::executeNonQuery(String^ operation)
{
	try
	{
		SqlConnection sqlConnection(marshal_as<String^>(connectionString));
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

bool TopDogShow::DBHandler::checkEntryExists(std::string searchName, std::string tableName)
{
	String^ sqlOperation = String::Format(
		"SELECT * FROM {0} WHERE name LIKE '{1}'",
		marshal_as<String^>(tableName),
		marshal_as<String^>(searchName)
	);


	SqlConnection sqlConnection(marshal_as<String^>(connectionString));
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

bool TopDogShow::DBHandler::checkDogExists(std::string dogName)
{
	return DBHandler::checkEntryExists(dogName, "dogs");	
}
bool TopDogShow::DBHandler::checkUserExists(std::string username)
{
	return DBHandler::checkEntryExists(username, "users");
}