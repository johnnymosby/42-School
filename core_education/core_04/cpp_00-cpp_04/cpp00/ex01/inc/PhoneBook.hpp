#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
  private:
    int     last_updated;
    Contact contacts[8];
    void    prompt_fields_to_add(std::string prompt, t_phonebook_field field);
    bool    print_contacts();
    void    print_value(t_phonebook_field field, unsigned i);
    void    display_contact(int index);

  public:
    void  add();
    void  search();
    PhoneBook();
};

#endif
