#include "Dog.h"

TopDogShow::Dog::Dog(std::string dogName, std::string ownerName, float dogWeight)
{
	name = dogName;
	owner = ownerName;
	weight = dogWeight;
	defineCategory();
}

void TopDogShow::Dog::defineCategory()
{
	int weight_int = (int)(100 * weight);
	if (weight_int  < 2000)
		category = Categories::LIGHT_WEIGHT;
	else if ((weight_int >= 2000) && (weight_int < 2500))
		category = Categories::MEDIUM_WEIGHT;
	else
		category = Categories::HEAVY_WEIGTH;
}