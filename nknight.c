#include <stdio.h>
#include <stdlib.h>

#define N 8 // Size of the chessboard (8x8)

// Array to hold the positions of the knights
int board[N][N];

// Possible moves for a knight
int knightMoves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

// Function to check if placing a knight at (row, col) is feasible
int feasible(int board[N][N], int row, int col) {
    for (int i = 0; i < 8; i++) {
        int newRow = row + knightMoves[i][0];
        int newCol = col + knightMoves[i][1];
        // Check if the new position is within bounds and already occupied by a knight
        if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && board[newRow][newCol] == 1) {
            return 0; // Not feasible
        }
    }
    return 1; // Feasible to place knight
}
// Recursive function to solve the n-knight problem
void recur_nKnights(int board[N][N], int k, int row, int col) {
    // Base case: If k knights have been placed
    if (k == N) {
          for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
       printf("\n"); // Print one possible solution
        return;
    }

    // Iterate through each cell of the board
    for (int i = row; i < N; i++) {
        for (int j = (i == row ? col : 0); j < N; j++) {
            // Check if we can place a knight at (i, j)
            if (feasible(board, i, j)) {
                board[i][j] = 1; // Place knight
                // Recur to place the next knight
                recur_nKnights(board, k + 1, i, j + 1);
                board[i][j] = 0; // Backtrack, remove knight
            }
        }
        col=0;
    }
}

int main() {
    // Initialize the board with 0 (no knight placed)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // Start placing knights
    recur_nKnights(board, 0, 0, 0);
    return 0;
}
