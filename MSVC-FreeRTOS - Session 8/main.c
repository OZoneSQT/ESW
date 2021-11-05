#include <stdio.h>
// #include "FreeRTOS.h"
#include "FreeRTOS/Source/include/task.h"
#include "FreeRTOS/Source/include/FreeRTOS.h"

/* Priorities at which the tasks are created. */
#define TASK_MY_TASK_PRIORITY			( tskIDLE_PRIORITY + 1 )
#define	TASK_MY_SECOND_TASK_PRIORITY	( tskIDLE_PRIORITY + 2 )
#define	TASK_MY_THIRD_TASK_PRIORITY	( tskIDLE_PRIORITY + 3 )
/* Task stack sizes*/
#define TASK_MY_TASK_STACK				( configMINIMAL_STACK_SIZE )
#define	TASK_MY_SECOND_TASK_STACK		( configMINIMAL_STACK_SIZE )
#define	TASK_MY_THIRD_TASK_STACK		( configMINIMAL_STACK_SIZE )

/* Task Handles */
TaskHandle_t _taskSecondHandle = NULL;


// --------------------------------------------------------------------------------------
xSemaphoreHandle xSemaphoreMutex_A = NULL;
void taskMyTask(void* pvParameters)
{
	xSemaphoreMutex_A = xSemaphoreCreateMutex();
	xSemaphoreTake(xSemaphoreMutex_A, portMAX_DELAY);

	// Remove compiler warnings.
	(void)pvParameters;

		for (;;)
		{
			vTaskDelay(pdMS_TO_TICKS(200));
			puts("Hi from My Task 1");
		}
	
	xSemaphoreGive(xSemaphoreMutex_A);

}

// --------------------------------------------------------------------------------------
xSemaphoreHandle xSemaphoreMutex_B = NULL;
void taskMySeccondTask(void* pvParameters)
{
	
	xSemaphoreTake(xSemaphoreMutex_B, portMAX_DELAY);

	// Remove compiler warnings.
	(void)pvParameters;


		for (;;)
		{
			vTaskDelay(pdMS_TO_TICKS(200));
			puts("Hi from My Task 2");
		}

	xSemaphoreGive(xSemaphoreMutex_B);

}

// --------------------------------------------------------------------------------------
xSemaphoreHandle xSemaphoreMutex_C = NULL;
void taskMyThirdTask(void* pvParameters)
{
	
	xSemaphoreTake(xSemaphoreMutex_C, portMAX_DELAY);

	// Remove compiler warnings.
	(void)pvParameters;

		for (;;)
		{
			vTaskDelay(pdMS_TO_TICKS(200));
			puts("Hi from My Task 3");
		}
	
	xSemaphoreGive(xSemaphoreMutex_C);
}

// --------------------------------------------------------------------------------------
void main(void)
{
	//	Create mutex
	
	xSemaphoreMutex_B = xSemaphoreCreateMutex();
	xSemaphoreMutex_C = xSemaphoreCreateMutex();


	/* Create the task, not storing the handle. */
	xTaskCreate(
		taskMyTask,       /* Function that implements the task. */
		"MyTask",          /* Text name for the task. */
		TASK_MY_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)1,    /* Parameter passed into the task. */
		TASK_MY_TASK_PRIORITY,/* Priority at which the task is created. */
		NULL);      /* Used to pass out the created task's handle. */

		/* Create the task, storing the handle. */
	xTaskCreate(
		taskMySeccondTask,       /* Function that implements the task. */
		"MySecondTask",          /* Text name for the task. */
		TASK_MY_SECOND_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)2,    /* Parameter passed into the task. */
		TASK_MY_SECOND_TASK_PRIORITY,/* Priority at which the task is created. */
		&_taskSecondHandle);      /* Used to pass out the created task's handle. */

		/* Create the task, storing the handle. */
	xTaskCreate(
		taskMyThirdTask,       /* Function that implements the task. */
		"MyThirdTask",          /* Text name for the task. */
		TASK_MY_THIRD_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)2,    /* Parameter passed into the task. */
		TASK_MY_THIRD_TASK_PRIORITY,/* Priority at which the task is created. */
		&_taskSecondHandle);      /* Used to pass out the created task's handle. */

	// Let the operating system take over :)
	vTaskStartScheduler();
}