/**
 * @file OsekIntro_Example2.c
 * @author Sarea Alhariri (Sarea.h95@outlook.com)
 * @brief  Array Multiplication and task execution measurement  
 * @version 0.1
 * @date 2020-08-28
 *
 * @copyright Sarea Alhariri - All rights reserved
 *
 */


#include "os.h"
#include <stdlib.h>


#define UNIFORM_SIZE 12U 

#define A_M     UNIFORM_SIZE 
#define A_N     UNIFORM_SIZE
#define B_M     UNIFORM_SIZE
#define B_N     UNIFORM_SIZE

static uint8_t A[A_M][A_N] = {0U}; 
static uint8_t B[B_M][B_N] = {0U}; 
static uint8_t result[A_M][B_N] = {0U}; 


DeclareTask(AppTask_Periodic);


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
   uint8_t i = 0U; 
   uint8_t j = 0U; 
   uint8_t k = 0U; 
   
   for(i = 0U; i<A_M; i++) /*Initialize the array */
   {
      for(j = 0U; j<A_N; j++)
      {
         A[i][j] = rand(); 
         B[i][j] = rand(); 
      }
   }
   
   for(i = 0U; i<A_M; i++) /* Multiplication A*B */
   {
      for(j = 0U; j<A_N; j++)
      {
         for(k = 0U; k<A_N; k++)
         {
            result[i][j] += A[i][k] * B[k][j];
         }
      }
   }       
	TerminateTask(); 
}

