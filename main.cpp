#include <iostream>
#include "graph.hpp"

static constexpr int RGN = 1321312;
static constexpr int N = 100;
static constexpr double RANDOM_GRAPH_P = 0.4;
static constexpr int TRIES_PER_P = 1000;

int main(int argc, char* argv[]) {
    // Seed the random number generator
    srand(RGN);

    const int n = 100;
    const double RG_prob = 0.4;

    // Número de pasos que deseas para q (de 0.0 a 1.0 en pasos de 0.01)
    const int steps = 101;
    
    for (int step = 0; step < steps; ++step) {
        // Calcula el valor de q a partir del número de pasos, para no perder presición
        double q = step * 0.01;

        int connectedCount = 0;

        for (int i = 0; i < TRIES_PER_P; ++i) {
            // Generar un grafo aleatorio G(n, p)
            std::cout << step << " - " << i << std::endl;
            Graph G = Graph::generateRandomGraph(n, RG_prob);

            // Check if the graph is connected, if not, continue
            if (G.connectedComponents() != 1) continue;

            // Realizar percolación de nodos en el grafo
            Graph Gp = G.nodePercolation(q);

            if (Gp.connectedComponents() == 1) ++connectedCount;
        }

        std::cout << "- q: " << q << " Connected: " << connectedCount << " Not connected: " << TRIES_PER_P - connectedCount << std::endl;
    }

    return 0;
}
