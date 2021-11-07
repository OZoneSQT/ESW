#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include <semphr.h>

/* Priorities at which the tasks are created. */
#define TASK_MY_FIRST_TASK_PRIORITY		( tskIDLE_PRIORITY + 1 )
#define	TASK_MY_SECOND_TASK_PRIORITY	( tskIDLE_PRIORITY + 2 )
#define	TASK_MY_THIRD_TASK_PRIORITY		( tskIDLE_PRIORITY + 3 )
#define	TASK_MY_FOURTH_TASK_PRIORITY	( tskIDLE_PRIORITY + 4 )

/* Task stack sizes*/
#define TASK_MY_FIRST_TASK_STACK		( configMINIMAL_STACK_SIZE )
#define	TASK_MY_SECOND_TASK_STACK		( configMINIMAL_STACK_SIZE )
#define	TASK_MY_THIRD_TASK_STACK		( configMINIMAL_STACK_SIZE )
#define	TASK_MY_TOURTH_TASK_STACK		( configMINIMAL_STACK_SIZE )

/* Task Handles */
TaskHandle_t _taskSecondHandle = NULL;
TaskHandle_t _taskThirdHandle = NULL;
TaskHandle_t _taskFourthHandle = NULL;

//create storage for a pointer to a mutex (this is the same container as a semaphore)
SemaphoreHandle_t mutexPtr = NULL;

// --------------------------------------------------------------------------------------

void taskMyFirstTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		if (xSemaphoreTake(mutexPtr, portMAX_DELAY))
		{
			puts("Hi from first My Task");
			xSemaphoreGive(mutexPtr);
		}

		vTaskDelay(pdMS_TO_TICKS(200));
	}
}


// --------------------------------------------------------------------------------------

void taskMySeccondTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		if (xSemaphoreTake(mutexPtr, portMAX_DELAY))
		{
			puts("Hi from My Second Task");
			xSemaphoreGive(mutexPtr);
		}

		vTaskDelay(pdMS_TO_TICKS(300));
	}
}


// --------------------------------------------------------------------------------------

void taskMyThirdTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		if (xSemaphoreTake(mutexPtr, portMAX_DELAY))
		{
			puts("Hi from My Third Task");
			xSemaphoreGive(mutexPtr);
		}

		vTaskDelay(pdMS_TO_TICKS(400));
	}
}


// --------------------------------------------------------------------------------------


void taskMyFourthTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		if (xSemaphoreTake(mutexPtr, portMAX_DELAY))
		{
			puts("Hi from My Fourth Task");
			xSemaphoreGive(mutexPtr);
		}

		vTaskDelay(pdMS_TO_TICKS(400));
	}
}


// --------------------------------------------------------------------------------------


void main(void)
{

	/* Create the task, not storing the handle. */
	xTaskCreate(
		taskMyFirstTask,				/* Function that implements the task. */
		"MyFirstTask",						/* Text name for the task. */
		TASK_MY_FIRST_TASK_STACK,		/* Stack size in words, not bytes. */
		(void*)1,						/* Parameter passed into the task. */
		TASK_MY_FIRST_TASK_PRIORITY,	/* Priority at which the task is created. */
		NULL);							/* Used to pass out the created task's handle. */

	/* Create the task, storing the handle. */
	xTaskCreate(
		taskMySeccondTask,				/* Function that implements the task. */
		"MySecondTask",					/* Text name for the task. */
		TASK_MY_SECOND_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)2,						/* Parameter passed into the task. */
		TASK_MY_SECOND_TASK_PRIORITY,	/* Priority at which the task is created. */
		&_taskSecondHandle);			/* Used to pass out the created task's handle. */

	/* Create the task, storing the handle. */ 
	xTaskCreate(
		taskMyThirdTask,				/* Function that implements the task. */
		"MyThirdTask",					/* Text name for the task. */
		TASK_MY_THIRD_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)3,						/* Parameter passed into the task. */
		TASK_MY_THIRD_TASK_PRIORITY,	/* Priority at which the task is created. */
		&_taskThirdHandle);				/* Used to pass out the created task's handle. */

	/* Create the task, storing the handle. */
	xTaskCreate(
		taskMyFourthTask,				/* Function that implements the task. */
		"MyThirdTask",					/* Text name for the task. */
		TASK_MY_TOURTH_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)4,						/* Parameter passed into the task. */
		TASK_MY_FOURTH_TASK_PRIORITY,	/* Priority at which the task is created. */
		&_taskFourthHandle);				/* Used to pass out the created task's handle. */


	//create a mutex - note this is just a special case of a binary semaphore
	mutexPtr = xSemaphoreCreateMutex();

	// Let the operating system take over :)
	vTaskStartScheduler();

}