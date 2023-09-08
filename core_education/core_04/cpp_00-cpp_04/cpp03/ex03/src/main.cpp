#include "DiamondTrap.hpp"

int main() {
	ClapTrap		clavtrap("ClavTrap");
	ScavTrap		scavtrap("ScavTrap");
	FragTrap		fragtrap("FragTrap");
	DiamondTrap		diamondtrap("DiamondTrap");

	diamondtrap.attack("DiamondTrap");
	diamondtrap.takeDamage(30);
	diamondtrap.beRepaired(30);
	diamondtrap.highFivesGuys();
	diamondtrap.whoAmI();
}
