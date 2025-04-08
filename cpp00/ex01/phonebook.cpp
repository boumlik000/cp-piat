#include "h.hpp"

int main()
{
    phonebook phonebookus;
    std :: string choice;
    while (1)
    {
        std::cout << "THE PHONEBOOK : \n-----------------\n ADD or SEARCH or EXIT : " ;
        std::getline(std::cin , choice);

        
        if (choice == "ADD")
            phonebookus.add_contact();        
        else if (choice == "SEARCH")
            phonebookus.display_contacts();
        else if (choice == "EXIT")
        {
            std::cout << "exit" << std::endl;
            exit(0);
        }
        else
            std::cout << "Invalid command!" << std::endl;
    }
    
    
    
    return 0;
}
