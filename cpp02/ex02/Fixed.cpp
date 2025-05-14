#include "Fixed.hpp"


const int Fixed::fract = 8;

Fixed::Fixed(): nbr(0)
{
}
Fixed::Fixed(const Fixed& obj)
{
    *this = obj;
}

int Fixed::getRawBits( void ) const
{
    return this->nbr;
}

void Fixed::setRawBits( int const raw )
{
    this->nbr = raw;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    if (this != &copy)
    {
        this->nbr = copy.getRawBits();
    }
    return *this;
}

bool Fixed::operator>(const Fixed& copy)
{
    if (this->nbr > copy.nbr)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& copy)
{
    
    if (this->nbr < copy.nbr)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed& copy)
{
    if (this->nbr >= copy.nbr)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& copy)
{
    
    if (this->nbr <= copy.nbr)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed& copy)
{
    
    if (this->nbr == copy.nbr)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& copy)
{
    
    if (this->nbr != copy.nbr)
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed& copy)
{
    Fixed obj;
    obj.nbr = nbr + copy.nbr;
    return obj;
}

Fixed Fixed::operator-(const Fixed& copy)
{
    Fixed obj;
    obj.nbr = nbr - copy.nbr;
    return obj;
}

Fixed Fixed::operator*(const Fixed& copy)
{
    Fixed obj;
    obj.nbr = (nbr * copy.nbr)/256;
    return obj;
}

Fixed Fixed::operator/(const Fixed& copy)
{
    Fixed obj;
    obj.nbr = (nbr / copy.nbr) * 256;
    return obj;
}

Fixed& Fixed::operator++()//++i
{
    nbr = nbr + 1;
    return *this;
}

Fixed Fixed::operator++(int)//i++
{
    Fixed obj = *this;
    // nbr += 1;
    this->nbr = this->nbr + 1;
    return obj;
}

Fixed Fixed::operator--(int)//i--
{
    Fixed obj = *this;
    this->nbr = this->nbr - 1;
    return obj;
}

Fixed& Fixed::operator--()//--i
{
    nbr = nbr - 1;
    return *this;
}

Fixed& Fixed::min(Fixed& a,Fixed& b)
{
    if(a.nbr < b.nbr)
        return a;
    return b; 
}
Fixed& Fixed::max(Fixed& a,Fixed& b)
{
    if(a.nbr > b.nbr)
        return a;
    return b; 
}

const Fixed& Fixed::min(const Fixed& a,const Fixed& b)
{
    if(a.nbr < b.nbr)
        return a;
    return b; 
}
const Fixed& Fixed::max(const Fixed& a,const Fixed& b)
{
    if(a.nbr > b.nbr)
        return a;
    return b; 
}


Fixed::~Fixed()
{
}

Fixed::Fixed(const int intnb)
{
    this->nbr = intnb * (1 << this->fract);
}
Fixed::Fixed(const float floatnb)
{
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