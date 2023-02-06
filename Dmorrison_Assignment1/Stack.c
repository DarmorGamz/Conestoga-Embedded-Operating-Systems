/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/


/** INCLUDES ******************************************************************/
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/
struct sNode* sNode(int tPriority) {
    // Init new Node.
    struct sNode* temp = (struct sNode*)malloc(sizeof(struct sNode));

    // Set Parameters.
    temp->identifier = generateRandomString();
    temp->priority = tPriority;
    temp->next = NULL;

    // Set Response.
    return temp;
}


struct Stack* Stack() {
    // Init new Queue.
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));

    // Set vars.
    s->front = NULL;

    // Set Response.
    return s;
}


void Push(struct Stack* s, int tPriority) {
    if (tPriority < 1 || tPriority > 10) {
        printf("Priority must be between 1-10\n");
        return;
    }
    // Create a new node
    struct sNode* temp = sNode(tPriority);

    // If stack is empty, then new node is front
    if (s->front == NULL) {
        s->front = temp;
        return;
    }

    struct sNode* currentNode = s->front;
    s->front = temp;
    s->front->next = currentNode;

    return;
}

void Pop(struct Stack* s) {
    // If stack is empty, return NULL.
    if (s->front == NULL) {
        printf("Stack is empty\n");
        return;
    }

    // Store previous front and move front one node ahead
    struct sNode* temp = s->front;

    // Move second item to first item, this can be NUll if queue is now empty.
    s->front = s->front->next;

    // Display info.
    display(s, temp);

    // Free memory.
    free(temp->identifier);
    free(temp);
}

void display(struct Stack* s, struct sNode* n = NULL) {
    // Only 1 Node to display.
    if (n != NULL) {
        printf("Stack element removed:\nIdentifier - %s\nPriority - %d\n", n->identifier, n->priority);
        return;
    }

    // No items in Stack.
    if (s->front == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct sNode* temp = s->front;
    printf("Stack Elements:\n");
    int count = 1;
    while (temp != NULL) {
        printf("Location - %d\nIdentifier - %s\nPriority - %d\n", count, temp->identifier, temp->priority);

        temp = temp->next;
        count++;
    }
    printf("\n");
}

void clean(struct Stack* s) {
    // No Stack elements.
    if (s->front == NULL) {
        free(s);
        return;
    }

    // Stack elements.
    struct sNode* next = NULL;
    if (s->front->next != NULL) {
        next = s->front->next;
    }
    while (s->front != NULL) {
        free(s->front->identifier);
        free(s->front);
        s->front = next;

        if (s->front != NULL) {
            next = s->front->next;
        }
    }

    free(s);
}

/*Function to swap the nodes */
struct sNode* swap(struct sNode* ptr1, struct sNode* ptr2) {
    struct sNode* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void Sort(struct Stack* s) {
    int swapped = 0;
    while (swapped == 0) {
        struct sNode* current = s->front;
        struct sNode* prev = s->front;
        bool isFirst = true;
        swapped = 0;

        while (current->next != NULL) {
            if (current->priority < current->next->priority) {
                
                current = swap(current, current->next);
                
                if (isFirst) {
                    s->front = current;
                    isFirst = false;
                } else {
                    prev->next = current;
                }
                swapped++;
            }

            prev = current;
            current = current->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0) break;
    }
}
