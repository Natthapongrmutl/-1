#include <stdio.h>

struct Student {
    char name[50];
    int studentId;
    float score;
};

int main() {
    int N, i;
    int passCount = 0;
    int failCount = 0;

    printf("Enter number of students: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    struct Student students[N];

    for (i = 0; i < N; i++) {
        printf("Enter student %d ID, score, and name: ", i + 1);
        if (scanf("%d %f %49s", &students[i].studentId, &students[i].score, students[i].name) != 3) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    for (i = 0; i < N; i++) {
        if (students[i].score >= 60.0) {
            passCount++;
        } else {
            failCount++;
        }
    }

    printf("Pass Count: %d\n", passCount);
    printf("Fail Count: %d\n", failCount);

    return 0;
}
