#include "AbstractAnimal.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AbstractAnimal::AbstractAnimal(): type("AbstractAnimal") {
	std::cout << "Default constructor is called [AbstractAnimal]\n";
}

AbstractAnimal::AbstractAnimal(std::string const & type): type(type) {
	std::cout << "'string type' constructor is called [AbstractAnimal]\n";
}

AbstractAnimal::AbstractAnimal(AbstractAnimal const & src) {
	std::cout << "Copy constructor is called [AbstractAnimal]\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/


AbstractAnimal::~AbstractAnimal() {
	std::cout << "Destructor for " << BOLDGREEN << type << RESET << " is called [AbstractAnimal]\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AbstractAnimal & AbstractAnimal::operator=(AbstractAnimal const & other) {
	std::cout << "Copy assignment operator is called [AbstractAnimal]\n";
	if (this != &other ) {
		type = other.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AbstractAnimal::getType() const {
	return type;
}

/* ************************************************************************** */