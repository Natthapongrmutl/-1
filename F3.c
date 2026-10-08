#include <stdio.h>  //use printf
#include <conio.h>  //use getch
#include <stdlib.h> //use malloc
#include <string.h>

#define MAX_STACK 5

struct Student
{
    char id[10];
    char name[50];
    float gpa;
};

struct DNode
{
    struct Student data;
    struct DNode *prev;
    struct DNode *next;
};

struct Operation
{
    int type;
    struct Student data;
};

struct Stack
{
    struct Operation op[MAX_STACK];
    int top;
};

struct DNode *insertSorted(struct DNode *head,
                           struct Student student,
                           struct Stack *stack);

struct DNode *deleteById(struct DNode *head,
                         char id[],
                         struct Stack *stack);

void printForward(struct DNode *head);
void printBackward(struct DNode *head);

void push(struct Stack *stack, int type, struct Student student);
int pop(struct Stack *stack, struct Operation *op);

struct DNode *insertWithoutStack(struct DNode *head,
                                 struct Student student);

struct DNode *deleteWithoutStack(struct DNode *head,
                                 char id[]);

struct DNode *undo(struct DNode *head,
                   struct Stack *stack);

void freeList(struct DNode *head);

/*push */
void push(struct Stack *stack, int type, struct Student student)
{
    int i;

    /* ถ้า Stack เต็ม ให้เลื่อนข้อมูลเก่าออก */
    if (stack->top == MAX_STACK)
    {
        for (i = 0; i < MAX_STACK - 1; i++)
        {
            stack->op[i] = stack->op[i + 1];
        }

        stack->top = MAX_STACK - 1;
    }

    stack->op[stack->top].type = type;
    stack->op[stack->top].data = student;
    stack->top++;
}

/* pop */
int pop(struct Stack *stack, struct Operation *op)
{
    if (stack->top == 0)
    {
        return 0;
    }

    stack->top--;

    *op = stack->op[stack->top];

    return 1;
}

/*insertWithoutStack*/

struct DNode *insertWithoutStack(struct DNode *head,
                                 struct Student student)
{
    struct DNode *newNode;
    struct DNode *current;

    newNode = (struct DNode *)malloc(sizeof(struct DNode));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = student;
    newNode->prev = NULL;
    newNode->next = NULL;

    /* กรณี List ว่าง */
    if (head == NULL)
    {
        return newNode;
    }

    /* แทรกก่อน Head */
    if (student.gpa > head->data.gpa)
    {
        newNode->next = head;
        head->prev = newNode;

        return newNode;
    }

    current = head;

    /* หา position ที่เหมาะสม */
    while (current->next != NULL &&
           current->next->data.gpa >= student.gpa)
    {
        current = current->next;
    }

    /* แทรกหลัง current */
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }

    current->next = newNode;

    return head;
}

/*insertsorted*/
struct DNode *insertSorted(struct DNode *head,
                           struct Student student,
                           struct Stack *stack)
{
    head = insertWithoutStack(head, student);

    /* บันทึกการเพิ่มลง Stack */
    push(stack, 1, student);

    return head;
}

/*deletewithoutstack*/
struct DNode *deleteWithoutStack(struct DNode *head,
                                 char id[])
{
    struct DNode *current;

    current = head;

    while (current != NULL)
    {
        if (strcmp(current->data.id, id) == 0)
        {
            /* กรณีเป็น Head */
            if (current->prev == NULL)
            {
                head = current->next;

                if (head != NULL)
                {
                    head->prev = NULL;
                }
            }
            else
            {
                current->prev->next = current->next;

                if (current->next != NULL)
                {
                    current->next->prev = current->prev;
                }
            }

            free(current);

            return head;
        }

        current = current->next;
    }

    return head;
}

/*deletebyid*/
struct DNode *deleteById(struct DNode *head,
                         char id[],
                         struct Stack *stack)
{
    struct DNode *current;

    current = head;

    while (current != NULL)
    {
        if (strcmp(current->data.id, id) == 0)
        {
            /* เก็บข้อมูลก่อน free */
            struct Student deletedStudent = current->data;

            head = deleteWithoutStack(head, id);

            /* บันทึกการลบลง Stack */
            push(stack, 2, deletedStudent);

            return head;
        }

        current = current->next;
    }

    printf("no id %s\n", id);

    return head;
}

/*printforward*/
void printForward(struct DNode *head)
{
    struct DNode *current;

    current = head;

    if (current == NULL)
    {
        printf("NULL\n");
        return;
    }

    while (current != NULL)
    {
        printf("[%s|%s|%.2f]",
               current->data.id,
               current->data.name,
               current->data.gpa);

        if (current->next != NULL)
        {
            printf(" -> ");
        }

        current = current->next;
    }

    printf(" -> NULL\n");
}

/*printbackward*/
void printBackward(struct DNode *head)
{
    struct DNode *current;

    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }

    /* ไปหา Tail */
    current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    /* เดินย้อนกลับ */
    while (current != NULL)
    {
        printf("[%s|%s|%.2f]",
               current->data.id,
               current->data.name,
               current->data.gpa);

        if (current->prev != NULL)
        {
            printf(" -> ");
        }

        current = current->prev;
    }

    printf(" -> NULL\n");
}

/*undo*/
struct DNode *undo(struct DNode *head,
                   struct Stack *stack)
{
    struct Operation op;

    if (pop(stack, &op) == 0)
    {
        printf("no Undo\n");
        return head;
    }

    /* ถ้าเป็น INSERT ให้ลบออก */
    if (op.type == 1)
    {
        head = deleteWithoutStack(head, op.data.id);

        printf("Undo: insert %s\n",
               op.data.id);
    }

    /* ถ้าเป็น DELETE ให้ใส่กลับ */
    else if (op.type == 2)
    {
        head = insertWithoutStack(head, op.data);

        printf("Undo: delete %s\n",
               op.data.id);
    }

    return head;
}


/*free */
void freeList(struct DNode *head)
{
    struct DNode *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
    }
}

int main()
{
    struct DNode *head = NULL;
    struct Stack stack;

    struct Student student;

    int choice;
    char id[10];

    stack.top = 0;

    do{
        printf("\n=========std exxam01 ==========\n");
        printf("1. Insert\n2. Delete by ID\n3. Print Forward\n4. Print Backward\n5.Undo\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("id: ");
                scanf("%9s", student.id);

                printf("name: ");
                scanf("%49s", student.name);

                printf("GPA: ");
                scanf("%f", &student.gpa);

                head = insertSorted(head, student, &stack);

                break;
            case 2:
                
                printf("id: ");
                scanf("%9s", id);

                head = deleteById(head, id, &stack);

                break;
            case 3:

                printf("\nForward:\n");
                printForward(head);

                break;

            case 4:

                printf("\nBackward:\n");
                printBackward(head);

                break;

            case 5:

                head = undo(head, &stack);

                break;

            case 0:

                printf("Exit\n");

                break;
            default:

                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    freeList(head);

    return 0;

}
