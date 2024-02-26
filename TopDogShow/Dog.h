#pragma once
#include <string>

#include "Constants.h"

namespace TopDogShow
{
	using namespace System;

	public ref class Dog
	{
	private:
		String^ name;
		String^ owner;
		String^ category;
		String^ pictureFile;

		String^ escapeChar(String^ original, String^ toEscape);
	public:
		Dog() {}
		Dog(String^ dogName, String^ ownerName, String^ category, String^ picturePath);

		String^ getName();
		String^ getOwner();
		String^ getCategory();
		String^ getPictureFile();

		void setName(String^ name);
		void setOwner(String^ owner);
		void setCategory(String^ category);
		void setPictureFile(String^ path);
		
	};
}


