//
//  BinarySearchTree.hpp
//  BST
//
//  Created by William Shepherd on 2/13/16.
//  Copyright © 2016 William Shepherd. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <string>

using std::string;

#endif /* BinarySearchTree_hpp */

#define MAX_NODES 100

enum TraversalType {
    Inorder,
    Preorder,
    Postorder
};

struct BinaryTreeNode {
    int data;
    int leftndex;
    int rightIndex;
};

class BinarySearchTree {
    
private:
    BinaryTreeNode nodeArray[MAX_NODES];
    
    string inorderTraversal();
    string preorderTraversal();
    string postOrderTraversal();
    
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree &obj);
    ~BinarySearchTree();
    
    int Find(int value);
    int FindMin();
    int FindMax();
    void Insert(int data);
    void Delete(int data);
    
    inline string Traversal(TraversalType traversal) {
        switch (traversal) {
            case Inorder:
                return inorderTraversal();
                break;
            case Preorder:
                return preorderTraversal();
                break;
            case Postorder:
                return postOrderTraversal();
                break;
            default:
                return "";
                break;
        }
    };
};
