/*
 * csp_tm4c.c
 *
 *  Created on: Mar 11, 2018
 *      Author: Murtuza
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"





//GPIO PTR Register
volatile uint32_t* PTR_PORT_DATA[6] = {
                                                 &GPIO_PORTA_DATA_R, &GPIO_PORTB_DATA_R, &GPIO_PORTC_DATA_R,
                                                 &GPIO_PORTD_DATA_R, &GPIO_PORTE_DATA_R, &GPIO_PORTF_DATA_R
                                            };

volatile uint32_t* PTR_PORT_DIR[6] = {
                                                 &GPIO_PORTA_DIR_R, &GPIO_PORTB_DIR_R, &GPIO_PORTC_DIR_R,
                                                 &GPIO_PORTD_DIR_R, &GPIO_PORTE_DIR_R, &GPIO_PORTF_DIR_R
                                            };

volatile uint32_t* PTR_PORT_IS[6] = {
                                                 &GPIO_PORTA_IS_R, &GPIO_PORTB_IS_R, &GPIO_PORTC_IS_R,
                                                 &GPIO_PORTD_IS_R, &GPIO_PORTE_IS_R, &GPIO_PORTF_IS_R
                                            };

volatile uint32_t* PTR_PORT_IBE[6] = {
                                                 &GPIO_PORTA_IBE_R, &GPIO_PORTB_IBE_R, &GPIO_PORTC_IBE_R,
                                                 &GPIO_PORTD_IBE_R, &GPIO_PORTE_IBE_R, &GPIO_PORTF_IBE_R
                                            };

volatile uint32_t* PTR_PORT_IEV[6] = {
                                                 &GPIO_PORTA_IEV_R, &GPIO_PORTB_IEV_R, &GPIO_PORTC_IEV_R,
                                                 &GPIO_PORTD_IEV_R, &GPIO_PORTE_IEV_R, &GPIO_PORTF_IEV_R
                                            };

volatile uint32_t* PTR_PORT_IM[6] = {
                                                 &GPIO_PORTA_IM_R, &GPIO_PORTB_IM_R, &GPIO_PORTC_IM_R,
                                                 &GPIO_PORTD_IM_R, &GPIO_PORTE_IM_R, &GPIO_PORTF_IM_R
                                            };

volatile uint32_t* PTR_PORT_RIS[6] = {
                                                 &GPIO_PORTA_RIS_R, &GPIO_PORTB_RIS_R, &GPIO_PORTC_RIS_R,
                                                 &GPIO_PORTD_RIS_R, &GPIO_PORTE_RIS_R, &GPIO_PORTF_RIS_R
                                            };

volatile uint32_t* PTR_PORT_MIS[6] = {
                                                 &GPIO_PORTA_MIS_R, &GPIO_PORTB_MIS_R, &GPIO_PORTC_MIS_R,
                                                 &GPIO_PORTD_MIS_R, &GPIO_PORTE_MIS_R, &GPIO_PORTF_MIS_R
                                            };

volatile uint32_t* PTR_PORT_ICR[6] = {
                                                 &GPIO_PORTA_ICR_R, &GPIO_PORTB_ICR_R, &GPIO_PORTC_ICR_R,
                                                 &GPIO_PORTD_ICR_R, &GPIO_PORTE_ICR_R, &GPIO_PORTF_ICR_R
                                            };

volatile uint32_t* PTR_PORT_AFSEL[6] = {
                                                 &GPIO_PORTA_AFSEL_R, &GPIO_PORTB_AFSEL_R, &GPIO_PORTC_AFSEL_R,
                                                 &GPIO_PORTD_AFSEL_R, &GPIO_PORTE_AFSEL_R, &GPIO_PORTF_AFSEL_R
                                            };

volatile uint32_t* PTR_PORT_DR2R[6] = {
                                                 &GPIO_PORTA_DR2R_R, &GPIO_PORTB_DR2R_R, &GPIO_PORTC_DR2R_R,
                                                 &GPIO_PORTD_DR2R_R, &GPIO_PORTE_DR2R_R, &GPIO_PORTF_DR2R_R
                                            };

volatile uint32_t* PTR_PORT_DR4R[6] = {
                                                 &GPIO_PORTA_DR4R_R, &GPIO_PORTB_DR4R_R, &GPIO_PORTC_DR4R_R,
                                                 &GPIO_PORTD_DR4R_R, &GPIO_PORTE_DR4R_R, &GPIO_PORTF_DR4R_R
                                            };

volatile uint32_t* PTR_PORT_DR8R[6] = {
                                                 &GPIO_PORTA_DR8R_R, &GPIO_PORTB_DR8R_R, &GPIO_PORTC_DR8R_R,
                                                 &GPIO_PORTD_DR8R_R, &GPIO_PORTE_DR8R_R, &GPIO_PORTF_DR8R_R
                                            };

volatile uint32_t* PTR_PORT_ODR[6] = {
                                                 &GPIO_PORTA_ODR_R, &GPIO_PORTB_ODR_R, &GPIO_PORTC_ODR_R,
                                                 &GPIO_PORTD_ODR_R, &GPIO_PORTE_ODR_R, &GPIO_PORTF_ODR_R
                                            };

volatile uint32_t* PTR_PORT_PUR[6] = {
                                                 &GPIO_PORTA_PUR_R, &GPIO_PORTB_PUR_R, &GPIO_PORTC_PUR_R,
                                                 &GPIO_PORTD_PUR_R, &GPIO_PORTE_PUR_R, &GPIO_PORTF_PUR_R
                                            };


volatile uint32_t* PTR_PORT_PDR[6] = {
                                                 &GPIO_PORTA_PDR_R, &GPIO_PORTB_PDR_R, &GPIO_PORTC_PDR_R,
                                                 &GPIO_PORTD_PDR_R, &GPIO_PORTE_PDR_R, &GPIO_PORTF_PDR_R
                                            };

volatile uint32_t* PTR_PORT_DEN[6] = {
                                                 &GPIO_PORTA_DEN_R, &GPIO_PORTB_DEN_R, &GPIO_PORTC_DEN_R,
                                                 &GPIO_PORTD_DEN_R, &GPIO_PORTE_DEN_R, &GPIO_PORTF_DEN_R
                                            };


volatile uint32_t* PTR_PORT_LOCK[6] = {
                                                 &GPIO_PORTA_LOCK_R, &GPIO_PORTB_LOCK_R, &GPIO_PORTC_LOCK_R,
                                                 &GPIO_PORTD_LOCK_R, &GPIO_PORTE_LOCK_R, &GPIO_PORTF_LOCK_R
                                            };

volatile uint32_t* PTR_PORT_CR[6] = {
                                                 &GPIO_PORTA_CR_R, &GPIO_PORTB_CR_R, &GPIO_PORTC_CR_R,
                                                 &GPIO_PORTD_CR_R, &GPIO_PORTE_CR_R, &GPIO_PORTF_CR_R
                                            };

//NVIC PTR Register
volatile uint32_t* PTR_NVIC_EN_REG[6] = {
                                        &NVIC_EN0_R, &NVIC_EN0_R, &NVIC_EN0_R,
                                        &NVIC_EN0_R, &NVIC_EN0_R, &NVIC_EN0_R
                                        };

uint32_t PORT_NVIC_EN_MASK[6] = {
                                  (1 << 0U), (1 << 1U), (1 << 2U),
                                  (1 << 3U), (1 << 4U), (1 << 30U)
                                 };
