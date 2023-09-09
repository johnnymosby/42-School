#include "Animal.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(): type("Animal") {}

Animal::Animal(std::string type): type(type) {}

Animal::Animal(Animal const & src) {
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/


Animal::~Animal() {
	std::cout << "Destructor for " << YELLOW << type << RESET << " is called\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	virtual	Animal::getType() {

}

/* ************************************************************************** */