#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "Default constructor is called [FragTrap]\n";
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "Constructor with 'string name' is called ["
				<< name << ", " << hp << " HP, " << ep << " EP, " << ad << " AD; FragTrap]\n";
}

FragTrap::FragTrap(const FragTrap & src)
{
	std::cout << "Copy constructor is called [FragTrap]\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "Destructor is called [FragTrap]\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/
FragTrap &		FragTrap::operator=(FragTrap const & other) {
	std::cout << "Copy assignment operator is called [FragTrap]\n";
	if (this != &other ) {
		*this = other;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	FragTrap::attack(const std::string& target) {
	if (this->hp <= 0) {
		std::cout << "FragTrap "
					<< BOLDGREEN << this->name << RESET
					<< RED << " is dead!\n" << RESET;
	} else if (this->ep > 0) {
		std::cout << "FragTrap "
					<< BOLDGREEN << this->name << RESET
					<< RED << " attacks " << RESET
					<< target << ", causing " << this->ad << " points of damage!\n";
		this->ep -= 1;
	}
}

void	FragTrap::highFivesGuys(void) {
	if (this->hp > 0) {
		std::cout << "FragTrap "
					<< BOLDGREEN << this->name << RESET
					<< " is asking for high fives!\n";
	} else {
		std::cout << "FragTrap "
					<< BOLDGREEN << this->name << RESET
					<< " can't high five"
					<< RED << " [is dead]!\n" << RESET;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	FragTrap::getDefaultHP(void) {
	return 100;
}

int	FragTrap::getDefaultEP(void) {
	return 100;
}

int	FragTrap::getDefaultAD(void) {
	return 30;
}

/* ************************************************************************** */