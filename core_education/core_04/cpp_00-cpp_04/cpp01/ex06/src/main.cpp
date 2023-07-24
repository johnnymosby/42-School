#include "Harl.hpp"

int main(int argc, char **argv)
{
  std::string parameter;
  Harl        harl;
  t_level     hashed_parameter;

  if (argc != 2) {
    std::cout << "Incorrect number of arguments\n";
    return (0);
  }
  parameter = argv[1];
  hashed_parameter = t_level(0 * (parameter == "DEBUG")
                      + 1 * (parameter == "INFO")
                      + 2 * (parameter == "WARNING")
                      + 3 * (parameter == "ERROR"));
  hashed_parameter = t_level(hashed_parameter
                      + 4 * ((hashed_parameter == 0)
                        && (parameter != "DEBUG")));
  harl.complain(hashed_parameter);

  return 0;
}
