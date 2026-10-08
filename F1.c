#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK 5

/* -----------------------------
   โครงสร้างข้อมูลนักศึกษา
   ----------------------------- */
struct Student
{
    char id[10];
    char name[50];
    float gpa;
};

/* -----------------------------
   โครงสร้าง Doubly Linked List
   ----------------------------- */
struct DNode
{
    struct Student data;
    struct DNode *prev;
    struct DNode *next;
};

/* -----------------------------
   โครงสร้าง Stack สำหรับ Undo
   ----------------------------- */
struct Operation
{
    char type[10];          // INSERT หรือ DELETE
    struct Student student;
};

struct Stack
{
    struct Operation data[MAX_STACK];
    int top;
};


/* =========================================================
   ฟังก์ชัน Stack
   ========================================================= */

/* เริ่มต้น Stack */
void initStack(struct Stack *stack)
{
    stack->top = -1;
}

/* ตรวจสอบว่า Stack ว่างหรือไม่ */
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

/* เพิ่ม Operation ลง Stack */
void push(struct Stack *stack, char type[], struct Student student)
{
    /* ถ้า Stack เต็ม ให้ลบข้อมูลเก่าสุดออก
       เพื่อเก็บ Undo ล่าสุดไว้ 5 รายการ */
    if (stack->top == MAX_STACK - 1)
    {
        int i;

        for (i = 0; i < MAX_STACK - 1; i++)
        {
            stack->data[i] = stack->data[i + 1];
        }

        stack->top--;
    }

    stack->top++;

    strcpy(stack->data[stack->top].type, type);
    stack->data[stack->top].student = student;
}

/* ดึง Operation ล่าสุดออกจาก Stack */
struct Operation pop(struct Stack *stack)
{
    struct Operation op;

    op = stack->data[stack->top];

    stack->top--;

    return op;
}


/* =========================================================
   ฟังก์ชัน Doubly Linked List
   ========================================================= */

/*
   เพิ่มนักศึกษาแบบเรียง GPA จากมากไปน้อย
*/
void insertSorted(struct DNode **head, struct Student student)
{
    struct DNode *newNode;
    struct DNode *current;

    /* สร้าง Node ใหม่ */
    newNode = (struct DNode *)malloc(sizeof(struct DNode));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = student;
    newNode->prev = NULL;
    newNode->next = NULL;

    /* กรณี List ว่าง */
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    /* กรณี GPA ใหม่มากกว่าหรือเท่ากับตัวแรก
       ให้แทรกด้านหน้า */
    if (student.gpa >= (*head)->data.gpa)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;

        return;
    }

    /* ค้นหาตำแหน่งที่เหมาะสม */
    current = *head;

    while (current->next != NULL &&
           current->next->data.gpa > student.gpa)
    {
        current = current->next;
    }

    /* แทรก Node */
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }

    current->next = newNode;
}


/*
   ลบนักศึกษาตาม ID

   คืนค่า 1 ถ้าลบสำเร็จ
   คืนค่า 0 ถ้าไม่พบ ID
*/
int deleteById(struct DNode **head, char id[], struct Student *deletedStudent)
{
    struct DNode *current;

    current = *head;

    /* ค้นหา ID */
    while (current != NULL)
    {
        if (strcmp(current->data.id, id) == 0)
        {
            /* เก็บข้อมูลไว้สำหรับ Undo */
            *deletedStudent = current->data;

            /* ถ้าเป็น Node แรก */
            if (current->prev == NULL)
            {
                *head = current->next;

                if (*head != NULL)
                {
                    (*head)->prev = NULL;
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

            return 1;
        }

        current = current->next;
    }

    return 0;
}


/*
   แสดงข้อมูลจากหัวไปท้าย
   Forward
*/
void printForward(struct DNode *head)
{
    struct DNode *current;

    current = head;

    printf("\nForward : ");

    while (current != NULL)
    {
        printf("[%s | %s | GPA=%.2f]",
               current->data.id,
               current->data.name,
               current->data.gpa);

        printf(" -> ");

        current = current->next;
    }

    printf("NULL\n");
}


/*
   แสดงข้อมูลจากท้ายไปหัว
   Backward
*/
void printBackward(struct DNode *head)
{
    struct DNode *current;

    if (head == NULL)
    {
        printf("\nBackward : NULL\n");
        return;
    }

    /* เดินไป Node สุดท้าย */
    current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    printf("\nBackward : ");

    /* เดินย้อนกลับด้วย prev */
    while (current != NULL)
    {
        printf("[%s | %s | GPA=%.2f]",
               current->data.id,
               current->data.name,
               current->data.gpa);

        printf(" -> ");

        current = current->prev;
    }

    printf("NULL\n");
}


/* =========================================================
   ฟังก์ชัน Undo
   ========================================================= */

void undo(struct DNode **head, struct Stack *stack)
{
    struct Operation op;
    struct Student deletedStudent;

    /* ถ้าไม่มี Operation ให้ Undo */
    if (isEmpty(stack))
    {
        printf("\nไม่มี Operation ให้ Undo\n");
        return;
    }

    /* เอา Operation ล่าสุดออกจาก Stack */
    op = pop(stack);

    /* ---------------------------------
       ถ้า Operation เดิมคือ INSERT

       Undo INSERT
       = ลบข้อมูลที่เคยเพิ่มออก
       --------------------------------- */
    if (strcmp(op.type, "INSERT") == 0)
    {
        if (deleteById(head, op.student.id, &deletedStudent))
        {
            printf("\nUndo : ยกเลิกการเพิ่ม %s\n",
                   op.student.id);
        }
        else
        {
            printf("\nไม่สามารถ Undo INSERT ได้\n");
        }
    }

    /* ---------------------------------
       ถ้า Operation เดิมคือ DELETE

       Undo DELETE
       = เพิ่มข้อมูลที่เคยลบกลับเข้าไป
       --------------------------------- */
    else if (strcmp(op.type, "DELETE") == 0)
    {
        insertSorted(head, op.student);

        printf("\nUndo : ยกเลิกการลบ %s\n",
               op.student.id);
    }
}


/* =========================================================
   MAIN
   ========================================================= */

int main()
{
    struct DNode *head = NULL;

    struct Stack stack;

    struct Student student;
    struct Student deletedStudent;

    int choice;

    /* เริ่มต้น Stack */
    initStack(&stack);

    /* Menu */
    do
    {
        printf("\n====================================\n");
        printf("        STUDENT MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Print Forward\n");
        printf("4. Print Backward\n");
        printf("5. Undo\n");
        printf("0. Exit\n");
        printf("====================================\n");

        printf("เลือกเมนู : ");
        scanf("%d", &choice);

        /* ---------------------------------
           1. INSERT
           --------------------------------- */
        if (choice == 1)
        {
            printf("\n--- Insert Student ---\n");

            printf("ID   : ");
            scanf("%9s", student.id);

            printf("Name : ");
            scanf(" %49[^\n]", student.name);

            printf("GPA  : ");
            scanf("%f", &student.gpa);

            /* เพิ่มข้อมูลลง Linked List */
            insertSorted(&head, student);

            /* บันทึก Operation สำหรับ Undo */
            push(&stack, "INSERT", student);

            printf("\nเพิ่มนักศึกษาเรียบร้อย\n");
        }

        /* ---------------------------------
           2. DELETE
           --------------------------------- */
        else if (choice == 2)
        {
            char id[10];

            printf("\n--- Delete Student ---\n");

            printf("กรอก ID ที่ต้องการลบ : ");
            scanf("%9s", id);

            /* ลบข้อมูล */
            if (deleteById(&head, id, &deletedStudent))
            {
                /* บันทึกข้อมูลที่ถูกลบไว้สำหรับ Undo */
                push(&stack, "DELETE", deletedStudent);

                printf("\nลบนักศึกษา %s เรียบร้อย\n", id);
            }
            else
            {
                printf("\nไม่พบ ID %s\n", id);
            }
        }

        /* ---------------------------------
           3. PRINT FORWARD
           --------------------------------- */
        else if (choice == 3)
        {
            printForward(head);
        }

        /* ---------------------------------
           4. PRINT BACKWARD
           --------------------------------- */
        else if (choice == 4)
        {
            printBackward(head);
        }

        /* ---------------------------------
           5. UNDO
           --------------------------------- */
        else if (choice == 5)
        {
            undo(&head, &stack);
        }

        /* ---------------------------------
           0. EXIT
           --------------------------------- */
        else if (choice == 0)
        {
            printf("\nจบการทำงาน\n");
        }

        else
        {
            printf("\nกรุณาเลือกเมนู 0-5\n");
        }

    } while (choice != 0);

    return 0;
}
