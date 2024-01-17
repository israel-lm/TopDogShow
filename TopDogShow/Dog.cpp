#include "Dog.h"

TopDogShow::Dog::Dog(String^ dogName, String^ ownerName, float dogWeight)
{
	name = dogName;
	escapeChar(name, "'");
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
		category = Categories::HEAVY_WEIGHT;
}

System::String^ TopDogShow::Dog::escapeChar(String^ original, String^ toEscape)
{
	return original->Replace(toEscape, String::Format("\{0}", toEscape));
}