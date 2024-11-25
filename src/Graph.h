#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <limits>
using namespace std;

// Graph class definition using adjacency list representation.
class Graph {
private:
   int V; // Number of vertices.
   vector<list<pair<int, int>>> adj; // Adjacency list.

public:
   Graph(int V); // Constructor.
   void addEdge(int u, int v, int w); // Add edge to graph.
   void BFS(int start); // BFS traversal.
   void DFS(int start); // DFS traversal.
   void Dijkstra(int start); // Dijkstra's algorithm for shortest path.
};

#endif // GRAPH_H
