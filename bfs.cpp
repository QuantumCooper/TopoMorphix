#include "dfs.h"

void dfsUtil(Grid &grid, int x, int y) {
    if (x < 0 || y < 0 || x >= grid.rows || y >= grid.cols || grid.cells[x][y] != 0)
        return;

    grid.cells[x][y] = 2;

    int dx[8] = {-1,-1,-1,0,1,1,1,0};
    int dy[8] = {-1,0,1,1,1,0,-1,-1};

    for (int i = 0; i < 8; i++)
        dfsUtil(grid, x + dx[i], y + dy[i]);
}

void DFS::findPath(Grid &grid) {
    grid.resetPaths();
    dfsUtil(grid, 0, 0);
}
