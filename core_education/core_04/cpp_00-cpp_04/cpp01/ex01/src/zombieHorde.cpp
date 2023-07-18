# include "../inc/Zombie.hpp"

Zombie*  zombieHorde(int N, std::string name)
{
  Zombie* zombies;

  try {
    zombies = new Zombie[N];
  } catch (std::bad_alloc &bad_allocation) {
    std::cerr << "Error encountered: " << bad_allocation.what() << std::endl;
    return NULL;
  }
  for (int i = 0; i < N; i++) {
    zombies[i].setName(name);
  }
  return zombies;
}
