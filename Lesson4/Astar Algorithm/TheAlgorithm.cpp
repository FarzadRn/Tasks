/*
READABLE A* FOR YOUR MAZE.TXT (MSVC / C++14)

Maze format (each line same length):
  '*'  = wall / blocked
  ' '  = open space (walkable)
  'S'  = start
  'E'  = end/goal

This program:
  1) loads the maze
  2) runs A* with a Manhattan heuristic (4-direction movement)
  3) reconstructs the shortest path S?E
  4) draws that path with solid blocks (char(219))
  5) prints the maze

Everything is heavily commented for learning.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <cstdlib>   // std::abs

// --------- Types & constants -------------------------------------------------

// A single cell on the grid is addressed by (row, col).
// We'll store the maze as a vector<string> (grid[row][col] is a char).
typedef std::vector<std::string> MazeGrid;

// Visual for path drawing (?). Windows console shows char(219) as a solid block.
static constexpr char PATH_BLOCK = char(219);

// Return true if this character is walkable.
// We allow stepping onto ' ', 'S', and 'E'.
static inline bool isWalkable(char cellChar) {
    return cellChar == ' ' || cellChar == 'S' || cellChar == 'E';
}

// 4-neighbor Manhattan distance (admissible & consistent heuristic for 4-way moves).
// Heuristic h(n) = |r - goalR| + |c - goalC|
static inline int manhattan(int r, int c, int goalR, int goalC) {
    return std::abs(r - goalR) + std::abs(c - goalC);
}

// Priority-queue node for A*.
// We order by lowest f first. std::priority_queue is max-heap by default,
// so we invert comparison to make it behave like a min-heap on f.
struct OpenNode {
    int f;   // total estimated cost = g + h
    int g;   // cost so far from start
    int r;   // row
    int c;   // col

    bool operator<(const OpenNode& other) const {
        return f > other.f; // reverse (min-heap behavior)
    }
};

// --------- File loading ------------------------------------------------------

// Read maze file into grid. Also strip trailing '\r' (CRLF files).
// Returns false on failure.
static bool loadMaze(const std::string& filename, MazeGrid& outGrid) {
    std::ifstream in(filename);
    if (!in) return false;

    outGrid.clear();
    std::string line;
    while (std::getline(in, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back(); // handle CRLF
        outGrid.push_back(line);
    }
    return !outGrid.empty();
}

// Find coordinates of 'S' and 'E'. Return false if either missing.
static bool findStartAndEnd(const MazeGrid& grid,
    int& outStartR, int& outStartC,
    int& outEndR, int& outEndC) {
    outStartR = outStartC = outEndR = outEndC = -1;
    const int rows = (int)grid.size();
    const int cols = (int)grid[0].size();

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 'S') { outStartR = r; outStartC = c; }
            if (grid[r][c] == 'E') { outEndR = r; outEndC = c; }
        }
    }
    return (outStartR >= 0 && outEndR >= 0);
}

// --------- A* search ---------------------------------------------------------

/*
A* on a 4-neighbor grid:

- g[r][c]  = best-known cost from start to (r,c).
- parentR/parentC = predecessor cell for path reconstruction.
- openSet (priority_queue) orders cells by f = g + h (lowest first).
- We pop the best-looking cell, relax its neighbors, and stop when we reach E.

Correctness notes:
- With manhattan() on a 4-direction grid, the heuristic is admissible/consistent,
  so A* finds an optimal (shortest) path and never overestimates.
*/
static bool aStarShortestPath(const MazeGrid& grid,
    int startR, int startC,
    int endR, int endC,
    std::vector<std::vector<int>>& parentR,
    std::vector<std::vector<int>>& parentC) {
    const int rows = (int)grid.size();
    const int cols = (int)grid[0].size();

    // Initialize g (cost-so-far) with +? (a large number).
    const int INF = std::numeric_limits<int>::max() / 4;
    std::vector<std::vector<int>> g(rows, std::vector<int>(cols, INF));

    // Parents: initialize to -1 (no parent).
    parentR.assign(rows, std::vector<int>(cols, -1));
    parentC.assign(rows, std::vector<int>(cols, -1));

    // Movement deltas for Up, Down, Left, Right.
    const int dRow[4] = { -1, 1, 0, 0 };
    const int dCol[4] = { 0, 0,-1, 1 };

    // Open set (frontier) ordered by minimal f.
    std::priority_queue<OpenNode> openSet;

    // Seed with the start cell.
    g[startR][startC] = 0;
    int hStart = manhattan(startR, startC, endR, endC);
    openSet.push(OpenNode{ hStart, 0, startR, startC });

    // Standard A* loop.
    while (!openSet.empty()) {
        OpenNode best = openSet.top();
        openSet.pop();

        const int r = best.r;
        const int c = best.c;
        const int gHere = best.g;

        // If this queue entry is stale (we already found a better g), skip it.
        if (gHere != g[r][c]) continue;

        // Goal test: we reached E — shortest path found.
        if (r == endR && c == endC) return true;

        // Relax 4 neighbors (grid bounds + walkable).
        for (int k = 0; k < 4; ++k) {
            int nr = r + dRow[k];
            int nc = c + dCol[k];

            // Bounds check.
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            // Blocked?
            if (!isWalkable(grid[nr][nc])) continue;

            // Cost of stepping is 1 (uniform grid).
            const int tentativeG = gHere + 1;

            // If this is a better path to (nr,nc), record it and push to open set.
            if (tentativeG < g[nr][nc]) {
                g[nr][nc] = tentativeG;
                parentR[nr][nc] = r;
                parentC[nr][nc] = c;

                const int h = manhattan(nr, nc, endR, endC);
                const int f = tentativeG + h;
                openSet.push(OpenNode{ f, tentativeG, nr, nc });
            }
        }
    }

    // Open set exhausted without reaching E ? no path.
    return false;
}

// Reconstruct path from E back to S using parent arrays.
// Any ' ' on the path becomes PATH_BLOCK (?). Keep 'S' and 'E' as-is.
static void drawPathOnGrid(MazeGrid& grid,
    const std::vector<std::vector<int>>& parentR,
    const std::vector<std::vector<int>>& parentC,
    int startR, int startC,
    int endR, int endC) {
    int r = endR;
    int c = endC;
    while (!(r == startR && c == startC)) {
        if (grid[r][c] == ' ') grid[r][c] = PATH_BLOCK;
        int pr = parentR[r][c];
        int pc = parentC[r][c];
        // If pr/pc is -1 unexpectedly, the path is broken; stop safely.
        if (pr < 0 || pc < 0) break;
        r = pr; c = pc;
    }
}

// --------- Main --------------------------------------------------------------

int main() {
    // 1) Load maze
    MazeGrid grid;
    if (!loadMaze("Maze2.txt", grid)) {
        std::cerr << "Failed to open Maze.txt or file is empty.\n";
        return 1;
    }

    // Sanity: all rows should be the same width for indexing to be valid.
    const int rows = (int)grid.size();
    const int cols = (int)grid[0].size();
    for (int r = 1; r < rows; ++r) {
        if ((int)grid[r].size() != cols) {
            std::cerr << "Maze.txt has ragged rows (different line lengths).\n";
            return 1;
        }
    }

    // 2) Find S and E
    int startR, startC, endR, endC;
    if (!findStartAndEnd(grid, startR, startC, endR, endC)) {
        std::cerr << "Maze must contain both 'S' (start) and 'E' (end).\n";
        return 1;
    }

    // 3) Run A*
    std::vector<std::vector<int>> parentR, parentC;
    const bool found = aStarShortestPath(grid, startR, startC, endR, endC, parentR, parentC);

    // 4) Draw path if found
    if (found) {
        drawPathOnGrid(grid, parentR, parentC, startR, startC, endR, endC);
    }
    else {
        std::cerr << "No path found from S to E.\n";
    }

    // 5) Print result
    for (int r = 0; r < rows; ++r) {
        std::cout << grid[r] << "\n";
    }

    return 0;
}