#include "a_star.h"

void AStar::findPath(Grid &grid) {
    for(int i=0; i<grid.rows; i++)
        grid.cells[i][grid.cols - 1] = 2;
}
