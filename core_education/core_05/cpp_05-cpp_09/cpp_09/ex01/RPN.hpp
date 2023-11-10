#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <algorithm>
# include <stack>
# include <exception>
# include <cctype>
# include <cmath>

const double EPSILON = 1e-9;

bool isValidInput(char const * expr);
bool calculate(char const * expr, double &answer);

#endif