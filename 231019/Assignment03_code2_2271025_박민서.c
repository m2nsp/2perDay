#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode {
    int data;
    struct ListNode* link; 
} ListNode;

typedef struct ListHeader {
    int length;
    ListNode* head;
    ListNode* tail;
} ListHeader;

void initList(ListHeader* plist) {
    plist->length = 0;
    plist->head = plist->tail = NULL;
}

void list_add(ListHeader* plist, int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->link = NULL;

    if (plist->head == NULL) {
        plist->head = newNode;
        plist->tail = newNode;
    } else {
        plist->tail->link = newNode;
        plist->tail = newNode;
    }

    plist->length++;
}


void mergeLists(ListHeader* plist1, ListHeader* plist2, ListHeader* plist3) {
    initList(plist3);
    ListNode *a = plist1->head;
    ListNode *b = plist2->head;
    ListNode *c = plist3->head;
    
while(a != NULL && b!= NULL){
    if(a->data < b->data){
        list_add(plist3, a->data);
        a = a->link;
    }else if (a->data > b->data) {
        list_add(plist3, b->data);
        b = b->link;
    } else {  // a->data == b->data
        list_add(plist3, a->data);
        a = a->link;
        b = b->link;
    }
    c = c->link;
}

    while (a != NULL) {
        list_add(plist3, a->data);
        a = a->link;
        c = c->link;
    }


    while (b != NULL) {
        list_add(plist3, b->data);
        b = b->link;
        c = c->link;
    }
}


void list_print(ListHeader *plist) {
    ListNode *p = plist->head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

int main() {
    //Initialization of linked list
    ListHeader plist1, plist2, plist3;
    initList(&plist1);
    initList(&plist2);
    initList(&plist3);
    //Generate list1
    list_add(&plist1, 1);
    list_add(&plist1, 2);
    list_add(&plist1, 5);
    list_add(&plist1, 10);
    list_add(&plist1, 15);
    list_add(&plist1, 20);
    list_add(&plist1, 25);
    //Generate list2
    list_add(&plist2, 3);
    list_add(&plist2, 7);
    list_add(&plist2, 8);
    list_add(&plist2, 15);
    list_add(&plist2, 18);
    list_add(&plist2, 30);

    // list1 + list2 = list3 
    mergeLists(&plist1, &plist2, &plist3);

    // Print the merged list (list3 now contains the merged result)
    printf("Merged List: ");
    list_print(&plist3);

    // Free memory (you should free nodes individually)
    free(plist1.head);
    free(plist2.head);
    free(plist3.head);

    return 0;
}