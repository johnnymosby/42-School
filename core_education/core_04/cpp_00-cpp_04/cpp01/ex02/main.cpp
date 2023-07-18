#include <iostream>
#include <string>

int main()
{
  std::string str;
  std::string *stringPTR;
  std::string &stringREF = str;

  str = "HI THIS IS BRAIN";
  stringPTR = &str;
  stringREF = str;

  std::cout << std::endl;
  std::cout << "Memory address of the string variable:  " << &str << std::endl;
  std::cout << "Memory address held by stringPTR:       " << stringPTR << std::endl;
  std::cout << "Memory address held by stringREF:       " << &stringREF << std::endl;
  std::cout << std::endl;

  std::cout << "Value of the string variable:           " << str << std::endl;
  std::cout << "Value pointed to by stringPTR:          " << *stringPTR << std::endl;
  std::cout << "Value pointed to by stringREF:          " << stringREF << std::endl;
  std::cout << std::endl;

  return 0;
}
