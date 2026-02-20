#include <stdio.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

class LinkedList {

protected:
    studentNode *start;
    studentNode *now;

public:

    LinkedList() {
        start = NULL;
        now = NULL;
    }

    ~LinkedList() {
        studentNode *temp;
        while (start != NULL) {
            temp = start;
            start = start->next;
            delete temp;
        }
    }

    void InsNode(const char n[], int a, char s, float g) {

        studentNode *newNode = new studentNode;

        // ลองเทส
        int i = 0;
        while (n[i] != '\0') {
            newNode->name[i] = n[i];
            i++;
        }
        newNode->name[i] = '\0';

        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
            now = newNode;
        } else {
            now->next = newNode;
            now = newNode;
        }
    }

    void GoNext() {
        if (now != NULL && now->next != NULL)
            now = now->next;
    }

    void DelNode() {

        if (start == NULL || now == NULL) return;

        if (now == start) {
            start = start->next;
            delete now;
            now = start;
            return;
        }

        studentNode *walk = start;

        while (walk->next != now) {
            walk = walk->next;
        }

        walk->next = now->next;
        delete now;
        now = walk;
    }

    virtual void ShowNode() {

        studentNode *walk = start;

        while (walk != NULL) {
            printf("%s ", walk->name);
            walk = walk->next;
        }

        printf("\n");
    }
};

class NewList : public LinkedList {

public:

    void GoFirst() {
        now = start;
    }

    virtual void ShowNode() {
        printf("NewList: ");
        LinkedList::ShowNode();
    }
};

int main() {

    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);

    listA.GoNext();
    listA.ShowNode();

    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);

    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}
