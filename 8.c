#include <stdio.h>

int main() {
    int dayCode, hour;
    
    printf("Enter day code (1=Monday to 7=Sunday): ");
    scanf("%d", &dayCode);
    
    printf("Enter hour (0-23): ");
    scanf("%d", &hour);
    
    switch (dayCode) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            if (hour >= 8 && hour <= 17) {
                printf("System Running (Workday)\n");
            } else {
                printf("System Idle (Off-hours)\n");
            }
            break;
        case 6:
        case 7:
            printf("Weekend Relax Mode\n");
            break;
        default:
            printf("Invalid Day Code\n");
    }
    
    return 0;
}
