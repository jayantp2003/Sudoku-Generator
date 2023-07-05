#include <iostream>
using namespace std;

const int N = 9;

bool findEmptyLocation(int grid[N][N], int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool isSafeInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isSafeInColumn(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isSafeInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    return isSafeInRow(grid, row, num) &&
           isSafeInColumn(grid, col, num) &&
           isSafeInBox(grid, row - row % 3, col - col % 3, num);
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    if (!findEmptyLocation(grid, row, col)) {
        return true; // All cells are filled, sudoku is solved.
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true; // Recursive call successful
            }

            grid[row][col] = 0; // Undo the current cell if the current configuration leads to a dead end
        }
    }
    return false; // Trigger backtracking
}

int main() {
    int grid[N][N];

    cout << "Enter the 9x9 Sudoku grid (0 for empty cells):\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    if (solveSudoku(grid)) {
        cout << "Sudoku solved:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists for the given Sudoku.\n";
    }

    return 0;
}
