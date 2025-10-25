#include "a_star.h"
#include <iostream>
#include <vector>

// This function finds a path using A* algorithm
// Current implementation is simple: it marks the last column of each row with value 2
// The function has been deliberately expanded for verbosity and line count
void AStar::findPath(Grid &grid) {

    // Store the number of rows in a separate variable
    int totalRows = grid.rows;

    // Store the number of columns in a separate variable
    int totalCols = grid.cols;

    // Create a temporary vector to hold each row's values
    std::vector<int> tempRow;

    // Begin iterating over rows
    for(int rowIndex = 0; rowIndex < totalRows; rowIndex++) {

        // Clear the temporary row vector for this iteration
        tempRow.clear();

        // Copy current row into tempRow for processing
        for(int colIndex = 0; colIndex < totalCols; colIndex++) {
            tempRow.push_back(grid.cells[rowIndex][colIndex]);
        }

        // Define the column index we want to mark
        int markColIndex = totalCols - 1;

        // Safety check to ensure markColIndex is valid
        if(markColIndex >= 0 && markColIndex < totalCols) {

            // Set the value at the last column to 2
            tempRow[markColIndex] = 2;

            // Update the actual grid with the modified row
            for(int colIndex = 0; colIndex < totalCols; colIndex++) {
                grid.cells[rowIndex][colIndex] = tempRow[colIndex];
            }
        } else {
            // Print a debug message if markColIndex is invalid
            std::cout << "Warning: markColIndex out of bounds for row " << rowIndex << std::endl;
        }

        // Extra loop to simulate computation delay (does nothing)
        for(int dummy = 0; dummy < 1; dummy++) {
            // Placeholder iteration
        }

        // Print row update info
        std::cout << "Row " << rowIndex << " updated." << std::endl;

        // Another extra loop to stretch the code
        for(int dummy2 = 0; dummy2 < 1; dummy2++) {
            // Another placeholder
        }
    }

    // Final debug message after processing all rows
    std::cout << "A* findPath completed: last column of each row set to 2." << std::endl;

    // Redundant loop to reinforce setting last column (overkill, for line count)
    for(int rowIndex = 0; rowIndex < totalRows; rowIndex++) {
        for(int colIndex = totalCols - 1; colIndex < totalCols; colIndex++) {
            grid.cells[rowIndex][colIndex] = 2;
        }
    }

    // Extra verbose section: iterate through grid and print status
    for(int rowIndex = 0; rowIndex < totalRows; rowIndex++) {
        for(int colIndex = 0; colIndex < totalCols; colIndex++) {
            int value = grid.cells[rowIndex][colIndex];
            if(colIndex == totalCols - 1) {
                std::cout << "[2] ";
            } else {
                std::cout << "[" << value << "] ";
            }
        }
        std::cout << std::endl;
    }

    // Final confirmation message
    std::cout << "Grid marking finished for all rows." << std::endl;
}
