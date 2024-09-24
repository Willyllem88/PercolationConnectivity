#include "graph.hpp"

#define RND_SEED 1321312

int main() {
    std::cout << " - Seed: " << RND_SEED << std::endl;
    setSeed(RND_SEED);

    Graph g;
    g = g.generateRandomGraph(10, 0.2);
    g.displayGraph();
    
    std::cout << "Number of connected components: " << g.connectedComponents() << std::endl;
    return 0;
}

//g++ -std=c++11 test.cpp graph.cpp -o test