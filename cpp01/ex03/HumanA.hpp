#ifndef HUMANA_CPP
#define HUMANA_CPP

// #include <iostream>
#include "Weapon.hpp"


class HumanA
{

    std::string name;
    Weapon& weapon ;
    
    public:

        HumanA(std::string nameh, Weapon& weaponh);
        void attack();
};



#endif 