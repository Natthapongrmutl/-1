#include <stdio.h>

#define DAYS 7

int main() {
    int daily_temp[DAYS];
    int max_temp;
    int i;

    for (i = 0; i < DAYS; i++) {
        printf("temperature to Day %d: ", i + 1);
        scanf("%d", &daily_temp[i]);
    }

    max_temp = daily_temp[0];

    for (i = 1; i < DAYS; i++) {
        if (daily_temp[i] > max_temp) {
            max_temp = daily_temp[i];
        }
    }

    printf("DAILY TEMPERATURE REPORT");
    printf("Recorded Temperatures (C): ");

    for (i = 0; i < DAYS; i++) {
        printf("%d ", daily_temp[i]);
    }

    printf("\n");
    printf("Maximum Temperature Found: %d C\n", max_temp);

    if (max_temp >= 35) {
        printf("Weather is HOT");
    } else {
        printf("Weather is MODERATE.");
    }

    return 0;
}
