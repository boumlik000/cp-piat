#ifndef ROBOTOMYREAUESTFORM
#define ROBOTOMYREAUESTFORM

#include "form.hpp"

class Robotomyreauestform
{
private:
    /* data */
public:
    Robotomyreauestform(/* args */);
    Robotomyreauestform(const Robotomyreauestform& obj);
    Robotomyreauestform& operator=(const Robotomyreauestform& obj);
    ~Robotomyreauestform();
};

Robotomyreauestform::Robotomyreauestform(/* args */)
{
    std::cout << "Robotomyreauestform default parameter";
}

Robotomyreauestform& Robotomyreauestform::operator=(const Robotomyreauestform& obj)
{
    std::cout << "Robotomyreauestform operator parameter";
    
}

Robotomyreauestform::Robotomyreauestform(const Robotomyreauestform& obj)
{
    std::cout << "Robotomyreauestform copy constructor parameter";
    
}

Robotomyreauestform::~Robotomyreauestform()
{
    std::cout << "Robotomyreauestform deconstructor parameter";
}


#endif // !PRESIDENTIALPARDONFORM
