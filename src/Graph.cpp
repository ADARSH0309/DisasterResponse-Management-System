#include "Graph.h"

// Constructor initializes graph with V vertices.
Graph::Graph(int V) : V(V) {
   adj.resize(V); 
}

// Add an edge to the graph.
void Graph::addEdge(int u, int v, int w) {
   adj[u].push_back(make_pair(v, w)); 
   adj[v].push_back(make_pair(u, w)); 
}

// BFS traversal from a given source vertex.
void Graph::BFS(int start) {
   vector<bool> visited(V, false);
   list<int> queue;

   visited[start] = true; 
   queue.push_back(start);

   while (!queue.empty()) {
       int current = queue.front();
       cout << current << " ";
       queue.pop_front();

       for (auto& neighbor : adj[current]) {
           if (!visited[neighbor.first]) {
               visited[neighbor.first] = true;
               queue.push_back(neighbor.first);
           }
       }
   }
}

// DFS traversal from a given source vertex.
void Graph::DFS(int start) {
   vector<bool> visited(V, false);
   stack<int> stack;

   stack.push(start);

   while (!stack.empty()) {
       int current = stack.top();
       stack.pop();

       if (!visited[current]) {
           cout << current << " ";
           visited[current] = true;
       }

       for (auto& neighbor : adj[current]) {
           if (!visited[neighbor.first]) {
               stack.push(neighbor.first);
           }
       }
   }
}

// Dijkstra's algorithm to find shortest paths from source vertex.
void Graph::Dijkstra(int start) {
   vector<int> dist(V, numeric_limits<int>::max());
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

   dist[start] = 0; 
   pq.push(make_pair(0, start));

   while (!pq.empty()) {
       int u = pq.top().second;
       pq.pop();

       for (auto& neighbor : adj[u]) {
           int v = neighbor.first;
           int weight = neighbor.second;

           if (dist[u] + weight < dist[v]) {
               dist[v] = dist[u] + weight;
               pq.push(make_pair(dist[v], v));
           }
       }
   }

   cout << "Vertex Distance from Source:\n";
   for (int i = 0; i < V; ++i)
       cout << i << "\t\t" << dist[i] << "\n";
}
