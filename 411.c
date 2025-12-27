#include <stdio.h>

#define ROWS 2
#define COLS 4

int main() {

    int matrix[ROWS][COLS];
    int total_sum = 0;
    int i, j;

    printf("Enter %d integer numbers for the 2x4 matrix:\n", ROWS * COLS);

    /* รับข้อมูลลงใน Array 2 มิติ */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Enter element for Row %d, Col %d: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            total_sum += matrix[i][j];
        }
    }

    printf("\n--- 2D ARRAY SUMMATION REPORT ---\n");
    printf("Recorded Matrix (2x4):\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Sum of all elements: %d\n", total_sum);

    return 0;
}
