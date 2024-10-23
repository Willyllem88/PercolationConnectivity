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
            if (rand01() < p) {
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
            //Connect with neighbours right and below, if possible
            if(i<m-1){
                int belowNode = (i+1)*m + j;
                g.addEdge(currentNode,belowNode);
            }
            if(j<m-1){
                int rightNode = i*m + (j+1);
                g.addEdge(currentNode,rightNode);
            }
        }
    }
    return g;
}

//Generate a Triangular Grid Graph
Graph Graph::generateTriangularGridGraph(int rows){
    int n = (rows*(rows+1))/2;
    Graph g(n);
    int currentNode = 0;
    for(int i = 0; i<rows;++i){
        for(int j=0;j<=i;++j){
            //Connect currentNode with right neighbour and the two below, if they exist
            if(j<i){
                int rightNode = currentNode + 1;
                g.addEdge(currentNode,rightNode);
            }
            if(i < rows-1){
                int belowLeftNode = currentNode + i + 1;
                g.addEdge(currentNode, belowLeftNode);
                int belowRightNode = currentNode + i + 2;
                g.addEdge(currentNode, belowRightNode);
            }
            currentNode++;
        }
    }
    return g;
}

//Generate a Random Geometric Graph(n, r)
Graph Graph::generateRandomGeometricGraph(int n, double r){
    Graph g(n);
    std::vector<std::pair<double,double>> coords(n);
    for(int i = 0; i < n; ++i){
        coords[i].first = rand01();
        coords[i].second = rand01();
        //std::cout << coords[i].first << "  "  << coords[i].second << std::endl;
    }
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){            
            double dist_x = coords[i].first - coords[j].first;
            double dist_y = coords[i].second - coords[j].second;
            //std::cout << (sqrt(dist_x * dist_x + dist_y * dist_y)) << std::endl;
            if((sqrt(dist_x * dist_x + dist_y * dist_y)) < r) g.addEdge(i, j);
        }
    }
    return g;
}

//Returns a candidate to connection in a BA model Graph following a preferential attachment method
int preferentialAttachment(std::vector<int> connection_degree){
    int degree_sum = 0, temp_sum = 0, random_num, chosen = 0;  
    for(auto i : connection_degree) degree_sum += i;
    random_num = rand() % degree_sum;
    for(int i = 0; i < int(connection_degree.size()); ++i){
        temp_sum += connection_degree[i];
        if(random_num <= temp_sum){
            chosen = i;
            break;
        } 
    }
    return chosen;
}

Graph Graph::generateRandom_BarabasiAlbert(int n, int m0, int m){
    Graph g(n);
    std::vector<int> connection_degree(n);
    //Connect m0 nodes with each other, assign them a connection degree of m0 - 1
    for(int i = 0; i < m0; ++i){
        for(int j = i + 1; j < m0; ++j) g.addEdge(i, j);
        connection_degree[i] = m0 - 1;
    }
    for(int i = m0; i < n; ++i){
        //Connect the remaining nodes with the others based on their connection degree
        std::vector<int> candidates;
        while(int(candidates.size()) < m){
            int selectedNode = preferentialAttachment(connection_degree);
            if(find(candidates.begin(), candidates.end(), selectedNode) == candidates.end()) candidates.push_back(selectedNode);
        }
        for(auto j : candidates) {
            g.addEdge(i, j);
            connection_degree[j] += 1;
        }
        connection_degree[i] = m;
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
    // std::vector to track which nodes survived percolation
    std::vector<std::pair<bool, int>> nodeAlive(n, {true, 0});
    int nbNodesAlive = n;

    // Iterate over each node
    for (int u = 0; u < n; ++u) {
        // Generate a random number between 0 and 1
        double randomValue = rand01();

        // If randomValue is less than p, the node fails and is removed
        if (randomValue < p) {
            nodeAlive[u].first = false;  // Mark the node as failed
            nbNodesAlive--;
        }
        else {
            nodeAlive[u].second = u - n + nbNodesAlive;
        }
    }

    Graph percolatedGraph(nbNodesAlive);

    // Now add edges to the percolatedGraph for nodes that survived
    for (int u = 0; u < n; ++u) {
        if (nodeAlive[u].first) {
            for (int v : adjList[u]) {
                // Only add the edge if both nodes u and v survived and the edge is not added
                if (nodeAlive[v].first && u < v) {
                    percolatedGraph.addEdge(nodeAlive[u].second, nodeAlive[v].second);
                }
            }
        }
    }

    // Return the new percolated graph
    return percolatedGraph;
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
