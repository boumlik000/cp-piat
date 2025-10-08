#include "easyfind.hpp"

int main()
{

    int arr[] = {2,4,77,89,0,23};
    std::vector<int> vec( arr ,arr + (sizeof(arr) / sizeof(arr[0]))) ;
    // vec.push_back(10);     
    // vec.push_back(8);     
    // vec.push_back(0);     
    // vec.push_back(9);  
    try
    {
        easyfind(vec,0);
        easyfind(vec,4);
        easyfind(vec,8);
        easyfind(vec,23);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
       
    return 0;
}
