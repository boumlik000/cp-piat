#include "iter.hpp"


int main()
{
    
    std::string arr[] = {"ana","howa","hia"};
    int arr2[] = {6,1,2};
    ::Iter(arr,arr->length(),print);
    ::Iter(arr,arr->length(),print_ee);
    ::Iter(arr2,(sizeof(arr2) / sizeof(arr2[0])),doubleElement);

    return 0;
}
