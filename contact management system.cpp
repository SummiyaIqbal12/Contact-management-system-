#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;

public:
    Contact(string name, string phoneNumber) {
        this->name = name;
        this->phoneNumber = phoneNumber;
    }

    string getName() {
        return name;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }
};

void displayMenu() {
    cout << "Contact Management System" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. View Contacts" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void addContact(vector<Contact>& contacts) {
    string name, phoneNumber;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone number: ";
    cin >> phoneNumber;

    Contact newContact(name, phoneNumber);
    contacts.push_back(newContact);

    cout << "Contact added successfully!" << endl;
}

void viewContacts(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts found." << endl;
    } else {
        cout << "List of Contacts:" << endl;
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << i + 1 << ". Name: " << contacts[i].getName() 
                 << ", Phone Number: " << contacts[i].getPhoneNumber() << endl;
        }
    }
}

void deleteContact(vector<Contact>& contacts) {
    int index;
    viewContacts(contacts);
    if (!contacts.empty()) {
        cout << "Enter the contact number to delete: ";
        cin >> index;

        if (index > 0 && index <= contacts.size()) {
            contacts.erase(contacts.begin() + index - 1);
            cout << "Contact deleted successfully!" << endl;
        } else {
            cout << "Invalid contact number!" << endl;
        }
    }
}

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addContact(contacts);
            break;
        case 2:
            viewContacts(contacts);
            break;
        case 3:
            deleteContact(contacts);
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}