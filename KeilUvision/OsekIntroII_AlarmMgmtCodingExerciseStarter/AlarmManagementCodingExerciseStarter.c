/**
 * @file AlarmManagementCodingExerciseStarter.c
 * @author Sarea Alhariri (Sarea.h95@outlook.com)
 * @brief  Alarm Managment coding exercise starter file
 * @version 0.1
 * @date 2020-10-23
 *
 * @copyright Sarea Alhariri - All rights reserved
 *
 */

#include "os.h"
#include "switch.h"


volatile static bool g_PwmSignal = 0u; 


/*******************************************************************************
 * TODO: 
 * Add your needed shared variables 
 ******************************************************************************/

/*******************************************************************************
 * TODO: 
 * Add the tasks & callback prototypes (DeclareTask(XX))
 ******************************************************************************/


void SystemInit(void) {}
int main(void) {
  StartOS();
  while (1)
    ; /* Should not be executed */
  return 0;
}

/*******************************************************************************
 * TODO: 
 * Add your implementation for AppTask_PulseWidthUpdate task 
 ******************************************************************************/

/*******************************************************************************
 * TODO: 
 * Add your implementation for AppTask_PwmOn task 
 ******************************************************************************/

/*******************************************************************************
 * TODO: 
 * Add your implementation for PwmOff callback 
 ******************************************************************************/

