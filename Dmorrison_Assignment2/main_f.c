/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/

/*
	Define three tasks vTask1, vTask2, and vTask3 and write code such that they always run in
	the order vTask1, vTask3, vTask2.
*/

// Includes
#include "common.h"

int main_f(void) {
	// Define two tasks vTask1, vTask2 and vTask3.
	xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, "Task 1", 3, NULL);
	xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, "Task 2", 1, NULL);
	xTaskCreate(vTask3, "Task 3", configMINIMAL_STACK_SIZE, "Task3", 2, NULL);

	// Start the scheduler.
	vTaskStartScheduler();

	// Set response.
	return 0;
}