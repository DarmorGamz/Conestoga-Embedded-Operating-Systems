/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/

/*
	Define a task vTask1 that repeated prints a string that was passed to it from main function.
*/

// Includes
#include "common.h"

// New implementation of the function
void vTask1_New0(void* pvParameters) {
	for (;;) {
		vPrintString((char*)pvParameters);
		vPrintReturn();
	}
}

#define vTask1 vTask1_New0

int main_c(void) {
	// Define a task vTask1
	xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, "Task 1", 1, NULL);

	// Start the scheduler.
	vTaskStartScheduler();

	// Set response.
	return 0;
}