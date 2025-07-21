#include <iostream>
#include <cstring>

// #include <iostream>

class Base {
public:
    virtual ~Base() {}
    int a = 0;
    char c = 'z';
};

class Der : public Base {
public:
    int b = 5;
};

class oth : public Base {
public:
    int z = 5;
};

int main() {
    Base *a = new Der();
    Base *b = new oth();
    Der *newa = dynamic_cast<Der*>(a);
    oth *z = dynamic_cast<oth *>(b);
}
    