#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1) return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1) return false;

    return true;
}

void printBoard(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int N, int &count) {
    if (row == N) {
        count++;
        printBoard(board, N);
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            res = solveNQueensUtil(board, row + 1, N, count) || res;
            board[row][col] = 0;
        }
    }
    return res;
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));
    int count = 0;
    if (!solveNQueensUtil(board, 0, N, count))
        cout << "No solution exists!" << endl;
    else
        cout << "Total solutions = " << count << endl;
}

int main() {
    int N;
    cout << "Enter value of N: ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
