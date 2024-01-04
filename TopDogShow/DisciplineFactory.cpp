#include "DisciplineFactory.h"
#include "WallClimb.h"
#include "HighJump.h"
#include "LongJump.h"
#include "Treadmil.h"

TopDogShow::DisciplineFactory* TopDogShow::DisciplineFactory::instance = nullptr;

TopDogShow::DisciplineFactory::DisciplineFactory()
{

}

System::Windows::Forms::Form^ TopDogShow::DisciplineFactory::createDiscipline(DisciplineType disciplineType)
{
	switch (disciplineType)
	{
		case DisciplineType::WallClimb:
			return (gcnew WallClimb());
		case DisciplineType::HighJump:
			return (gcnew HighJump());
		case DisciplineType::LongJump:
			return (gcnew LongJump());
		case DisciplineType::Treadmil:
			return (gcnew Treadmil());
	}
	
}

TopDogShow::DisciplineFactory* TopDogShow::DisciplineFactory::getInstance()
{
	if (instance == nullptr)
		return (new DisciplineFactory());
	else
		return instance;
}
