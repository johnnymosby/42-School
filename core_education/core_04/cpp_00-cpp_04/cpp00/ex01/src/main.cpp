#include <string>
#include <iostream>
#include "../inc/PhoneBook.hpp"
#include "../inc/utils.hpp"

int main(void)
{
  std::string input;
  PhoneBook   phonebook;

  while (true) {
    std::cout << "Type a command [ADD, SEARCH, EXIT]: ";
    std::cin >> input;
    exit_if_eof();
    if (input == "ADD")
      phonebook.add();
    else if (input == "SEARCH")
      phonebook.search();
    else if (input == "EXIT") {
      std::cout << "Exiting the program.\n";
      return 0;
    }
    else
      std::cout << "Incorrect input\n";
  }
  return 0;
}
