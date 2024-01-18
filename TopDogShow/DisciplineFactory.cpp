#include "DisciplineFactory.h"
#include "WallClimb.h"
#include "HighJump.h"
#include "LongJump.h"
#include "Treadmil.h"

TopDogShow::DisciplineFactory* TopDogShow::DisciplineFactory::instance = nullptr;

TopDogShow::DisciplineFactory::DisciplineFactory()
{

}

System::Windows::Forms::Form^ TopDogShow::DisciplineFactory::createDiscipline(DisciplineType disciplineType, String^ dogName)
{
	switch (disciplineType)
	{
		case DisciplineType::WallClimb:
			return (gcnew WallClimb(dogName));
		case DisciplineType::HighJump:
			return (gcnew HighJump(dogName));
		case DisciplineType::LongJump:
			return (gcnew LongJump(dogName));
		case DisciplineType::Treadmil:
			return (gcnew Treadmil());
	}
	
}

TopDogShow::DisciplineFactory* TopDogShow::DisciplineFactory::getInstance()
{
	if (!instance)
		instance = new DisciplineFactory();
	
	return instance;
}
