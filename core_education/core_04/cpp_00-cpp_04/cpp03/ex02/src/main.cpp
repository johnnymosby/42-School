#include "FragTrap.hpp"

int main(void) {
	ClapTrap	clavtrap("ClavTrap");
	FragTrap	fragtrap("FragTrap");

	clavtrap.attack("FragTrap");
	fragtrap.takeDamage(10);
	fragtrap.beRepaired(10);
	fragtrap.highFivesGuys();

	clavtrap.attack("FragTrap");
	fragtrap.takeDamage(100);
	fragtrap.beRepaired(100);
	fragtrap.highFivesGuys();

	fragtrap.attack("ClapTrap");
	clavtrap.takeDamage(20);
	clavtrap.beRepaired(20);
}
