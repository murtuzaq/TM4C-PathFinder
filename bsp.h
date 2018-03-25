/*
 * bsp.h
 *
 *  Created on: Mar 9, 2018
 *      Author: Murtuza
 */

#ifndef BSP_H_
#define BSP_H_

#include <stdint.h>
#include "csp_gpio.h"
#include "csp_intx.h"
#include "csp_tm4c.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define BSP_SW_01           CSP_GPIO_40
#define BSP_SW_02           CSP_GPIO_44
#define BSP_LED_RED         CSP_GPIO_41
#define BSP_LED_BLUE        CSP_GPIO_42
#define BSP_LED_GREEN       CSP_GPIO_43

void Bsp_Init(void);

//API
csp_gpio_dev_instance_t* Bsp_Gpio_Inst_Led_Red(void);
csp_gpio_dev_instance_t* Bsp_Gpio_Inst_Led_Green(void);
csp_gpio_dev_instance_t* Bsp_Gpio_Inst_Led_Blue(void);
csp_gpio_dev_instance_t* Bsp_Gpio_Inst_Sw_01(void);
csp_gpio_dev_instance_t* Bsp_Gpio_Inst_Sw_02(void);

csp_intx_dev_instance_t* Bsp_Intx_Inst_SW_01(void);


#ifdef __cplusplus
}
#endif

#endif /* BSP_H_ */
