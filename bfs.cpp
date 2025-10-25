#include "bfs.h"
#include <queue>
#include <utility>

void BFS::findPath(Grid &grid) {
    
    for(int i=0; i<std::min(grid.rows, grid.cols); i++)
        grid.cells[i][i] = 2;
}
