#include "a_star.h"
#include <queue>
#include <vector>
#include <cmath>
#include <utility>

struct Node {
    int x, y;
    int cost, priority;
    bool operator>(const Node &other) const { return priority > other.priority; }
};

int heuristic(int x1,int y1,int x2,int y2) {
    // Euclidean distance
    return std::sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void AStar::findPath(Grid &grid) {
    grid.resetPaths();
    if(grid.rows==0 || grid.cols==0) return;

    std::priority_queue<Node,std::vector<Node>,std::greater<Node>> pq;
    pq.push({0,0,0,0});
    std::vector<std::vector<bool>> visited(grid.rows,std::vector<bool>(grid.cols,false));

    int targetX = grid.rows-1;
    int targetY = grid.cols-1;
    int dx[8] = {-1,-1,-1,0,1,1,1,0};
    int dy[8] = {-1,0,1,1,1,0,-1,-1};

    while(!pq.empty()) {
        Node current = pq.top(); pq.pop();
        int x = current.x, y = current.y;
        if(x==targetX && y==targetY) break;
        if(visited[x][y]) continue;
        visited[x][y] = true;
        grid.cells[x][y] = 2;

        for(int i=0;i<8;i++){
            int nx = x+dx[i], ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<grid.rows && ny<grid.cols && !visited[nx][ny] && grid.cells[nx][ny]==0){
                int g = current.cost+1;
                int h = heuristic(nx,ny,targetX,targetY);
                pq.push({nx,ny,g,g+h});
            }
        }
    }
}
