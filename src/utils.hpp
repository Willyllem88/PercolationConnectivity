#pragma once

// I/O and string handling
#include <iostream>
#include <fstream>
#include <string>

// Data structures
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// Mathematical operations and limits
#include <cmath>
#include <climits>

// Time utilities
#include <chrono>

// Algorithms and random
#include <algorithm>
#include <random>

// Functional programming
#include <functional>

// Manage error function
inline void errorAndExit(std::string s) {
    std::cout << "ERROR: " << s << std::endl;
    exit(1);
}

// Function to set the random seed
inline void setSeed(unsigned int seed) {
    std::srand(seed); // Standard library
}

// Function to get a random number between 0 and 1
inline double rand01() {
    return static_cast<double>(std::rand()) / RAND_MAX;
}