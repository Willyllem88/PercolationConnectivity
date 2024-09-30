#include "graph.hpp"

// Default constructor
Graph::Graph() : n(0) {}

// Constructor to initialize graph with 'n' nodes
Graph::Graph(int nodes) : n(nodes) {
    adjList.resize(n);
}

// Generate a random graph G(n, p), being p the probability of an edge between two nodes
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
Graph Graph::edgePercolation(double p) const {
    Graph gp(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            //check if the edge exists continue
            if (std::find(adjList[i].begin(), adjList[i].end(), j) == adjList[i].end()) {
                continue; //if the edge does not exist
            }

            if (rand01() > p) { //if the edge is not removed
                gp.addEdge(i, j);
            }
        }
    }
    return gp;
}

// Perform node percolation on the graph, returns the percolated graph
Graph Graph::nodePercolation(double p) const {
    //TODO: implement;
}

// Display the adjacency list of the graph
void Graph::displayGraph() const{
    for (int i = 0; i < n; ++i) {
        std::cout << "Node " << i << ": ";
        for (int neighbor : adjList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

// Get the number of nodes
int Graph::getNbNodes() const {
    return n;
}

// Get the number of edges
int Graph::getNbEdges() const {
    int edgeCount = 0;
    for (int i = 0; i < n; ++i) {
        edgeCount += adjList[i].size();
    }
    return edgeCount / 2;  // Each edge is counted twice
}

// Get the number of connected components using BFS
int Graph::connectedComponents() const {
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
void Graph::dfs(int start, std::vector<bool>& visited) const {
    visited[start] = true;
    for (int neighbor : adjList[start]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}

// BFS traversal to explore the component
void Graph::bfs(int start, std::vector<bool>& visited) const {
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



