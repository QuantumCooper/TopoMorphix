#include "dijkstra.h"

void Dijkstra::findPath(Grid &grid) {
    for(int i=0; i<grid.rows; i++)
        grid.cells[i][0] = 2;
}
