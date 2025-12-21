#include <stdio.h>

struct Campaign {
    char name[50];
    float productPrice;
    int salesCount;
    float adSpend;
};

int main() {
    int N, i;

    printf("Enter number of campaigns: ");
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Campaign campaigns[N];

    for (i = 0; i < N; i++) {
        printf("\nEnter data for campaign %d (name price sales adSpend):\n", i + 1);
        if (scanf("%s %f %d %f", campaigns[i].name, &campaigns[i].productPrice,
                  &campaigns[i].salesCount, &campaigns[i].adSpend) != 4) {
            return 1;
        }
    }

    for (i = 0; i < N; i++) {
        float commissionRate = 0.0;
        float totalRevenue, totalCommission, netProfitLoss;

        // เซ็ตอัตราคอมมิชชั่นตามยอดขาย
        if (campaigns[i].salesCount >= 20) {
            commissionRate = 0.20;
        } else if (campaigns[i].salesCount >= 10) {
            commissionRate = 0.15;
        } else {
            commissionRate = 0.10;
        }

        // คำนวณรายได้รวม คอมมิชชั่น และกำไร/ขาดทุนสุทธิ
        totalRevenue = campaigns[i].salesCount * campaigns[i].productPrice;
        totalCommission = totalRevenue * commissionRate;
        netProfitLoss = totalCommission - campaigns[i].adSpend;

        // แสดงผลลัพธ์
        printf("\n--- Campaign: %s ---\n", campaigns[i].name);
        printf("Sales: %d, Ad Spend: %.2f\n", campaigns[i].salesCount, campaigns[i].adSpend);
        printf("Rate Used: %.0f%%\n", commissionRate * 100);
        printf("Calculation: (%.2f * %.0f%%) - %.2f = %.2f\n",
               totalRevenue, commissionRate * 100, campaigns[i].adSpend, netProfitLoss);
        printf("Net Result: %.2f\n", netProfitLoss);
    }

    return 0;
}
