#include <iostream>
#include "AVLTree.h"

void testAVLTree() {
    AVLTree avl;
    
    // Test Insertion
    avl.insert("Region3");
    avl.insert("Region1");
    avl.insert("Region2");

    std::cout << "In-order Traversal after insertions: ";
    avl.inOrder(); // Expected: Region1 Region2 Region3
    std::cout << std::endl;

    // Test Balancing
    avl.insert("Region4");
    avl.insert("Region5");
    
    std::cout << "In-order Traversal after more insertions: ";
    avl.inOrder(); // Expected: Region1 Region2 Region3 Region4 Region5
    std::cout << std::endl;

    // Test Deletion
    avl.insert("Region0");
    avl.insert("Region6");
    std::cout << "In-order Traversal before deletion: ";
    avl.inOrder(); // Expected: Region0 Region1 Region2 Region3 Region4 Region5 Region6
    std::cout << std::endl;

    // Assume we have a delete method (not implemented in the previous code)
    // avl.delete("Region3"); 
    // std::cout << "In-order Traversal after deletion of Region3: ";
    // avl.inOrder(); // Expected: Region0 Region1 Region2 Region4 Region5 Region6
}

int main() {
    testAVLTree();
    return 0;
}
