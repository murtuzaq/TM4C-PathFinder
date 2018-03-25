#ifndef CSP_GPIO_H__
#define CSP_GPIO_H__

#include <stdint.h>
#include "csp_tm4c.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CSP_GPIO_CONFIG_INPUT(gpio)                             \
{                                                               \
        .pin               = gpio,                              \
        .dir               = CSP_GPIO_PIN_INPUT                 \
} 

#define BSP_GPIO_CONFIG_OUTPUT(gpio)                            \
{                                                               \
        .pin                = gpio,                             \
        .dir                = CSP_GPIO_PIN_OUTPUT               \
} 
  
typedef enum
{
    CSP_GPIO_NO_ERROR         = 0,
    CSP_GPIO_ERROR            = 1,
}csp_gpio_err_t;


typedef enum
{
   CSP_GPIO_STATE_NONE   = 0,
   CSP_GPIO_STATE_LOW    = 1,
   CSP_GPIO_STATE_HIGH   = 2,
}csp_gpio_pin_state_t;


typedef enum
{
   CSP_GPIO_PIN_INPUT_NORMAL    = 1,
   CSP_GPIO_PIN_INPUT_PULLUP    = 2,
   CSP_GPIO_PIN_INPUT_PULLDN    = 3,
   CSP_GPIO_PIN_OUTPUT_NORMAL   = 4,
   CSP_GPIO_PIN_OUTPUT_OPENDR   = 5,

}csp_gpio_pin_dir_t;

typedef struct 
{
  int8_t*           gpio_name;
  csp_gpio_pinout_t gpio_pin;
  csp_gpio_pin_dir_t gpio_dir;
  csp_gpio_pin_state_t gpio_state;
  csp_gpio_err_t gpio_err;
  uint8_t       port;
  uint8_t       portpin;
  
}csp_gpio_dev_instance_t;


typedef struct 
{
  int8_t*           name;
  csp_gpio_pinout_t pin;
  csp_gpio_pin_dir_t dir;
  
}csp_gpio_dev_config_t;


void Csp_Gpio_Init(csp_gpio_dev_instance_t* gpio_inst, csp_gpio_dev_config_t gpio_config);
csp_gpio_pin_state_t Csp_Gpio_Read(csp_gpio_dev_instance_t* gpio_inst);
void Csp_Gpio_Write(csp_gpio_dev_instance_t* gpio_inst, csp_gpio_pin_state_t gpio_out);
  
  
#ifdef __cplusplus
}
#endif
    
#endif // CSP_GPIO_H__
