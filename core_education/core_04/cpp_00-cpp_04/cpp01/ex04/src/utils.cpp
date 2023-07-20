#include "../inc/losers.hpp"

bool  is_input_wrong(int argc, char *argv[])
{
  if (argc != 4) {
    std::cout << "Wrong input [filename str1 str2]\n";
    return true;
  }
  if (argv[2][0] == '\0') {
    std::cout << "Wrong input: str1 must be not empty\n";
    return true;
  }
  if (argv[3][0] == '\0') {
    std::cout << "Wrong input: str2 must be not empty\n";
    return true;
  }
  return false;
}

bool  open_files(std::ifstream &infile, std::ofstream &outfile, char const *filename) {
  std::string filename_string = filename;
  filename_string.append(".replace");

  try {
    infile.open(filename);
    outfile.open(filename_string.c_str());
  } catch (const std::ios_base::failure& fail) {
    std::cout << fail.what() << '\n';
    return false;
  }
  return true;
}

bool  replace(std::ifstream &infile, std::ofstream &outfile, char const *str1, char const *str2) {
  std::string line;
  size_t word_position;
  std::string string1 = str1;
  int str1_length = string1.length();
  while (!infile.eof()) {
    word_position = 0;
    std::getline(infile, line);
    word_position = line.find(str1);
    while (word_position != std::string::npos)
    {
      outfile << line.substr(0, word_position) << str2;
      line = line.substr(word_position + str1_length);
      word_position = line.find(str1);
    }
    outfile << line << '\n';
  }
  return true;
}
