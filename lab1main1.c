#include <stdio.h>

int main(){
    int num;
    if(scanf("%d", &num) != 1){
        return 1;
    }
    for(int i = 1; i <= num; i++){
        printf("[%d] Hello world\n", i);
    }
    
    return 0;
}
