#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>

# ifndef PHONEBOOK_FIELD
# define PHONEBOOK_FIELD
typedef enum  e_phonebook_field
{
  FIRST_NAME,
  LAST_NAME,
  NICKNAME,
  PHONE_NUMBER,
  DARKEST_SECRET
} t_phonebook_field;
# endif

# ifndef CONTACT
# define CONTACT
class Contact
{
  private:
    std::string   first_name, last_name, nickname, phone_number, darkest_secret;
  public:
    std::string   get_value(t_phonebook_field field);
    void          set_value(t_phonebook_field field, std::string value);
};
# endif

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
