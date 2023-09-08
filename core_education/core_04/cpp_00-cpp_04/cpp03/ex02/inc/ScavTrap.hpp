#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

// HP - Health Points
// EP - Energy Points
// AD - Attack Damage

class ScavTrap : public ClapTrap
{

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(std::string name, int hp, int ep, int ad);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();

		ScavTrap & operator=(ScavTrap const & other);

		void	attack(const std::string& target);

		void	guardGate(void);

	private:
};


#endif /* ***************************************************** SCAVTRAP_HPP */