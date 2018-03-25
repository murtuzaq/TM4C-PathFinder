//*****************************************************************************
//
// task_linefollower.c
//
//*****************************************************************************

#include <stdint.h>

#include "task_linefollower.h"
#include "bsp.h"

#include "FreeRTOS_Priorities.h"
#include "FreeRTOS\include\FreeRTOS.h"
#include "FreeRTOS\include\task.h"
#include "FreeRTOS\include\queue.h"
#include "FreeRTOS\include\semphr.h"
//*****************************************************************************
//
// The stack size for the task.
//
//*****************************************************************************

#define LINEFOLLOWSTASKSTACKSIZE        128         // Stack size in words


static void Linefollower_Task(void *pvParameters);


uint32_t Linefollower_TaskInit(void)
{

    //
    // Create the LED task.
    //
    if(xTaskCreate(Linefollower_Task,"LINE", LINEFOLLOWSTASKSTACKSIZE, NULL,
                   tskIDLE_PRIORITY + PRIORITY_THIRD_TASK, NULL) != pdTRUE)
    {
        while(1)
        {
            //lock up;
        }
    }

    //
    // Success.
    //
    return(0);
}

static void Linefollower_Task(void *pvParameters)
{
    uint32_t k;


    while(1)
    {
        k++;

        vTaskDelay(500);

    }
}
