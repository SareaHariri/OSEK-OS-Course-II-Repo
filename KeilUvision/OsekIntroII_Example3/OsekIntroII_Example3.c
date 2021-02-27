/**
 * @file OsekIntro_Example3.c
 * @author Sarea Alhariri (Sarea.h95@outlook.com)
 * @brief  LED State Machine using alarms and periodic tasks
 * @version 0.1
 * @date 2020-08-12
 *
 * @copyright Sarea Alhariri - All rights reserved
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"
#include "hw_memmap.h"
#include "os.h"
#include "switch.h"
#include "sysctl.h"
#include "tm4c123gh6pm.h"

typedef enum { RED = 0, GREEN, BLUE, WHITE } LedState_t;

static uint8_t AppTask_Periodic_Toggle = 0U;
static LedState_t LedCurrentState = RED;

DeclareTask(AppTask_Init);
DeclareTask(AppTask_Periodic);
DeclareTask(AppTask_Aperiodic);

void SystemInit(void) {}
int main(void) {
  StartOS();
  while (1)
    ; /* Should not be executed */
  return 0;
}

TASK(AppTask_Init) {
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0);
  GPIO_PORTF_LOCK_R = 0x4c4f434b;
  GPIO_PORTF_CR_R = 0x01f;
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0, GPIO_STRENGTH_2MA,
                   GPIO_PIN_TYPE_STD_WPU);
  TerminateTask();
}

TASK(AppTask_Switch) {
  bool l_RightIsPressed;
  bool l_LeftIsPressed;
  AppTask_Periodic_Toggle ^= 1;

  l_RightIsPressed = Switch_RightIsPressed();
  l_LeftIsPressed = Switch_LeftIsPressed();

  if (l_RightIsPressed) {
    if (LedCurrentState != WHITE) {
      LedCurrentState++;
    }
  } else if (l_LeftIsPressed) {
    if (LedCurrentState != RED) {
      LedCurrentState--;
    }
  }

  TerminateTask();
}

TASK(AppTask_Led) {
  switch (LedCurrentState) {
  case RED:
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
                 GPIO_PIN_1);
    break;
  case GREEN:
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
                 GPIO_PIN_3);
    break;
  case BLUE:
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
                 GPIO_PIN_2);
    break;
  case WHITE:
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
                 GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    break;
  default:
    break;
  }
  TerminateTask();
}
