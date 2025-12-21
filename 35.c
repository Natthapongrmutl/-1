#include <stdio.h>

#define SHIPPING_FEE 50.0

struct Order {
    int itemId;
    float unitPrice;
    int quantity;
};

int main() {
    int N, i;
    float grandTotal = 0.0;

    // รับจำนวนคำสั่งซื้อ
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Order orders[N];

    // รับข้อมูลคำสั่งซื้อและคำนวณราคารวม
    for (i = 0; i < N; i++) {
        float itemTotal;

        if (scanf("%d %f %d", &orders[i].itemId, &orders[i].unitPrice, &orders[i].quantity) != 3) {
            return 1;
        }

        itemTotal = (orders[i].unitPrice * orders[i].quantity) + SHIPPING_FEE;

        if (itemTotal >= 500.0) {
            itemTotal *= 0.90; // ลด 10%
        }

        grandTotal += itemTotal;
    }

    printf("Grand Total: %.2f\n", grandTotal);

    return 0;
}
