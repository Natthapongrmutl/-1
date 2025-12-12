#include <stdio.h>

int main() {
    int customerType;
    double consumption_kWh, rate, totalBill;
    
    printf("Enter customer type (1 for Household, 2 for Business): ");
    scanf("%d", &customerType);
    
    printf("Enter electricity consumption (kWh): ");
    scanf("%lf", &consumption_kWh);
    
    if (customerType == 1) {
        if (consumption_kWh <= 100) {
            rate = 3.0;
        } else {
            rate = 4.0;
        }
        totalBill = consumption_kWh * rate;
        printf("Total electricity bill: %.2f baht\n", totalBill);
    } else if (customerType == 2) {
        if (consumption_kWh <= 500) {
            rate = 5.0;
        } else {
            rate = 6.5;
        }
        totalBill = consumption_kWh * rate;
        printf("Total electricity bill: %.2f baht\n", totalBill);
    } else {
        printf("Invalid Customer Type\n");
    }
    
    return 0;
}
