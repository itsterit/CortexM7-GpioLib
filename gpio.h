/**
 ******************************************************************************
 * @file           : gpio.h
 * @brief          : config gpio
 * 
 * Created on      : 27 апр. 2023 г.
 * Author          : itsterit
 ******************************************************************************
 */

#ifdef __cplusplus
extern "C"
{
#endif
#ifndef GPIO_H
#define GPIO_H

#include "stm32h750xx.h"

#define GPIOA_CLK_ENABLE (RCC->AHB4ENR |= RCC_AHB4ENR_GPIOAEN);
#define GPIOB_CLK_ENABLE (RCC->AHB4ENR |= RCC_AHB4ENR_GPIOBEN);
#define GPIOC_CLK_ENABLE (RCC->AHB4ENR |= RCC_AHB4ENR_GPIOCEN);
#define GPIOD_CLK_ENABLE (RCC->AHB4ENR |= RCC_AHB4ENR_GPIODEN);
#define GPIOE_CLK_ENABLE (RCC->AHB4ENR |= RCC_AHB4ENR_GPIOEEN);

/**
 * @brief Switches the pin state

 * @param [in] GPIOx        x = A..E
 * @param [in] GPIO_ODR_ODx x = 1..15
 */
#define TOGGLE_PIN(GPIOx, GPIO_ODR_ODx) (GPIOx->ODR ^= GPIO_ODR_ODx);
/**
 * @brief Write port output data(high or low)

 * @param [in] GPIOx         x = A..E
 * @param [in] GPIO_BSRR_Bxy x = S(set) or R(reset) and y = 1..15
 */
#define DIGITALWRITE(GPIOx, GPIO_BSRR_Bxy) (GPIOx->BSRR |= GPIO_BSRR_Bxy);

typedef enum
{
  eGPIOA = GPIOA,
  eGPIOB = GPIOB,
  eGPIOC = GPIOC,
  eGPIOD = GPIOD,
  eGPIOE = GPIOE
} eGPIOx;

typedef enum
{
  eMODEx_Port_0  = GPIO_MODER_MODE0_Pos,
  eMODEx_Port_1  = GPIO_MODER_MODE1_Pos,
  eMODEx_Port_2  = GPIO_MODER_MODE2_Pos,
  eMODEx_Port_3  = GPIO_MODER_MODE3_Pos,
  eMODEx_Port_4  = GPIO_MODER_MODE4_Pos,
  eMODEx_Port_5  = GPIO_MODER_MODE5_Pos,
  eMODEx_Port_6  = GPIO_MODER_MODE6_Pos,
  eMODEx_Port_7  = GPIO_MODER_MODE7_Pos,
  eMODEx_Port_8  = GPIO_MODER_MODE8_Pos,
  eMODEx_Port_9  = GPIO_MODER_MODE9_Pos,
  eMODEx_Port_10 = GPIO_MODER_MODE10_Pos,
  eMODEx_Port_11 = GPIO_MODER_MODE11_Pos,
  eMODEx_Port_12 = GPIO_MODER_MODE12_Pos,
  eMODEx_Port_13 = GPIO_MODER_MODE13_Pos,
  eMODEx_Port_14 = GPIO_MODER_MODE14_Pos,
  eMODEx_Port_15 = GPIO_MODER_MODE015_Pos
} eMODEx_Port;

typedef enum
{
  eMODE_INPUT_MODE        = (0b00),
  eMODE_OUTPUT_MODE       = (0b01),
  eMODE_ALTERNATE_MODE    = (0b10),
  eMODE_ANALOG_MODE       = (0b11)
} eMODER;

typedef enum
{
  eOTYPE_OUTPUT_PUSH_PULL  = (0b0),
  eOTYPE_OUTPUT_OPEN_DRAIN = (0b1)
} eOTYPER;

typedef enum
{
  eOSPEED_LOW_SPEED         = (0b00),
  eOSPEED_MEDIUM_SPEED      = (0b01),
  eOSPEED_HIGH_SPEED        = (0b10),
  eOSPEED_VERY_HIGH_SPEED   = (0b11)
} eOSPEEDR;

typedef enum
{
  ePUPD_NO_PULL           = (0b00),
  ePUPD_PULL_UP           = (0b01),
  ePUPD_PULL_DOWN         = (0b10)
} ePUPDR;

typedef struct
{
  eGPIOx GPIOx;

  eMODEx_Pos MODEx_Port;
  eMODER   MODER;

  eOTYPER  OTYPER;
  eOSPEEDR OSPEEDR;
  ePUPDR   PUPDR;
} GpioConfig;

#endif /* GPIO_H */
#ifdef __cplusplus
}
#endif