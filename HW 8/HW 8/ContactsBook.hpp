//
//  ContactsBook.hpp
//  HW 8
//
//  Created by Jayden Pereira on 11/14/18.
//  Copyright © 2018 Jayden Pereira. All rights reserved.
//

#ifndef ContactsBook_hpp
#define ContactsBook_hpp

class ContactsBook {
public:
    int test;
    std::ifstream bookReader;
    std::ofstream bookWriter;
    void bookSelector();
    void createContact();
    void searchBook();
    void displayBook();
    int closeBook();
};

#endif /* ContactsBook_hpp */
