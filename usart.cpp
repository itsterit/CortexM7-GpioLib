/**
  ******************************************************************************
  * @file           : usart.c
  * @brief          : usart body
  ******************************************************************************
  */
#include "usart.h"
#include "stm32h750xx.h"
#include "Gpio/gpio.h"
#include "ErrHandler.h"

ErrHandle_t UartControl::setСonfig(UartConfig *cfg)
{   
  /* PC7 pin configuration for usart 6 rx pin */
  GpioConfig Usart6_Rx = {0};
  Usart6_Rx.GPIOx       = GPIOC;
  Usart6_Rx.MODEx_Pos   = GPIO_MODER_MODE7_Pos;
  Usart6_Rx.MODER       = eMODE_ALTERNATE_MODE;
  Usart6_Rx.OTYPEx_Pos  = GPIO_OTYPER_OT7_Pos;
  Usart6_Rx.OTYPER      = eOTYPE_OUTPUT_PUSH_PULL;
  Usart6_Rx.OSPEEDx_Pos = GPIO_OSPEEDR_OSPEED7_Pos;
  Usart6_Rx.OSPEEDR     = eOSPEED_VERY_HIGH_SPEED;
  Usart6_Rx.PUPDx_Pos   = GPIO_PUPDR_PUPD7_Pos;
  Usart6_Rx.PUPDR       = ePUPD_NO_PULL;
  ConfigPin(&Usart6_Rx);
  GPIOB->AFR[7] |=0b0111;

  /* PC6 pin configuration for usart 6 tx pin */
  GpioConfig Usart6_Tx = {0};
  Usart6_Tx.GPIOx       = GPIOC;
  Usart6_Tx.MODEx_Pos   = GPIO_MODER_MODE6_Pos;
  Usart6_Tx.MODER       = eMODE_ALTERNATE_MODE;
  Usart6_Tx.OTYPEx_Pos  = GPIO_OTYPER_OT6_Pos;
  Usart6_Tx.OTYPER      = eOTYPE_OUTPUT_PUSH_PULL;
  Usart6_Tx.OSPEEDx_Pos = GPIO_OSPEEDR_OSPEED6_Pos;
  Usart6_Tx.OSPEEDR     = eOSPEED_VERY_HIGH_SPEED;
  Usart6_Tx.PUPDx_Pos   = GPIO_PUPDR_PUPD6_Pos;
  Usart6_Tx.PUPDR       = ePUPD_NO_PULL;
  ConfigPin(&Usart6_Tx);
  GPIOB->AFR[6] |=0b0111;

  RCC->APB2ENR |= RCC_APB2ENR_USART6EN;

  USART6->RTOR = 0x00;
  USART6->RTOR |= (0 << USART_RTOR_RTO_Pos);              // Receiver timeout value

  USART6->CR3 = 0x00;
  USART6->CR3 |=  ( 0 << USART_CR3_DMAT_Pos );            // DMA mode is enabled for transmission
  USART6->CR3 |=  ( 0 << USART_CR3_DMAR_Pos );            // DMA mode is enabled for reception
  USART6->CR3 |=  ( 0 << USART_CR3_EIE_Pos );             // Interrupt generated when FE = 1 or ORE = 1 or NE = 1 or UDR = 1 (in SPI slave mode) in the USART_ISR register

  USART6->BRR = 45000000 / 9600;

  USART6->CR2 = 0x00;
  USART6->CR2 |=  ( 1 << USART_CR2_ABRMODE_Pos );         // Auto baud rate mode
  USART6->CR2 |=  ( 1 << USART_CR2_ABREN_Pos );           // Auto baud rate detection is enabled.
  USART6->CR2 |=  ( 0 << USART_CR2_RTOEN_Pos );           // Receiver timeout enable

  USART6->CR1 = 0x00;
  USART6->CR1 |=  ( 0 << USART_CR1_RXFFIE_Pos );          // USART interrupt generated when RXFF = 1 in the USART_ISR register
  USART6->CR1 |=  ( 0 << USART_CR1_TXFEIE_Pos );          // USART interrupt generated when TXFE = 1 in the USART_ISR register
  USART6->CR1 |=  ( 0 << USART_CR1_FIFOEN_Pos );          // FIFO mode enable
  USART6->CR1 |=  ( 0 << USART_CR1_M1_Pos );              // Word length(1 start bit, 8 Data bits, n Stop bit)
  USART6->CR1 |=  ( 0 << USART_CR1_M0_Pos );              // Word length(1 start bit, 8 Data bits, n Stop bit)
  USART6->CR1 |=  ( 0 << USART_CR1_EOBIE_Pos );           // USART interrupt generated when the EOBF flag is set in the USART_ISR register
  USART6->CR1 |=  ( 0 << USART_CR1_RTOIE_Pos );           // Receiver timeout interrupt enable
  USART6->CR1 |=  ( 0 << USART_CR1_RTOIE_Pos );           // USART interrupt generated when the RTOF bit is set in the USART_ISR register.
  USART6->CR1 |=  ( 0 << USART_CR1_CMIE_Pos );            // USART interrupt generated when the CMF bit is set in the USART_ISR register. 
  USART6->CR1 |=  ( 0 << USART_CR1_PEIE_Pos );            // USART interrupt generated whenever PE = 1 in the USART_ISR register
  USART6->CR1 |=  ( 0 << USART_CR1_TXEIE_TXFNFIE_Pos );   // USART interrupt generated whenever TXFNF =1 in the USART_ISR register
  USART6->CR1 |=  ( 0 << USART_CR1_TCIE_Pos );            // Transmission complete interrupt enable
  USART6->CR1 |=  ( 0 << USART_CR1_RXNEIE_RXFNEIE_Pos );  // USART interrupt generated whenever ORE = 1 or RXFNE = 1 in the USART_ISR register
  USART6->CR1 |=  ( 1 << USART_CR1_TE_Pos );              // Transmitter is enabled
  USART6->CR1 |=  ( 0 << USART_CR1_RE_Pos );              // Receiver enable
  USART6->CR1 |=  ( 1 << USART_CR1_UE_Pos );              // USART enabled

  //NVIC_EnableIRQ(USART6_IRQn);
  return STM_OK;
}