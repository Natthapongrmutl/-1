#include <stdio.h>

#define A_ROWS 2
#define A_COLS 3

#define B_ROWS 2
#define B_COLS 3

#define BT_ROWS 3
#define BT_COLS 2

#define C_ROWS 2
#define C_COLS 2

void print_matrix_2x3(int matrix[2][3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_3x2(int matrix[3][2]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_2x2(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int A[A_ROWS][A_COLS];
    int B[B_ROWS][B_COLS];
    int BT[BT_ROWS][BT_COLS];
    int C[C_ROWS][C_COLS];

    int i, j, k;

    printf("Enter elements for Matrix A (2x3):\n");
    for (i = 0; i < A_ROWS; i++) {
        for (j = 0; j < A_COLS; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements for Matrix B (2x3):\n");
    for (i = 0; i < B_ROWS; i++) {
        for (j = 0; j < B_COLS; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < B_ROWS; i++) {
        for (j = 0; j < B_COLS; j++) {
            BT[j][i] = B[i][j];
        }
    }

    for (i = 0; i < C_ROWS; i++) {
        for (j = 0; j < C_COLS; j++) {
            C[i][j] = 0;
            for (k = 0; k < A_COLS; k++) {
                C[i][j] += A[i][k] * BT[k][j];
            }
        }
    }

    printf("\nMatrix A:\n");
    print_matrix_2x3(A);

    printf("\nMatrix B:\n");
    print_matrix_2x3(B);

    printf("\nMatrix B Transposed:\n");
    print_matrix_3x2(BT);

    printf("\nResult Matrix C:\n");
    print_matrix_2x2(C);

    return 0;
}
