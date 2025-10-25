#include "dijkstra.h"
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>

struct Node {
    int row;
    int col;
    int distance;
    Node(int r, int c, int d)
        : row(r), col(c), distance(d) {}
};

struct CompareNode {
    bool operator()(const Node &a, const Node &b) const {
        return a.distance > b.distance;
    }
};

Dijkstra::Dijkstra() {
    allowDiagonal = false;
}

void Dijkstra::setDiagonalMovement(bool enable) {
    allowDiagonal = enable;
}

bool Dijkstra::isWalkable(Grid &grid, int r, int c) {
    return grid.isValid(r, c) &&
           grid.cells[r][c] != grid.OBSTACLE;
}

bool Dijkstra::isDestination(Grid &grid, int r, int c) {
    return r == grid.endRow && c == grid.endCol;
}

int Dijkstra::cost(Grid &grid, int r, int c) {
    return 1; // can extend for weighted grids
}

void Dijkstra::reconstructPath(
        Grid &grid,
        std::vector<std::vector<std::pair<int, int>>> &parent) {
    int r = grid.endRow;
    int c = grid.endCol;

    std::vector<std::pair<int, int>> path;

    while(!(r == grid.startRow && c == grid.startCol)) {
        path.push_back({r, c});
        auto p = parent[r][c];
        r = p.first;
        c = p.second;
    }
    path.push_back({grid.startRow, grid.startCol});

    std::reverse(path.begin(), path.end());

    for(auto &cell : path) {
        int pr = cell.first;
        int pc = cell.second;

        if(grid.cells[pr][pc] != grid.START && grid.cells[pr][pc] != grid.END) {
            grid.cells[pr][pc] = grid.PATH;
        }
    }
}

void Dijkstra::markVisited(Grid &grid, int r, int c) {
    if(grid.cells[r][c] != grid.START &&
       grid.cells[r][c] != grid.END &&
       grid.cells[r][c] != grid.PATH) {
        grid.cells[r][c] = grid.VISITED;
    }
}

void Dijkstra::markFrontier(Grid &grid, int r, int c) {
    if(grid.cells[r][c] != grid.START &&
       grid.cells[r][c] != grid.END &&
       grid.cells[r][c] != grid.PATH) {
        grid.cells[r][c] = grid.FRONTIER;
    }
}

void Dijkstra::findPath(Grid &grid) {
    int rows = grid.rows;
    int cols = grid.cols;

    if(!grid.isValid(grid.startRow, grid.startCol) ||
       !grid.isValid(grid.endRow, grid.endCol)) {
        std::cout << "Invalid start or end" << std::endl;
        return;
    }

    std::vector<std::vector<int>> distance(
        rows, std::vector<int>(cols, std::numeric_limits<int>::max()));

    std::vector<std::vector<bool>> visited(
        rows, std::vector<bool>(cols, false));

    std::vector<std::vector<std::pair<int, int>>> parent(
        rows, std::vector<std::pair<int, int>>(cols, {-1, -1}));

    std::priority_queue<Node, std::vector<Node>, CompareNode> pq;

    distance[grid.startRow][grid.startCol] = 0;
    pq.push(Node(grid.startRow, grid.startCol, 0));

    std::vector<std::pair<int, int>> directions;

    directions.push_back({-1, 0});
    directions.push_back({1, 0});
    directions.push_back({0, -1});
    directions.push_back({0, 1});

    if(allowDiagonal) {
        directions.push_back({-1, -1});
        directions.push_back({-1, 1});
        directions.push_back({1, -1});
        directions.push_back({1, 1});
    }

    bool pathFound = false;

    while(!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int r = current.row;
        int c = current.col;

        if(visited[r][c]) {
            continue;
        }

        visited[r][c] = true;
        markVisited(grid, r, c);

        if(isDestination(grid, r, c)) {
            pathFound = true;
            break;
        }

        for(auto &d : directions) {
            int nr = r + d.first;
            int nc = c + d.second;

            if(isWalkable(grid, nr, nc)) {
                int newCost = distance[r][c] + cost(grid, nr, nc);

                if(newCost < distance[nr][nc]) {
                    distance[nr][nc] = newCost;
                    parent[nr][nc] = {r, c};
                    pq.push(Node(nr, nc, newCost));
                    markFrontier(grid, nr, nc);
                }
            }
        }
    }

    if(pathFound) {
        reconstructPath(grid, parent);
        grid.cells[grid.startRow][grid.startCol] = grid.START;
        grid.cells[grid.endRow][grid.endCol] = grid.END;
        std::cout << "Path found using Dijkstra" << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
}
