/**
 * @file OsekIntro_Example2.c
 * @author Sarea Alhariri (Sarea.h95@outlook.com)
 * @brief  Periodic and Aperiodic tasks using OSEK alarms
 * @version 0.1
 * @date 2020-08-12
 *
 * @copyright Sarea Alhariri - All rights reserved
 *
 */

#include <stdint.h>
#include <stdbool.h>
#include "os.h"



static uint8_t AppTask_Periodic_Toggle = 0U ; 
static uint8_t AppTask_Aperiodic_Toggle = 0U ; 
static uint8_t RelativeCounter = 0U; 

DeclareTask(AppTask_Periodic);
DeclareTask(AppTask_Aperiodic);


void SystemInit(void)
{
}
int main(void)
{
  StartOS();
  while(1); /* Should not be executed */
  return 0;
}

TASK(AppTask_Periodic)
{
    
    AppTask_Periodic_Toggle ^= 0x1U; 

    
   if(RelativeCounter == 0U)
   {
      SetRelAlarm(Alrm_RelativeActivation, 10, 0);
   }
   else if (RelativeCounter == 1U)
   {
      SetRelAlarm(Alrm_RelativeActivation, 20, 0); 
   }
   else if (RelativeCounter == 2U )
   {
      SetRelAlarm(Alrm_RelativeActivation, 30, 0); 
   }
	 RelativeCounter++; 
	 if (RelativeCounter > 2) RelativeCounter = 0U; 
   
	 TerminateTask(); 
}

TASK(AppTask_Aperiodic)
{
    AppTask_Aperiodic_Toggle ^= 0x1U; 
    TerminateTask(); 
}




