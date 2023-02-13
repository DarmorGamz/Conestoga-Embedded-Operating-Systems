/********************************************
Author: Darren Morrison
Email: dmorrison8832@conestogac.on.ca
SN: 8258832
*********************************************/

#ifndef COMMON_H_
#define COMMON_H_
/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "supporting_functions.h"

/* The task function. */
inline void vTask1(void* pvParameters);
inline void vTask2(void* pvParameters);
inline void vTask3(void* pvParameters);
inline void vPrintReturn(void);

void vPrintReturn() {
    vPrintString("\n");
}

void vTask1(void* pvParameters) {
    for (;;) {
        vPrintString("vTask1\n");
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void vTask2(void* pvParameters) {
    for (;;) {
        vPrintString("vTask2\n");
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void vTask3(void* pvParameters) {
    for (;;) {
        vPrintString("vTask3\n");
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
#endif /* COMMON_H_ */

