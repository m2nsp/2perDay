#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

typedef struct {
    ListNode* head; 
    ListNode* tail; 
    int length;     
} ListType;


void init(ListType* list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}


int is_empty(ListType* list) {
    return list->length == 0;
}

void add_first(ListType* list, element data) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = list->head;

    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }

    list->length++;
}

void add_last(ListType* list, element data) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = NULL;

    if (is_empty(list)) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        list->tail->link = new_node;
        list->tail = new_node;
    }

    list->length++;
}

// Function to delete a node from the beginning of the list
void delete_first(ListType* list) {
    if (!is_empty(list)) {
        ListNode* temp = list->head;
        list->head = list->head->link;
        free(temp);
        list->length--;

        if (is_empty(list)) {
            list->tail = NULL; // If the list becomes empty after deletion
        }
    }
}

// Function to delete a node from the end of the list
void delete_last(ListType* list) {
    if (!is_empty(list)) {
        if (list->length == 1) {
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
        }
        else {
            ListNode* current = list->head;
            while (current->link != list->tail) {
                current = current->link;
            }
            free(list->tail);
            current->link = NULL;
            list->tail = current;
        }
        list->length--;
    }
}


void add(ListType* list, int position, element data) {
    if (position < 0 || position > list->length) {
        fprintf(stderr, "Invalid position for add\n");
        exit(1);
    }

    if (position == 0) {
        add_first(list, data);
    }
    else if (position == list->length) {
        add_last(list, data);
    }
    else {
        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }
        new_node->data = data;

        ListNode* prev = list->head;
        for (int i = 0; i < position - 1; i++) {
            prev = prev->link;
        }

        new_node->link = prev->link;
        prev->link = new_node;
        list->length++;
    }
}

void delete(ListType* list, int position) {
    if (position < 0 || position >= list->length) {
        fprintf(stderr, "Invalid position for delete\n");
        exit(1);
    }

    if (position == 0) {
        delete_first(list);
    }
    else if (position == list->length - 1) {
        delete_last(list);
    }
    else {
        ListNode* prev = list->head;
        for (int i = 0; i < position - 1; i++) {
            prev = prev->link;
        }

        ListNode* temp = prev->link;
        prev->link = temp->link;
        free(temp);
        list->length--;
    }
}

void display(ListType* list) {
    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

int is_in_list(ListType* list, element data) {
    ListNode* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return 1; // TRUE
        }
        current = current->link;
    }
    return 0; // FALSE
}

element get_entry(ListType* list, int position) {
    if (position < 0 || position >= list->length) {
        fprintf(stderr, "Invalid position for get_entry\n");
        exit(1);
    }

    ListNode* current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->link;
    }

    return current->data;
}

int main() {
    ListType list1;
    init(&list1);

    add_first(&list1, 20);
    add_last(&list1, 30);
    add_first(&list1, 10);
    add_last(&list1, 40);
    add(&list1, 2, 70);

    printf("List after adding elements:\n");
    display(&list1);

    delete(&list1, 2);
    delete_first(&list1);
    delete_last(&list1);

    printf("\nList after deleting elements:\n");
    display(&list1);

    printf("Is 20 in the list? %s\n", is_in_list(&list1, 20) ? "TRUE" : "FALSE");
    printf("Entry at position 0: %d\n", get_entry(&list1, 0));
}