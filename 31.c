#include <stdio.h>

struct Product {
    char name[50];
    int productId;
    float price;
};

int main() {

    struct Product item;

    if (scanf("%d %f %49s", &item.productId, &item.price, item.name) != 3) {
        return 1;
    }

    printf("--- PRODUCT INFORMATION ---\n");
    printf("Product ID: %d\n", item.productId);
    printf("Product Name: %s\n", item.name);
    printf("Price: %.2f\n", item.price);

    return 0;
}
