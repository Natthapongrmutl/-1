#include <stdio.h>

int main() {
    int N, i;
    int studentId, score, totalClasses, absentClasses;
    float attendancePercent;
    int passCount = 0;
    int failCount = 0;

    printf("Enter number of students: ");
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    for (i = 0; i < N; i++) {
        printf("Enter StudentID Score TotalClasses AbsentClasses: ");
        if (scanf("%d %d %d %d", &studentId, &score, &totalClasses, &absentClasses) != 4) {
            break;
        }

        attendancePercent = (float)(totalClasses - absentClasses) / totalClasses * 100.0;

        printf("Student %d: ", studentId);

        int passScore = (score >= 50);
        int passAttendance = (attendancePercent >= 75.0);

        if (passScore && passAttendance) {
            printf("PASS\n");
            passCount++;
        } else {
            printf("FAIL (");
            if (!passScore && !passAttendance) {
                printf("Both Score and Attendance");
            } else if (!passScore) {
                printf("Score");
            } else if (!passAttendance) {
                printf("Attendance");
            }
            printf(")\n");
            failCount++;
        }
    }

    printf("Summary");
    printf("Total PASS: %d\n", passCount);
    printf("Total FAIL: %d\n", failCount);

    return 0;
}
