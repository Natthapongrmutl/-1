#include <stdio.h>

void GetMatrix( int **value, int *rows, int *cols);

int main(){
    int *data;
    int m, n;

    GetMatrix(&data, &m, &n);

    return 0;
}

void GetMatrix(int **value, int *rows, int *cols){
    int *var;

    printf("enter rows, cols : ");
    scanf("%d %d", rows, cols);

    var = new int[ *rows * *cols];

    for(int i = 0; i < *rows; i++){
        for(int j = 0; j < *cols; j++){
            printf("value[%d][%d] = ", i, j);
            scanf("%d", &var[ i * * cols + j]);
        }
    }
    *value = var;
}
