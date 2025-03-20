#include <stdio.h>

#define SIZE 9

int grid[SIZE][SIZE];

// Function to check if placing a number is feasible
int feasible(int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        // Check row and column
        if (grid[row][x] == num || grid[x][col] == num) {
            return 0;
        }
    }
    // Check 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Recursive function to solve the Sudoku grid
int solveSudoku() {
    int i,j,empty = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {  // Find an empty cell
                empty = 1;
                break;
            }
        }
        if (empty==1) break;
    }
    // No empty cells left; Sudoku is solved
    if (empty==0) return 1;

    for (int num = 1; num <= SIZE; num++) {
        if (feasible(i, j, num)) {
            grid[i][j] = num;  // Place number
            if (solveSudoku()) return 1;
            grid[i][j] = 0;  // Backtrack
        }
    }
    return 0;
}

void printGrid() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the Sudoku grid (0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solveSudoku()) {
        printf("Solved Sudoku grid:\n");
        printGrid();
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}