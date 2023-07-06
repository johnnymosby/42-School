#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }

  unsigned int strLen;
  std::string str;

  for (unsigned int i = 1; i < argc; i++) {
    str = argv[i];
    strLen = str.length();
    for (unsigned int j = 0; j < strLen; j++) {
      str.at(j) = std::toupper(str.at(j));
    }
    std::cout << str;
  }
  std::cout << std::endl;
  return (0);
}
