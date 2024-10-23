#include "graph.hpp"

// Constants
namespace Options {
    static int RGN;
    static int MIN_NB_NODES;
    static int MAX_NB_NODES;
    static int NB_NODES_STEP;
    static std::string PERC_MODE; // Percolation Mode, (EDGE_PERC, NODE_PERC)
    static int TRIES_PER_P; // Number of tries for each value of p
    static std::string CSV_FILE = "data/results.csv";
    static std::function<Graph(int)> GRAPH_GENERATOR;
}

// Struct for CSV entry
struct CSVEntry {
    double p;
    int n;
    double connectedPercentatge;

    // Serialize CSV entry to string
    std::string toCSVString() const {
        return std::to_string(p) + ";" + std::to_string(n) + ";" + std::to_string(connectedPercentatge);
    }


    // Print CSV entry to console with tabs
    std::string printEntry() const {
        return "p: " + std::to_string(p) + " \n: " + std::to_string(n) + " \tconnectedPercentatge: " + std::to_string(connectedPercentatge);
    }
};

// Write CSV header
void writeCSVHeader(std::ofstream& csvFile) {
    csvFile << "p;n;connectedGraphsPercentatge" << std::endl;
}

// Write CSV entry
void writeCSVEntry(std::ofstream& csvFile, const CSVEntry& entry) {
    csvFile << entry.toCSVString() << std::endl;
}

std::function<Graph(int)> selectGraphAlgorithm() {
    std::string choice;

    std::cout << "Select the graph generation algorithm:\n";
    std::cout << "[Erdos-Renyi]\n";
    std::cout << "[Square-Grid]\n";
    std::cout << "[Triangular-Grid]\n";
    std::cout << "[Random-Geometric]\n";
    std::cout << "[Barabasi-Albert]\n";
    std::cin >> choice;
    
    if (choice == "Erdos-Renyi") {
        double p;
        std::cout << "Enter p: ";
        std::cin >> p;
        return [p](int n) { return Graph::generateRandomGraph_ErdosRenyi(n, p); };
    }
    else if (choice == "Square-Grid") {
        return [](int m) { return Graph::generateSquareGridGraph(m); };
    }
    else if (choice == "Triangular-Grid") {
        return [](int rows) { return Graph::generateTriangularGridGraph(rows); };
    }
    else if (choice == "Random-Geometric") {
        double r;
        std::cout << "Enter r: ";
        std::cin >> r;
        return [r](int n) { return Graph::generateRandomGeometricGraph(n, r); };
    }
    else if (choice == "Barabasi-Albert") {
        int m0, m;
        std::cout << "Enter m0 and m: ";
        std::cin >> m0 >> m;
        return [m0, m](int n) { return Graph::generateRandom_BarabasiAlbert(n, m0, m); };
    }
    else {
        errorAndExit(choice + " is not a valid generation algoritm");
        return nullptr;
    }
}

// Selects options
void selectOptions() {
    std::cout << "Enter the seed for the random number generator: ";
    std::cin >> Options::RGN;

    std::cout << "Enter the minimum number of nodes: ";
    std::cin >> Options::MIN_NB_NODES;

    std::cout << "Enter the maximum number of nodes: ";
    std::cin >> Options::MAX_NB_NODES;

    std::cout << "Enter the step for the number of nodes: ";
    std::cin >> Options::NB_NODES_STEP;

    std::cout << "Enter the number of tries per p: ";
    std::cin >> Options::TRIES_PER_P;

    std::cout << "Select the percolation mode [EDGE_PERC | NODE_PERC]: ";
    std::cin >> Options::PERC_MODE;
    if (Options::PERC_MODE != "EDGE_PERC" && Options::PERC_MODE != "NODE_PERC")
        errorAndExit(Options::PERC_MODE + " is not a valid percolation mode");

    std::cout << "Enter the path of the CSV file: ";
    std::cin >> Options::CSV_FILE;

    //Select the algorithm
    Options::GRAPH_GENERATOR = selectGraphAlgorithm();
}

// Main function
int main() {
    // Select options
    selectOptions();

    // Seed the random number generator
    srand(Options::RGN);

    // Write CSV header, first an info about the constants
    std::ofstream csvFile(Options::CSV_FILE);
    writeCSVHeader(csvFile);
    
    for (int n = Options::MIN_NB_NODES; n <= Options::MAX_NB_NODES; n += Options::NB_NODES_STEP) {
        for (int step = 0; step <= 100; ++step) {
            // Calculate the value of q from the number of steps, to avoid losing precision
            double p = step * 0.01; //Probability of not failure

            int connectedCount = 0;
            for (int i = 0; i < Options::TRIES_PER_P; ++i) {
                Graph G;

                // Keep generating random graphs until you get a connected graph
                while (true) {
                    // Generate a random graph
                    G = Options::GRAPH_GENERATOR(n);

                    // Check if the graph is connected, if not, continue
                    if (G.connectedComponents() == 1) break;
                }

                // Check if the graph is connected, if not, continue
                if (G.connectedComponents() != 1) continue;

                // Perform node percolation on the graph
                Graph Gp;
                if (Options::PERC_MODE == "EDGE_PERC")
                    Gp = G.edgePercolation(p);
                else
                    Gp = G.nodePercolation(p);

                if (Gp.connectedComponents() == 1) ++connectedCount;
            }

            // Write CSV entry
            CSVEntry entry = {p, n, (double)connectedCount / Options::TRIES_PER_P};
            writeCSVEntry(csvFile, entry);
            std::cout << entry.printEntry() << std::endl;
        }
    }

    return 0;
}
