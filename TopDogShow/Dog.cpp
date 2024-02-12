#include "Dog.h"

TopDogShow::Dog::Dog(String^ dogName, String^ ownerName, Categories^ category, String^ picturePath)
{
	this->name = dogName;
	this->escapeChar(name, "'");
	this->owner = ownerName;
	this->category = category;
	this->pictureFile = picturePath;
}


System::String^ TopDogShow::Dog::escapeChar(String^ original, String^ toEscape)
{
	return original->Replace(toEscape, String::Format("\{0}", toEscape));
}

System::String^ TopDogShow::Dog::getName() 
{ 
	return name; 
}

System::String^ TopDogShow::Dog::getOwner() 
{ 
	return owner; 
}

TopDogShow::Categories^ TopDogShow::Dog::getCategory()
{ 
	return category; 
}

System::String^ TopDogShow::Dog::getPictureFile()
{
	return pictureFile;
}

void TopDogShow::Dog::setName(String^ name) 
{ 
	this->name = name; 
}

void TopDogShow::Dog::setOwner(String^ owner) 
{ 
	this->owner = owner; 
}

void TopDogShow::Dog::setCategory(Categories^ category)
{ 
	this->category = category; 
}

void TopDogShow::Dog::setPictureFile(String^ path)
{
	this->pictureFile = path;
}