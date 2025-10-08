#ifndef SWAP_HPP
#define SWAP_HPP

#include <iostream>


template<typename t>
void Swap(t& a, t& b)
{
    t c;
    c = a;
    a = b;
    b = c;
}

template<typename t>
t& min(t& a,t& b)
{
    if(a > b)
        return b;
    else
        return a;
}

template<typename t>
t& max(t& a,t& b)
{
    if(a > b)
        return a;
    else
        return b;
}



#endif