// This program create input files for testing the different sorting methods.
#include <iostream>
#include <fstream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int file_sizes[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};

    // loops through each size and generates a file
    for (int size : file_sizes) {
        // constructs the filename based on the amount of integers
        std::string filename = "input_" + std::to_string(size) + ".txt";
        
        std::ofstream outfile(filename);

        if (!outfile.is_open()) {
            std::cerr << "Error: could not open file " << filename << std::endl;
            return 1;
        }

        // generates random integers and writes them to the file
        for (int i = 0; i < size; ++i) {
            int random_number = rand();  
            outfile << random_number << std::endl;  
        }

        outfile.close();
        std::cout << "Generated file: " << filename << " with " << size << " integers." << std::endl;
    }

    return 0;
}
