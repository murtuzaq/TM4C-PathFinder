
/* Standard includes. */
#include <stdint.h>
/* Kernel includes. */
#include "FreeRTOS/include/FreeRTOS.h"
#include "FreeRTOS/include/task.h"

/*Application include*/
#include "task_first.h"
#include "task_second.h"
#include "task_third.h"
#include "bsp.h"
/*-----------------------------------------------------------*/



void main(void)
{

	while (1) {

	    //hardware resource initilization;
	    Bsp_Init();

		if (FIRST_TaskInit() != 0) {

			while (1) {
			}
		}

		if (SECOND_TaskInit() != 0) {

			while (1) {
			}
		}

		if (THIRD_TaskInit() != 0) {
			while (1) {
			}
		}

		Linefollower_TaskInit();

		//
		// Start the scheduler.  This should not return.
		//
		vTaskStartScheduler();

		//
		// In case the scheduler returns for some reason, print an error and loop
		// forever.
		//

		while (1) {
		}
	}

}

