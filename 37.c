#include <stdio.h>

struct SalesRecord {
    char name[50];
    float target;
    float actual;
};

int main() {
    int N, i;
    float grandTotalCommission = 0.0;

    // รับจำนวนเรคคอร์ด
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct SalesRecord records[N];

    for (i = 0; i < N; i++) {
        float baseCommission;

        // รับข้อมูลเรคคอร์ด
        if (scanf("%f %f %s", &records[i].target, &records[i].actual, records[i].name) != 3) {
            return 1;
        }

        // นำยอดขายจริงมาคำนวณคอมมิชชั่นพื้นฐาน 10%
        baseCommission = records[i].actual * 0.10;

        // โบนัสและค่าปรับตามเงื่อนไข
        if (records[i].actual >= records[i].target * 1.20) {
            baseCommission += 200.0; // Tier 2 bonus
        } else if (records[i].actual >= records[i].target) {
            baseCommission += 50.0;  // Tier 1 bonus
        } else if (records[i].actual < records[i].target * 0.90) {
            baseCommission -= 100.0; // ค่าปรับ
        }

        grandTotalCommission += baseCommission;
    }

    printf("Grand Total Commission: %.2f\n", grandTotalCommission);

    return 0;
}
