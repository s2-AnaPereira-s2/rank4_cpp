#include "Fixed.hpp"


Fixed::Fixed() : _value(0){}

Fixed::Fixed(const int n)
{
    this->_value = n << _bits;
}

Fixed::Fixed(const float f)
{
    _value = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_value = other._value;
    return *this;
}

Fixed::~Fixed(){}

int Fixed::getRawBits() const
{
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)_value / (1 << _bits);
}

int Fixed::toInt(void) const
{
    return _value / (1 << _bits);
}

bool Fixed::operator>(const Fixed& other) const
{
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _value++;
    return temp;
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _value--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min (const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max (const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();  // Convert Fixed to float and print it
    return os;              // Return stream for chaining
}