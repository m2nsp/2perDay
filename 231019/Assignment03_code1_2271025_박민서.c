#include <stdio.h>
#include <stdlib.h>

typedef struct DlistNode {
    int data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
} DlistNode;

typedef struct ListHeader {                         
    DlistNode *head;
    DlistNode *tail;
} ListHeader;

void initialize(ListHeader *listHeader) {
    listHeader->head = NULL;
    listHeader->tail = NULL;
}

void dinsert_first_node(ListHeader *listHeader, int data) {
    DlistNode *new_node = (DlistNode *)malloc(sizeof(DlistNode));
    new_node->data = data;
    new_node->llink = NULL;
    new_node->rlink = NULL;

    if (listHeader->head == NULL) {
        // 리스트가 비어있을 경우, 새로운 노드가 유일한 노드가 됩니다.
        listHeader->head = new_node;
        listHeader->tail = new_node;
    } else {
        new_node->rlink = listHeader->head;
        listHeader->head->llink = new_node;
        listHeader->head = new_node;
    }
}

void dinsert_last_node(ListHeader *listHeader, int data) {
    DlistNode *new_node = (DlistNode *)malloc(sizeof(DlistNode));
    new_node->data = data;
    new_node->llink = NULL;
    new_node->rlink = NULL;

    if (listHeader->head == NULL) {
        // 리스트가 비어있을 경우, 새로운 노드가 유일한 노드가 됩니다.
        listHeader->head = new_node;
        listHeader->tail = new_node;
    } else {
        DlistNode *current = listHeader->tail;
        current->rlink = new_node;
        new_node->llink = current;
        new_node->rlink = NULL;
        listHeader->tail = new_node;
    }
}
