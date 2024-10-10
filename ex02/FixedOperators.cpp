#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool	Fixed::operator>(const Fixed& other)
{
	if (fixedPointValue > other.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator<(const Fixed& other)
{
	if (fixedPointValue < other.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator>=(const Fixed& other)
{
	if (fixedPointValue >= other.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator<=(const Fixed& other)
{
	if (fixedPointValue <= other.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator==(const Fixed& other)
{
	if (fixedPointValue == other.fixedPointValue)
		return true;
	else
		return false;
}

bool	Fixed::operator!=(const Fixed& other)
{
	if (fixedPointValue != other.fixedPointValue)
		return true;
	else
		return false;
}


Fixed	Fixed::operator+(const Fixed& other)
{
	return (fixedPointValue + other.fixedPointValue);
}

Fixed	Fixed::operator-(const Fixed& other)
{
	return (fixedPointValue - other.fixedPointValue);
}

Fixed	Fixed::operator*(const Fixed& other)
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed& other)
{
	return Fixed(toFloat() / other.toFloat());
}


Fixed&	Fixed::operator++()
{
	fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	previousValue(*this);
	this->fixedPointValue++;
	return (previousValue);
}

Fixed&	Fixed::operator--()
{
	fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	previousValue(*this);
	this->fixedPointValue--;
	return (previousValue);
}


