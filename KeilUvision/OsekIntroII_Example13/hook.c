/**
 * @file hook.c
 * @author Sarea Alhariri (sarea.h95@outlook.com)
 * @brief Hook routine stubs
 * @version 0.1
 * @date 2020-05-03
 *
 * @copyright ALL RIGHT RESERVED - Sarea Alhariri
 *
 */
#include "OsTypes.h"
#include "OsCfg.h"
static uint8_t PreTaskToggle = 0u; 
static uint8_t PostTaskToggle = 0u; 

/**
 * @brief Error hook that will be triggered in any error is detected
 *          upon system service call
 * @remark The hook implementation is user defined
 *
 * @param status
 */
void ErrorHook(StatusType status){}

/**
 * @brief This hook routine is called by the operating system at the end of
 * the operating system initialisation and before the scheduler is running.
 * The user may use it for App related Init/device driver init..etc.
 */
void StartupHook(void){
}

/**
 * @brief This hook routine is called by the operating system before
 * executing a new task, but after the transition of the task to the
 * running state
 *
 */
void PreTaskHook(void){
	TaskType l_CurrentTask = 0 ; 
	GetTaskID(&l_CurrentTask); 
	if(AppTask_MultiEventTask == l_CurrentTask){
		PreTaskToggle ^= 1u; 
	}
}

/**
 * @brief This hook routine is called by the operating system after
 * executing a new task, but before the transition of the task out of the
 * running state
 *
 */
void PostTaskHook(void){
	TaskType l_CurrentTask = 0 ; 
	GetTaskID(&l_CurrentTask); 
	if(AppTask_MultiEventTask == l_CurrentTask){	
		PostTaskToggle ^= 1u; 
	}
}

/**
 * @brief if configured, this hook will be triggerd if the OS detected
 * an stack overflow for any application thread
 *
 */
void StackOverFlowHook(void){}


	