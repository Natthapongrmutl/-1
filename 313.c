#include <stdio.h>
#include <ctype.h>

int main() {
    char text[101];
    int countUpper = 0;
    int countLower = 0;
    int countDigit = 0;
    int countOther = 0;
    int i;

    // รับข้อความจากผู้ใช้
    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    // นับประเภทของตัวอักษร
    for (i = 0; text[i] != '\0' && text[i] != '\n'; i++) {
        if (isupper(text[i])) {
            countUpper++;
        } else if (islower(text[i])) {
            countLower++;
        } else if (isdigit(text[i])) {
            countDigit++;
        } else {
            countOther++;
        }
    }

    printf("Uppercase: %d\n", countUpper);
    printf("Lowercase: %d\n", countLower);
    printf("Digits: %d\n", countDigit);
    printf("Special/other: %d\n", countOther);

    return 0;
}
