/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

/** INCLUDES ******************************************************************/
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/
struct Node* Node(int tPriority) {
    // Init new Node.
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    // Set Parameters.
    temp->identifier = generateRandomString();
    temp->priority = tPriority;
    temp->next = NULL;

    // Set Response.
    return temp;
}


struct Queue* Queue() {
    // Init new Queue.
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

    // Set vars.
    q->front = NULL;

    // Set Response.
    return q;
}


void enQueue(struct Queue* q, int tPriority) {
    if (tPriority < 1 || tPriority > 10) {
        printf("Priority must be between 1-10\n");
        return;
    }
    // Create a new node
    struct Node* temp = Node(tPriority);

    // If queue is empty, then new node is front and rear
    // both
    if (q->front == NULL) {
        q->front = temp;
        return;
    }

    struct Node* currentNode = q->front;

    // Check first Node.
    if (q->front->priority < temp->priority) {
        q->front = temp;
        temp->next = currentNode;
        return;
    }


    struct Node* previousNode = currentNode;
    while (currentNode != NULL) {
        if (currentNode->priority < temp->priority) {
            previousNode->next = temp;
            temp->next = currentNode;
            return;
        }

        // Iterate nodes.
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    previousNode->next = temp;
    return;
}

void deQueue(struct Queue* q) {
    // If queue is empty, return NULL.
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    // Store previous front and move front one node ahead
    struct Node* temp = q->front;

    // Move second item to first item, this can be NUll if queue is now empty.
    q->front = q->front->next;

    // Display info.
    display(q, temp);

    // Free memory.
    free(temp->identifier);
    free(temp);
}

void display(struct Queue* q, struct Node* n = NULL) {
    // Only 1 Node to display.
    if (n != NULL) {
        printf("Queue element removed:\nIdentifier - %s\nPriority - %d\n", n->identifier, n->priority);
        return;
    }

    // No items in Queue.
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue Elements:\n");
    int count = 1;
    while (temp != NULL) {
        printf("Location - %d\nIdentifier - %s\nPriority - %d\n", count, temp->identifier, temp->priority);

        temp = temp->next;
        count++;
    }
    printf("\n");
}

void clean(struct Queue* q) {
    // No Queue elements.
    if (q->front == NULL) {
        free(q);
        return;
    }

    // Queue elements.
    struct Node* next = NULL;
    if (q->front->next != NULL) {
        next = q->front->next;
    }
    while (q->front != NULL) {
        free(q->front->identifier);
        free(q->front);
        q->front = next;

        if (q->front != NULL) {
            next = q->front->next;
        }
    }

    free(q);
}

// https://codereview.stackexchange.com/questions/29198/random-string-generator-in-c
char* generateRandomString() {
    int i;
    char* res = (char*)malloc(SIZE + 1);
    for (i = 0; i < SIZE; i++) {
        res[i] = (char)(rand() % (ASCII_END - ASCII_START)) + ASCII_START;
    }
    res[i] = '\0';
    return res;
}