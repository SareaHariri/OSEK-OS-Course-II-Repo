/**
 * @file OsekIntro_Example2.c
 * @author Sarea Alhariri (Sarea.h95@outlook.com)
 * @brief  PWM
 * @version 0.1
 * @date 2020-08-19
 *
 * @copyright Sarea Alhariri - All rights reserved
 *
 */

#include "os.h"
#include "gpio.h"
#include "sysctl.h"
#include "hw_memmap.h"
#include "tm4c123gh6pm.h"


#define USE_REAL_HW 1

uint8_t l_PWMSignal = 0u; 
uint8_t l_PWMCounter = 0u;

DeclareTask(AppTask_PWM);
DeclareTask(AppTask_Init);



void SystemInit(void) {}
int main(void) {
  StartOS();
  while (1)
    ; /* Should not be executed */
  return 0;
}

TASK(AppTask_PWM) {
   EventMaskType l_ev; 
 
   uint8_t l_DirectionIsUp = 1u; 
   while(true)
   {
      WaitEvent(CycleStart|PulseWidth);
      GetEvent(AppTask_PWM, &l_ev);
      ClearEvent(l_ev); 
      
      if((l_ev & CycleStart) == CycleStart)
      {
#if USE_REAL_HW
         GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_1);    
#endif 
         l_PWMSignal = 1u; 
         if (1u == l_DirectionIsUp)
         {
            l_PWMCounter++; 
            if (99u == l_PWMCounter)
            {
               l_DirectionIsUp = 0u; 
            }
         }
         else 
         {
            l_PWMCounter--; 
            if (1u == l_PWMCounter)
            {
               l_DirectionIsUp = 1u; 
            }
         }
				 SetRelAlarm(Alrm_PWMPulseWidth, l_PWMCounter, (TickType)0); 
      } 
      

      if((l_ev & PulseWidth) == PulseWidth)
      {
#if USE_REAL_HW
         GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0U);
#endif 
         l_PWMSignal = 0u; 
      }
   }
}


TASK(AppTask_Init)
{
#if USE_REAL_HW
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF) ;
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3) ;
	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0) ;
   GPIO_PORTF_LOCK_R = 0x4c4f434b ;
   GPIO_PORTF_CR_R = 0x01f ;
	GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
#endif 
     TerminateTask(); 
}


