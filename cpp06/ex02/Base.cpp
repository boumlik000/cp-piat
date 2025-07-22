#include "Base.hpp"

Base::Base(/* args */)
{
    std::cout << "Default Constructor Base" <<std::endl; 
}
Base::Base(const Base& obj)
{
    (void)obj;
    std::cout << "copy constructor  Base" <<std::endl; 
}
Base& Base::operator=(const Base& obj)
{   
    (void)obj;
    std::cout << "operator  Base" <<std::endl; 
    return *this;
}

// Function that randomly instantiates A, B, or C and returns as Base pointer
Base* generate(void) {
    // Seed random number generator (you might want to do this once in main)
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0)); // Use 0 instead of nullptr
        seeded = true;
    }
    
    int random = std::rand() % 3; // 0, 1, or 2
    
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
        default:
            return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    (void)(p);
    try {
        dynamic_cast<A&>(p);
        std::cout << "Identified dial reference type " << "A" << std::endl;
    }
    catch (std::exception& e) {
    }
    try {
        dynamic_cast<B&>(p);
        std::cout << "Identified dial reference type " << "B" << std::endl;
    }
    catch (std::exception& e) {
    }
    try {
        dynamic_cast<C&>(p);
        std::cout << "Identified dial reference type " << "C" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Type unidentified!" << std::endl;
    }
}

Base::~Base()
{
    std::cout << "DeConstructor Base" <<std::endl; 
}