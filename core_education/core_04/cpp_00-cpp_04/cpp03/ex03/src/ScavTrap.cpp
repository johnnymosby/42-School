#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "Default constructor is called [ScavTrap]\n";
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	std::cout << "Constructor with 'string name' is called ["
				<< name << ", " << hp << " HP, " << ep << " EP, " << ad << " AD; ScavTrap]\n";
}

ScavTrap::ScavTrap(const ScavTrap & src)
{
	std::cout << "Copy constructor is called [ScavTrap]\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor is called [ScavTrap]\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/
ScavTrap &		ScavTrap::operator=(ScavTrap const & other) {
	std::cout << "Copy assignment operator is called [ScavTrap]\n";
	if (this != &other ) {
		*this = other;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScavTrap::guardGate(void) {
	std::cout << MAGENTA << "ScavTrap have enterred in Gate keeper mode ["
				<< name << ", " << hp << " HP, " << ep << " EP, " << ad << " AD]\n" << RESET;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->hp <= 0) {
		std::cout << "ScavTrap "
					<< BOLDGREEN << this->name << RESET
					<< RED << " is dead!\n" << RESET;
	} else if (this->ep > 0) {
		std::cout << "ScavTrap "
					<< BOLDCYAN << this->name << RESET
					<< RED << " attacks " << RESET
					<< target << ", causing " << this->ad << " points of damage!\n";
		this->ep -= 1;
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
int	ScavTrap::getDefaultHP(void) {
	return 100;
}

int	ScavTrap::getDefaultEP(void) {
	return 50;
}

int	ScavTrap::getDefaultAD(void) {
	return 20;
}

/* ************************************************************************** */