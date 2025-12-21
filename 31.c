#include <stdio.h>

struct Product {
    char name[50];
    int productId;
    float price;
};

int main() {
    struct Product item;

    printf("Enter product ID: ");
    scanf("%d", &item.productId);

    printf("Enter product price: ");
    scanf("%f", &item.price);

    // เลียร์บัฟเฟอร์ก่อนอ่านสตริง
    while (getchar() != '\n');

    printf("Enter product name: ");
    fgets(item.name, sizeof(item.name), stdin);

    size_t len = 0;
    while (item.name[len] != '\0') {
        if (item.name[len] == '\n') {
            item.name[len] = '\0';
            break;
        }
        len++;
    }

    printf("\nProduct Details:\n");
    printf("ID: %d\n", item.productId);
    printf("Price: %.2f\n", item.price);
    printf("Name: %s\n", item.name);

    return 0;
}
