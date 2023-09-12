#include "Brain.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() {
	std::cout << "Default constructor is called [Brain]\n";

	size_ = 100;
	ideas = new std::string[size_];

	for (size_t i = 0; i < size_; i++) {
		ideas[i] = "DEFAULT IDEA";
	}
}

Brain::Brain(Brain const & src) {
	std::cout << "Copy constructor is called [Brain]\n";

	size_ = src.size_; 
	ideas = new std::string[size_];

	std::string *src_ideas = src.getIdeas();

	for (size_t i = 0; i < size_; i++) {
		ideas[i] = src_ideas[i];
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() {
	std::cout << "Destructor is called [Brain]\n";
	delete [] this->ideas;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain & Brain::operator=(Brain const & other) {
	std::cout << "Copy assignment operator is called [Brain]\n";
	if (this != &other) {
		for (size_t i = 0; i < size_ && i < other.size_; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	*Brain::getIdeas() const {
	return this->ideas;
}

size_t	Brain::getSize() {
	return size_;
}

/* ************************************************************************** */