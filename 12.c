#include <stdio.h>

int main() {
    int planCode;
    float dataUsage_GB;
    float totalBill;
    
    printf("Enter plan code (1 or 2): ");
    scanf("%d", &planCode);
    
    printf("Enter data usage (GB): ");
    scanf("%f", &dataUsage_GB);
    
    if (planCode == 1) {
        if (dataUsage_GB <= 10) {
            totalBill = 299;
        } else {
            totalBill = 299 + 10 * (dataUsage_GB - 10);
        }
        printf("Total Bill: %.2f THB\n", totalBill);
    } else if (planCode == 2) {
        if (dataUsage_GB <= 20) {
            totalBill = 599;
        } else {
            totalBill = 599 + 50 + 5 * (dataUsage_GB - 20);
        }
        printf("Total Bill: %.2f THB\n", totalBill);
    } else {
        printf("Invalid Plan Code\n");
    }
    
    return 0;
}
