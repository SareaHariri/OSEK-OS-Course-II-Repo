/**
 * @file OsekIntro_Example2.c
 * @author Sarea Alhariri (Sarea.h95@outlook.com)
 * @brief  FSM
 * @version 0.1
 * @date 2020-08-19
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

#define FSM_MAX_INPUT 2U

typedef enum {
  FSM_OUPUT_RED,
  FSM_OUPUT_GREEN,
  FSM_OUPUT_BLUE,
  FSM_OUPUT_WHITE
} FSMOutput_t;

typedef struct State_tag {
  FSMOutput_t output;
  struct State_tag *Next[3];
} State_t;

static State_t FSM[4] = {
    {FSM_OUPUT_RED,
     {&FSM[FSM_OUPUT_GREEN], &FSM[FSM_OUPUT_BLUE], &FSM[FSM_OUPUT_WHITE]}},
    {FSM_OUPUT_GREEN,
     {&FSM[FSM_OUPUT_BLUE], &FSM[FSM_OUPUT_WHITE], &FSM[FSM_OUPUT_RED]}},
    {FSM_OUPUT_BLUE,
     {&FSM[FSM_OUPUT_WHITE], &FSM[FSM_OUPUT_RED], &FSM[FSM_OUPUT_GREEN]}},
    {FSM_OUPUT_WHITE,
     {&FSM[FSM_OUPUT_RED], &FSM[FSM_OUPUT_GREEN], &FSM[FSM_OUPUT_BLUE]}}};

static State_t *FSM_CurrentState = &FSM[0];

DeclareTask(AppTask_FSMServer);
DeclareTask(AppTask_GetSWInput);
DeclareTask(AppTask_Init);

static void FSM_SetOutput(void);

void SystemInit(void) {}
int main(void) {
  StartOS();
  while (1)
    ; /* Should not be executed */
  return 0;
}

TASK(AppTask_FSMServer) {
  EventMaskType l_ev;
  static uint8_t l_FSMInput = 0U;

  FSM_SetOutput();
  while (true) {
    WaitEvent(IncrementInput | StateTransition);
    GetEvent(AppTask_FSMServer, &l_ev);
    ClearEvent(l_ev);

    if ((l_ev & IncrementInput) == IncrementInput) {
      l_FSMInput++;
      if (l_FSMInput > FSM_MAX_INPUT) {
        l_FSMInput = 0U;
      }
    }

    if ((l_ev & StateTransition) == StateTransition) {
      FSM_CurrentState = FSM_CurrentState->Next[l_FSMInput];
      l_FSMInput = 0U;
      /* Set the new output */
      FSM_SetOutput();
    }
  }
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

TASK(AppTask_GetSWInput) {
  bool l_RightIsPressed;
  bool l_LeftIsPressed;

  l_RightIsPressed = Switch_RightIsPressed();
  l_LeftIsPressed = Switch_LeftIsPressed();

  if (l_RightIsPressed) {
    SetEvent(AppTask_FSMServer, IncrementInput);
  } else if (l_LeftIsPressed) {
    SetEvent(AppTask_FSMServer, StateTransition);
  }

  TerminateTask();
}

static void FSM_SetOutput(void) {
  switch (FSM_CurrentState->output) {
  case FSM_OUPUT_RED:
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
                 GPIO_PIN_1);
    break;
  case FSM_OUPUT_GREEN:
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
                 GPIO_PIN_3);
    break;
  case FSM_OUPUT_BLUE:
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
                 GPIO_PIN_2);
    break;
  case FSM_OUPUT_WHITE:
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
                 GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    break;
  default:
    break;
  }
}