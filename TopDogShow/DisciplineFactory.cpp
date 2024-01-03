#include "DisciplineFactory.h"
#include "WallClimb.h"

System::Windows::Forms::Form^ TopDogShow::DisciplineFactory::createDiscipline(std::string disciplineType)
{
	return (gcnew WallClimb());
}
