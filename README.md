'CONTACT MANAGEMENT SYSTEM IN C++'

INTRODUCTION:

The Contact Management System is a simple yet effective console-based application developed in C++. It allows users to manage personal contacts by providing functionalities to add, view, and delete contact information. This project is intended for those learning C++ and aims to demonstrate fundamental concepts such as object-oriented programming, data handling using vectors, and user interaction via console input/output.

OBJECTIVE:

The primary objective of this project is to create a command-line application that efficiently manages a list of contacts. The system is designed to:
- Offer an intuitive menu-driven interface.
- Enable users to store, view, and manage their contacts effortlessly.
- Serve as an educational tool for understanding C++ programming basics, including classes, vectors, loops, and conditionals.

SCOPE:

This Contact Management System is a beginner-level project, focusing on fundamental contact management features such as adding, viewing, and deleting contacts. The project is not intended to be a full-fledged contact management system but rather a demonstration of how such a system could be built using basic C++ programming techniques.

SOURCE CODE AND WORKING:

Below is the complete source code for the Contact Management System, along with an explanation of how the system works.

Source Code:


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;

public:
    // Constructor to initialize a contact with a name and phone number
    Contact(string name, string phoneNumber) {
        this->name = name;
        this->phoneNumber = phoneNumber;
    }

    // Getter functions to retrieve contact details
    string getName() const {
        return name;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }
};

// Function to display the main menu
void displayMenu() {
    cout << "\n--- Contact Management System ---\n";
    cout << "1. Add Contact\n";
    cout << "2. View Contacts\n";
    cout << "3. Delete Contact\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a new contact
void addContact(vector<Contact>& contacts) {
    string name, phoneNumber;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone number: ";
    cin >> phoneNumber;

    Contact newContact(name, phoneNumber);
    contacts.push_back(newContact);

    cout << "Contact added successfully!\n";
}

// Function to view all contacts
void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts found.\n";
    } else {
        cout << "\n--- List of Contacts ---\n";
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << i + 1 << ". Name: " << contacts[i].getName() 
                 << ", Phone Number: " << contacts[i].getPhoneNumber() << endl;
        }
    }
}

// Function to delete a contact
void deleteContact(vector<Contact>& contacts) {
    int index;
    viewContacts(contacts);
    if (!contacts.empty()) {
        cout << "Enter the contact number to delete: ";
        cin >> index;

        if (index > 0 && index <= contacts.size()) {
            contacts.erase(contacts.begin() + index - 1);
            cout << "Contact deleted successfully!\n";
        } else {
            cout << "Invalid contact number!\n";
        }
    }
}

// Main function to run the Contact Management System
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
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


WORKING:

1. Program Initialization:
   - The program begins by declaring a `vector<Contact>` named `contacts` to store the contact information.
   - A `do-while` loop is used to keep the application running until the user decides to exit.

2. Displaying the Menu:
   - The `displayMenu` function shows a menu with options for adding, viewing, deleting contacts, or exiting the program.

3. Adding Contacts:
   - The `addContact` function collects the name and phone number from the user, creates a `Contact` object, and stores it in the `contacts` vector.
   - A confirmation message is displayed after successfully adding a contact.

4. Viewing Contacts:
   - The `viewContacts` function displays the list of all stored contacts.
   - If no contacts are found, it informs the user. Otherwise, it displays each contact's name and phone number.

5. Deleting Contacts:
   - The `deleteContact` function first displays the contacts using `viewContacts`.
   - It then prompts the user to enter the contact's index number to delete.
   - The contact is deleted from the `contacts` vector if the input is valid.

6. Exiting the Program:
   - The program exits when the user selects the "Exit" option from the menu.

This system effectively demonstrates how to build a simple Contact Management System using C++, providing a strong foundation for understanding basic programming concepts.

CONCLUSION:

This Contact Management System is a valuable project for beginners to learn C++ programming. It covers essential topics such as object-oriented programming, vector operations, and basic user interaction in a console application. The system's simplicity makes it an excellent starting point for those interested in developing more complex applications in the future.
