/**
 * @file OsekIntro_Example1.c
 * @author Sarea Alhariri (Sarea.h95@outlook.com)
 * @brief  Simple example to show the support of periodic callbacks using Alarm OS object
 * @version 0.1
 * @date 2020-05-1
 *
 * @copyright Sarea Alhariri - All rights reserved
 *
 */

#include "os.h"




static uint8_t AlarmA_CB_Toggle;  
static uint8_t AlarmB_CB_Toggle;


void SystemInit(void)
{
}
int main(void)
{
  StartOS();
  while(1); /* Should not be executed */
  return 0;
}

ALARMCALLBACK(AlarmA_CB)
{
   AlarmA_CB_Toggle ^= 1; 
}
ALARMCALLBACK(AlarmB_CB)
{
   AlarmB_CB_Toggle ^= 1; 
}

TASK(AppTask_Init)
{
   AlarmA_CB_Toggle = 0U; 
   AlarmB_CB_Toggle = 0U; 

   TerminateTask(); 
}
