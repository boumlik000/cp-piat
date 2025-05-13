#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
# include <cmath>

class Fixed
{
private:
    int nbr;
    static const int fract;
public:
    Fixed();
    Fixed(const Fixed& obj);
    
    Fixed(const int intnb);
    Fixed(const float floatnb);
    Fixed&  operator=(const Fixed& copy);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;
    ~Fixed();
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );


#endif // !FIXED_HPP