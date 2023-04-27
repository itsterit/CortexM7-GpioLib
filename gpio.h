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
  INPUT_MODE        = (0b00),
  OUTPUT_MODE       = (0b01),
  ALTERNATE_MODE    = (0b10),
  ANALOG_MODE       = (0b11)
} MODER;

typedef enum
{
  OUTPUT_PUSH_PULL  = (0b0),
  OUTPUT_OPEN_DRAIN = (0b1)
} OTYPER;

typedef enum
{
  LOW_SPEED         = (0b00),
  MEDIUM_SPEED      = (0b01),
  HIGH_SPEED        = (0b10),
  VERY_HIGH_SPEED   = (0b11)
} OSPEEDR;

typedef enum
{
  NO_PULL           = (0b00),
  PULL_UP           = (0b01),
  PULL_DOWN         = (0b10)
} PUPDR;

#endif /* GPIO_H */
#ifdef __cplusplus
}
#endif