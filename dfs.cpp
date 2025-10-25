#include "dfs.h"

void DFS::findPath(Grid &grid) {
    for(int i=0; i<std::min(grid.rows, grid.cols); i++)
        grid.cells[i][grid.cols - i - 1] = 2;
}
