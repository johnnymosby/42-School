#include "Harl.hpp"

void  Harl::debug(void)
{
  std::cout << DEBUG;
}

void  Harl::info(void)
{
  std::cout << INFO;
}

void  Harl::warning(void)
{
  std::cout << WARNING;
}

void  Harl::error(void)
{
  std::cout << ERROR;
}

void  Harl::other(void)
{
  std::cout << OTHER;
}

void  Harl::complain(t_level level)
{
  HarlMemFn foos[] = {&Harl::debug, &Harl::info, &Harl::warning,
                        &Harl::error, &Harl::other};

  switch (level)
  {
    case DEBUG_LEVEL:
      CALL_MEMBER_FN(this, foos[DEBUG_LEVEL]) ();
    case INFO_LEVEL:
      CALL_MEMBER_FN(this, foos[INFO_LEVEL]) ();
    case WARNING_LEVEL:
      CALL_MEMBER_FN(this, foos[WARNING_LEVEL]) ();
    case ERROR_LEVEL:
      CALL_MEMBER_FN(this, foos[ERROR_LEVEL]) ();
      return ;
    case OTHER_LEVEL:
      CALL_MEMBER_FN(this, foos[OTHER_LEVEL]) ();
      return ;
    this
  }
}
