//*****************************************************************************
//
// task_first.c
//
//*****************************************************************************

#include <stdint.h>

#include "task_first.h"
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

#define FIRSTSTASKSTACKSIZE        128         // Stack size in words


static void FIRST_Task(void *pvParameters);


uint32_t FIRST_TaskInit(void)
{

    //
    // Create the task.
    //
    if(xTaskCreate(FIRST_Task, "FIRST", FIRSTSTASKSTACKSIZE, NULL,
                   tskIDLE_PRIORITY + PRIORITY_FIRST_TASK, NULL) != pdTRUE)
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



static void FIRST_Task(void *pvParameters)
{
	uint32_t i;
	csp_gpio_dev_instance_t* led_red_inst;
	csp_gpio_dev_instance_t* sw_02_inst;

	led_red_inst = Bsp_Gpio_Inst_Led_Red();
	sw_02_inst = Bsp_Gpio_Inst_Sw_02();

    while(1)
    {
    	i++;

    	if (Csp_Gpio_Read(sw_02_inst) == CSP_GPIO_STATE_HIGH)
    	{

    	    Csp_Gpio_Write(led_red_inst, CSP_GPIO_STATE_HIGH);
    	}

    	vTaskDelay(500);

    	Csp_Gpio_Write(led_red_inst, CSP_GPIO_STATE_LOW);

    	vTaskDelay(500);
    }
}





