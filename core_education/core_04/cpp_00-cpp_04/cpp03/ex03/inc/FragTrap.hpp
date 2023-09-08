#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

// HP - Health Points
// EP - Energy Points
// AD - Attack Damage

class FragTrap : virtual public ClapTrap
{

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap();

		FragTrap & operator=(FragTrap const & other);

		void	attack(const std::string& target);

		void	highFivesGuys(void);
		int		getDefaultHP(void);
		int		getDefaultEP(void);
		int		getDefaultAD(void);
};


#endif /* ***************************************************** FRAGTRAP_HPP */