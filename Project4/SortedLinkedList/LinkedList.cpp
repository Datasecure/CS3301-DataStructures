//
//  LinkedList.cpp
//  SortedLinkedList
//
//  Created by William Shepherd on 2/1/16.
//  Copyright © 2016 William Shepherd. All rights reserved.
//

#include <iostream>
#include <string>
#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList() {
    count = 0;
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList &obj) {
    count = obj.count;
    head = obj.head;
}


LinkedList::~LinkedList() {
    Node* currNode = head;
    
    while (currNode != nullptr) {
        // TODO
        currNode = currNode -> Next;
    }
    
    head = nullptr;
    count = 0;
}


void LinkedList::Print() {
    Node* node = head;
    
    while (node != nullptr) {
        cout << to_string(node -> Data) << endl;
        
        node = node -> Next;
    }
}


void LinkedList::Add(int data) {
    Node* newNode = new Node;
    
    newNode -> Data = data;
    newNode -> Next = nullptr;
    
    if (Length() == 0) {
        head = newNode;
    } else {
        Node* currNode = head;
        Node* prevNode = nullptr;
        
        while (currNode != nullptr && newNode -> Data > currNode -> Data)
        {
            prevNode = currNode;
            currNode = currNode -> Next;
        }
        
        if (prevNode == nullptr){
            Node* tmp = head;
            
            head = newNode;
            newNode -> Next = tmp;
        }else {
            prevNode -> Next = newNode;
        }
        
        newNode -> Next = currNode;
    }
    
    count++;
}


void LinkedList::Delete(int data) {
    if (Length() == 0) {
        return;
    }
    
    if (Length() == 1 &&  head -> Data == data) {
        head = nullptr;
    }
    else {
        Node* currNode = head;
        Node* prevNode = nullptr;
        
        while (currNode != nullptr && currNode-> Data != data){
            prevNode = currNode;
            currNode = currNode -> Next;
        }
        
        if (prevNode == nullptr) {
            head = currNode -> Next;
        }
        else {
            prevNode -> Next = currNode -> Next;
        }
        
        delete currNode;
    }
    
    count--;
}