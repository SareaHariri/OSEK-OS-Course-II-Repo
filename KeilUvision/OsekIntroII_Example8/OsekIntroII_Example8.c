/**
 * @file OsekIntro_Example2.c
 * @author Sarea Alhariri (Sarea.h95@outlook.com)
 * @brief  Conditional events and server tasks  
 * @version 0.1
 * @date 2020-08-19
 *
 * @copyright Sarea Alhariri - All rights reserved
 *
 */


#include "os.h"


static uint8_t EventA_Toggle = 0U ;
static uint8_t EventB_Toggle = 0U ;
static uint8_t EventC_Toggle = 0U ;
static uint8_t AppTask_PeriodicBasic_Toggle = 0U ; 

DeclareTask(AppTask_ServerTask);
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
TASK(AppTask_ServerTask)
{ 
   EventMaskType l_ev; 
   while(true)
   {
      WaitEvent(EventA|EventB|EventC); 
      GetEvent(AppTask_ServerTask, &l_ev);
      ClearEvent(l_ev); 
      
      if ((l_ev & EventA) == EventA)
      {
         EventA_Toggle ^= 1; 
      }
      if ((l_ev & EventB) == EventB)
      {
         EventB_Toggle ^= 1; 
      }
      if ((l_ev & EventC) == EventC)
      {
         EventC_Toggle ^= 1; 
      }
   }
}

TASK(AppTask_PeriodicBasic)
{
    static uint8_t l_counter = 0; 
    
    AppTask_PeriodicBasic_Toggle ^= 0x1U;  
    
    l_counter++; 
    if (l_counter>3)
    {
       l_counter = 1; 
    }
    
    /* Events Setting*/
    if(l_counter == 1)
    {
       SetEvent(AppTask_ServerTask, EventA); 
    }
    else if (l_counter == 2)
    {
       SetEvent(AppTask_ServerTask, EventB); 
    }
    else if (l_counter == 3)
    {
       SetEvent(AppTask_ServerTask, EventC); 
    }
    else
    {
       
    }
    
	  TerminateTask(); 
}
