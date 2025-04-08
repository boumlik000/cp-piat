#include "Zombie.hpp"

int main() {
    Zombie *z = newZombie("Ali");
    z->announce();
    delete z;

    randomChump("houda");

    return 0;
}