#include "Serializer.hpp"


int main()
{
    Data  my_data;
    my_data.a = 2;
    my_data.s ="me";
    Data* original_D2 ;

    uintptr_t i =  Serializer::serialize(&my_data);
    original_D2 =  Serializer::deserialize(i);

    std::cout <<"Data : " << &my_data <<std::endl; 
    std::cout <<"uintptr : " << i << std::endl;
    std::cout <<"Data : " << original_D2 <<std::endl;
    
    std::cout << original_D2->a << std::endl;
    std::cout << original_D2->s << std::endl;

    if (&my_data == original_D2)
    {
        std::cout << "reiterpret Success ,they match :) " << std::endl;
    }else
        std::cout << "reiterpret failure ,they dont match :) " << std::endl;


    return 0;
}
