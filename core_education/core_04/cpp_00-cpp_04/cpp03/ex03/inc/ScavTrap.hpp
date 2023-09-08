#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

// HP - Health Points
// EP - Energy Points
// AD - Attack Damage

class ScavTrap : virtual public ClapTrap
{

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();

		ScavTrap & operator=(ScavTrap const & other);

		void	attack(const std::string& target);

		void	guardGate(void);
		int		getDefaultHP(void);
		int		getDefaultEP(void);
		int		getDefaultAD(void);

	private:
};


#endif /* ***************************************************** SCAVTRAP_HPP */