//
//  LinkedList.hpp
//  SortedLinkedList
//
//  Created by William Shepherd on 2/1/16.
//  Copyright © 2016 William Shepherd. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

#endif /* LinkedList_hpp */
struct Node {
    int Data;
    Node* Next;
};

class LinkedList {
private:
    Node* head;
    int count;
    
public:
    LinkedList();
    LinkedList(const LinkedList &obj);
    virtual ~LinkedList();
    
    void Add(int data);
    void Delete(int data);
    void Print();
    int Length() const
    {
        return count;
    }
    
    void operator=(const LinkedList &obj) {
        count = obj.count;
        head = obj.head;
    }
};
