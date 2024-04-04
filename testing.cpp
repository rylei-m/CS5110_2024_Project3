#include <iostream>
#include <vector>
#include <fstream> // Include for file I/O

int main() {
    std::ifstream inputFile("prog3A.txt"); // Open the input file

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    int numRows, numCols;
    // Read the number of actions for row and column players from the file
    inputFile >> numRows >> numCols;

    std::vector<std::vector<int>> rowPlayerRewards(numRows, std::vector<int>(numCols));
    std::vector<std::vector<int>> colPlayerRewards(numRows, std::vector<int>(numCols));

    // Read the rewards for the row player from the file
    for(int i = 0; i < numRows; ++i) {
        for(int j = 0; j < numCols; ++j) {
            inputFile >> rowPlayerRewards[i][j];
        }
    }

    // Read the rewards for the column player from the file
    for(int i = 0; i < numRows; ++i) {
        for(int j = 0; j < numCols; ++j) {
            inputFile >> colPlayerRewards[i][j];
        }
    }

    inputFile.close(); // Optional: Close the file explicitly

    // Optional: Print the rewards to verify the input
    std::cout << "Row Player Rewards:\n";
    for(int i = 0; i < numRows; ++i) {
        for(int j = 0; j < numCols; ++j) {
            std::cout << rowPlayerRewards[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Column Player Rewards:\n";
    for(int i = 0; i < numRows; ++i) {
        for(int j = 0; j < numCols; ++j) {
            std::cout << colPlayerRewards[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
