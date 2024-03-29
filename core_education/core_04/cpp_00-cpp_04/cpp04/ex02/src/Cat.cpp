#include "Cat.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): AbstractAnimal("Cat"), brain(new Brain()) {
	std::cout << "Default constructor is called [Cat]\n";
}

Cat::Cat(std::string const & type): AbstractAnimal(type), brain(new Brain()) {
	std::cout << "'string type' constructor is called [Cat]\n";
}

Cat::Cat(Cat const & src): AbstractAnimal(src) {
	std::cout << "Copy constructor is called [Cat]\n";
	brain = NULL;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
	std::cout << "Destructor for " << BOLDYELLOW << type << RESET << " is called [Cat]\n";
	delete brain;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat & Cat::operator=(Cat const & other)
{
	std::cout << "Copy assignment operator is called [Cat]\n";
	type = other.getType();
	if (this->brain)
		delete brain;
	this->brain = new Brain(*other.brain);
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

Brain * Cat::getBrain() {
	return brain;
}

/* ************************************************************************** */