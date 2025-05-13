#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int nbr;
    static const int fract;
public:
    Fixed();
    Fixed(const Fixed& obj);
    Fixed&  operator=(const Fixed& copy);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    ~Fixed();
};



#endif // !FIXED_HPP