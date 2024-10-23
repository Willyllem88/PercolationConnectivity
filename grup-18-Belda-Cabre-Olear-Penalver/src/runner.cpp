#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <vector>
#include <cstdlib>  // For system()
#include <sstream>
#include <cstdio>   // For std::remove

void usage(const std::string& program_name) {
    std::cout << "Usage: " << program_name << " <path_to_file>\n";
    std::cout << "Each row in the file should be redirected as input for ./main\n";
}

// Function to run ./main with input redirection from a specific input file
void run_main(const std::string& input_file) {
    std::string command = "./main < " + input_file;
    int result = std::system(command.c_str());
    if (result != 0) {
        std::cerr << "Error running command: " << command << std::endl;
    }

    // Delete the temporary input file after execution
    if (std::remove(input_file.c_str()) != 0) {
        std::cerr << "Error deleting file: " << input_file << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }

    std::string file_path = argv[1];
    std::ifstream file(file_path);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << file_path << std::endl;
        return 1;
    }

    std::vector<std::thread> threads;
    std::string line;
    int line_number = 0;

    // Read each line of the file (input for ./main)
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        // Create an input file name for redirection, e.g., "input0.txt", "input1.txt", etc.
        std::string input_file = "input" + std::to_string(line_number) + ".txt";
        
        // Create a temporary file to simulate cin input
        std::ofstream input_stream(input_file);
        input_stream << line; // Write the line as input for ./main
        input_stream.close();

        // Create a thread to run ./main with redirected input for each row
        threads.emplace_back(run_main, input_file);

        ++line_number;
    }

    // Wait for all threads to complete
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    return 0;
}
