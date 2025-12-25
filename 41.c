#include <stdio.h>

int main() {
    int n, i;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    int score[n];

    for (i = 0; i < n; i++) {
        if (scanf("%d", &score[i]) != 1) {
            return 1;
        }
    }

    for (i = n - 1; i >= 0; i--) {
        printf("%d ", score[i]);
    }

    return 0;
}
