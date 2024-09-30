#pragma once

#include "utils.hpp"

class Graph {
public:
    // Default constructor
    Graph();

    // Constructor to initialize the graph with 'n' nodes
    Graph(int nodes);

    // Generate a random graph G(n, p)
    static Graph generateRandomGraph(int n, double p);
    
    // Add an edge between two nodes u and v
    void addEdge(int u, int v);

    // Perform edge percolation on the graph
    Graph edgePercolation(double q);

    // Perform node percolation on the graph
    Graph nodePercolation(double q);
    
    // Get the number of connected components
    int connectedComponents();

    // Display the graph
    void displayGraph();

private:
    int n;  // Number of nodes
    std::vector<std::vector<int>> adjList;  // Adjacency list

    // Helper function for DFS traversal
    void dfs(int start, std::vector<bool>& visited);

    // Helper function for BFS traversal
    void bfs(int start, std::vector<bool>& visited);
};