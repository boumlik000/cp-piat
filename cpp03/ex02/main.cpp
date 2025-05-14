#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    
    ClapTrap p1("hassan");
    FragTrap p2("boumlik");
    ScavTrap p3("zzaki");
    
    p2.Attack("boumlik");
    p3.Attack("hassan");
    p2.BeRepaired(2);
    p2.TakeDamage(15);
    p3.TakeDamage(15);
    p2.highFivesGuys();
    p2.BeRepaired(2);
    p3.guardGate();
    return 0;
}
