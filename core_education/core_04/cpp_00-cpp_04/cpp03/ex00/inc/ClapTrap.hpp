#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

// HP - Health Points
// EP - Energy Points
// AD - Attack Damage

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();

		ClapTrap & operator=(ClapTrap const & rhs);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int	ClapTrap::getHP(void) const;
		int	ClapTrap::getEP(void) const;
		int	ClapTrap::getAD(void) const;

	private:

		std::string	name;
		int			hp;
		int			ep;
		int			ad;
};

#endif /* ******************************************************** CLAPTRAP_H */