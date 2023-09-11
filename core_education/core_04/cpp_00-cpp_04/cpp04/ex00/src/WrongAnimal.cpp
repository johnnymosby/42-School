#include "WrongAnimal.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal(): type("WrongAnimal") {
	std::cout << "Default constructor is called [WrongAnimal]\n";
}

WrongAnimal::WrongAnimal(std::string const & type): type(type) {
	std::cout << "'string type' constructor is called [WrongAnimal]\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	std::cout << "Copy constructor is called [WrongAnimal]\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/


WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor for " << BOLDYELLOW << type << RESET << " is called [WrongAnimal]\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & other) {
	std::cout << "Copy assignment operator is called [WrongAnimal]\n";
	if (this != &other ) {
		*this = other;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound() const {
	std::cout << BOLDYELLOW << type << RESET << " makes generic wronganimal sound\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	WrongAnimal::getType() const {
	return type;
}

/* ************************************************************************** */