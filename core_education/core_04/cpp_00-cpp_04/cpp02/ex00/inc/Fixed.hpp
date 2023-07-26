#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

  public:

    Fixed();
    Fixed(Fixed const & src);
    ~Fixed();

    Fixed &   operator=(Fixed const & other);
    int       getRawBits(void) const;
    void      setRawBits(int const raw);

  private:
  static const int  kNFractionalBits = 8;
  int               raw_bits;
};

#endif /* *********************************************************** FIXED_H */