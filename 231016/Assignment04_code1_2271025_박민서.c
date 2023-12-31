#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int element;

typedef struct DlistNode {
    element data;
    struct DlistNode* llink;
    struct DlistNode* rlink;
} DlistNode;

typedef struct {
    DlistNode* top;
} CDlinkedStackType;

void init(CDlinkedStackType* list) {
    list->top = NULL;
}

int is_empty(CDlinkedStackType* s)
{
    return (s->top == NULL);
}

void push(CDlinkedStackType* s, element data) {
    DlistNode* temp = (DlistNode*)malloc(sizeof(DlistNode));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return;
    }
    else {
        temp->data = data;
        if (is_empty(s)) {
            // If the stack is empty, set both top and bottom to temp
            temp->llink = temp;
            temp->rlink = temp;
        }
        else {
            // Connect temp to the previous top
            temp->llink = s->top;
            temp->rlink = s->top->rlink;
            s->top->rlink->llink = temp;
            s->top->rlink = temp; 
        }
        s->top = temp;  // Update the top to temp
    }
}

element pop(CDlinkedStackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else {
        DlistNode* temp = s->top;
        int data = temp->data;
        s->top = temp->llink;

        if (s->top == temp) {
            s->top = NULL;
        }
        else {
            temp->llink->rlink = temp->rlink;
            temp->rlink->llink = temp->llink;
        }
        free(temp);
        return data;
    }
}

element peek(CDlinkedStackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else {
        return s->top->data;
    }
}

int main() {
    CDlinkedStackType s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    return 0;
}