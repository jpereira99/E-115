//
//  main.cpp
//  HW 3
//
//  Created by Jayden Pereira on 9/26/18.
//  Copyright © 2018 Jayden Pereira. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib> //used for rand()
#include <time.h> //used for seeding rand()
using namespace std;

//Declaration of Variable Functions
int intfunc();
int floatfunc();
int strfunc();

int main()
{
    intfunc();
    floatfunc();
    strfunc();
    
    return 0;
}

//Integer Variable Function
int intfunc()
{
    //Integer Input
    cout << "Please enter an integer: ";
    int x;
    cin >> x;
    cout << "Please enter another integer: ";
    int y;
    cin >> y;
    cout << endl;
    
    //Integer Math and Output
    cout << "The sum of " << x << " + " << y << " is " << x+y << endl;
    cout << "The difference of " << x << " - " << y << " is " << x-y << endl;
    cout << "The product of " << x << " * " << y << " is " << x*y << endl;
    cout << "The division of " << x << " / " << y << " is " << (x)/y << endl;
    cout << "The modulo of " << x << " % " << y << " is " << x%y << endl;
    cout << endl;
    return 11;
}


//Floating Point Variable Function
int floatfunc()
{
    //Floating Point Input
    cout << "Please enter a decimal: ";
    float a;
    cin >> a;
    cout << "Please enter another decimal: ";
    float b;
    cin >> b;
    cout << endl;
    
    //Floating Point Math and Output
    cout << "The sum of " << a << " + " << b << " is " << a+b << endl;
    cout << "The difference of " << a << " - " << b << " is " << a-b << endl;
    cout << "The product of " << a << " * " << b << " is " << a*b << endl;
    cout << "The division of " << a << " / " << b << " is " << (a)/b << endl;
    cout << endl;
    return 22;
}

//String Variable Function
int strfunc()
{
    //String Input
    cout << "Alright, enough with the calculators, let's come up with a sweet new username for you." << endl;
    cout << "Please enter your name: ";
    string j;
    cin >> j;
    cout << "Please enter your favorite animal: ";
    string k;
    cin >> k;
    cout << endl;
    
    //String Math, Random End Number Generator, and Output
    string l;
    srand((int)time(0));
    l = to_string(rand() % 100);
    cout << "Your new username is " << j+k+l;
    cout << endl;
    return 33;
}
