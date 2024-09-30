#include "graph.hpp"

// Constants
static constexpr int RGN = 1321312;
static constexpr int NB_NODES = 100;
static constexpr double RANDOM_GRAPH_P = 0.2; // 0 = no edges (empty graph), 1 = all edges (complete graph)
static constexpr int TRIES_PER_P = 1000; // Number of tries for each value of p
const std::string CSV_FILE = "results.csv";

// Struct for CSV entry
struct CSVEntry {
    double p;
    int connectedCount;
    int notConnectedCount;

    // Serialize CSV entry to string
    std::string toCSVString() const {
        return std::to_string(p) + ";" + std::to_string(connectedCount) + ";" + std::to_string(notConnectedCount);
    }


    // Print CSV entry to console with tabs
    std::string printEntry() const {
        return "p: " + std::to_string(p) + " \tConnected: " + std::to_string(connectedCount) + " \tNot connected: " + std::to_string(notConnectedCount);
    }
};

// Write CSV header
void writeCSVHeader(std::ofstream& csvFile) {
    csvFile << "NB_NODES: " << NB_NODES << std::endl;
    csvFile << "RANDOM_GRAPH_P: " << RANDOM_GRAPH_P << std::endl;
    csvFile << "TRIES_PER_P: " << TRIES_PER_P << std::endl << std::endl;
    csvFile << "p;Connected;Not connected" << std::endl;
}

// Write CSV entry
void writeCSVEntry(std::ofstream& csvFile, const CSVEntry& entry) {
    csvFile << entry.toCSVString() << std::endl;
}

// Main function
int main(int argc, char* argv[]) {
    // Seed the random number generator
    srand(RGN);

    // Write CSV header, first an info about the constants
    std::ofstream csvFile(CSV_FILE);
    writeCSVHeader(csvFile);
    
    for (int step = 0; step <= 100; ++step) {
        // Calculate the value of q from the number of steps, to avoid losing precision
        double p = step * 0.01; //Probability of failure

        int connectedCount = 0;

        for (int i = 0; i < TRIES_PER_P; ++i) {
            Graph G;

            // Keep generating random graphs until you get a connected graph
            while (true) {
                // Generate a random graph G(n, p)
                G = Graph::generateRandomGraph(NB_NODES, RANDOM_GRAPH_P);

                // Check if the graph is connected, if not, continue
                if (G.connectedComponents() == 1) break;
            }

            // Check if the graph is connected, if not, continue
            if (G.connectedComponents() != 1) continue;

            // Perform node percolation on the graph
            Graph Gp = G.edgePercolation(p);

            if (Gp.connectedComponents() == 1) ++connectedCount;
        }

        // Write CSV entry
        CSVEntry entry = {p, connectedCount, TRIES_PER_P - connectedCount};
        writeCSVEntry(csvFile, entry);
        std::cout << entry.printEntry() << std::endl;
    }

    return 0;
}
