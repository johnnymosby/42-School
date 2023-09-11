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
	std::cout << "Destructor for " << BOLDYELLOW << type << RESET << " is called [Animal]\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

void virtual	Animal::makeSound() {
	std::cout << BOLDYELLOW << type << RESET << " makes generic animal sound\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Animal::getType() {
	return type;
}

/* ************************************************************************** */