/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

#ifndef QUEUE_H_
#define QUEUE_H_

/** INCLUDES ******************************************************************/
#include <malloc.h>

/** STRUCTURES AND ENUMERATIONS *************************************/
#define ASCII_START 65
#define ASCII_END 122
#define SIZE 10

struct Node {
    char* identifier;
    int priority;
    struct Node* next;
};

struct Queue {
    struct Node* front;
};

/** PROTOTYPES *************************************/
struct Node* Node(int tPriority);
struct Queue* Queue();
void enQueue(struct Queue* q, int tPriority);
void deQueue(struct Queue* q);
void display(struct Queue* q, struct Node* n);
void clean(struct Queue* q);

char* generateRandomString();

#endif