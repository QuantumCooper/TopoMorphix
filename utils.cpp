#include "utils.h"
#include <fstream>
#include <sstream>

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
