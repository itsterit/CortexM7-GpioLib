/**
 ******************************************************************************
 * @file           : usart.h
 * @brief          : config usart
 *
 * Created on      : 27 апр. 2023 г.
 * Author          : itsterit
 ******************************************************************************
 */

#ifndef USART_H
#define USART_H

#include "stm32h750xx.h"
#include "ErrHandler.h"

typedef enum
{
  eSET           = 1,
  eRE_SET        = 0
} eCONDITION;

typedef struct
{
  eCONDITION   CONDITION;
} UartConfig;

class UartControl
{
public:
    ErrHandle_t setСonfig(UartConfig *cfg); 
};

#endif /* GPIO_H */
