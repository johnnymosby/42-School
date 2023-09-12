#include "Dog.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): Animal("Dog"), brain(new Brain()) {
	std::cout << "Default constructor is called [Dog]\n";
}

Dog::Dog(std::string const & type): Animal(type), brain(new Brain()) {
	std::cout << "'string type' constructor is called [Dog]\n";
}

Dog::Dog(Dog const & src): Animal(src) {
	std::cout << "Copy constructor is called [Dog]\n";
	brain = NULL;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/


Dog::~Dog() {
	std::cout << "Destructor for " << BOLDBLUE << type << RESET << " is called [Dog]\n";
	delete brain;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog & Dog::operator=(const Dog &other)
{
	std::cout << "Assignment Operator Dog Called" << std::endl;
	type = other.getType();
	if (this->brain)
		delete brain;
	this->brain = new Brain(*other.brain);
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

Brain * Dog::getBrain() {
	return brain;
}

/* ************************************************************************** */