//
//  ContactsBook.cpp
//  HW 8
//
//  Created by Jayden Pereira on 11/14/18.
//  Copyright © 2018 Jayden Pereira. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "ContactsBook.hpp"
using namespace std;

void ContactsBook::bookSelector() {
    //selector
    cout <<
    "Enter 1 to create a contact\n"
    "Enter 2 to search for a contact\n"
    "Enter 3 to display the contact book\n"
    "Enter 4 to close the contact book\n";
    int selector;
    cin >> selector;
    
    //Determine input loop and call funcs
    while(true) {
        if (selector == 1) {createContact(); break;}
        else if (selector == 2) {searchBook(); break;}
        else if (selector == 3) {displayBook(); break;}
        else if (selector == 4) {closeBook(); break;}
        else {
            cout << "\nSorry, wrong input, please try again: ";
            cin >> selector;
            continue;
        }
    }
}

void ContactsBook::createContact() {
    //var init
    string firstName;
    string lastName;
    string num;
    
    //ask values
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Number: ";
    cin >> num;
    
    //write new line
    bookWriter.open("ContactsBook.txt", ios::app);
    bookWriter << firstName << " " << lastName << " " << num << endl;
    bookWriter.close();
    
    //callback
    bookSelector();
}

void ContactsBook::searchBook() {
    //var init
    string line;
    string contact;
    
    //input
    cout << "Who are you trying to find: ";
    cin >> contact;
    
    //seach and print line
    bookReader.open("ContactsBook.txt");
    while(!bookReader.eof()) {
        getline(bookReader, line);
        if (line.find(contact, 0) != string::npos) {
            cout << line << endl;
        }
    }
    bookReader.close();
    
    //callback
    bookSelector();
}

void ContactsBook::displayBook() {
    
    //open and print line by line
    bookReader.open("ContactsBook.txt");
    while (true) {
        string firstName;
        string lastName;
        string num;
        bookReader >> firstName >> lastName >> num;
        string contact = firstName + " " + lastName + " " + num;
        if(bookReader.eof()) {break;}
        cout << contact << endl;
    }
    
    //callback
    bookSelector();

}

int ContactsBook::closeBook() {
    return 0;
}
