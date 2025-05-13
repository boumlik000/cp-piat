#include "Fixed.hpp"


const int Fixed::fract = 8;

Fixed::Fixed(): nbr(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->nbr;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->nbr = raw;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->nbr = copy.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intnb)
{
    std::cout << "Int constructor called" << std::endl;
    this->nbr = intnb * (1 << this->fract);
}
Fixed::Fixed(const float floatnb)
{
    std::cout << "Float constructor called" << std::endl;
    this->nbr = roundf(floatnb * (1 << this->fract));

}
float Fixed::toFloat(void) const
{
    return (float)this->nbr / (1 << this->fract);
}

int Fixed::toInt(void) const
{
    return this->nbr / (1 << this->fract);
}

std::ostream& operator<< ( std::ostream& os, const Fixed& fixed ) {
    os << fixed.toFloat();
    return os;
}