//
//  atm.h
//  HW 7
//
//  Created by Jayden Pereira on 11/7/18.
//  Copyright © 2018 Jayden Pereira. All rights reserved.
//
#ifndef atm_h
#define atm_h

class atmMachine {
public:
    void checkIfUser();
private:
    std::ofstream balanceOfUserWriter;
    std::ifstream balanceOfUserReader;
    void mainTerminal();
    void depositMoney();
    void withdrawMoney();
    void checkBalance();
    void changePass();
    int closeTerminal();
};

#endif

