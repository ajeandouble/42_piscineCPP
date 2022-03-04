# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	static const int fractional_bits = 8;
	int	fp_value;
public:
	Fixed();
	Fixed(const int &fixed);
	Fixed(const float &fixed);
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed& operator= (const Fixed &fixed);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<< (std::ostream &os, Fixed const &fixed);

# endif
