/*
 * FreeRTOS_Overflow.c
 *
 */
#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/task.h"

//Stack Usage and Stack Overflow Checking
//This hook is called by FreeRTOS when an stack overflow error is detected.
//Stack Overflow Detection (Method 2) enabled when CHECK_FOR_STACK_OVERFLOW
//is set to 2.  When detection occurs, the below function will execute.
void vApplicationStackOverflowHook(TaskHandle_t *pxTask, char *pcTaskName)
{
    //
    // This function can not return, so loop forever.  Interrupts are disabled
    // on entry to this function, so no processor interrupts will interrupt
    // this loop.
    //
    while(1)
    {
    }
}


