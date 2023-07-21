#include "../inc/Contact.hpp"
#include "../inc/utils.hpp"

std::string   Contact::get_value(t_phonebook_field field)
{
  switch (field)
  {
    case  FIRST_NAME:
      return this->first_name;
    case  LAST_NAME:
      return this->last_name;
    case  NICKNAME:
      return this->nickname;
    case  PHONE_NUMBER:
      return this->phone_number;
    case  DARKEST_SECRET:
      return this->darkest_secret;
    default:
      return "";
  }
}

void   Contact::set_value(t_phonebook_field field, std::string value)
{
  switch (field)
  {
    case  FIRST_NAME:
      this->first_name = value;
      break ;
    case  LAST_NAME:
      this->last_name = value;
      break ;
    case  NICKNAME:
      this->nickname = value;
      break ;
    case  PHONE_NUMBER:
      this->phone_number = value;
      break ;
    case  DARKEST_SECRET:
      this->darkest_secret = value;
      break ;
  }
}
