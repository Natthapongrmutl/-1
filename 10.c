#include <stdio.h>

int main() {
    int clearance, age, isActive;
    
    printf("Enter clearance level: ");
    scanf("%d", &clearance);
    
    printf("Enter age: ");
    scanf("%d", &age);
    
    printf("Enter status (1=Active, 0=Inactive): ");
    scanf("%d", &isActive);
    
    if ((clearance == 3 && isActive == 1) || (clearance == 2 && age >= 25 && isActive == 1)) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }
    
    return 0;
}
