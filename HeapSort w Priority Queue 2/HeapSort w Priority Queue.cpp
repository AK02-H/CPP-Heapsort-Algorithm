// HeapSort w Priority Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "PQueMin.h"
#include "BinHeapMin.h"

using namespace std;

int main()
{

    cout << "Enter number of items to sort: " << endl;
    int itemCount;
    cin >> itemCount;


    PQueMin<string> priorityQueue = PQueMin<string>(itemCount);

    for (size_t i = 0; i < itemCount; i++)
    {
        string newItemName;
        int newItemPriority;

        cout << "Enter new item name: " << endl;
        cin >> newItemName;
        //getline(cin, newItemName, '\n');

       

        cout << "Enter item's priority: " << endl;
        cin >> newItemPriority;
        cin.clear();


        priorityQueue.insert(newItemName, newItemPriority);


    }

    //change
    vector<string> newArray; //Must take a constant, but shouldn't matter if the for loops only run itemCount number of times, as long as itemCount is under 32

    for (size_t i = 0; i < itemCount; i++)
    {
        newArray.push_back(priorityQueue.extractMin());
        //cout << "extracted " << newArray[i] << endl;
    }

    cout << "Order is: ";
    for (size_t i = 0; i < itemCount; i++)
    {
        cout << newArray[i] << " ";
    }

    cout << endl;






   


}




