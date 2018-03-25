/*
 * bsp.c
 *
 *  Module that contains all of system resources
 *  Created on: Mar 9, 2018
 *      Author: Murtuza
 */

#include "bsp.h"

static void Bsp_Hw_Init_Led_Red(void);
static void Bsp_Hw_Init_Led_Green(void);
static void Bsp_Hw_Init_Led_Blue(void);
static void Bsp_Hw_Init_Sw_01(void);
static void Bsp_Hw_Init_Sw_02(void);


csp_gpio_dev_instance_t gpio_led_red;
csp_gpio_dev_instance_t gpio_led_green;
csp_gpio_dev_instance_t gpio_led_blue;
csp_gpio_dev_instance_t gpio_sw_01;
csp_gpio_dev_instance_t gpio_sw_02;
csp_intx_dev_instance_t intx_sW_01;


void Bsp_Init(void)
{
    Bsp_Hw_Init_Led_Red();
    Bsp_Hw_Init_Led_Green();
    Bsp_Hw_Init_Led_Blue();
    Bsp_Hw_Init_Sw_01();
    Bsp_Hw_Init_Sw_02();

}

static void Bsp_Hw_Init_Led_Red(void)
{
    csp_gpio_dev_config_t gpio_led_red_config;

     gpio_led_red_config.name = "red_led";
     gpio_led_red_config.dir = CSP_GPIO_PIN_OUTPUT_NORMAL;
     gpio_led_red_config.pin = BSP_LED_RED;

     Csp_Gpio_Init(&gpio_led_red, gpio_led_red_config);
}

static void Bsp_Hw_Init_Led_Green(void)
{
    csp_gpio_dev_config_t gpio_led_green_config;

    gpio_led_green_config.name  = "green_led";
    gpio_led_green_config.dir   = CSP_GPIO_PIN_OUTPUT_NORMAL;
    gpio_led_green_config.pin   = BSP_LED_GREEN;

    Csp_Gpio_Init(&gpio_led_green, gpio_led_green_config);
}

static void Bsp_Hw_Init_Led_Blue(void)
{
    csp_gpio_dev_config_t gpio_led_blue_config;

    gpio_led_blue_config.name  = "blue_led";
    gpio_led_blue_config.dir   = CSP_GPIO_PIN_OUTPUT_NORMAL;
    gpio_led_blue_config.pin   = BSP_LED_BLUE;

    Csp_Gpio_Init(&gpio_led_blue, gpio_led_blue_config);
}

static void Bsp_Hw_Init_Sw_01(void)
{
    csp_gpio_dev_config_t gpio_sw_01_config;
    csp_intx_dev_config_t intx_sw_01_config;

    gpio_sw_01_config.name  = "Sw1";
    gpio_sw_01_config.dir   = CSP_GPIO_PIN_INPUT_PULLUP;
    gpio_sw_01_config.pin   = BSP_SW_01;

    Csp_Gpio_Init(&gpio_sw_01, gpio_sw_01_config);

    intx_sw_01_config.text = "Sw1_Int";
    intx_sw_01_config.gpio_inst = &gpio_sw_01;
    intx_sw_01_config.func = 0;

    Csp_Intx_Init(&intx_sW_01, intx_sw_01_config);
}

static void Bsp_Hw_Init_Sw_02(void)
{
    csp_gpio_dev_config_t gpio_sw_02_config;

    gpio_sw_02_config.name  = "Sw2";
    gpio_sw_02_config.dir   = CSP_GPIO_PIN_INPUT_PULLUP;
    gpio_sw_02_config.pin   = BSP_SW_02;

    Csp_Gpio_Init(&gpio_sw_02, gpio_sw_02_config);
}

csp_gpio_dev_instance_t* Bsp_Gpio_Inst_Led_Red(void)
{
    return(&gpio_led_red);
}

csp_gpio_dev_instance_t* Bsp_Gpio_Inst_Led_Green(void)
{
   return(&gpio_led_green);
}

csp_gpio_dev_instance_t* Bsp_Gpio_Inst_Led_Blue(void)
{
    return(&gpio_led_blue);
}
csp_gpio_dev_instance_t* Bsp_Gpio_Inst_Sw_01(void)
{
    return(&gpio_sw_01);
}
csp_gpio_dev_instance_t* Bsp_Gpio_Inst_Sw_02(void)
{
    return(&gpio_sw_02);
}






