#include <stdio.h>

struct Student {
    char name[50];
    int studentId;
    float score;
};

int main() {
    int N;
    float totalScore = 0, averageScore;

    printf("Enter number of students: ");
    scanf("%d", &N);

    struct Student students[N];

    for (int i = 0; i < N; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", students[i].name); // รับชื่อ

        printf("Enter student ID of student %d: ", i + 1);
        scanf("%d", &students[i].studentId);

        printf("Enter score of student %d: ", i + 1);
        scanf("%f", &students[i].score);

        totalScore += students[i].score;
    }

    averageScore = totalScore / N;
    printf("Average Score = %.2f\n", averageScore);

    return 0;
}
