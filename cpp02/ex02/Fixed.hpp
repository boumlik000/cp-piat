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

    bool operator>(const Fixed& copy);
    bool operator<(const Fixed& copy);
    bool operator>=(const Fixed& copy); 
    bool operator<=(const Fixed& copy);
    bool operator==(const Fixed& copy);
    bool operator!=(const Fixed& copy);



    Fixed operator+(const Fixed& copy);
    Fixed operator-(const Fixed& copy);
    Fixed operator*(const Fixed& copy);
    Fixed operator/(const Fixed& copy);

    Fixed operator++(int);
    Fixed& operator++();
    Fixed operator--(int);
    Fixed& operator--();

    static Fixed& max(Fixed& a,Fixed& b);
    static Fixed& min(Fixed& a,Fixed& b);

    static const Fixed& min(const Fixed& a,const Fixed& b);
    static const Fixed& max(const Fixed& a,const Fixed& b);


    float toFloat( void ) const;
    int toInt( void ) const;


    ~Fixed();
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );


#endif // !FIXED_HPP