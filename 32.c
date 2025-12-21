#include <stdio.h>

struct Student {
    char name[50];
    int studentId;
    float score;
};

int main() {
    int N, i;

    // รับจำนวนของนักเรียน
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Student students[N];

    // รับข้อมูลนักเรียน
    for (i = 0; i < N; i++) {
        scanf("%d %f %s", &students[i].studentId, &students[i].score, students[i].name);
    }

    // แสดงข้อมูลนักเรียน
    for (i = 0; i < N; i++) {
        printf("ID: %d, Score: %.2f, Name: %s\n", students[i].studentId, students[i].score, students[i].name);
    }

    return 0;
}
