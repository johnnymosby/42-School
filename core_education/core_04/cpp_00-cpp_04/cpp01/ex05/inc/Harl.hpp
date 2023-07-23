#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
# define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
# define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n"
# define ERROR "This is unacceptable! I want to speak to the manager now.\n"
# define OTHER "Probably complaining about insignificant problems\n"

class Harl
{
  public:
    void  complain(std::string level);

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
