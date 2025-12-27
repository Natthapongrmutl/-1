#include <stdio.h>

int main() {

    int N_MONTHS, month, successCount = 0;
    float dailyDeposit, monthlyTotal;

    if (scanf("%d", &N_MONTHS) != 1) {
        return 1;
    }

    for (month = 1; month <= N_MONTHS; month++) {

        monthlyTotal = 0.0;

        while (1) {
            if (scanf("%f", &dailyDeposit) != 1) {
                return 1;
            }

            if (dailyDeposit == 0.00) {
                break;
            }

            monthlyTotal += dailyDeposit;
        }

        if (monthlyTotal >= 500.00) {
            successCount++;
        }

        printf("Month %d Total: %.2f\n", month, monthlyTotal);
    }

    printf("Success Count: %d\n", successCount);

    return 0;
}
