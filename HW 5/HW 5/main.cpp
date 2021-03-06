//
//  main.cpp
//  HW 5
//
//  Created by Jayden Pereira on 10/10/18.
//  Copyright © 2018 Jayden Pereira. All rights reserved.
//

#include <iostream>
#include <vector> //Used for merge sort on Program 2
using namespace std;

//Declaration of functions
int program1();
int program2();
vector<int> mergeSort();

int main() {
    //Program Selector
    while (true)
    {
        cout << "Please type 1 for PROGRAM 1 or type 2 for PROGRAM 2: ";
        int funcSelect;
        cin >> funcSelect;
        if (funcSelect == 1)
        {
            program1();
            break;
        }
        else if (funcSelect == 2)
        {
            program2();
            break;
        }
        else
        {
            cout << "Sorry, wrong input. ";
            continue;
        }
    }
}


int program1() {
    //Declaration of variables
    int sumOfValues = 0;
    int minOfValues = INT_MAX;
    int maxOfValues = INT_MIN;
    int tempNumber;

    //For Loop
    for (int i = 1; i < 10; i++)
    {
        cout << "Give me a number: ";
        cin >> tempNumber;
        
        //Min and Max check algorithm
        sumOfValues = sumOfValues + tempNumber;

        if (tempNumber >= maxOfValues) {
            maxOfValues = tempNumber;
        }

        if (tempNumber <= minOfValues) {
            minOfValues = tempNumber;
        }
    }
    
    //Print
    cout << "\nThe sum of all numbers is " << sumOfValues << endl;
    cout << "The minimum value is " << minOfValues << endl;
    cout << "The maximum value is " << maxOfValues << endl;
    
    return 1;
}


//Merge Sort
vector<int> mergeSort(vector<int> inputOfNumbers)
{
    //Check vector size
    if (inputOfNumbers.size() == 1)
    { return inputOfNumbers; }
    vector<int> outputOfNumbers(inputOfNumbers.size());
    
    //Splitting and recursion
    int midpoint = 0.5 * inputOfNumbers.size();
    vector<int> leftSide(inputOfNumbers.begin(),inputOfNumbers.begin()+midpoint);
    vector<int> rightSide(inputOfNumbers.begin()+midpoint,inputOfNumbers.end());
    leftSide = mergeSort(leftSide);
    rightSide = mergeSort(rightSide);

    //Merge leftSide and rightSide vectors
    merge(leftSide.begin(),leftSide.end(),rightSide.begin(),rightSide.end(),outputOfNumbers.begin());
    
    return outputOfNumbers;
}


int program2() {
    //Declaration of variables
    int sumOfValues = 0;
    int minOfValues = INT_MAX;
    int maxOfValues = INT_MIN;
    vector<int> listOfNumbers;
    
    //While Loop
    while (true)
    {
        int tempNumber;
        cout << "Give me a number: ";
        cin >> tempNumber;
        
        if (tempNumber != -1)
        {
            listOfNumbers.push_back(tempNumber);
            
            //Min and Max check algorithm
            sumOfValues = sumOfValues + tempNumber;

            if (tempNumber >= maxOfValues) {
                maxOfValues = tempNumber;
            }

            if (tempNumber <= minOfValues) {
                minOfValues = tempNumber;
            }
        }
        else { break; }
    }
    
    //Print
    cout << "\nThe sum of all numbers is " << sumOfValues << endl;
    cout << "The minimum value is " << minOfValues << endl;
    cout << "The maximum value is " << maxOfValues << endl;
    
    //Call to merge sort and then print out sorted vector
    vector<int> sortedListOfNumbers = mergeSort(listOfNumbers);
    cout << "\nThe list of numbers after being sorted: \n";
    int i;
    for(i = 0; i <+ sortedListOfNumbers.size(); i++) {
        cout << sortedListOfNumbers[i] << " ";
    }
    
    return 2;
}
