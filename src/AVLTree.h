#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>
using namespace std;

// Node structure for AVL Tree
struct Node {
    string key;
    Node* left;
    Node* right;
    int height;
};

// AVL Tree class definition
class AVLTree {
private:
    Node* root;

    // Helper functions for AVL Tree operations
    int height(Node* node);
    int getBalance(Node* node);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* insert(Node* node, string key);
    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);
    
public:
    AVLTree();
    void insert(string key);
    void preOrder();
    void inOrder();
    void postOrder();
};

#endif // AVLTREE_H
