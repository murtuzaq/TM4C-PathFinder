//*****************************************************************************
//
// task_second.c
//
//*****************************************************************************

#include <stdint.h>

#include "task_second.h"
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

#define SECONDTASKSTACKSIZE        128         // Stack size in words


static void SECOND_Task(void *pvParameters)
{
	uint32_t j;

    csp_gpio_dev_instance_t* led_green_inst;
    csp_gpio_dev_instance_t* sw_01_inst;

    led_green_inst = Bsp_Gpio_Inst_Led_Green();
    sw_01_inst = Bsp_Gpio_Inst_Sw_01();

	while(1)
    {
		j++;

        if (Csp_Gpio_Read(sw_01_inst) == CSP_GPIO_STATE_HIGH)
        {

            Csp_Gpio_Write(led_green_inst, CSP_GPIO_STATE_HIGH);
        }

        vTaskDelay(500);

        Csp_Gpio_Write(led_green_inst, CSP_GPIO_STATE_LOW);

        vTaskDelay(500);


    }
}


uint32_t SECOND_TaskInit(void)
{

    if(xTaskCreate(SECOND_Task, "SECOND", SECONDTASKSTACKSIZE, NULL,
                   tskIDLE_PRIORITY + PRIORITY_SECOND_TASK, NULL) != pdTRUE)
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



