#include <stdio.h>

struct Student {
    char name[50];
    int studentId;
    float score;
};

int main() {

    int N, i;

    if (scanf("%d", &N) != 1 || N <= 0) {
        return 1;
    }

    struct Student students[N];

    for (i = 0; i < N; i++) {
        if (scanf("%d %f %49s",
                  &students[i].studentId,
                  &students[i].score,
                  students[i].name) != 3) {
            return 1;
        }
    }

    printf("\n--- STUDENT LIST ---\n");
    for (i = 0; i < N; i++) {
        printf("Student %d\n", i + 1);
        printf("ID: %d\n", students[i].studentId);
        printf("Name: %s\n", students[i].name);
        printf("Score: %.2f\n\n", students[i].score);
    }

    return 0;
}
