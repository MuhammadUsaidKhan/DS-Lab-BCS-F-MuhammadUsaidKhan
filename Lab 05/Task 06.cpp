#include <iostream>
using namespace std;
#define N 5   // Size of the maze
// Function to print the solution matrix
void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}
// Function to check if maze[x][y] is safe to move into
bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}
// Backtracking function to solve the maze
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N], bool visited[N][N]) {
    // If destination is reached
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y) && !visited[x][y]) {
        visited[x][y] = true;    // Mark current cell as visited
        sol[x][y] = 1;           // Mark current cell in solution path

        // Move Right
        if (solveMazeUtil(maze, x, y + 1, sol, visited)) return true;

        // Move Down
        if (solveMazeUtil(maze, x + 1, y, sol, visited)) return true;

        // Move Left
        if (solveMazeUtil(maze, x, y - 1, sol, visited)) return true;

        // Move Up
        if (solveMazeUtil(maze, x - 1, y, sol, visited)) return true;

        // Backtracking
        sol[x][y] = 0;
        visited[x][y] = false;
        return false;
    }
    return false;
}
int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1}
    };
    int sol[N][N] = { {0} };           // To store the path
    bool visited[N][N] = { {false} };  // To track visited cells
    if (!solveMazeUtil(maze, 0, 0, sol, visited)) {
        cout << "No path found!" << endl;
    } else {
        cout << "Path found:\n";
        printSolution(sol);
    }
    return 0;
}
