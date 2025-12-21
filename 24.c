#include <stdio.h>

int main() {
    float principal, monthlyPayment, interest;
    int monthCount = 0;
    const float INTEREST_RATE = 0.01;
    const float PENALTY = 10.0;

    if (scanf("%f %f", &principal, &monthlyPayment) != 2) {
        return 1;
    }

    while (principal > 0) {
        monthCount++;
        interest = principal * INTEREST_RATE;
        principal += interest;

        if (monthlyPayment < interest) {
            principal += PENALTY;
        }

        principal -= monthlyPayment;

        if (principal < 0) principal = 0; 

        printf("Month %d: Remaining Debt = %.2f\n", monthCount, principal);
    }

    return 0;
}
