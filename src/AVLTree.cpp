#include "AVLTree.h"

// Constructor initializes the root to nullptr
AVLTree::AVLTree() : root(nullptr) {}

// Get height of the node
int AVLTree::height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Get balance factor of node
int AVLTree::getBalance(Node* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

// Right rotate subtree rooted with y
Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // New root
}

// Left rotate subtree rooted with x
Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // New root
}

// Insert a key into the tree and balance it if needed
Node* AVLTree::insert(Node* node, string key) {
    if (node == nullptr) {
        Node* newNode = new Node{key, nullptr, nullptr, 1};
        return newNode;
    }

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right)));

    // Balance the tree if needed
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Return unchanged node pointer
}

// Public insert function to add keys to the AVL tree.
void AVLTree::insert(string key) {
   root = insert(root, key);
}

// Pre-order traversal of the tree.
void AVLTree::preOrder() {
   preOrder(root);
}

// In-order traversal of the tree.
void AVLTree::inOrder() {
   inOrder(root);
}

// Post-order traversal of the tree.
void AVLTree::postOrder() {
   postOrder(root);
}

// Implement traversal methods...
