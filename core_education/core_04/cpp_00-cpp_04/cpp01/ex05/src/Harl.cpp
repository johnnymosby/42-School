#include "../inc/Harl.hpp"

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

void  Harl::complain(std::string level)
{
  HarlMemFn foos[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  std::string strs[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for (int i = 0; i < 4; i++) {
    if (level.compare(strs[i]) == 0) {
      CALL_MEMBER_FN(this, foos[i]);
      return ;
    }
  }
   Harl::other();
}
