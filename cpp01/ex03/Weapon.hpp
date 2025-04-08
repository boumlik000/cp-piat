#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    std::string type;
    public:
        Weapon(std::string clubname) : type(clubname) {}

        const std::string& get_type() const ;
        void setType(std::string t) ;
};

#endif // !Weapon