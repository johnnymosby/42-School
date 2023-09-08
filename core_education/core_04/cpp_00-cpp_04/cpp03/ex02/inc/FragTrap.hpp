#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

// HP - Health Points
// EP - Energy Points
// AD - Attack Damage

class FragTrap : public ClapTrap
{

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(std::string name, int hp, int ep, int ad);
		FragTrap(FragTrap const & src);
		~FragTrap();

		FragTrap & operator=(FragTrap const & other);

		void	attack(const std::string& target);

		void	highFivesGuys(void);

	private:
};


#endif /* ***************************************************** FRAGTRAP_HPP */