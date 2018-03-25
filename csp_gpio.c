#include  "csp_gpio.h"

#include "csp_tm4c.h"
#include "tm4c123gh6pm.h"

//initlize each pin

static uint8_t Csp_Gpio_Port(csp_gpio_pinout_t);
static uint8_t Csp_Gpio_Port_Pin(csp_gpio_pinout_t);

void Csp_Gpio_Init(csp_gpio_dev_instance_t* gpio_inst, csp_gpio_dev_config_t gpio_config)
{
    uint8_t port;
    uint8_t pin;

    gpio_inst->gpio_name = gpio_config.name;
    gpio_inst->gpio_pin = gpio_config.pin;
    gpio_inst->gpio_dir = gpio_config.dir;

    gpio_inst->port    = Csp_Gpio_Port(gpio_config.pin);
    gpio_inst->portpin = Csp_Gpio_Port_Pin(gpio_config.pin);

    port = gpio_inst->port;
    pin = gpio_inst->portpin;

    //Enable Clock to the port by setting the appropriate bits in RCGCGPIO
    SYSCTL_RCGCGPIO_R |= (1 << port);  //Enable Clock for PORT

    *PTR_PORT_LOCK[port] = GPIO_LOCK_KEY; //unlock port

    *PTR_PORT_CR[port] |= (1 << pin);   //unlock pin

    //Enable GPIO pin as digital IO in GPIODEN
    *PTR_PORT_DEN[port] |= (1 <<pin);

    *PTR_PORT_AFSEL[port] &= ~(1 << pin); //not alternative function, GPIO function

    switch(gpio_config.dir)
    {
        case CSP_GPIO_PIN_OUTPUT_NORMAL:
            *PTR_PORT_DIR[port] |= (1 <<pin);       //output
            *PTR_PORT_ODR[port] &= ~(1<< pin);      //clear open drain
            *PTR_PORT_DR2R[port] &= ~(1 << pin);    //clear 2 mA
            *PTR_PORT_DR4R[port] &= ~(1 << pin);    //clear 4 mA
            *PTR_PORT_DR8R[port] &= ~(1 << pin);    //clear 8 mA

            *PTR_PORT_DATA[port] &= ~(1 << pin);    //clear output;
            break;

        case CSP_GPIO_PIN_OUTPUT_OPENDR:
            *PTR_PORT_DIR[port] |= (1 <<pin);       //output
            *PTR_PORT_ODR[port] |= (1<< pin);       //set as open drain

            *PTR_PORT_DATA[port] &= ~(1 << pin);    //clear output;
            break;

        case CSP_GPIO_PIN_INPUT_NORMAL:
            *PTR_PORT_DIR[port] &= ~(1 <<pin);       //set as input
            *PTR_PORT_PUR[port]  &= ~(1 <<pin);       //disable pullup
            *PTR_PORT_PDR[port]  &= ~(1 <<pin);       //disable pulldown

            break;

        case CSP_GPIO_PIN_INPUT_PULLUP:
            *PTR_PORT_DIR[port] &= ~(1 <<pin);       //set as input
            *PTR_PORT_PUR[port]  |= (1 <<pin);       //enable pullup
            *PTR_PORT_PDR[port]  &= ~(1 <<pin);       //disable pulldown
            break;

        case CSP_GPIO_PIN_INPUT_PULLDN:
            *PTR_PORT_DIR[port] &= ~(1 <<pin);       //set as input
            *PTR_PORT_PUR[port]  &= ~(1 <<pin);       //disable pullup
             *PTR_PORT_PDR[port]  |= (1 <<pin);       //enable pullup
            break;

   }

   *PTR_PORT_LOCK[port] = 0;


}

csp_gpio_pin_state_t Csp_Gpio_Read(csp_gpio_dev_instance_t* gpio_inst)
{
    uint8_t port;
    uint8_t pin;

    port = gpio_inst->port;
    pin = gpio_inst->portpin;

    uint8_t state;

    state = *PTR_PORT_DATA[port] & (1 << pin);

    if (state == (1 << pin))
    {
        return (CSP_GPIO_STATE_HIGH);
    }
    else
    {
        return (CSP_GPIO_STATE_LOW);
    }

}

void Csp_Gpio_Write(csp_gpio_dev_instance_t* gpio_inst, csp_gpio_pin_state_t gpio_out)
{
    uint8_t port;
    uint8_t pin;

    port = gpio_inst->port;
    pin = gpio_inst->portpin;

    if (gpio_out == CSP_GPIO_STATE_HIGH)
    {
        *PTR_PORT_DATA[port] |= (1 << pin);
    }
    else if (gpio_out == CSP_GPIO_STATE_LOW)
    {
        *PTR_PORT_DATA[port] &= ~(1 << pin);
    }
}


static uint8_t Csp_Gpio_Port(csp_gpio_pinout_t portpin)
{
    uint8_t port;

    port = (uint8_t)portpin;

    port = ((port & 0xF0) >> 4) - 1;

    return(port);
}


static uint8_t Csp_Gpio_Port_Pin(csp_gpio_pinout_t portpin)
{
    uint8_t pin;

    pin = (uint8_t)portpin;

    pin = (pin & 0x0F) - 1;

    return(pin);
}

