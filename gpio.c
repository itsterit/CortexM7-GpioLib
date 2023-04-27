/**
  ******************************************************************************
  * @file           : gpio.c
  * @brief          : gpio body
  ******************************************************************************
  */
#include "gpio.h"
#include "stm32h750xx.h"

/**
 * @brief Switches the pin state
 * 
 * @param [in] example of filling a pointer structure:  
    GpioConfig Gpio_Cfg = {0};
  
    Gpio_Cfg.GPIOx       = GPIOE;
    Gpio_Cfg.MODEx_Pos   = GPIO_MODER_MODE5_Pos;
    Gpio_Cfg.MODER       = eMODE_OUTPUT_MODE;
  
    Gpio_Cfg.OTYPEx_Pos  = GPIO_OTYPER_OT5_Pos; 
    Gpio_Cfg.OTYPER      = eOTYPE_OUTPUT_PUSH_PULL;
  
    Gpio_Cfg.OSPEEDx_Pos = GPIO_OSPEEDR_OSPEED5_Pos;
    Gpio_Cfg.OSPEEDR     = eOSPEED_LOW_SPEED;
  
    Gpio_Cfg.PUPDx_Pos   = GPIO_PUPDR_PUPD5_Pos;
    Gpio_Cfg.PUPDR       = ePUPD_PULL_DOWN;
  
    Set_Gpio(&Gpio_Cfg);
 */

void Set_Gpio(GpioConfig *cfg)
{
  if(cfg->GPIOx == GPIOA) GPIOA_CLK_ENABLE
  else if(cfg->GPIOx == GPIOB) GPIOB_CLK_ENABLE
  else if(cfg->GPIOx == GPIOC) GPIOC_CLK_ENABLE
  else if(cfg->GPIOx == GPIOD) GPIOD_CLK_ENABLE
  else if(cfg->GPIOx == GPIOE) GPIOE_CLK_ENABLE
  else return;

  (cfg->GPIOx)->MODER   &= ~(11         << (cfg->MODEx_Pos));
  (cfg->GPIOx)->MODER   |=  (cfg->MODER << (cfg->MODEx_Pos));

  (cfg->GPIOx)->OTYPER  &= ~(11          << (cfg->OTYPEx_Pos));
  (cfg->GPIOx)->OTYPER  |=  (cfg->OTYPER << (cfg->OTYPEx_Pos));

  (cfg->GPIOx)->OSPEEDR &= ~(11           << (cfg->OSPEEDx_Pos));
  (cfg->GPIOx)->OSPEEDR |=  (cfg->OSPEEDR << (cfg->OSPEEDx_Pos));

  (cfg->GPIOx)->PUPDR   &= ~(11         << (cfg->PUPDx_Pos));
  (cfg->GPIOx)->PUPDR   |=  (cfg->PUPDR << (cfg->PUPDx_Pos));
}