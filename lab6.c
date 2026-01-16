#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll(struct studentNode *walk);

struct studentNode* AddNode(struct studentNode **start,
                            char *name, int age, char sex, float gpa)
{
    struct studentNode *newNode, *walk;

    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;
    newNode->back = NULL;

    if (*start == NULL) {
        *start = newNode;
        return newNode;
    }

    walk = *start;
    while (walk->next != NULL) {
        walk = walk->next;
    }

    walk->next = newNode;
    newNode->back = walk;

    return newNode;
}

void InsNode(struct studentNode **start, struct studentNode *now,
             char *name, int age, char sex, float gpa)
{
    struct studentNode *newNode;

    if (now == NULL) return;

    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    if (now->back == NULL) {
        newNode->next = now;
        newNode->back = NULL;
        now->back = newNode;
        *start = newNode;
    } 
    else {
        newNode->next = now;
        newNode->back = now->back;
        now->back->next = newNode;
        now->back = newNode;
    }
}

void GoBack(struct studentNode **now)
{
    if (*now != NULL && (*now)->back != NULL) {
        *now = (*now)->back;
    }
}

void DelNode(struct studentNode **start, struct studentNode **now)
{
    struct studentNode *temp;

    if (*now == NULL) return;

    temp = *now;

    if (temp->back == NULL) {
        *start = temp->next;
        if (*start != NULL)
            (*start)->back = NULL;
        *now = *start;
    }
    else if (temp->next == NULL) {
        temp->back->next = NULL;
        *now = temp->back;
    }
    else {
        temp->back->next = temp->next;
        temp->next->back = temp->back;
        *now = temp->next;
    }

    free(temp);
}

void ShowAll(struct studentNode *walk)
{
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}
