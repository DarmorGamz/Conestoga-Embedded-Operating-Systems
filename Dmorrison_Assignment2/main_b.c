/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/

/*
    Define three tasks vTask1, vTask2, and vTask3 such that when each task runs, its name is
    printed repeatedly. Create vTask1 and vTask2 before starting the scheduler. vTask3 should
    get created after the scheduler has started
*/

// Includes
#include "common.h"

int IdleHandler = 0;
int main_b(void) {
    IdleHandler = 1;
    // Define two tasks vTask1 and vTask2
    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Start the scheduler.
    vTaskStartScheduler();

    // Set response.
    return 0;
}

TaskHandle_t vTask3Handle = NULL;
void vApplicationIdleHook(void) {
    if (vTask3Handle == NULL && IdleHandler == 1) {
        xTaskCreate(vTask3, "Task 3", configMINIMAL_STACK_SIZE, NULL, 1, &vTask3Handle);
    }
}