#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fp_value = 0;
}

Fixed::Fixed(const int &value)
{
	this->fp_value = value << this->fractional_bits;
	std::cout << "Int constructor called" << std::endl;
}


Fixed::Fixed(const float &value)
{
	this->fp_value = roundf(value * pow(2, (this->fractional_bits)));
	std::cout << "Float constructor called" << std::endl;
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

int Fixed:: getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_value);
}

void    Fixed::setRawBits(int const raw)
{
	this->fp_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->fp_value * pow(2, -(this->fractional_bits)));
}

int		Fixed::toInt( void ) const
{
	return (this->fp_value / pow(2, (this->fractional_bits)));
}


std::ostream& operator<< (std::ostream &os, Fixed const &fixed)
{
	float f = fixed.toFloat();
	float i = fixed.toInt();
	if (f != i)
		os << f;
	else
		os << i;
	return os;
}
