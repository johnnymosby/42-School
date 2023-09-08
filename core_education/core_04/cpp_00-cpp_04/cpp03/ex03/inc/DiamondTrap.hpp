#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

// HP - Health Points
// EP - Energy Points
// AD - Attack Damage

class DiamondTrap: public ScavTrap, public FragTrap
{

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap();

		DiamondTrap & operator=(DiamondTrap const & other);

		void	attack(const std::string& target);

		void	whoAmI(void);

	private:
		std::string		_name;
};


#endif /* ***************************************************** DIAMONDTRAP_HPP */