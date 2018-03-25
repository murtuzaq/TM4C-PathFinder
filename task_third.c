//*****************************************************************************
//
// task_third.c
//
//*****************************************************************************

#include <stdint.h>

#include "task_third.h"
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

#define THIRDSTASKSTACKSIZE        128         // Stack size in words


static void THIRD_Task(void *pvParameters);


uint32_t THIRD_TaskInit(void)
{

    //
    // Create the LED task.
    //
    if(xTaskCreate(THIRD_Task,"THIRD", THIRDSTASKSTACKSIZE, NULL,
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

static void THIRD_Task(void *pvParameters)
{
	uint32_t k;

    csp_gpio_dev_instance_t* led_blue_inst;

    led_blue_inst = Bsp_Gpio_Inst_Led_Blue();

    while(1)
    {
    	k++;
        Csp_Gpio_Write(led_blue_inst, CSP_GPIO_STATE_HIGH);

        vTaskDelay(500);

        Csp_Gpio_Write(led_blue_inst, CSP_GPIO_STATE_LOW);

        vTaskDelay(500);
    }
}





