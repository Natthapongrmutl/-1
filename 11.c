#include <stdio.h>

int main() {
    double price_before_vat;
    int categoryCode;
    double total_price;
    double vat_amount;
    
    printf("Enter product price before tax: ");
    scanf("%lf", &price_before_vat);
    
    printf("Enter product category code: ");
    scanf("%d", &categoryCode);
    
    switch(categoryCode) {
        case 1:
            total_price = price_before_vat * 1.07;
            vat_amount = total_price - price_before_vat;
            break;
        case 2:
            total_price = price_before_vat;
            vat_amount = 0;
            break;
        case 3:
            total_price = price_before_vat * 1.15;
            vat_amount = total_price - price_before_vat;
            break;
        default:
            printf("Invalid Category\n");
            printf("Total Price: 0.00\n");
            return 0;
    }
    
    printf("VAT Amount: %.2f\n", vat_amount);
    printf("Total Price: %.2f\n", total_price);
    
    return 0;
}
