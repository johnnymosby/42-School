#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

  public:
    Fixed();
    Fixed(const int val);
    Fixed(const float val);
    Fixed(Fixed const & src);
    ~Fixed();

    Fixed &       operator=(Fixed const & rhs);
    int           getRawBits(void) const;
    void          setRawBits(int const raw);

    float         toFloat(void) const;
    int           toInt(void) const;

  private:
    static const int  kNFractionalBits = 8;
    int               raw_bits;
};

std::ostream &operator<<(std::ostream &os, const Fixed & rhs);

#endif /* *********************************************************** FIXED_H */