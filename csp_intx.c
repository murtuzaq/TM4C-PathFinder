/*
 * csp_intx.c
 *
 *  Created on: Mar 11, 2018
 *      Author: Murtuza
 */

#include "csp_tm4c.h"
#include "csp_intx.h"
#include "tm4c123gh6pm.h"


 uint32_t bounce_number = 0;
 static csp_intx_dev_instance_t* hintx[CSP_GPIO_MAX_PORT][CSP_GPIO_MAX_PIN];       //register hw instance to global array

void Csp_Intx_Init(csp_intx_dev_instance_t* intx_inst, csp_intx_dev_config_t intx_config)
{
    uint8_t port;
    uint8_t pin;

    intx_inst->name = intx_config.text;
    intx_inst->gpio_inst = intx_config.gpio_inst;
    intx_inst->func = intx_config.func;

    port = intx_inst->gpio_inst->port;
    pin = intx_inst->gpio_inst->portpin;

    hintx[port][pin] = intx_inst;

    *PTR_PORT_IM[port] &= ~( 1 << pin); //the interrupt from the corresponding pin is masked

    //prepare interrupt for double sided edge detection;
    *PTR_PORT_IS[port] &= ~(1 << pin);                  //clear bit to interrupt on the edge
    *PTR_PORT_IBE[port] |= (1 << pin);                  // set bit to trigger on both edge

    *PTR_PORT_ICR[port] |= (1 << pin);                  //clear the bit in GPIORIS register

    *PTR_PORT_IM[port] |= ( 1 << pin);                  //unmask the port in the GPIOIM register

    *PTR_NVIC_EN_REG[port] |= PORT_NVIC_EN_MASK[port];  //enable nvic interrupt bit;


}


void Csp_Intx_Interrupt(void)
{
    uint8_t port;
    uint8_t pin;

    //find out who caused the interrupt;
    for (port = 0; port < 6; port++)
    {
        if ((SYSCTL_RCGCGPIO_R  & (1 << port) ) == (1 << port) )      //if port is enabled;
        {
            if (*PTR_PORT_MIS[port] > 0)
            {
                for (pin = 0; pin < 8; pin ++)
                {
                    if ( (*PTR_PORT_MIS[port] & (1 << pin)) == (1 << pin) )
                    {
                        bounce_number++;

                        if (hintx[port][pin]->func != 0)    //if function exist
                        {
                            hintx[port][pin]->func();       //execute call back function;
                        }
                        *PTR_PORT_ICR[port] |= (1 << pin);  //clear interrupt;
                        break;
                    }
                }
            }
        }
    }

}




