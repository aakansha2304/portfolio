#include <stdio.h>
#include <stdbool.h>

#define N 4 

void knight(bool board[N][N], int row, int col, int knights);
int isfeasible(bool board[N][N], int row, int col);
int isValid(int row, int col);
void display(bool board[N][N]);

int main() {
    bool board[N][N] = {false};  
    knight(board, 0, 0, 4);     
    return 0;
}
void knight(bool board[N][N], int row, int col, int knights) {
    // Base case: If all knights have been placed
    if (knights == 0) {
        display(board);   
        printf("\n");
        return;
    }
    if (row == N - 1 && col == N) {
        return;
    }

    if (col == N) {
        knight(board, row + 1, 0, knights);
        return;
    }

    if (isfeasible(board, row, col)) {
        board[row][col] = true; 
        knight(board, row, col + 1, knights - 1); 
        board[row][col] = false; // Backtrack
    }
    knight(board, row, col + 1, knights);
}


int isfeasible(bool board[N][N], int row, int col) {

    if (isValid(row - 2, col - 1) && board[row - 2][col - 1]) {
        return 0;
    }

    if (isValid(row - 1, col - 2) && board[row - 1][col - 2]) {
        return 0;
    }

    if (isValid(row - 2, col + 1) && board[row - 2][col + 1]) {
        return 0;
    }

    if (isValid(row - 1, col + 2) && board[row - 1][col + 2]) {
        return 0;
    }

    return 1;  // Safe to place knight
}
int isValid(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < N;
}

void display(bool board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                printf("1 "); // 1 for placing the knight 
            } else {
                printf("0 "); // 0 for empty 
            }
        }
        printf("\n");
    }
}
