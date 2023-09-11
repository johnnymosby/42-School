#include "WrongCat.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat(): type("WrongCat") {
	std::cout << "Default constructor is called [WrongCat]\n";
}

WrongCat::WrongCat(std::string const & type): type(type) {
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


/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound() {
	std::cout << BOLDYELLOW << type << RESET << " meows wrongly\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	WrongCat::getType() {
	return type;
}

/* ************************************************************************** */