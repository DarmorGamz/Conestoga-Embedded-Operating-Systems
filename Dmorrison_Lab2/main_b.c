/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/

// Includes
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include "supporting_functions.h"
#include <stdio.h>
#include <semphr.h>

// Prototypes
void TaskA(void* pvParameters);
void TaskB(void* pvParameters);

/* Define shared variable */
int shared_var = 100;

/* Define semaphores */
SemaphoreHandle_t sem_A, sem_B;

void task_A(void* pvParameters) {
    while (1) {
        /* Wait for Task B to read and print the value */
        xSemaphoreTake(sem_A, portMAX_DELAY);

        /* Increment shared variable */
        shared_var++;

        /* Release semaphore to allow Task B to proceed */
        xSemaphoreGive(sem_B);
    }
}

void task_B(void* pvParameters) {
    while (1) {
        /* Wait for Task A to increment the shared variable */
        xSemaphoreTake(sem_B, portMAX_DELAY);

        /* Read and print the value of shared variable */
        char buffer[100];
        sprintf_s(buffer, sizeof(buffer), "Shared variable value: %d\n", shared_var);
        vPrintString(buffer);

        /* Release semaphore to allow Task A to proceed */
        xSemaphoreGive(sem_A);

        // Add a delay for visibility.
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

int main_b(void) {
    /* Create semaphores */
    sem_A = xSemaphoreCreateBinary();
    sem_B = xSemaphoreCreateBinary();

    /* Initialize semaphores to start with Task B */
    xSemaphoreGive(sem_B);

    /* Create tasks */
    xTaskCreate(task_A, "Task A", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(task_B, "Task B", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    /* Start scheduler */
    vTaskStartScheduler();

    return 0;
}