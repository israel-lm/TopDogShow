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
		float weight;
		String^ category;

		void defineCategory();
		String^ escapeChar(String^ original, String^ toEscape);
	public:
		Dog() {}
		Dog(String^ dogName, String^ ownerName, float dogWeight);

		String^ getName() { return name; }
		String^ getOwner() { return owner; }

		void setName(String^ name) { this->name = name; }
		void setOwner(String^ owner) { this->owner = owner; }
		void setWeight(float weight) { this->weight = weight; defineCategory(); }

		float getWeight() { return weight; }
		String^ getCategory() { return category; }
	};
}


