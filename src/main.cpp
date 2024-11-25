#include "AVLTree.h"
#include "Graph.h"

int main() {
    
     // Example usage of AVL Tree:
     AVLTree avl;
     avl.insert("Region3");
     avl.insert("Region1");
     avl.insert("Region2");

     cout << "In-order Traversal of AVL Tree: ";
     avl.inOrder(); // Should print: Region1 Region2 Region3

     cout << endl;

     // Example usage of Graph:
     Graph g(4); // Create a graph with 4 vertices.
     g.addEdge(0, 1, 1); 
     g.addEdge(0, 2, 4); 
     g.addEdge(1, 2, 2); 
     g.addEdge(1, 3, 5); 

     cout << "BFS starting from vertex 0: ";
     g.BFS(0); 

     cout << "\nDFS starting from vertex 0: ";
     g.DFS(0);

     cout << "\nDijkstra's shortest path from vertex 0:\n";
     g.Dijkstra(0);

     return 0;
}
