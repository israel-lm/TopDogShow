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
		Categories^ category;
		String^ pictureFile;

		String^ escapeChar(String^ original, String^ toEscape);
	public:
		Dog() {}
		Dog(String^ dogName, String^ ownerName, Categories^ category, String^ picturePath);

		String^ getName();
		String^ getOwner();
		Categories^ getCategory();
		String^ getPictureFile();

		void setName(String^ name);
		void setOwner(String^ owner);
		void setCategory(Categories^ category);
		void setPictureFile(String^ path);
		
	};
}


