#include <stdio.h>

int main() {
    int num, evenSum = 0, oddSum = 0;
    
    printf("Enter integers (0 to stop):\n");
    
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);
        
        if (num == 0) {
            break;
        }
        
        if (num % 2 == 0) {
            evenSum += num;
        } else {
            oddSum += num;
        }
    }
    
    printf("\nSum of even numbers: %d\n", evenSum);
    printf("Sum of odd numbers: %d\n", oddSum);
    
    return 0;
}
