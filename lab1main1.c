#include <stdio.h>

int main() {
    int num;
    int i;
    
    scanf("%d", &num);
    for (i = 1; i <= num; i++) {
        printf("[%d] Hello world\n", i);
    }

    return 0;
}
