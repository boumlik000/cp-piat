#include "Base.hpp"

// Test program
int main() {
    Base* b_ptr = generate();
    std::cout <<std::endl;
    identify(b_ptr);
    std::cout <<std::endl;
    identify(*b_ptr);
    std::cout <<std::endl;
    identify(NULL);
    std::cout <<std::endl;

    delete b_ptr;
    
    
    return 0;
}