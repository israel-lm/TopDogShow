#pragma once
#include <string>

#include "Constants.h"

namespace TopDogShow
{
	class Dog
	{
	private:
		std::string name;
		std::string owner;
		float weight;
		Categories category;

		void defineCategory();
		void escapeChar(std::string& str, std::string toEscape);
	public:
		Dog() {}
		Dog(std::string dogName, std::string ownerName, float dogWeight);

		std::string getName() { return name; }
		std::string getOwner() { return owner; }

		void setName(std::string name) { this->name = name; }
		void setOwner(std::string owner) { this->owner = owner; }
		void setWeight(float weight) { this->weight = weight; defineCategory(); }

		float getWeight() { return weight; }
		Categories getCategory() { return category; }
	};
}


