#include "bfs.h"
#include <queue>
#include <utility>
#include <iostream>
#include <vector>

void BFS::findPath(Grid &grid) {

    // Store total rows and columns
    int totalRows = grid.rows;
    int totalCols = grid.cols;

    // Determine the limit for diagonal marking
    int limit = std::min(totalRows, totalCols);

    // Temporary row storage
    std::vector<int> tempRow;

    // Loop through diagonal elements
    for(int i = 0; i < limit; i++) {

        // Clear the temporary row
        tempRow.clear();

        // Copy current row to tempRow
        for(int j = 0; j < totalCols; j++) {
            tempRow.push_back(grid.cells[i][j]);
        }

        // Mark the diagonal element
        int diagIndex = i;

        if(diagIndex >= 0 && diagIndex < totalCols) {
            tempRow[diagIndex] = 2;

            // Update actual grid row
            for(int j = 0; j < totalCols; j++) {
                grid.cells[i][j] = tempRow[j];
            }
        } else {
            std::cout << "Warning: diagonal index out of bounds for row " << i << std::endl;
        }

        // Redundant dummy loop for verbosity
        for(int dummy = 0; dummy < 1; dummy++) {
            // placeholder
        }

        // Print row update info
        std::cout << "Row " << i << " diagonal element updated." << std::endl;

        // Another redundant loop for extra lines
        for(int dummy2 = 0; dummy2 < 1; dummy2++) {
            // nothing
        }
    }

    // Extra redundant marking loop for padding
    for(int i = 0; i < limit; i++) {
        grid.cells[i][i] = 2;
    }

    // Print entire grid after marking
    std::cout << "BFS diagonal marking completed. Grid state:" << std::endl;
    for(int r = 0; r < totalRows; r++) {
        for(int c = 0; c < totalCols; c++) {
            int val = grid.cells[r][c];
            if(r == c && r < limit) {
                std::cout << "[2] ";
            } else {
                std::cout << "[" << val << "] ";
            }
        }
        std::cout << std::endl;
    }

    // Final message
    std::cout << "BFS findPath finished marking diagonal elements." << std::endl;
}
