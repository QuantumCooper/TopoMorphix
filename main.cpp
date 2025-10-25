#include <iostream>
#include <string>
#include "grid.h"
#include "bfs.h"
#include "dfs.h"
#include "dijkstra.h"
#include "a_star.h"
#include "utils.h"

// Function to display the main menu
void displayMenu() {
    std::cout << "==================== Pathfinder Menu ====================" << std::endl;
    std::cout << "1. Run BFS" << std::endl;
    std::cout << "2. Run DFS" << std::endl;
    std::cout << "3. Run Dijkstra" << std::endl;
    std::cout << "4. Run A* Search" << std::endl;
    std::cout << "5. Toggle diagonal movement" << std::endl;
    std::cout << "6. Reload grid" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "=========================================================" << std::endl;
}

// Function to print grid metrics
void printGridMetrics(Grid &grid) {
    int pathLength = grid.calculatePathLength();
    int visitedCells = grid.countVisited();
    std::cout << "Path Length: " << pathLength << std::endl;
    std::cout << "Visited Cells: " << visitedCells << std::endl;
}

// Function to run a chosen algorithm
void runAlgorithm(int choice, Grid &grid, Dijkstra &dijkstra) {
    switch(choice) {
        case 1: {
            BFS bfs;
            std::cout << "\nRunning BFS..." << std::endl;
            bfs.findPath(grid);
            grid.print();
            printGridMetrics(grid);
            break;
        }
        case 2: {
            DFS dfs;
            std::cout << "\nRunning DFS..." << std::endl;
            dfs.findPath(grid);
            grid.print();
            printGridMetrics(grid);
            break;
        }
        case 3: {
            std::cout << "\nRunning Dijkstra..." << std::endl;
            dijkstra.findPath(grid);
            grid.print();
            printGridMetrics(grid);
            break;
        }
        case 4: {
            AStar aStar;
            std::cout << "\nRunning A* Search..." << std::endl;
            aStar.findPath(grid);
            grid.print();
            printGridMetrics(grid);
            break;
        }
        case 5: {
            dijkstra.setDiagonalMovement(!dijkstra.isDiagonalAllowed());
            std::cout << "Diagonal movement set to: "
                      << (dijkstra.isDiagonalAllowed() ? "ENABLED" : "DISABLED") 
                      << std::endl;
            break;
        }
        default:
            std::cout << "Invalid choice!" << std::endl;
    }
}

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

    Dijkstra dijkstra;

    bool running = true;
    while(running) {
        std::cout << "\nCurrent Grid:" << std::endl;
        grid.print();

        displayMenu();
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch(choice) {
            case 0:
                running = false;
                std::cout << "Exiting Pathfinder..." << std::endl;
                break;
            case 6: {
                std::string fileName;
                std::cout << "Enter grid file to reload: ";
                std::cin >> fileName;
                if(loadGridFromFile(fileName, grid)) {
                    std::cout << "Grid reloaded successfully." << std::endl;
                } else {
                    std::cout << "Failed to reload grid." << std::endl;
                }
                break;
            }
            default:
                runAlgorithm(choice, grid, dijkstra);
                break;
        }
    }

    std::cout << "Thank you for using Pathfinder!" << std::endl;
    return 0;
}
