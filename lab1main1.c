#include <stdio.h>

int main(){
    int number888;
    printf("ใส่เลข: ");
    if(scanf("%d", &number888) != 1){
        return 1;
    }
    for(int i = 1; i <= number888; i++){
        printf("[%d] Hello world\n", i);
    }
    
    return 0;
}
