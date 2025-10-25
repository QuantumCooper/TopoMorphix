#include <iostream>
#include "grid.h"
#include "bfs.h"
#include "dfs.h"
#include "dijkstra.h"
#include "a_star.h"
#include "utils.h"

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "Usage: ./pathfinder <grid_file>" << std::endl;
        return 1;
    }

    Grid grid;
    if(!loadGridFromFile(argv[1], grid)) {
        std::cout << "Failed to load grid from file." << std::endl;
        return 1;
    }

    std::cout << "Original Grid:" << std::endl;
    grid.print();

    std::cout << "\nBFS Path:" << std::endl;
    BFS bfs;
    bfs.findPath(grid);
    grid.print();

    std::cout << "\nDFS Path:" << std::endl;
    DFS dfs;
    dfs.findPath(grid);
    grid.print();

    return 0;
}
