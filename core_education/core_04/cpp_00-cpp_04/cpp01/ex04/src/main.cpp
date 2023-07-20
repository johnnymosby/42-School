#include "../inc/losers.hpp"

int main(int argc, char *argv[])
{
  std::ifstream  infile;
  std::ofstream  outfile;

  if (is_input_wrong(argc, argv) == true)
    return 1;
  if (open_files(infile, outfile, argv[1]) == false)
    return 1;
  replace(infile, outfile, argv[2], argv[3]);
  infile.close();
  outfile.close();
  return 0;
}
