#include <stdio.h>

int main(){
    int num;
    printf("Please Enter number: ");
    if(scanf("%d", &num) != 1){
        printf("This is not a number ");
        return 1;
    }
    if (num <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }
    for(int i = 1; i <= num; i++){
        printf("[%d] Hello world\n", i);
    }
    
    return 0;
}
