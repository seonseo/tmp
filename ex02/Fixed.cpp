#include "Fixed.hpp"

Fixed::Fixed()
	: fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
	: fixedPointValue(other.fixedPointValue)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignation operator called" << std::endl;
	if (this != &other)
		fixedPointValue = other.fixedPointValue;
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	// std::cout << "Int constructor called" << std::endl;
	fixedPointValue = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	// std::cout << "Float constructor called" << std::endl;
	fixedPointValue = roundf(floatValue * (1 << fractionalBits));
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (fixedPointValue / (float)(1 << fractionalBits));
}

int		Fixed::toInt(void) const
{
	// if (fixedPointValue >= 0)
    //     return ((fixedPointValue + (1 << (fractionalBits - 1))) >> fractionalBits);
    // else
    //     return ((fixedPointValue - (1 << (fractionalBits - 1))) >> fractionalBits);
	return roundf(fixedPointValue / (float)(1 << fractionalBits));
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.fixedPointValue < b.fixedPointValue)
		return b;
	else
		return a;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.fixedPointValue < b.fixedPointValue)
		return b;
	else
		return a;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.fixedPointValue < b.fixedPointValue)
		return b;
	else
		return a;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.fixedPointValue < b.fixedPointValue)
		return b;
	else
		return a;
}
