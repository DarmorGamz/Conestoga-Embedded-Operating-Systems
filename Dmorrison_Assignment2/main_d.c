/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/

/*
	 Define two tasks vTask1 and vTask2 such that whenever vTask1 runs it prints its name and
	the string “Going to sleep for 30 ticks” and enters “Blocked” state for 30 ticks. When vTask2
	runs, it repeatedly prints its name.
*/

// Includes
#include "common.h"

// New implementation of the function
void vTask1_New(void* pvParameters) {
	for (;;) {
		vPrintString((char*)pvParameters);
		vPrintReturn();
		vPrintString("Going to sleep for 30 ticks\n");
		vTaskDelay(30);
	}
}

#define vTask1 vTask1_New

int main_d(void) {
	xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, "Task 1", 1, NULL);
	xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, "Task 2", 1, NULL);

	// Start the scheduler.
	vTaskStartScheduler();

	// Set response.
	return 0;
}