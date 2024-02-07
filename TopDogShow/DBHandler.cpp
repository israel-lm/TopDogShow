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
	String^ sqlQuery = String::Format("SELECT * from {1} WHERE name='{0}'", username, USERS_TABLE_NAME);
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
	String^ sqlQuery = String::Format("SELECT * from {1} WHERE name='{0}'", dogName, REGISTRATION_TABLE_NAME);
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
	String^ sqlOperation;

	if (DBHandler::checkDogExists(dog->getName(), "dogs"))
	{
		sqlOperation = String::Format(
			"UPDATE {4} SET owner = '{0}', category = '{1}', picturePath = '{2}' WHERE name = '{3}';",
			dog->getOwner(),
			dog->getCategory(),
			dog->getPictureFile(),
			dog->getName(),
			REGISTRATION_TABLE_NAME
		);
	}
	else
	{
		sqlOperation = String::Format(
			"INSERT INTO {4} (name, owner, category, picturePath) VALUES ('{0}', '{1}', '{2}', '{3}')",
			dog->getName(),
			dog->getOwner(),
			dog->getCategory(),
			dog->getPictureFile(),
			REGISTRATION_TABLE_NAME
		);
	}
	return DBHandler::executeNonQuery(sqlOperation);
}

DBErrorType DBHandler::saveUserInfo(User^ user)
{
	String^ sqlOperation;

	if (DBHandler::checkUserExists(user->getName()))
	{
		sqlOperation = String::Format(
			"UPDATE {2} SET password = '{0}' WHERE name = '{1}';",
			user->getPassword(),
			user->getName(),
			USERS_TABLE_NAME
		);
	}
	else
	{
		sqlOperation = String::Format(
			"INSERT INTO {2} (name, password) VALUES ('{0}', '{1}')",
			user->getName(),
			user->getPassword(),
			USERS_TABLE_NAME
		);
	}
	return DBHandler::executeNonQuery(sqlOperation);
}

DBErrorType DBHandler::getAllDogs(List<Dog^>^ dogs)
{
	String^ sqlQuery = String::Format("SELECT * from {0}", REGISTRATION_TABLE_NAME);
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


DBErrorType DBHandler::checkTableAndCreate(String^ tableName)
{
	if (!checkTableExists(tableName))
	{
		if (tableName->Contains(WALL_CLIMB_TABLE_NAME) || tableName->Contains(HIGH_JUMP_TABLE_NAME))
			return createMarkTable(tableName);
	
		else if (tableName->Contains(LONG_JUMP_TABLE_NAME))
			return createTableLongJump();
		
		else if (tableName->Contains(TREADMILL_TABLE_NAME))
			return createTableTreadmill();
	}
	return DBErrorType::OK;
}

DBErrorType DBHandler::saveMarkTableResults(String^ tableName, MarkTablePerformanceData^ data)
{
	DBErrorType res = checkTableAndCreate(tableName);

	if (res == DBErrorType::OK)
	{
		for each (KeyValuePair<int, MarksData^> ^ kvp in data->marks)
		{
			int mark = kvp->Key;
			int attempts = kvp->Value->attempts;
			bool result = kvp->Value->result;

			String^ sqlOperation = String::Format(
				"INSERT INTO {0} (mark, attempts, result) VALUES ({1}, {2}, {3})",
				tableName,
				mark,
				attempts,
				int(result)
			);

			res = DBHandler::executeNonQuery(sqlOperation);
			if (res != DBErrorType::OK)
				break;
		}
	}

	return res;
}

DBErrorType  DBHandler::saveWallClimbResults(MarkTablePerformanceData^ data)
{
	String^ tableName = String::Format("{0}_{1}", data->dogName, WALL_CLIMB_TABLE_NAME);	
	return saveMarkTableResults(tableName, data);
}

DBErrorType  DBHandler::saveHighJumpResults(MarkTablePerformanceData^ data)
{
	String^ tableName = String::Format("{0}_{1}", data->dogName, HIGH_JUMP_TABLE_NAME);
	return saveMarkTableResults(tableName, data);
}

DBErrorType  DBHandler::saveLongJumpResults(LongJumpPerformanceData^ data)
{
	DBErrorType res = checkTableAndCreate(LONG_JUMP_TABLE_NAME);

	if (res == DBErrorType::OK)
	{
		String^ sqlOperation;

		if (checkDogExists(data->dogName, LONG_JUMP_TABLE_NAME))
		{
			sqlOperation = String::Format(
				"UPDATE {6} SET mark1 = {0}, mark2 = {1}, mark3 = {2}, mark4 = {3}, mark5 = {4} WHERE name = '{5}';",
				data->marks[0],
				data->marks[1],
				data->marks[2],
				data->marks[3],
				data->marks[4],
				data->dogName,
				LONG_JUMP_TABLE_NAME
			);
		}
		else
		{
			sqlOperation = String::Format(
				"INSERT INTO {6} (dogName, mark1, mark2, mark3, mark4, mark5) VALUES ('{0}', {1}, {2}, {3}, {4}, {5})",
				data->dogName,
				data->marks[0],
				data->marks[1],
				data->marks[2],
				data->marks[3],
				data->marks[4],
				LONG_JUMP_TABLE_NAME
			);
		}

		return DBHandler::executeNonQuery(sqlOperation);
	}

	return res;
}

DBErrorType  DBHandler::saveTreadmilllResults(TreadmilllPerformanceData^ data)
{
	DBErrorType res = checkTableAndCreate(TREADMILL_TABLE_NAME);

	if (res == DBErrorType::OK)
	{
		String^ sqlOperation;
		if (checkDogExists(data->dogName, TREADMILL_TABLE_NAME))
		{
			sqlOperation = String::Format(
				"UPDATE {1} SET  mark = {1} WHERE dogName = '{0}'",
				data->dogName,
				data->distance,
				TREADMILL_TABLE_NAME
			);
		}
		else
		{
			sqlOperation = String::Format(
				"INSERT INTO {2} (dogName, mark) VALUES ('{0}', {1})",
				data->dogName,
				data->distance,
				TREADMILL_TABLE_NAME
			);
		}		

		return DBHandler::executeNonQuery(sqlOperation);
	}

	return res;
}


DBErrorType DBHandler::createMarkTable(String^ tableName)
{
	String^ sqlOperation = String::Format(
		"CREATE TABLE {0} ("
			"mark INT NOT NULL PRIMARY KEY,"
			"attempts INT NOT NULL,"
			"result BIT NOT NULL"
		");",
		tableName
	);

	return DBHandler::executeNonQuery(sqlOperation);
}


DBErrorType DBHandler::createTableLongJump()
{
	String^ sqlOperation = String::Format(
		"CREATE TABLE {0} ("
			"dogName VARCHAR(100) NOT NULL PRIMARY KEY,"
			"mark1 INT NOT NULL,"
			"mark2 INT NOT NULL,"
			"mark3 INT NOT NULL,"
			"mark4 INT NOT NULL,"
			"mark5 INT NOT NULL"
		");",
		LONG_JUMP_TABLE_NAME
	);

	return DBHandler::executeNonQuery(sqlOperation);
}


DBErrorType DBHandler::createTableTreadmill()
{
	String^ sqlOperation = String::Format(
		"CREATE TABLE {0} ("
		"dogName VARCHAR(100) NOT NULL PRIMARY KEY,"
		"mark INT NOT NULL,"
		");",
		TREADMILL_TABLE_NAME
	);

	return DBHandler::executeNonQuery(sqlOperation);
}


DBErrorType DBHandler::deleteTable(String^ tableName)
{
	String^ sqlOperation = String::Format(
		"DROP TABLE {0};",
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

		command.ExecuteNonQuery();

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

bool DBHandler::checkDogExists(String^ dogName, String^ tableName)
{
	String^ operation = String::Format("SELECT * FROM {1} WHERE name LIKE '{0}'", dogName, tableName);
	return DBHandler::checkEntryExists(operation);	
}

bool DBHandler::checkUserExists(String^ username)
{
	String^ operation = String::Format("SELECT * FROM users WHERE name LIKE '{0}'", username);
	return DBHandler::checkEntryExists(operation);
}

