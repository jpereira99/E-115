//
//  main.cpp
//  HW 2
//
//  Created by Jayden Pereira on 9/19/18.
//  Copyright © 2018 Jayden Pereira. All rights reserved.
//

#include <iostream>
using namespace std;

//Declaration of calculator function
int calc();

int main()
{
    //"Loading Screen"
    cout << "Welcome to the TI-Pereira calculator!" << endl;
    
    //Call function
    calc();
}

//Calculator function
int calc()
{
    //Number input
    cout << "Enter your first number: ";
    int x;
    cin >> x;
    cout << "How about another: ";
    int y;
    cin >> y;
    
    //Calculations and text output
    cout << endl;
    cout << "The sum of " << x << " + " << y << " is " << x+y << endl;
    cout << "The difference of " << x << " - " << y << " is " << x-y << endl;
    cout << "The product of " << x << " * " << y << " is " << x*y << endl;
    cout << "The division of " << x << " / " << y << " is " << (x)/y << endl;
    cout << "The modulo of " << x << " % " << y << " is " << x%y << endl;
    cout << endl;
    
    //Loop or exit command
    int z;
    cout << "Press 1 to enter two more numbers or 0 to exit: ";
    cin >> z;
    cout << endl;
    
    if (z == 1){
        calc();
    }
    else{
        return 0;
    }
    return 1;
}
