#include "Harl.hpp"

void Harl::complain( std::string level )
{
    typedef void (Harl::*MemberFunc)(void);

    MemberFunc levels[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels_str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) {
        if (level == levels_str[i]) {
            (this->*levels[i])();  // Proper way to call member function pointer
            return;
        }
    }
    std::cout << "Invalid level" << std::endl;
}