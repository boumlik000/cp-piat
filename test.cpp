#include <iostream> 
#include <iomanip>
#include <string>
class contact
{
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

        int check_input(std::string input)
        {
            int i = 0;
            if (input.empty()) {
                std::cout << "empty!!" << std::endl;
                return 0;
            }
            while (input[i]) {
                if (!std::isprint(input[i])) {  // Now checking input[i] directly
                    std::cout << "not printable" << std::endl;
                    return 0;
                }
                i++;
            } 
            return 1;
        }

        void check_index(std::string num)
        {
            int i = 0;
            char c;
            while (num[i])
            {
                if (num.length() > 10) {  // Max int length is typically 10 digits
                    std::cout << "invalid index" << std::endl;
                    return;
                }
                if (!std::isdigit(num[i])) {
                    std::cout << "invalid index[search]" << std::endl;
                    return;
                }
                i++;
            }
            int n = stoi(num);
            i=0;
            if (n >= 0 && n < 8)
            {
                while (i <= n)
                {
                    if(i == n)
                    {
                        if (contacts[n].get_firstname().empty()) // Check if the entry is empty
                        {
                            std::cout << "Index is out of range: No contact stored at this index!" << std::endl;
                            return;
                        }
                        std::cout << "first name : " <<  contacts[n].get_firstname() << "\n";
                        std::cout << "last name : " <<  contacts[n].get_lastname() << "\n";
                        std::cout << "nickname : " <<  contacts[n].get_nickname() << "\n";
                        std::cout << "phone name : " <<  contacts[n].get_phone() << "\n";
                        std::cout << "dark secrete : " <<  contacts[n].get_darksecret() << "\n";
                    }
                    i++;
                }
            }
            else
            {
                std::cout << "invalid index[search00]" << std::endl;
                    return;
            }
        }

        void add_contact()
        {
            // std::cin.ignore();


            std::cout << "firstname : ";
            std::getline(std::cin, input);
            if (check_input(input) == 0)
                return;
            new_contact.Set_firstname(input);

            std::cout << "lastname : ";
            std::getline(std::cin , input);
            if (check_input(input) == 0)
                return;
            new_contact.Set_lastname(input);

            std::cout << "nickname : ";
            std::getline(std::cin , input);
            if (check_input(input) == 0)
                return;          
            new_contact.Set_nickname(input);

            std::cout << "phone : ";
            std::getline(std::cin , input);
            if (check_input(input) == 0)
                return;          
            new_contact.Set_phone(input);

            std::cout << "darsecrete : ";
            std::getline(std::cin , input);
            if (check_input(input) == 0)
                return;           
            new_contact.Set_darksecret(input);

            //dik current kan trakiw bih kolla contact but index kankhlliwha untill katosl 8
                //wkathbs hit list khssha tb9a t updata ms matfotch 8 in the same time
            contacts[current] = new_contact;
            current = (current +1 ) % 8;
            if (index < 8)
                index++;
            
        }

        void display_contacts(phonebook ph)
        {
            int i = 0;
            if (index == 0)
            {
                std::cout << "empty list \n" ;
                return;
            }
            
            std::cout << "|     Index|First Name| Last Name| Nickname |" << std::endl;
            std::cout << "|----------|----------|----------|----------|" << std::endl;
            while (i < index)
            {
               std::cout << "|" << std::setw(10) << i << "|";
            
                if (contacts[i].get_firstname().length() > 10)
                    std::cout << std::setw(10) << contacts[i].get_firstname().substr(0, 9) + ".";
                else
                    std::cout << std::setw(10) << contacts[i].get_firstname();
                
                std::cout << "|";
                
                if (contacts[i].get_lastname().length() > 10) 
                    std::cout << std::setw(10) << contacts[i].get_lastname().substr(0, 9) + ".";
                else 
                    std::cout << std::setw(10) << contacts[i].get_lastname();
                
                std::cout << "|";
                
                if (contacts[i].get_nickname().length() > 10) 
                    std::cout << std::setw(10) << contacts[i].get_nickname().substr(0, 9) + ".";
                else 
                    std::cout << std::setw(10) << contacts[i].get_nickname();
            
                std::cout << "|" << std::endl;
                i++;
            }
            std::cout << "\nindex : " ;

            std::string num;            
            std::getline(std::cin , num);

            if (check_input(num) == 0)
                return;
            check_index(num);
            
        }   
};




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
            phonebookus.display_contacts(phonebookus);
        else if (choice == "EXIT")
        {
            std::cout << "exit" << std::endl;
            exit(0);
        }
        else
            std::cout << "Invalid command!" << std::endl;
        /* code */
    }
    
    
    
    return 0;
}
