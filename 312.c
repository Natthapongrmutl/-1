#include <stdio.h>

int main() {
    int N_CALCULATIONS, i;
    int attkLvl, oppLvl, oppArmor;
    float baseAttack, damageReduction, netDamage, damageDeficit;
    const float WORTH_THRESHOLD = 150.0;

    // รับจำนวนการคำนวณ
    if (scanf("%d", &N_CALCULATIONS) != 1) {
        return 1;
    }

    for (i = 0; i < N_CALCULATIONS; i++) {
        // รับค่าระดับการโจมตี ระดับศัตรู และเกราะศัตรู
        if (scanf("%d %d %d", &attkLvl, &oppLvl, &oppArmor) != 3) {
            break;
        }

        // ขั้นตอนการคำนวณ
        baseAttack = attkLvl * 10.0;

        // การลดความเสียหายตามเกราะ
        if (oppArmor < 50) {
            damageReduction = 0.20;
        } else {
            damageReduction = 0.40;
        }

        // คำนวณความเสียหายสุทธิ
        netDamage = baseAttack * (1.0 - damageReduction);

        // ตรวจสอบผลลัพธ์
        if (netDamage >= WORTH_THRESHOLD) {
            printf("SUCCESS! Net Damage: %.2f\n", netDamage);
        } else {
            damageDeficit = WORTH_THRESHOLD - netDamage;
            printf("FAIL. Deficit: %.2f\n", damageDeficit);
        }
    }

    return 0;
}
