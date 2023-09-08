#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap(): ClapTrap("Bob_clap_name"), ScavTrap(), FragTrap(), _name("Bob") {
	ep = ScavTrap::getDefaultEP();
	std::cout << "Default constructor is called [DiamondTrap]\n";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
	ep = ScavTrap::getDefaultEP();
	std::cout << "Constructor with 'string name' is called ["
				<< name << ", " << hp << " HP, " << ep << " EP, " << ad << " AD; DiamondTrap]\n";
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) {
	std::cout << "Copy constructor is called [DiamondTrap]\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor is called [DiamondTrap]\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
DiamondTrap & DiamondTrap::operator=(DiamondTrap const & other) {
	std::cout << "Copy assignment operator is called [DiamondTrap]\n";

	if (this != &other) {
		*this = other;
	}

	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name is " << BOLDGREEN << _name << RESET
				<< " and ClapTrap name is " << BOLDMAGENTA << name << RESET << std::endl;
}

void	DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */