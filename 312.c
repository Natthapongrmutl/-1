#include <stdio.h>

float calculate_net_damage(int attackerLevel, int opponentArmor) {

    float baseAttack = attackerLevel * 10.0;
    float reduction;

    if (opponentArmor < 50) {
        reduction = 0.20;
    } else {
        reduction = 0.40;
    }

    return baseAttack * (1.0 - reduction);
}

int main() {

    int N;
    int attkLvl, oppLvl, oppArmor;
    float netDamage;
    float deficit;

    const float WORTH_THRESHOLD = 150.0;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    for (int i = 0; i < N; i++) {

        if (scanf("%d %d %d", &attkLvl, &oppLvl, &oppArmor) != 3) {
            break;
        }

        netDamage = calculate_net_damage(attkLvl, oppArmor);

        if (netDamage >= WORTH_THRESHOLD) {
            printf("SUCCESS! Net Damage: %.2f\n", netDamage);
        } else {
            deficit = WORTH_THRESHOLD - netDamage;
            printf("FAIL. Deficit: %.2f\n", deficit);
        }
    }

    return 0;
}
