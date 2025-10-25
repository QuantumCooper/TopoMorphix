#include "grid.h"
#include <iostream>

Grid::Grid() : rows(0), cols(0) {}

void Grid::print() {
    for(auto &row : cells) {
        for(auto &cell : row) {
            if(cell == 0) std::cout << ". ";
            else if(cell == 1) std::cout << "# ";
            else if(cell == 2) std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

void Grid::resetPaths() {
    for(auto &row : cells)
        for(auto &cell : row)
            if(cell == 2) cell = 0;
}
