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
    int size;
    int rootIndex;
    bool isEmpty() const;
    
    BinaryTreeNode nodeArray[MAX_NODES];
    
    string inorderTraversal();
    string preorderTraversal();
    string postOrderTraversal();
    
    static int findHelper(BinarySearchTree bst, int value) ;
    
    
    inline static BinaryTreeNode createNode(int data) {
        auto node = BinaryTreeNode();
        
        node.data = data;
        node.leftndex = -1;
        node.rightIndex = -1;
        
        return node;
    };
    
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree &obj);
    ~BinarySearchTree();
    
    int Find(int value) const;
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
