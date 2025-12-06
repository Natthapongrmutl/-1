#include <stdio.h>

int *GetMatrix(int *rows, int *cols);

int main(){
    int *data;
    int m , n;

    data = GetMatrix(&m, &n);

    printf("\nMatrix Input\n");
    for(int i = 0; i < m; i++){
        printf("%d row\n",i+1);
        for(int j = 0; j < n; j++){
            printf("%d col number: ",j+1);
            scanf("%d", &data[ i * n + j]);
        }
    }

    return 0;
}

int *GetMatrix(int *row, int *col){
    int *var;

    printf("enter rows, cols :");
    scanf("%d %d", row, col);

    var = new int[ *row * *col];
    
    return var;
}
