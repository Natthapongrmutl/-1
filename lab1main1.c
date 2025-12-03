#include <stdio.h>

int main() {
    int num;

    printf("ใส่เลข: ");    // รับค่าจำนวนรอบจากผู้ใช้
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (num <= 0) {
        printf("ใส่เลขดีๆ\n");// ตรวจสอบว่าค่าที่กรอกเป็นบวก
        return 1;
    }

    for (int i = 1; i <= num; i++) {
        printf("[%d] Hello world\n", i);// วนลูปแสดงผล
    }

    return 0;
}
