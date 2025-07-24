#include "./Serializer.hpp"


int main()
{
    Data info={"mohamed","boumlik",23};

    uintptr_t uptr = Serializer::serialize(&info);
    std::cout << "After Serialization: " << std::hex << &info << std::endl;
    std::cout << "After Serialization: " << std::hex << "0x" << uptr << std::endl;

    std::cout << std::endl;

    Data* data_ptr = Serializer::deserialize(uptr);
    std::cout << "After Deserialization: " << data_ptr->age << std::endl;
    std::cout << "After Deserialization: " << data_ptr->name << std::endl;
    std::cout << "After Deserialization: " << data_ptr->lastname << std::endl;
    return 0;
}
