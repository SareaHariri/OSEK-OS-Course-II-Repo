/**
 * @file OsekIntro_Example1.c
 * @author Sarea Alhariri (Sarea.h95@outlook.com)
 * @brief  Simple example to show the support of periodic task using Alarm OS
 * object
 * @version 0.1
 * @date 2020-05-1
 *
 * @copyright Sarea Alhariri - All rights reserved
 *
 */
#include <stdbool.h>
#include <stdint.h>
#include "gpio.h"
#include "hw_memmap.h"
#include "sysctl.h"
#include "tm4c123gh6pm.h"
#include "os.h"

#define USE_REAL_HW   0 /* 0 for simulation, 1 for real hardware */

DeclareTask(AppTaskBlinker);
DeclareTask(AppTaskInit);

void SystemInit(void) {}
int main(void) {
  StartOS();
  while (1)
    ; /* Should not be executed */
  return 0;
}

TASK(AppTaskBlinker) {

  static uint8_t Blinker_Counter = 0u;
  Blinker_Counter ^= 0x2;
#if USE_REAL_HW
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, Blinker_Counter);
#endif
  TerminateTask();
}
TASK(AppTaskInit) {

#if USE_REAL_HW
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0);
  GPIO_PORTF_LOCK_R = 0x4c4f434b;
  GPIO_PORTF_CR_R = 0x01f;
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0, GPIO_STRENGTH_2MA,
                   GPIO_PIN_TYPE_STD_WPU);

#endif
  TerminateTask();
}
