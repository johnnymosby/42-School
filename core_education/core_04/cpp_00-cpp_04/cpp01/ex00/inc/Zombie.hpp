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
  private:
    std::string name;
};

Zombie* newZombie(std::string name);
void  randomChump(std::string name);

#endif