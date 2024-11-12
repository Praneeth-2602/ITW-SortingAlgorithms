#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
    struct ListNode *prev; // Add this line
};

// Function to swap data of two nodes a and b
void swap(struct ListNode *a, struct ListNode *b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

// Partition the list taking the last element as the pivot
struct ListNode* partition(struct ListNode *low, struct ListNode *high) {
    int pivot = high->val;
    struct ListNode *i = low->prev;
    for (struct ListNode *j = low; j != high; j = j->next) {
        if (j->val <= pivot) {
            i = (i == NULL) ? low : i->next;
            swap(i, j);
        }
    }
    i = (i == NULL) ? low : i->next;
    swap(i, high);
    return i;
}

// QuickSort recursive function
void quickSort(struct ListNode *low, struct ListNode *high) {
    if (high != NULL && low != high && low != high->next) {
        struct ListNode *p = partition(low, high);
        quickSort(low, p->prev);
        quickSort(p->next, high);
    }
}

// Function to get the last node of the list
struct ListNode *getLastNode(struct ListNode *head) {
    while (head != NULL && head->next != NULL)
        head = head->next;
    return head;
}

// Function to print the linked list
void printList(struct ListNode *node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

// Function to create a new node
struct ListNode* newNode(int data) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = data;
    temp->next = NULL;
    return temp;
}

int main() {
    struct ListNode *a = newNode(10);
    a->next = newNode(7);
    a->next->next = newNode(8);
    a->next->next->next = newNode(9);
    a->next->next->next->next = newNode(1);
    a->next->next->next->next->next = newNode(5);

    struct ListNode *last = getLastNode(a);
    quickSort(a, last);

    printf("Sorted Linked List is: \n");
    printList(a);

    return 0;
}