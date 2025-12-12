#include <stdio.h>

int main() {
    int zoneCode;
    float weight_kg;
    int shippingCost = 0;

    printf("Enter shipping zone code (1=Local, 2=Regional, 3=International): ");
    scanf("%d", &zoneCode);
    
    printf("Enter product weight (kg): ");
    scanf("%f", &weight_kg);

    switch (zoneCode) {
        case 1:
            if (weight_kg <= 5) {
                shippingCost = 50;
            } else {
                shippingCost = 80;
            }
            break;
        case 2:
            if (weight_kg <= 10) {
                shippingCost = 150;
            } else {
                shippingCost = 250;
            }
            break;
        case 3:
            shippingCost = 500;
            break;
        default:
            printf("Invalid Zone Code\n");
            return 1;
    }

    printf("Total Shipping Cost: %d Baht\n", shippingCost);
    return 0;
}
