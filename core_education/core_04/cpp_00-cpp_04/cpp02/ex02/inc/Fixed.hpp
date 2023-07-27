#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

# define TO_PRINT true

class Fixed
{

  public:
    Fixed();
    Fixed(const int val);
    Fixed(const float val);
    Fixed(Fixed const & src);
    ~Fixed();

    Fixed &       operator=(Fixed const & other);
    bool          operator>(Fixed const & other) const;
    bool          operator<(Fixed const & other) const;
    bool          operator>=(Fixed const & other) const;
    bool          operator<=(Fixed const & other) const;
    bool          operator==(Fixed const & other) const;
    bool          operator!=(Fixed const & other) const;
    Fixed         operator+(Fixed const & other) const;
    Fixed         operator-(Fixed const & other) const;
    Fixed         operator*(Fixed const & other) const;
    Fixed         operator/(Fixed const & other) const;
    Fixed &       operator++();
    Fixed         operator++(int);
    Fixed &       operator--();
    Fixed         operator--(int);
    int           getRawBits(void) const;
    void          setRawBits(int const raw);

    float         toFloat(void) const;
    int           toInt(void) const;

    static Fixed const &max(const Fixed & a, const Fixed & b);
    static Fixed const &min(const Fixed & a, const Fixed & b);
    static Fixed &max(Fixed & a, Fixed & b);
    static Fixed &min(Fixed & a, Fixed & b);

  private:
    static const int  kNFractionalBits = 8;
    int               raw_bits;
};

std::ostream &operator<<(std::ostream &os, const Fixed & other);

#endif /* *********************************************************** FIXED_H */