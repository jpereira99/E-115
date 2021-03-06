//
//  atm.cpp
//  HW 7
//
//  Created by Jayden Pereira on 11/7/18.
//  Copyright © 2018 Jayden Pereira. All rights reserved.
//
#include <iostream>
#include <string>
#include <unistd.h> //Used for getpass() password protection on unix
#include <fstream> //needed for .txt functionality
#include "atm.h" //atm class header
using namespace std;

/* PUBLIC FUNCS */

//check existing user
void atmMachine::checkIfUser() {
    int incorrectCounter = 0;
    while (true) {
        string passInput = getpass("Please enter your password: ");
        
        string passCheck;
        ifstream passOfUserCheck;
        passOfUserCheck.open("passOfUser.txt");
        getline(passOfUserCheck, passCheck);
        passOfUserCheck.close();
        if (passCheck == passInput) {
            mainTerminal();
            break;
        }
        if (incorrectCounter == 2) {
            cout << "\nToo many failed attempts!\n";
            closeTerminal();
            break;
        }
        else {
            incorrectCounter += 1;
            cout << "Incorrect password!\n";
            continue;
        }
    }
}

/* PRIVATE FUNCS */

//Terminal screen and func selector
void atmMachine::mainTerminal() {
    cout << "\n"
        "Enter 1 to check your balance\n"
        "Enter 2 to deposit money\n"
        "Enter 3 to withdraw money\n"
        "Enter 4 to change your password\n"
        "Enter 5 to close the session\n";
    int selector;
    cin >> selector;
    
    //Determine input loop and call atm funcs
    while(true) {
        if (selector == 1) {checkBalance(); break;}
        else if (selector == 2) {depositMoney(); break;}
        else if (selector == 3) {withdrawMoney(); break;}
        else if (selector == 4) {changePass(); break;}
        else if (selector == 5) {closeTerminal(); break;}
        else {
            cout << "\nSorry, wrong input, please try again: ";
            cin >> selector;
            continue;
        }
    }
}

void atmMachine::depositMoney() {
    cout << "\n"
    "Enter 1 to deposit a check\n"
    "Enter 2 to deposit cash\n";
    float input = 0;
    cin >> input;
    
    //check deposit
    if (input == 1) {
        cout << "Enter deposit amount: ";
        cin >> input;
        cout << "$" << input << " was deposited into your account successfully\n";
        
        //subtracting input from persistent balance
        string x;
        balanceOfUserReader.open("balanceOfUser.txt");
        balanceOfUserReader >> x;
        balanceOfUserReader.close();
        int currentBalance = atoi(x.c_str());
        int finalBalance = input + currentBalance;
        
        //change persistent balance
        balanceOfUserWriter.open("balanceOfUser.txt");
        balanceOfUserWriter << finalBalance;
        balanceOfUserWriter.close();
        
        mainTerminal();
    }
    //cash deposit
    else if (input == 2) {
        cout << "Enter deposit amount: ";
        cin >> input;
        if (input <= 100) {
            cout << "$" << input << " was deposited into your account successfully\n";
            
            //subtracting input from persistent balance
            string x;
            balanceOfUserReader.open("balanceOfUser.txt");
            balanceOfUserReader >> x;
            balanceOfUserReader.close();
            int currentBalance = atoi(x.c_str());
            int finalBalance = input + currentBalance;
            
            //change persistent balance
            balanceOfUserWriter.open("balanceOfUser.txt");
            balanceOfUserWriter << finalBalance;
            balanceOfUserWriter.close();
            
            mainTerminal();
        }
        //too much cash deposited
        else { cout << "$" << input << " is greater than $100, cannot complete deposit\n"; mainTerminal(); }
    }
    else {mainTerminal();}
}

void atmMachine::withdrawMoney() {
    //ask amount
    int input;
    cout << "\nEnter wihdrawal amount: ";
    cin >> input;
    //check if less than $200 and divisble by 20
    if (input <= 200) {
        if (input % 20 == 0) {
            cout << "$"<< input << " was withdrawed successfully\n";
            
            //subtracting input from persistent balance
            string x;
            balanceOfUserReader.open("balanceOfUser.txt");
            balanceOfUserReader >> x;
            balanceOfUserReader.close();
            
            cout << x;
            
            int currentBalance = atoi(x.c_str());
            int finalBalance = currentBalance - input;
            
            cout << finalBalance;
            
            //changing persistent balance
            balanceOfUserWriter.open("balanceOfUser.txt");
            balanceOfUserWriter << finalBalance;
            balanceOfUserWriter.close();
            
            mainTerminal();
        }
        //incorrect entry
        else { cout << input << " is not divisible by 20\n"; mainTerminal(); }
    }
    //incorrect entry
    else { cout << "Cannot withdraw that amount of money at once"; mainTerminal(); }
}

void atmMachine::checkBalance() {
    //Check balance on file
    string amount;
    balanceOfUserReader.open("balanceOfUser.txt");
    balanceOfUserReader >> amount;
    balanceOfUserReader.close();
    
    //print amount
    cout << "\nThe balance on your account is $" << amount << endl;
    mainTerminal();
}

//close session
int atmMachine::closeTerminal() {
    return 0;
}

void atmMachine::changePass() {
    //ask if sure
    char decision;
    cout << "Are you sure you want to change your password? [y/n]\n";
    cin >> decision;
    //change pass on .txt
    if (decision == 'y') {
        ofstream passAppender;
        string passInput = getpass("Please enter your new password: ");
        
        passAppender.open("passOfUser.txt");
        passAppender << passInput;
        passAppender.close();
        
        cout << "password successfully changed!\n";
        mainTerminal();
    }
    else {
        mainTerminal();
    }
}
