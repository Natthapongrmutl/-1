#include <stdio.h>

#define NUM_STUDENTS 3

struct Student {
    int id;
    int score;
};

int find_max_score_id(struct Student students[], int size);

int main() {

    struct Student class_data[NUM_STUDENTS];
    int top_student_id;
    int i;

    printf("Enter data for %d students:\n", NUM_STUDENTS);

    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("--- Student %d ---\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &class_data[i].id);

        printf("Enter Score: ");
        scanf("%d", &class_data[i].score);
    }

    top_student_id = find_max_score_id(class_data, NUM_STUDENTS);

    printf("\n--- STUDENT SCORE REPORT ---\n");
    printf("ID     | Score\n");
    printf("--------------\n");

    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("%-6d | %d\n", class_data[i].id, class_data[i].score);
    }

    printf("\nTOP PERFORMER ID: %d\n", top_student_id);

    return 0;
}

int find_max_score_id(struct Student students[], int size) {
    int i;
    int max_score = students[0].score;
    int max_id = students[0].id;

    for (i = 1; i < size; i++) {
        if (students[i].score > max_score) {
            max_score = students[i].score;
            max_id = students[i].id;
        }
    }

    return max_id;
}
