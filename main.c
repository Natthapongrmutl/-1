#include <stdio.h>

int main() {
    int N;
    
    printf("Enter an integer: ");
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        printf("Hello Loop!\n");
    }
    
    return 0;
}
