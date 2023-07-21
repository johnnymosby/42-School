#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

typedef enum  e_phonebook_field
{
  FIRST_NAME,
  LAST_NAME,
  NICKNAME,
  PHONE_NUMBER,
  DARKEST_SECRET
} t_phonebook_field;

class Contact
{
  private:
    std::string   first_name, last_name, nickname, phone_number, darkest_secret;
  public:
    std::string   get_value(t_phonebook_field field);
    void          set_value(t_phonebook_field field, std::string value);
};

#endif
