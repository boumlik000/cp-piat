#include <iostream>
#include <string>
#include <iomanip>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    // Setters
    void setFirstName(std::string str) { firstName = str; }
    void setLastName(std::string str) { lastName = str; }
    void setNickname(std::string str) { nickname = str; }
    void setPhoneNumber(std::string str) { phoneNumber = str; }
    void setDarkestSecret(std::string str) { darkestSecret = str; }

    // Getters
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDarkestSecret() const { return darkestSecret; }
};

class PhoneBook 
{
    private:
        Contact contacts[8];  // Array of maximum 8 contacts
        int count;           // Number of contacts currently stored
        int oldest;          // Index of the oldest contact

    public:
        PhoneBook() : count(0), oldest(0) {}  // Constructor

    void addContact() 
    {
        std::string input;
        
        Contact newContact;
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
        newContact.setFirstName(input);
        
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
        newContact.setLastName(input);
        
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, input);
        newContact.setNickname(input);
        
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, input);
        newContact.setPhoneNumber(input);
        
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
        newContact.setDarkestSecret(input);

        // Add contact to array (replacing oldest if necessary)
        if (count < 8)
            contacts[count++] = newContact;
        else {
            contacts[oldest] = newContact;
            oldest = (oldest + 1) % 8;
        }
    }

    void searchContact() {
        if (count == 0) {
            std::cout << "Phonebook is empty!" << std::endl;
            return;
        }

        // Display contact list
        std::cout << "|     Index|First Name| Last Name| Nickname |" << std::endl;
        std::cout << "|----------|----------|----------|----------|" << std::endl;
        
        for (int i = 0; i < count; i++)
        {
            std::cout << "|" << std::setw(10) << i << "|";
            
            if (contacts[i].getFirstName().length() > 10) {
                std::cout << std::setw(10) << contacts[i].getFirstName().substr(0, 9) + ".";
            } else {
                std::cout << std::setw(10) << contacts[i].getFirstName();
            }
            
            std::cout << "|";
            
            if (contacts[i].getLastName().length() > 10) {
                std::cout << std::setw(10) << contacts[i].getLastName().substr(0, 9) + ".";
            } else {
                std::cout << std::setw(10) << contacts[i].getLastName();
            }
            
            std::cout << "|";
            
            if (contacts[i].getNickname().length() > 10) {
                std::cout << std::setw(10) << contacts[i].getNickname().substr(0, 9) + ".";
            } else {
                std::cout << std::setw(10) << contacts[i].getNickname();
            }
            std::cout << "|" << std::endl;
        }

        // Search by index
        int index;
        std::cout << "\nEnter index to view details: ";
        std::cin >> index;
        std::cin.ignore();  // Clear newline from input buffer

        if (index >= 0 && index < count) {
            std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
            std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
            std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
        } else {
            std::cout << "Invalid index!" << std::endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            exit(0);
        else
            std::cout << "Invalid command!" << std::endl;
    }

    return 0;
}

