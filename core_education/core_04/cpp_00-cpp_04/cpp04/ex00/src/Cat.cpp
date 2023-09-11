#include "Cat.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): Animal("Cat") {
	std::cout << "Default constructor is called [Cat]\n";
}

Cat::Cat(std::string const & type): Animal(type) {
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

Cat & Cat::operator=(Cat const & other) {
	std::cout << "Copy assignment operator is called [Cat]\n";
	if (this != &other ) {
		*this = other;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const {
	std::cout << BOLDYELLOW << type << RESET << " meows\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Cat::getType() const {
	return type;
}

/* ************************************************************************** */