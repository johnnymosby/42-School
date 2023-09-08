#include "ClapTrap.hpp"

int main(void) {
	ClapTrap	default_one;
	ClapTrap	jim("Jim");
	ClapTrap	chad("Chad", 100, 100, 100);

	default_one.attack("Jim");
	jim.takeDamage(10);
	jim.beRepaired(10);

	jim.takeDamage(-5);
	jim.beRepaired(15);


	chad.takeDamage(50);
	chad.beRepaired(50);

	chad.takeDamage(150);
	chad.beRepaired(100);
}
