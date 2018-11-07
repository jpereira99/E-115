//
//  main.cpp
//  HW 6
//
//  Created by Jayden Pereira on 10/30/18.
//  Copyright © 2018 Jayden Pereira. All rights reserved.
//

#include <iostream>
using namespace std;

//Function 1
void printGreeting() {
    cout << "Hi, I hope you're having a fantastic day!\n";
}

//Function 2
void divideNumbers(float x, float y) {
    //check denominator
    if (y == 0) {
        cout << "Denominator is 0, cannot perform the division\n";
    }
    //divide if denom is good
    else {
        float divisionOfNums = x / y;
        cout << x << " divided by " << y << " equals " << divisionOfNums << endl;
    }
}

//Function 3
int factorial(int num) {
    //factorial of 0 and negative numbers is 0
    if (num < 0) {
        return 0;
    }
    //looping multiplication (n! = n1 * n2 * n3...)
    else {
        int tempValue = 1;
        for (int i = num; i > 0; i--) {
            tempValue *= i;
        }
        return tempValue;
    }
}

//Function 4
void fibonacci(int n) {
    //set first 3 ints of sequence and establish variables
    int x = 0;
    int y = 1;
    int z = 1;
    
    cout << "The fibonacci series with length " << n << " is:\n";
    cout << x << ", " << y;
    
    //loop that will continually add up and print the next number of the sequence
    for (int i = 2; i <= n; i++) {
        z = x + y;
        x = y;
        y = z;
        
        cout << ", " << y;
    }
    
    cout << endl;
}

//Towers of Hanoi challenge
void towersOfHanoiSolver(int numOfDisks, char start, char middle, char end) {
    //check if only one disk is there
    if (numOfDisks == 1) {
        cout << "Move disk 1 from rod " << start << " to rod " << end << endl;
    }
    //recursion method to perform the necessary sorting moves
    else {
        towersOfHanoiSolver(numOfDisks - 1, start, middle, end);
        cout << "Move disk " << numOfDisks << " from rod " << start << " to rod " << end << endl;
        towersOfHanoiSolver(numOfDisks - 1, middle, end, start);
    }
}

int main() {
    //Calling function 1
    printGreeting();
    cout << endl;
    
    //Calling function 2
    divideNumbers(5.0, 2.0);
    cout << endl;
    
    //Calling function 3
    int factorialNum = 0;
    cout << "What number do you want to find the factorial of: ";
    cin >> factorialNum;
    int printFactorial = factorial(factorialNum);
    cout << "The factorial of " << factorialNum << " is " << printFactorial << endl;
    cout << endl;
    
    //Calling function 4
    int fibNum = 1;
    cout << "How long do you want the fibonacci sequence: ";
    cin >> fibNum;
    fibonacci(fibNum);
    cout << endl;
    
    //Calling towers of hanoi function
    int numOfDisks = 1;
    cout << "How many disks are on the starting peg: ";
    cin >> numOfDisks;
    cout << "To solve the Towers of Hanoi with " << numOfDisks << " disks:\n";
    towersOfHanoiSolver(numOfDisks, 'A', 'B', 'C');
    
    return 0;
}
