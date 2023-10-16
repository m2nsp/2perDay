#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int element;

typedef struct DlistNode {
	element data;
	struct DlistNode *llink;
    struct DlistNode *rlink;
} DlistNode;

typedef struct {
    DlistNode* top; 
    DlistNode* bottom; 
    int length;     
} CDlinkedStackType;

void init(CDlinkedStackType* list) {
    list->top = NULL;
    list->bottom = NULL;
}

int is_empty(CDlinkedStackType *s)
{
	return (s->top == NULL);
}

void push(CDlinkedStackType* s, element data) {
    DlistNode* temp = (DlistNode*)malloc(sizeof(DlistNode));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return;
    } else {
        temp->data = data;
        if (s->top == NULL) {
            // If the stack is empty, set both top and bottom to temp
            s->top = temp;
            s->bottom = temp;
        } else {
            // Connect temp to the previous top
            temp->llink = s->top;
            temp->rlink = s->bottom;
            s->top->rlink = temp;
            s->top = temp; // Update the top to temp
        }
    }
}

element pop(CDlinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		DlistNode *temp = s->top;
		int data = temp->data;
		s->top = s->top->llink;
		free(temp);
		return data;
	}
}

element peek(CDlinkedStackType *s)
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