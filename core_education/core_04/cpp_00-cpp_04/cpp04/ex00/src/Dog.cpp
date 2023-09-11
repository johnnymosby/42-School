#include "Dog.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): type("Dog") {
	std::cout << "Default constructor is called [Dog]\n";
}

Dog::Dog(std::string const & type): type(type) {
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
	std::cout << "Destructor for " << BOLDYELLOW << type << RESET << " is called [Dog]\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() {
	std::cout << BOLDYELLOW << type << RESET << " barks\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Dog::getType() {
	return type;
}

/* ************************************************************************** */