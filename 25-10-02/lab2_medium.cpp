#include <stdio.h>

void rotateMatrix(int n, int mat[n][n]) {
   
    // Create an auxiliary matrix
    int res[n][n];

    // move mat[i][j] to mat[n-i-1][n-j-1]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = mat[n - i - 1][n - j - 1];
        }
    }

    // Copy back to original matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = res[i][j];
        }
    }
}

int main() {
    int n = 3;
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix(n, mat);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}