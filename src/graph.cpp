#include "graph.hpp"

// Default constructor
Graph::Graph() : n(0) {}

// Constructor to initialize graph with 'n' nodes
Graph::Graph(int nodes) : n(nodes) {
    adjList.resize(n);
}

// Generate a random graph G(n, p), being p the probability of an edge between two nodes
Graph Graph::generateRandomGraph_ErdosRenyi(int n, double p) {
    Graph g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!g.existsEdge(i, j) && rand01() < p) {
                g.addEdge(i, j);
            }
        }
    }
    return g;
}

//Generate a square grid graph G(m x m)
Graph Graph::generateSquareGridGraph(int m){
    int n = m*m;
    Graph g(n);
    for(int i=0; i<m;++i){
        for(int j=0; j<m;++j){
            int currentNode = i*m + j;
            //Add edge when two vertices are at distance 1
            //Connect with neighbours above, below, left and right, if possible
            if(i > 0){
                int neighborNode = (i-1)*m + j;
                g.addEdge(currentNode,neighborNode);
            }
            if(i<m-1){
                int neighborNode = (i+1)*m + j;
                g.addEdge(currentNode,neighborNode);
            }
            if(j>0){
                int neighborNode = i*m + (j-1);
                g.addEdge(currentNode,neighborNode);
            }
            if(j<m-1){
                int neighborNode = i*m + (j+1);
                g.addEdge(currentNode,neighborNode);
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

// Check if there is an edge between two nodes u and v
bool Graph::existsEdge(int u, int v) const {
    return std::find(adjList[u].begin(), adjList[u].end(), v) != adjList[u].end();
}

// Perform edge percolation on the graph, returns the percolated graph
Graph Graph::edgePercolation(double p) const {
    // Create a new graph as a deep copy of the current graph
    Graph percolatedGraph(this->n);  // Copy the number of nodes

    // Iterate over each node in the adjacency list
    for (int u = 0; u < n; ++u) {
        for (int v : adjList[u]) {
            // Avoid processing the same edge twice
            if (u < v) {
                // Generate a random number between 0 and 1
                double randomValue = rand01();

                // If randomValue is greater than p, keep the edge
                if (randomValue > p) {
                    percolatedGraph.addEdge(u, v);
                }
            }
        }
    }

    // Return the new percolated graph
    return percolatedGraph;
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



