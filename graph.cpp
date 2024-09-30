#include "graph.hpp"

// Default constructor
Graph::Graph() : n(0) {}

// Constructor to initialize graph with 'n' nodes
Graph::Graph(int nodes) : n(nodes) {
    adjList.resize(n);
}

// Generate a random graph G(n, p)
Graph Graph::generateRandomGraph(int n, double p) {
    Graph g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (rand01() < p) {
                g.addEdge(i, j);
            }
        }
    }
    return g;
}

// Add an undirected edge between node u and node v
void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);  // Bidirectional edge
}

// Perform edge percolation on the graph, returns the percolated graph
Graph Graph::edgePercolation(double q) {
    //use rand01() to generate a random number between 0 and 1
    Graph gp(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (rand01() < q) {
                gp.addEdge(i, j);
            }
        }
    }
    return gp;
}

// Perform node percolation on the graph, returns the percolated graph
Graph Graph::nodePercolation(double q) {
    //TODO: implement
}

// Display the adjacency list of the graph
void Graph::displayGraph() {
    for (int i = 0; i < n; ++i) {
        std::cout << "Node " << i << ": ";
        for (int neighbor : adjList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

// Get the number of connected components using BFS
int Graph::connectedComponents() {
    std::vector<bool> visited(n, false);
    int componentCount = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            componentCount++;
            dfs(i, visited);
        }
    }
    return componentCount;
}

// DFS traversal to explore the component
void Graph::dfs(int start, std::vector<bool>& visited) {
    visited[start] = true;
    for (int neighbor : adjList[start]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}

// BFS traversal to explore the component
void Graph::bfs(int start, std::vector<bool>& visited) {
    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int neighbor : adjList[u]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}



