#include <iostream>
#include "Graph.h"

void testGraph() {
    Graph g(4); // Create a graph with 4 vertices.
    
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);

    std::cout << "BFS starting from vertex 0: ";
    g.BFS(0); // Expected output: 0 1 2 3
    std::cout << std::endl;

    std::cout << "DFS starting from vertex 0: ";
    g.DFS(0); // Expected output: 0 1 2 3 (or similar depending on order)
    std::cout << std::endl;

    std::cout << "Dijkstra's shortest path from vertex 0:\n";
    g.Dijkstra(0); // Should show shortest distances from vertex 0
}

int main() {
    testGraph();
    return 0;
}
