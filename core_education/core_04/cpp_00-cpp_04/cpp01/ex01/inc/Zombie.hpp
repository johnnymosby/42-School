#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  public:
    void  announce(void);
    Zombie(void);
    Zombie(std::string name);
    ~Zombie() {
      std::cout << name << " is destroyed." << std::endl;
    };
    void  setName(std::string name);
  private:
    std::string name;
};

Zombie*  zombieHorde(int N, std::string name);

#endif