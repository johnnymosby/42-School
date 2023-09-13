#include "Animal.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(): type("Animal") {
	std::cout << "Default constructor is called [Animal]\n";
}

Animal::Animal(std::string const & type): type(type) {
	std::cout << "'string type' constructor is called [Animal]\n";
}

Animal::Animal(Animal const & src) {
	std::cout << "Copy constructor is called [Animal]\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/


Animal::~Animal() {
	std::cout << "Destructor for " << BOLDGREEN << type << RESET << " is called [Animal]\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal & Animal::operator=(Animal const & other) {
	std::cout << "Copy assignment operator is called [Animal]\n";
	type = other.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound() const {
	std::cout << BOLDGREEN<< type << RESET << " makes generic animal sound\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType() const {
	return type;
}

/* ************************************************************************** */