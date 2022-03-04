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
	
	bool operator< (Fixed const &fixed);
	bool operator> (Fixed const &fixed);
	bool operator<= (Fixed const &fixed);
	bool operator>= (Fixed const &fixed);
	bool operator== (Fixed const &fixed);
	bool operator!= (Fixed const &fixed);
	
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int l);
	Fixed operator--(int l);
	
	Fixed operator+(Fixed const &fixed);
	Fixed operator-(Fixed const &fixed);
	Fixed operator*(Fixed const &fixed);
	Fixed operator/(Fixed const &fixed);
	
	static const Fixed	&min(Fixed const &a, Fixed const &b);
	static const Fixed	&max(Fixed const &a, Fixed const &b);
	Fixed	&min(Fixed &a, Fixed &b);
	Fixed	&max(Fixed &a, Fixed &b);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<< (std::ostream &os, Fixed const &fixed);

# endif
