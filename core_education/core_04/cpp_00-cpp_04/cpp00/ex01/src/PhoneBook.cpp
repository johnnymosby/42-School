#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
  last_updated = 0;
}

void  PhoneBook::add()
{
  std::string value;
  int         i = this->last_updated;

  std::cout << "Please provide values for the fields of the new contact.\n";
  prompt_fields_to_add("    First name: ", FIRST_NAME);
  prompt_fields_to_add("     Last name: ", LAST_NAME);
  prompt_fields_to_add("      Nickname: ", NICKNAME);
  prompt_fields_to_add("  Phone number: ", PHONE_NUMBER);
  prompt_fields_to_add("Darkest secret: ", DARKEST_SECRET);
  this->last_updated = (this->last_updated + 1) % 8;
}

void  PhoneBook::prompt_fields_to_add(std::string prompt, t_phonebook_field field)
{
  std::string value;
  int i = this->last_updated;

  std::cout << prompt;
  std::cin >> value;
  exit_if_eof();
  while (true) {
    if (value.length() == 0) {
      std::cout << "Empty value is not a valid input for the field: ";
      std::cin >> value;
      exit_if_eof();
    }
    else {
      contacts[i].set_value(field, value);
      break ;
    }
  }
}

void  PhoneBook::search()
{
  std::string input;

  if (print_contacts() == false)
    return ;
  std::cout << std::endl << "Type index of the contact you want to know the full information about [0-7]:\n";
  std::cin >> input;
  exit_if_eof();
  while (true) {
    if (input.length() == 1 && ('0' <= input[0] && input[0] <= '7'))
      break ;
    else {
      std::cout << "The index is wrong. Type it again.\n" << "The index of the contact to display: ";
      std::cin >> input;
      exit_if_eof();
      std::cout << std::endl;
    }
  }
  display_contact(int(input[0] - '0'));
}

bool  PhoneBook::print_contacts()
{
  if (contacts[0].get_value(FIRST_NAME).empty()) {
    std::cout << "The phonebook is empty." << std::endl;
    return false;
  }
  else {
    std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
    std::cout << "----------|----------|----------|----------" << std::endl;
  }
  for (unsigned i = 0; i < 8; i++) {
    if (contacts[i].get_value(FIRST_NAME).empty())
      return true;
    else {
      std::cout << std::setw(10) << i << "|";
      print_value(FIRST_NAME, i);
      print_value(LAST_NAME, i);
      print_value(NICKNAME, i);
    }
  }
  return true;
}

void  PhoneBook::print_value(t_phonebook_field field, unsigned i)
{
  std::string substring;

  if (contacts[i].get_value(field).length() > 10) {
    substring = contacts[i].get_value(field).substr(0, 9);
    std::cout << substring << ".";
  }
  else {
    std::cout << std::setw(10) << contacts[i].get_value(field);
  }

  if (field == NICKNAME)
    std::cout << std::endl;
  else
    std::cout << "|";
}

void  PhoneBook::display_contact(int index)
{
  if (contacts[index].get_value(FIRST_NAME).empty()) {
    std::cout << "No entry with the index " << index << "." << std::endl;
    return ;
  }
  std::cout << "    First name: " << contacts[index].get_value(FIRST_NAME) << std::endl;
  std::cout << "     Last name: " << contacts[index].get_value(LAST_NAME) << std::endl;
  std::cout << "      Nickname: " << contacts[index].get_value(NICKNAME) << std::endl;
  std::cout << "  Phone number: " << contacts[index].get_value(PHONE_NUMBER) << std::endl;
  std::cout << "Darkest secret: " << contacts[index].get_value(DARKEST_SECRET) << std::endl;
}
