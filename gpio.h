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
#include "ErrHandler.h"

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
  GPIO_TypeDef  *GPIOx;           /*!< Specifies the GPIO pins to be configured.
                                    Example: GPIOE */
  uint32_t MODEx_Pos;
  eMODER   MODER;                 /*!< Specifies the operating mode for the selected pins.
                                    Example: GPIO_MODER_MODE5_Pos */
  uint32_t OTYPEx_Pos;
  eOTYPER  OTYPER;                /*!< Specifies the output push-pull or Output open-drain activation for the selected pins.
                                    Example: GPIO_OTYPER_OT5_Pos */
  uint32_t OSPEEDx_Pos;
  eOSPEEDR OSPEEDR;               /*!< Specifies the speed for the selected pins.
                                    Example: GPIO_OSPEEDR_OSPEED5_Pos */
  uint32_t PUPDx_Pos;
  ePUPDR   PUPDR;                 /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                                    Example: GPIO_PUPDR_PUPD5_Pos */
} GpioConfig;

ErrHandle_t Set_Gpio(GpioConfig *cfg);

#endif /* GPIO_H */
#ifdef __cplusplus
}
#endif