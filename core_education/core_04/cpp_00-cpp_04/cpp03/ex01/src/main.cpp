#include "ScavTrap.hpp"

int main(void) {
	ClapTrap	clavtrap("ClavTrap");
	ScavTrap	scavtrap("ScavTrap");

	clavtrap.attack("ScavTrap");
	scavtrap.takeDamage(10);
	scavtrap.beRepaired(10);


	scavtrap.attack("ClapTrap");
	clavtrap.takeDamage(20);
	clavtrap.beRepaired(20);
}
