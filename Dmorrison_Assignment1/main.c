/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

/** INCLUDES ******************************************************************/
#include <iostream>
#include "Queue.h"
#include "Stack.h"

/** PROTOTYPES *************************************/
void QueueProgram();
void StackProgram();

/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/

/**
*  Main Program entry.
*  @return int Return success.
*/
int main() {
	// Init vars.
	srand(time(NULL));
	int userChoice;

	// Infinite State Loop.
	while (true) {
		userChoice = 0;

		printf("Do you want to be the Queue program? Or the Stack program?\n");
		printf("1. Queue\n2. Stack\n3. Exit\nPlease enter selection: ");
		scanf_s("%d", &userChoice);

		system("cls");
		switch (userChoice) {
		case 1: // Queue.
			printf("QUEUE PROGRAM\n\n");
			QueueProgram();
			break;
		case 2: // Stack.
			printf("STACK PROGRAM\n\n");
			StackProgram();
			break;
		case 3: // Exit.
			printf("PROGRAM EXIT\n\n");
			exit(0);
			break;
		default:
			printf("Invalid selection!\n");
			break;
		}
	}

	return true;
}

void QueueProgram() {
	struct Queue* q = Queue();

	int userChoice;
	int priority;
	while (true) {
		userChoice = 0;
		printf("1. Add Element\n2. Remove Element\n3. Display Elements\n4. Exit\nPlease enter selection: ");
		scanf_s("%d", &userChoice);

		printf("\n");
		switch (userChoice) {
		case 1: // Add
			priority = 0;
			printf("Adding new Queue element!\nPlease enter priority between 1-10: ");
			scanf_s("%d", &priority);
			enQueue(q, priority);
			break;
		case 2: // Remove
			deQueue(q);

			break;
		case 3: // Display
			display(q, NULL);
			break;
		case 4: // Exit
			clean(q);
			printf("PROGRAM EXIT\n\n");
			exit(0);
			break;
		}

		printf("\n");
	}
}

void StackProgram() {
	struct Stack* s = Stack();

	int userChoice;
	int priority;
	while (true) {
		userChoice = 0;
		printf("1. Add Element\n2. Remove Element\n3. Display Elements\n4. Exit\nPlease enter selection: ");
		scanf_s("%d", &userChoice);

		printf("\n");
		switch (userChoice) {
		case 1: // Add
			priority = 0;
			printf("Adding new Stack element!\nPlease enter priority between 1-10: ");
			scanf_s("%d", &priority);
			Push(s, priority);
			Sort(s);
			break;
		case 2: // Remove
			Pop(s);

			break;
		case 3: // Display
			display(s, NULL);
			break;
		case 4: // Exit
			clean(s);
			printf("PROGRAM EXIT\n\n");
			exit(0);
			break;
		}

		printf("\n");
	}
}