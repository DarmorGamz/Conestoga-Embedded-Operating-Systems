/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

#ifndef STACK_H_
#define STACK_H_

/** INCLUDES ******************************************************************/

/** STRUCTURES AND ENUMERATIONS *************************************/
#define ASCII_START 65
#define ASCII_END 122
#define SIZE 10

struct sNode {
    char* identifier;
    int priority;
    struct sNode* next;
};

struct Stack {
    struct sNode* front;
};

/** PROTOTYPES *************************************/
struct sNode* sNode(int tPriority);
struct Stack* Stack();
void Push(struct Stack* s, int tPriority);
void Pop(struct Stack* s);
void display(struct Stack* s, struct sNode* n);
void clean(struct Stack* s);

void Sort(struct Stack* s);

char* generateRandomString();


#endif