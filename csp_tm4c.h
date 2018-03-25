#ifndef CSP_TM4C_H__
#define CSP_TM4C_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Pin Mapping from Board to MCU

#define CSP_PORT_A          0x10
#define CSP_PORT_B          0x20
#define CSP_PORT_C          0x30
#define CSP_PORT_D          0x40
#define CSP_PORT_E          0x50
#define CSP_PORT_F          0x60

#define CSP_PORT_PIN_0      0x01
#define CSP_PORT_PIN_1      0x02
#define CSP_PORT_PIN_2      0x03
#define CSP_PORT_PIN_3      0x04
#define CSP_PORT_PIN_4      0x05
#define CSP_PORT_PIN_5      0x06
#define CSP_PORT_PIN_6      0x07
#define CSP_PORT_PIN_7      0x08

#define CSP_PORT_A0      (CSP_PORT_A  | CSP_PORT_PIN_0)
#define CSP_PORT_A1      (CSP_PORT_A  | CSP_PORT_PIN_1)
#define CSP_PORT_A2      (CSP_PORT_A  | CSP_PORT_PIN_2)
#define CSP_PORT_A3      (CSP_PORT_A  | CSP_PORT_PIN_3)
#define CSP_PORT_A4      (CSP_PORT_A  | CSP_PORT_PIN_4)
#define CSP_PORT_A5      (CSP_PORT_A  | CSP_PORT_PIN_5)
#define CSP_PORT_A6      (CSP_PORT_A  | CSP_PORT_PIN_6)
#define CSP_PORT_A7      (CSP_PORT_A  | CSP_PORT_PIN_7)

#define CSP_PORT_B0      (CSP_PORT_B  | CSP_PORT_PIN_0)
#define CSP_PORT_B1      (CSP_PORT_B  | CSP_PORT_PIN_1)
#define CSP_PORT_B2      (CSP_PORT_B  | CSP_PORT_PIN_2)
#define CSP_PORT_B3      (CSP_PORT_B  | CSP_PORT_PIN_3)
#define CSP_PORT_B4      (CSP_PORT_B  | CSP_PORT_PIN_4)
#define CSP_PORT_B5      (CSP_PORT_B  | CSP_PORT_PIN_5)
#define CSP_PORT_B6      (CSP_PORT_B  | CSP_PORT_PIN_6)
#define CSP_PORT_B7      (CSP_PORT_B  | CSP_PORT_PIN_7)

#define CSP_PORT_C0      (CSP_PORT_C  | CSP_PORT_PIN_0)
#define CSP_PORT_C1      (CSP_PORT_C  | CSP_PORT_PIN_1)
#define CSP_PORT_C2      (CSP_PORT_C  | CSP_PORT_PIN_2)
#define CSP_PORT_C3      (CSP_PORT_C  | CSP_PORT_PIN_3)
#define CSP_PORT_C4      (CSP_PORT_C  | CSP_PORT_PIN_4)
#define CSP_PORT_C5      (CSP_PORT_C  | CSP_PORT_PIN_5)
#define CSP_PORT_C6      (CSP_PORT_C  | CSP_PORT_PIN_6)
#define CSP_PORT_C7      (CSP_PORT_C  | CSP_PORT_PIN_7)

#define CSP_PORT_D0      (CSP_PORT_D  | CSP_PORT_PIN_0)
#define CSP_PORT_D1      (CSP_PORT_D  | CSP_PORT_PIN_1)
#define CSP_PORT_D2      (CSP_PORT_D  | CSP_PORT_PIN_2)
#define CSP_PORT_D3      (CSP_PORT_D  | CSP_PORT_PIN_3)
#define CSP_PORT_D4      (CSP_PORT_D  | CSP_PORT_PIN_4)
#define CSP_PORT_D5      (CSP_PORT_D  | CSP_PORT_PIN_5)
#define CSP_PORT_D6      (CSP_PORT_D  | CSP_PORT_PIN_6)
#define CSP_PORT_D7      (CSP_PORT_D  | CSP_PORT_PIN_7)

#define CSP_PORT_E0      (CSP_PORT_E  | CSP_PORT_PIN_0)
#define CSP_PORT_E1      (CSP_PORT_E  | CSP_PORT_PIN_1)
#define CSP_PORT_E2      (CSP_PORT_E  | CSP_PORT_PIN_2)
#define CSP_PORT_E3      (CSP_PORT_E  | CSP_PORT_PIN_3)
#define CSP_PORT_E4      (CSP_PORT_E  | CSP_PORT_PIN_4)
#define CSP_PORT_E5      (CSP_PORT_E  | CSP_PORT_PIN_5)
#define CSP_PORT_E6      (CSP_PORT_E  | CSP_PORT_PIN_6)
#define CSP_PORT_E7      (CSP_PORT_E  | CSP_PORT_PIN_7)

#define CSP_PORT_F0      (CSP_PORT_F  | CSP_PORT_PIN_0)
#define CSP_PORT_F1      (CSP_PORT_F  | CSP_PORT_PIN_1)
#define CSP_PORT_F2      (CSP_PORT_F  | CSP_PORT_PIN_2)
#define CSP_PORT_F3      (CSP_PORT_F  | CSP_PORT_PIN_3)
#define CSP_PORT_F4      (CSP_PORT_F  | CSP_PORT_PIN_4)
#define CSP_PORT_F5      (CSP_PORT_F  | CSP_PORT_PIN_5)
#define CSP_PORT_F6      (CSP_PORT_F  | CSP_PORT_PIN_6)
#define CSP_PORT_F7      (CSP_PORT_F  | CSP_PORT_PIN_7)

//enum definition correspond to the physical port location on micro
typedef enum
{
    CSP_GPIO_NONE   = 0,
    CSP_GPIO_00     = CSP_PORT_A0,
    CSP_GPIO_01     = CSP_PORT_A1,
    CSP_GPIO_02     = CSP_PORT_A2,
    CSP_GPIO_03     = CSP_PORT_A3,
    CSP_GPIO_04     = CSP_PORT_A4,
    CSP_GPIO_05     = CSP_PORT_A5,
    CSP_GPIO_06     = CSP_PORT_A6,
    CSP_GPIO_07     = CSP_PORT_A7,
    CSP_GPIO_08     = CSP_PORT_B0,
    CSP_GPIO_09     = CSP_PORT_B1,
    CSP_GPIO_10     = CSP_PORT_B2,
    CSP_GPIO_11     = CSP_PORT_B3,
    CSP_GPIO_12     = CSP_PORT_B4,
    CSP_GPIO_13     = CSP_PORT_B5,
    CSP_GPIO_14     = CSP_PORT_B6,
    CSP_GPIO_15     = CSP_PORT_B7,
    CSP_GPIO_16     = CSP_PORT_C0,
    CSP_GPIO_17     = CSP_PORT_C1,
    CSP_GPIO_18     = CSP_PORT_C2,
    CSP_GPIO_19     = CSP_PORT_C3,
    CSP_GPIO_20     = CSP_PORT_C4,
    CSP_GPIO_21     = CSP_PORT_C5,
    CSP_GPIO_22     = CSP_PORT_C6,
    CSP_GPIO_23     = CSP_PORT_C7,
    CSP_GPIO_24     = CSP_PORT_D0,
    CSP_GPIO_25     = CSP_PORT_D1,
    CSP_GPIO_26     = CSP_PORT_D2,
    CSP_GPIO_27     = CSP_PORT_D3,
    CSP_GPIO_28     = CSP_PORT_D4,
    CSP_GPIO_29     = CSP_PORT_D5,
    CSP_GPIO_30     = CSP_PORT_D6,
    CSP_GPIO_31     = CSP_PORT_D7,
    CSP_GPIO_32     = CSP_PORT_E0,
    CSP_GPIO_33     = CSP_PORT_E1,
    CSP_GPIO_34     = CSP_PORT_E2,
    CSP_GPIO_35     = CSP_PORT_E3,
    CSP_GPIO_36     = CSP_PORT_E4,
    CSP_GPIO_37     = CSP_PORT_E5,
    CSP_GPIO_38     = CSP_PORT_E6,
    CSP_GPIO_39     = CSP_PORT_E7,
    CSP_GPIO_40     = CSP_PORT_F0,
    CSP_GPIO_41     = CSP_PORT_F1,
    CSP_GPIO_42     = CSP_PORT_F2,
    CSP_GPIO_43     = CSP_PORT_F3,
    CSP_GPIO_44     = CSP_PORT_F4,
    CSP_GPIO_45     = CSP_PORT_F5,
    CSP_GPIO_46     = CSP_PORT_F6,
    CSP_GPIO_47     = CSP_PORT_F7,


}csp_gpio_pinout_t;

#define CSP_GPIO_MAX    50
#define CSP_GPIO_MAX_PORT   6
#define CSP_GPIO_MAX_PIN    8

#define CSP_UART_0_TX
#define CSP_UART_0_RX

#define CSP_UART_1_TX
#define CSP_UART_1_RX

#define CSP_UART_2_TX
#define CSP_UART_2_RX

#define CSP_UART_3_TX
#define CSP_UART_3_RX


#define CSP_SPI_0_MISO
#define CSP_SPI_0_MOSI
#define CSP_SPI_0_CLK

#define CSP_SPI_1_MISO
#define CSP_SPI_1_MOSI
#define CSP_SPI_1_CLK

#define CSP_I2C_0_DIO
#define CSP_I2C_0_CLK

#define CSP_I2C_1_DIO
#define CSP_I2C_1_CLK

  
extern volatile uint32_t* PTR_PORT_DATA[6];
extern volatile uint32_t* PTR_PORT_DIR[6];
extern volatile uint32_t* PTR_PORT_IS[6];
extern volatile uint32_t* PTR_PORT_IBE[6];
extern volatile uint32_t* PTR_PORT_IEV[6];
extern volatile uint32_t* PTR_PORT_IM[6];
extern volatile uint32_t* PTR_PORT_RIS[6];
extern volatile uint32_t* PTR_PORT_MIS[6];
extern volatile uint32_t* PTR_PORT_ICR[6];
extern volatile uint32_t* PTR_PORT_AFSEL[6];
extern volatile uint32_t* PTR_PORT_DR2R[6];
extern volatile uint32_t* PTR_PORT_DR4R[6];
extern volatile uint32_t* PTR_PORT_DR8R[6];
extern volatile uint32_t* PTR_PORT_ODR[6];
extern volatile uint32_t* PTR_PORT_PUR[6];
extern volatile uint32_t* PTR_PORT_PDR[6];
extern volatile uint32_t* PTR_PORT_DEN[6];
extern volatile uint32_t* PTR_PORT_LOCK[6];
extern volatile uint32_t* PTR_PORT_CR[6];

//NVIC PTR Register
extern volatile uint32_t* PTR_NVIC_EN_REG[6];
extern uint32_t PORT_NVIC_EN_MASK[6];

#ifdef __cplusplus
}
#endif
    
#endif // CSP_TM4C_H__
