#include "WrongCat.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "Default constructor is called [WrongCat]\n";
}

WrongCat::WrongCat(std::string const & type): WrongAnimal(type) {
	std::cout << "'string type' constructor is called [WrongCat]\n";
}

WrongCat::WrongCat(WrongCat const & src) {
	std::cout << "Copy constructor is called [WrongCat]\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/


WrongCat::~WrongCat() {
	std::cout << "Destructor for " << BOLDYELLOW << type << RESET << " is called [WrongCat]\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat & WrongCat::operator=(WrongCat const & other) {
	std::cout << "Copy assignment operator is called [WrongCat]\n";
	if (this != &other ) {
		*this = other;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound() const {
	std::cout << BOLDYELLOW << type << RESET << " meows wrongly\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	WrongCat::getType() const {
	return type;
}

/* ************************************************************************** */