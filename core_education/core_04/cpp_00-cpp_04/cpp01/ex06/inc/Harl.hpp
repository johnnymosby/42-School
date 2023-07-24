#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n"
# define INFO "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n"
# define WARNING "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n"
# define ERROR "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n\n"
# define OTHER "[ Probably complaining about insignificant problems ]\n"

typedef enum e_level
{
  DEBUG_LEVEL,
  INFO_LEVEL,
  WARNING_LEVEL,
  ERROR_LEVEL,
  OTHER_LEVEL
}       t_level;

class Harl
{
  public:
    void  complain(t_level level);

  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void other(void);
};

typedef void (Harl::*HarlMemFn) (void);
# define CALL_MEMBER_FN(object, ptrToMember) ((object)->*(ptrToMember))

#endif
