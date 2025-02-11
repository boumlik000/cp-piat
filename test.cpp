#include <iostream> 
#include <iomanip>

class contact
{
    int index_i = 0;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone;
    std::string darksecret;

    public:
        void Set_firstname(std::string fn){first_name = fn;}
        void Set_lastname(std::string ln){last_name = ln;}
        void Set_nickname(std::string nm){nickname = nm;}
        void Set_phone(std::string ph){phone = ph;}
        void Set_darksecret(std::string ds){darksecret = ds;}

        std::string get_firstname(){return first_name;}
        std::string get_lastname(){return last_name;}
        std::string get_nickname(){return nickname;}
        std::string get_phone(){return phone;}
        std::string get_darksecret(){return darksecret;}

};

class phonebook
{
    contact contacts[8];
    public:
        contact new_contact;
        int index = 0;
        int current = 0;
        std::string input;
        std::string input0;
        void add_contact()
        {
            std::cin.ignore();
            std::cout << "firstname : ";
            std::getline(std::cin , input);            
            new_contact.Set_firstname(input);

            std::cout << "lastname : ";
            std::getline(std::cin , input0);            
            new_contact.Set_lastname(input0);

            std::cout << "nickname : ";
            std::getline(std::cin , input);            
            new_contact.Set_nickname(input);

            std::cout << "phone : ";
            std::getline(std::cin , input);            
            new_contact.Set_phone(input);

            std::cout << "darsecrete : ";
            std::getline(std::cin , input);            
            new_contact.Set_darksecret(input);

            //dik current kan trakiw bit kolla contact but index kankhlliwha untill katosl 8
                //wkathbs hit list khssha tb9a t updata ms matfotch 8 in the same time
            contacts[current] = new_contact;
            current = (current +1 ) % 8;
            if (index < 8)
                index++;
            
        }

        void display_contacts(phonebook ph)
        {
            int i = 0;
            int num ;
            if (index == 0)
            {
                std::cout << "empty list \n" ;
                return;
            }
            
            std::cout << " index | first_name | last_name | nickname\n";
            std::cout << " ------|------------|-----------|---------\n";
            while (i < index)
            {
                std::cout << std::setw(10) <<  i << "|"
                << std::setw(10) << contacts[i].get_firstname() << "|" 
                << std::setw(10) << contacts[i].get_lastname() << "|" 
                <<   std::setw(10) << contacts[i].get_nickname() << "\n" ;
                i++;
            }
            std::cout << "index : " ;
            std::cin >>  num ;
            if (num < index)
            {
                std::cout << "first name : " <<  contacts[num].get_firstname() << "\n";
                std::cout << "last name : " <<  contacts[num].get_lastname() << "\n";
                std::cout << "nickname : " <<  contacts[num].get_nickname() << "\n";
                std::cout << "phone name : " <<  contacts[num].get_phone() << "\n";
                std::cout << "dark secrete : " <<  contacts[num].get_darksecret() << "\n";
            }
        }   

};




int main()
{
    phonebook phonebookus;
    std :: string choice;
    while (1)
    {
        std::cout << "THE PHONEBOOK : \n-----------------\n ADD or SEARCH or EXIT : " ;
        std::cin >> choice ; 
        if (std::cin.eof())
            return 0;
        
        if (choice == "ADD")
            phonebookus.add_contact();        
        if (choice == "SEARCH")
            phonebookus.display_contacts(phonebookus);
        if (choice == "exit")
        {
            std::cout << "exit" << std::endl;
            exit(0);
        }
        std::cout << std::endl;
        /* code */
    }
    
    
    
    return 0;
}
