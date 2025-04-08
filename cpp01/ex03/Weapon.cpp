#include "Weapon.hpp"


const std::string& Weapon::get_type() const 
{ 
    return type;
}

void Weapon::setType(std::string t)
{
    type = t;
}