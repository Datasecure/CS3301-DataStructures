//
//  BinarySearchTree.cpp
//  BST
//
//  Created by William Shepherd on 2/13/16.
//  Copyright © 2016 William Shepherd. All rights reserved.
//

#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree() {
    size = 0;
    rootIndex = -1;
}

BinarySearchTree::~BinarySearchTree() {
    if (!isEmpty()) {
        
    }
}

bool BinarySearchTree::isEmpty() const {
    return size == 0;
}