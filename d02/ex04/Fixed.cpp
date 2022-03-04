#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->fp_value = 0;
}

Fixed::Fixed(const int &value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fp_value = value << this->fractional_bits;
}


Fixed::Fixed(const float &value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fp_value = roundf(value * pow(2, (this->fractional_bits)));
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	fp_value = fixed.fp_value;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator= (const Fixed &fixed)
{
	// std::cout << "Assignation operator called" << std::endl;
	fp_value = fixed.fp_value;
	return *this;
}

int Fixed:: getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
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


bool Fixed::operator< (Fixed const &fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator> (Fixed const &fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<= (Fixed const &fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator>= (Fixed const &fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator== (Fixed const &fixed)
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!= (Fixed const &fixed)
{
	return (this->toFloat() != fixed.toFloat());
}
Fixed  Fixed::operator++(int l) // value++
{
	(void)l;
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed  Fixed::operator--( int l) // value--
{
	(void)l;
	Fixed temp = *this;
	--(*this);
	return temp;
}

Fixed &Fixed::operator++(void)	// ++value
{
	this->fp_value++;
	return *this;
}

Fixed &Fixed::operator--(void) // --value
{
	this->fp_value--;
	return *this;
}

Fixed  Fixed::operator+(Fixed const &fixed)
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed  Fixed::operator/(Fixed const &fixed)
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed  Fixed::operator*(Fixed const &fixed)
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed  Fixed::operator-(Fixed const &fixed)
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	&min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a.toFloat() < b.toFloat() ? a : b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a.toFloat() > b.toFloat() ? a : b);
}
