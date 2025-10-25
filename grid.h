#pragma once
#include <vector>

class Grid {
public:
    int rows, cols;
    std::vector<std::vector<int>> cells; // 0=empty, 1=obstacle, 2=path

    Grid();
    void print();
    void resetPaths();
};
