#include "utils.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

// Load grid from file
bool loadGridFromFile(const std::string &filename, Grid &grid) {
    std::ifstream file(filename);
    if(!file.is_open()) return false;

    std::string line;
    grid.cells.clear();
    while(std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        int val;
        while(ss >> val) row.push_back(val);
        grid.cells.push_back(row);
    }
    grid.rows = grid.cells.size();
    grid.cols = grid.rows ? grid.cells[0].size() : 0;
    return true;
}

// Save grid to file
bool saveGridToFile(const std::string &filename, const Grid &grid) {
    std::ofstream file(filename);
    if(!file.is_open()) return false;

    for(int r = 0; r < grid.rows; r++) {
        for(int c = 0; c < grid.cols; c++) {
            file << grid.cells[r][c];
            if(c != grid.cols - 1) file << " ";
        }
        file << "\n";
    }
    return true;
}

// Print grid to console with formatting
void printGrid(const Grid &grid) {
    for(int r = 0; r < grid.rows; r++) {
        for(int c = 0; c < grid.cols; c++) {
            std::cout << std::setw(2) << grid.cells[r][c] << " ";
        }
        std::cout << std::endl;
    }
}

// Reset grid to initial state
void resetGrid(Grid &grid) {
    for(int r = 0; r < grid.rows; r++) {
        for(int c = 0; c < grid.cols; c++) {
            if(grid.cells[r][c] != grid.START && grid.cells[r][c] != grid.END)
                grid.cells[r][c] = grid.EMPTY;
        }
    }
}

// Count path cells
int countPathCells(const Grid &grid) {
    int count = 0;
    for(int r = 0; r < grid.rows; r++)
        for(int c = 0; c < grid.cols; c++)
            if(grid.cells[r][c] == grid.PATH) count++;
    return count;
}

// Count visited cells
int countVisitedCells(const Grid &grid) {
    int count = 0;
    for(int r = 0; r < grid.rows; r++)
        for(int c = 0; c < grid.cols; c++)
            if(grid.cells[r][c] == grid.VISITED) count++;
    return count;
}

// Check if coordinates are valid within the grid
bool isValidCell(const Grid &grid, int r, int c) {
    return r >= 0 && r < grid.rows && c >= 0 && c < grid.cols;
}

// Calculate total path length (sum of Manhattan distances for path cells)
int calculatePathLength(const Grid &grid) {
    int length = 0;
    for(int r = 0; r < grid.rows; r++) {
        for(int c = 0; c < grid.cols; c++) {
            if(grid.cells[r][c] == grid.PATH) length++;
        }
    }
    return length;
}
