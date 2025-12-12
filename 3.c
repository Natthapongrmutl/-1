#include <stdio.h>

int main() {
    int num1, num2, operationCode;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    printf("Enter operation code (1=Add, 2=Subtract, 3=Multiply, 4=Divide): ");
    scanf("%d", &operationCode);
    
    switch(operationCode) {
        case 1:
            printf("Result: %d\n", num1 + num2);
            break;
        case 2:
            printf("Result: %d\n", num1 - num2);
            break;
        case 3:
            printf("Result: %d\n", num1 * num2);
            break;
        case 4:
            if(num2 != 0) {
                printf("Result: %d\n", num1 / num2);
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        default:
            printf("Invalid Operation\n");
    }
    
    return 0;
}
