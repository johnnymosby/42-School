#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

// HP - Health Points
// EP - Energy Points
// AD - Attack Damage

const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string ORANGE = "\033[1;33m";
const std::string RESET = "\033[0m";

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hp, int ep, int ad);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();

		ClapTrap & operator=(ClapTrap const & rhs);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int	getHP(void) const;
		int	getEP(void) const;
		int	getAD(void) const;

	private:

		std::string	name;
		int			hp;
		int			ep;
		int			ad;
};

#endif /* ******************************************************** CLAPTRAP_H */