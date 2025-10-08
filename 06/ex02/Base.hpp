#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{

    public:
        virtual ~Base();
};

Base::~Base()
{
    std::cout << "DeConstructor Base" <<std::endl;
}

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if(dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if(dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    std::cout << "??" << std::endl;
}
void identify(Base& p)
{
    
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A with reference" << std::endl;
    }
    catch(const std::exception& e)
    { 
        try
        {
            dynamic_cast<B&>(p);
            std::cout << "B with reference" << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                dynamic_cast<C&>(p);
                std::cout << "C with reference" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "undefined" << std::endl;
            }
        }

    }

    
}





#endif