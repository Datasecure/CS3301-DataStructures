//
//  main.cpp
//  SortedLinkedList
//
//  Created by William Shepherd on 2/1/16.
//  Copyright © 2016 William Shepherd. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    LinkedList list;
    
    list.Add(10);
    list.Add(30);
    list.Add(50);
    list.Add(20);
    
    cout << "Printing list:" << endl;
    list.Print();
    cout << "Finished" << endl;
    
    list.Add(70);
    list.Add(60);
    list.Add(40);
    list.Add(80);
   
    cout << "Printing list:" << endl;
    list.Print();
    cout << "Finished" << endl;
    
    list.Delete(10);

    cout << "Printing list:" << endl;
    list.Print();
    cout << "Finished" << endl;
    
    list.Delete(80);
    
    list.Delete(50);
    
    cout << "Printing list:" << endl;
    list.Print();
    cout << "Finished" << endl;
    
    list.Delete(70);
    
    cout << "Printing list:" << endl;
    list.Print();
    cout << "Finished" << endl;
    
    cin.get();
    
    return 0;
}
