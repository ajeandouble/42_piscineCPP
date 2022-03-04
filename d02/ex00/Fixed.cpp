#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fp_value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	fp_value = fixed.fp_value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	fp_value = fixed.fp_value;
	return *this;
}

Fixed&	Fixed::operator<< (const Fixed &fixed)
{
	
}

int Fixed:: getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_value);
}

void    Fixed::setRawBits( int const raw )
{
	this->fp_value = raw;
}
