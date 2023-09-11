#include "Cat.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): type("Cat") {
	std::cout << "Default constructor is called [Cat]\n";
}

Cat::Cat(std::string const & type): type(type) {
	std::cout << "'string type' constructor is called [Cat]\n";
}

Cat::Cat(Cat const & src) {
	std::cout << "Copy constructor is called [Cat]\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/


Cat::~Cat() {
	std::cout << "Destructor for " << BOLDYELLOW << type << RESET << " is called [Cat]\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() {
	std::cout << BOLDYELLOW << type << RESET << " meows\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Cat::getType() {
	return type;
}

/* ************************************************************************** */