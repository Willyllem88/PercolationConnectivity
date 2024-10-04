#pragma once

#include "utils.hpp"

class Graph {
public:
    // Default constructor
    Graph();

    // Constructor to initialize the graph with 'n' nodes
    Graph(int nodes);

    // Generate a random graph G(n, p), being p the probability of an edge between two nodes
    static Graph generateRandomGraph_ErdosRenyi(int n, double p);

    //Generate a square grid graph G(m x m)
    static Graph generateSquareGridGraph(int m);

    //Generate a triangular grid graph G
    static Graph generateTriangularGridGraph(int rows);

    //Generate a BA model Graph(n, m0, m) being m0 the number of inital nodes connected and m the number of edges the rest of nodes are connected
    static Graph generateBAmodelGraph(int n, int m0, int m);

    // Add an edge between two nodes u and v
    void addEdge(int u, int v);

    // Check if there is an edge between two nodes u and v
    bool existsEdge(int u, int v) const;

    // Perform edge percolation on the graph. p is the probability of failure
    Graph edgePercolation(double p) const;

    // Perform node percolation on the graph. p is the probability of failure
    Graph nodePercolation(double p) const;

    // Get number of nodes
    int getNbNodes() const;

    // Get the number of edges
    int getNbEdges() const;
    
    // Get the number of connected components
    int connectedComponents() const;

    // Display the graph
    void displayGraph() const;

private:
    int n;  // Number of nodes
    std::vector<std::vector<int>> adjList;  // Adjacency list

    // Helper function for DFS traversal
    void dfs(int start, std::vector<bool>& visited) const;

    // Helper function for BFS traversal
    void bfs(int start, std::vector<bool>& visited) const;
};