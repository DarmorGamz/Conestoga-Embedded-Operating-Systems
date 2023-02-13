/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/

/*
	Define two tasks vTask1 and vTask2. After vTask1 runs for the first time, it should get
	“starved.” That is, vTask2 keeps running afterwards and vTask1 keeps waiting for its turn to
	run.
*/

// Includes
#include "common.h"

// New implementation of the function
void vTask1_New2(void* pvParameters) {
	vPrintString("vTask1");
	vPrintReturn();
	vTaskSuspend(NULL); // Sets Task1 into 'blocked' state.
}

#define vTask1 vTask1_New2

int main_e(void) {
	// Define two tasks vTask1 and vTask2.
	xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, "Task 1", 1, NULL);
	xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, "Task 2", 1, NULL);

	// Start the scheduler.
	vTaskStartScheduler();

	// Set response.
	return 0;
}