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

// Constants
#define MESSAGE_QUEUE_LENGTH 5
#define MESSAGE_VALUE 100
#define MESSAGE_ACK 1

// Prototypes
void TaskA(void* pvParameters);
void TaskB(void* pvParameters);

// Structures
typedef struct {
    int message;
    TaskFunction_t sender_task;
} Message_t;

QueueHandle_t message_queue;


void TaskA(void* pvParameters) {
    // Create Message Structure.
    Message_t message_sent = {
        .message = MESSAGE_VALUE,
        .sender_task = TaskA,
    };

    while (1) {
        // Send the message
        xQueueSend(message_queue, &message_sent, 0);

        // Print the Queue Length.
        char buffer[100];
        sprintf_s(buffer, sizeof(buffer), "Task A: Message Value Sent: %d, Queue length = %d\r\n", message_sent.message, uxQueueMessagesWaiting(message_queue));
        vPrintString(buffer);

        // Wait for TaskB to send back acknowledgement message with sender name
        Message_t message_received;
        while (xQueuePeek(message_queue, &message_received, 0) != pdTRUE || message_received.sender_task != TaskB) {}

        // Ack is in Queue, use Recieve to pop it.
        xQueueReceive(message_queue, &message_received, 0);

        // Print the Queue Length.
        sprintf_s(buffer, sizeof(buffer), "Task A: Ack Value Recieved: %d, Queue length = %d\r\n\n", message_received.message, uxQueueMessagesWaiting(message_queue));
        vPrintString(buffer);

        // Add a delay for visibility.
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void TaskB(void* pvParameters) {
    while (1) {
        // Wait for Message to be added to queue from TaskA.
        Message_t message_received;
        while (xQueuePeek(message_queue, &message_received, 0) != pdTRUE || message_received.sender_task != TaskA) {}

        // Message is in Queue, use Recieve to pop it.
        xQueueReceive(message_queue, &message_received, 0);

        // Print the Queue Length.
        char buffer[100];
        sprintf_s(buffer, sizeof(buffer), "Task B: Message Value Recieved: %d, Queue length = %d\r\n", message_received.message, uxQueueMessagesWaiting(message_queue));
        vPrintString(buffer);

        // Create acknowledgement.
        Message_t message_ack = {
            .message = MESSAGE_ACK,
            .sender_task = TaskB,
        };

        // Send the message
        xQueueSend(message_queue, &message_ack, 0);

        // Print the Queue Length.
        sprintf_s(buffer, sizeof(buffer), "Task B: Ack Value Sent: %d, Queue length = %d\r\n", message_ack.message, uxQueueMessagesWaiting(message_queue));
        vPrintString(buffer);

    }
}

void main_a() {
    message_queue = xQueueCreate(MESSAGE_QUEUE_LENGTH, sizeof(Message_t));

    xTaskCreate(TaskA, "TaskA", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(TaskB, "TaskB", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();
}