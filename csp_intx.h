#ifndef CSP_INTX_H__
#define CSP_INTX_H__

#include <stdint.h>
#include "csp_gpio.h"
#include "csp_tm4c.h"

#ifdef __cplusplus
extern "C" {
#endif




typedef struct
{
  int8_t*                   name;
  csp_gpio_dev_instance_t*   gpio_inst;
  void (*func)(void);

}csp_intx_dev_instance_t;

typedef struct
{
  int8_t*                   text;
  csp_gpio_dev_instance_t*   gpio_inst;
  void (*func)(void);

}csp_intx_dev_config_t;



void Csp_Intx_Init(csp_intx_dev_instance_t* intx_inst, csp_intx_dev_config_t intx_config);
void Csp_Intx_Interrupt(void);


#ifdef __cplusplus
}
#endif

#endif // CSP_INTX_H__


