#pragma once 
#include "grid.h"
#include <queue>
#include <vector>

class BFS {
public:
    void findPath(Grid &grid);

private:
    std::queue<std::pair<int, int>> q; // Queue for BFS traversal
    std::vector<std::vector<bool>> visited; // Track visited cells
};
