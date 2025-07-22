#ifndef BASE_HPP
#define BASE_HPP


#include <iostream>
#include <ctime>
#include <typeinfo>
#include <exception>
#include <cstdlib>

class Base
{

    public:
        Base(/* args */);
        Base(const Base& obj);
        Base& operator=(const Base& obj);
        virtual ~Base();
};
    
class A : public Base {};
class B : public Base {};
class C : public Base {};
    
Base * generate(void);
void identify(Base* p);
void identify(Base& p);



#endif // !BASE_HPP