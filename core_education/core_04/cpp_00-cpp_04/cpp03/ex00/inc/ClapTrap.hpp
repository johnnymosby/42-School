#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

  public:

    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const & src);
    ~ClapTrap();

    ClapTrap &    operator=(ClapTrap const & rhs);

    void  attack(const std::string& target);
    void  takeDamage(unsigned int amount);
    void  beRepaired(unsigned int amount);

  private:

    std::string name;
    int         hp;           // health points
    int         ep;           // energy points
    int         ad;           // attack damage
};

std::ostream &      operator<<(std::ostream & os, ClapTrap const & i);

#endif /* ******************************************************** CLAPTRAP_H */