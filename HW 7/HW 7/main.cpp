//
//  main.cpp
//  HW 7
//
//  Created by Jayden Pereira on 11/7/18.
//  Copyright © 2018 Jayden Pereira. All rights reserved.
//
#include <iostream>
#include <fstream>
#include "atm.h"//atm class header
using namespace std;

int main() {
    //Initialize class variable
    atmMachine key;
    
    //Boot screen and func selector
    cout << "Welcome to the Pereira Online Banking System!\n";
    key.checkIfUser();
    
    return 0;
}


