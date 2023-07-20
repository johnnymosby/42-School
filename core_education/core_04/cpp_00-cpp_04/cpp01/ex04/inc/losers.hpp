#ifndef LOSERS_HPP
# define LOSERS_HPP

# include <iostream>
# include <string>
# include <fstream>

bool  is_input_wrong(int argc, char *argv[]);
bool  open_files(std::ifstream &infile, std::ofstream &outfile, char const *filename);
bool  replace(std::ifstream &infile, std::ofstream &outfile, char const *str1, char const *str2);

#endif