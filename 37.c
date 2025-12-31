#include <stdio.h>

struct SalesRecord {
    char name[50];
    float target;
    float actual;
};

float calculate_commission(float target, float actual) {

    float commission;

    commission = actual * 0.10;

    if (actual >= target * 1.20) {
        commission += 200.0;   // Tier 2 bonus
    }
    else if (actual >= target) {
        commission += 50.0;    // Tier 1 bonus
    }
    else if (actual < target * 0.90) {
        commission -= 100.0;   // Penalty
    }

    return commission;
}

int main() {

    int N;
    float grandTotalCommission = 0.0;

    if (scanf("%d", &N) != 1 || N <= 0) {
        return 1;
    }

    struct SalesRecord records[N];

    for (int i = 0; i < N; i++) {

        if (scanf("%f %f %s",
                  &records[i].target,
                  &records[i].actual,
                  records[i].name) != 3) {
            return 1;
        }
        grandTotalCommission +=
            calculate_commission(records[i].target,
                                  records[i].actual);
    }

    printf("Grand Total Commission: %.2f\n", grandTotalCommission);

    return 0;
}
