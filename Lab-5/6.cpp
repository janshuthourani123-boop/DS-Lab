#include <iostream>
using namespace std;

#define N 4

void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int x, int y, int maze[N][N], int visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && visited[x][y] == 0);
}

bool solveMazeUtil(int x, int y, int maze[N][N], int visited[N][N], int sol[N][N]) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    visited[x][y] = 1;
    sol[x][y] = 1;

    int moveX[] = {1, 0, -1, 0};
    int moveY[] = {0, 1, 0, -1};

    for (int dir = 0; dir < 4; dir++) {
        int nextX = x + moveX[dir];
        int nextY = y + moveY[dir];
        if (isSafe(nextX, nextY, maze, visited)) {
            if (solveMazeUtil(nextX, nextY, maze, visited, sol))
                return true;
        }
    }

    sol[x][y] = 0;
    return false;
}

bool solveMaze(int maze[N][N]) {
    int sol[N][N] = {0};
    int visited[N][N] = {0};

    if (maze[0][0] == 0) {
        cout << "No path found" << endl;
        return false;
    }

    if (solveMazeUtil(0, 0, maze, visited, sol)) {
        printSolution(sol);
        return true;
    } else {
        cout << "No path found" << endl;
        return false;
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    solveMaze(maze);
    return 0;
}
