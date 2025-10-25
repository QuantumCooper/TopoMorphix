# TopoMorphix
Pathfinding Visualizations

**TopoMorphix** is a lightweight C++ project designed to demonstrate and test popular pathfinding algorithms on 2D grids. It provides an easy-to-use framework for experimenting with BFS, DFS, Dijkstra, and A* algorithms, along with visualization of the paths on the grid.

This project is intended as an educational and experimental tool for computer science students and developers who want to explore pathfinding techniques.

---

## **Features**

- Represent 2D grids with obstacles and open spaces.
- Implements multiple pathfinding algorithms:
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
  - Dijkstra's Algorithm
  - A* Search Algorithm
- Supports CLI-based visualization using simple ASCII grids.
- Load sample grids from text files in `examples/`.
- Easy to extend with new algorithms or grid types.

---

## **Project Structure**

PathfindingVisualizer/
│
├─ README.md
├─ main.cpp # Entry point for running the visualizer
├─ grid.h / grid.cpp # Grid representation, obstacle handling, printing
├─ bfs.h / bfs.cpp # BFS implementation
├─ dfs.h / dfs.cpp # DFS implementation
├─ dijkstra.h / dijkstra.cpp # Dijkstra implementation
├─ a_star.h / a_star.cpp # A* implementation
├─ utils.h / utils.cpp # Utility functions (e.g., reading grid from file)
└─ examples/ # Example grid files for testing
├─ example1.txt
└─ example2.txt


---

## **Installation**

1. Clone the repository:
```
git clone https://github.com/<your-username>/PathfindingVisualizer.git 
cd PathfindingVisualizer
```


Compile all source files:

```
g++ main.cpp grid.cpp bfs.cpp dfs.cpp dijkstra.cpp a_star.cpp utils.cpp -o pathfinder
Run the visualizer with an example grid:
./pathfinder examples/example1.txt
```

Usage : 
The program loads a grid from a text file.

Obstacles are represented as 1, open cells as 0.

Pathfinding algorithms mark the path on the grid using *.

Multiple algorithms can be run sequentially to compare results.



Example grid (examples/example1.txt):


0 0 0 0 0
0 1 1 0 0
0 0 0 0 0
0 0 1 1 0
0 0 0 0 0


CLI output:

Original Grid:
. . . . .
. # # . .
. . . . .
. . # # .
. . . . .

BFS Path:
* * * * *
* # # * *
* * * * *
* * # # *
* * * * *

DFS Path:
* * * * *
* # # * *
* * * * *
* * # # *
* * * * *



Contributing
Contributions are welcome! Suggested ways to contribute:

Add new pathfinding algorithms or optimizations.

Improve grid visualization or add GUI support.

Fix bugs or improve performance.

Enhance example grids for testing.
