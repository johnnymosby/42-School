#include "Dog.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): Animal("Dog") {
	std::cout << "Default constructor is called [Dog]\n";
}

Dog::Dog(std::string const & type): Animal(type) {
	std::cout << "'string type' constructor is called [Dog]\n";
}

Dog::Dog(Dog const & src) {
	std::cout << "Copy constructor is called [Dog]\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/


Dog::~Dog() {
	std::cout << "Destructor for " << BOLDBLUE << type << RESET << " is called [Dog]\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog & Dog::operator=(Dog const & other) {
	std::cout << "Copy assignment operator is called [Dog]\n";
	type = other.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const {
	std::cout << BOLDBLUE << type << RESET << " barks\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Dog::getType() const {
	return type;
}

/* ************************************************************************** */