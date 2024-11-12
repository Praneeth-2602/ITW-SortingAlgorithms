#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to swap data of two nodes a and b
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to perform selection sort on the linked list
void selectionSort(struct Node* head) {
    struct Node* temp = head;

    // Traverse the list
    while (temp) {
        struct Node* min = temp;
        struct Node* r = temp->next;

        // Traverse the unsorted sublist
        while (r) {
            if (r->data < min->data) {
                min = r;
            }
            r = r->next;
        }

        // Swap data of the current node with the minimum node
        swap(temp, min);
        temp = temp->next;
    }
}

// Function to insert a new node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver program to test the functions
int main() {
    struct Node* head = NULL;

    push(&head, 64);
    push(&head, 25);
    push(&head, 12);
    push(&head, 22);
    push(&head, 11);

    printf("Linked list before sorting:\n");
    printList(head);

    selectionSort(head);

    printf("Linked list after sorting:\n");
    printList(head);

    return 0;
}