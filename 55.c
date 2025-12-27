#include <stdio.h>

#define NUM_STUDENTS 4

struct Student {
    int id;
};

int check_id_existence(struct Student students[], int size, int search_id);

int main() {

    struct Student id_list[NUM_STUDENTS];
    int search_id;
    int found_status;
    int i;

    printf("Enter IDs for %d students:\n", NUM_STUDENTS);

    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d ID: ", i + 1);
        scanf("%d", &id_list[i].id);
    }

    printf("\nEnter ID to search: ");
    scanf("%d", &search_id);

    found_status = check_id_existence(id_list, NUM_STUDENTS, search_id);

    printf("\n--- ID SEARCH REPORT ---\n");
    printf("Recorded IDs: ");
    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("%d ", id_list[i].id);
    }
    printf("\n");

    printf("Search ID: %d\n", search_id);

    if (found_status == 1) {
        printf("ID FOUND in the system.\n");
    } else {
        printf("ID NOT FOUND in the system.\n");
    }

    return 0;
}

int check_id_existence(struct Student students[], int size, int search_id) {
    int i;

    for (i = 0; i < size; i++) {
        if (students[i].id == search_id) {
            return 1;
        }
    }

    return 0;
}
