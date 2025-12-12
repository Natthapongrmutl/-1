#include <stdio.h>

int main() {
    int number;
    
    do {
        printf("Enter a number between 1 and 10: ");
        scanf("%d", &number);
        
        if (number < 1 || number > 10) {
            printf("Error: Value must be 1-10.\n");
        }
    } while (number < 1 || number > 10);
    
    printf("Input accepted: %d\n", number);
    
    return 0;
}
