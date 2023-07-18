#include "../inc/utils.hpp"

void  exit_if_eof(void)
{
  if (std::cin.eof()) {
    std::cout << "\nYou pressed CTRL+D.\n" << "Exiting the program.\n";
    exit (0);
  }
}
