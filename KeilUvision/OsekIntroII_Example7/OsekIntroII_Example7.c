/**
 * @file OsekIntro_Example2.c
 * @author Sarea Alhariri (Sarea.h95@outlook.com)
 * @brief  Extended task and periodic event setting. 
 * @version 0.1
 * @date 2020-08-19
 *
 * @copyright Sarea Alhariri - All rights reserved
 *
 */


#include "os.h"


static uint8_t AppTask_PeriodicExtended_Toggle = 0U ; 
static uint8_t AppTask_PeriodicBasic_Toggle = 0U ; 

DeclareTask(AppTask_PeriodicExtended);
DeclareTask(AppTask_PeriodicBasic);


void SystemInit(void)
{
}
int main(void)
{
  StartOS();
  while(1); /* Should not be executed */
  return 0;
}

TASK(AppTask_PeriodicExtended)
{ 
   while(true)
   {
      WaitEvent(Periodic50Tick); 
      ClearEvent(Periodic50Tick); 
      
      AppTask_PeriodicExtended_Toggle ^= 1; 
   }
}

TASK(AppTask_PeriodicBasic)
{
    SetEvent(AppTask_PeriodicExtended, Periodic50Tick); 
    AppTask_PeriodicBasic_Toggle ^= 0x1U; 
    
    TerminateTask(); 
}
