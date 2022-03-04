# ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed& operator= (const Fixed &fixed);
	static const int fractional_bits = 8;
	int	fp_value;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

# endif
