
#include "switch.h"
#include "tm4c123gh6pm.h"



__inline bool Swich_RightRawPressed(void); 
__inline bool Swich_LeftRawPressed(void); 



bool Switch_RightIsPressed(void)
{
    static bool l_LastValue = false;
    bool RawValue ;
	  uint8_t l_pressed = 0 ; 
    
    RawValue = Swich_RightRawPressed();
    
    if (RawValue != l_LastValue){
       l_LastValue = RawValue;
		 if (l_LastValue)
       {
          l_pressed = 1U; 
       }
    }
    return l_pressed; 
}
bool Switch_LeftIsPressed(void)
{
    static bool l_LastValue = false;
    bool RawValue ;
	 uint8_t l_pressed = 0 ; 
    
    RawValue = Swich_LeftRawPressed();
    
    if (RawValue != l_LastValue){
       l_LastValue = RawValue;
		 if (l_LastValue)
       {
          l_pressed = 1U; 
       }
    }
    return l_pressed; 
}
__inline bool Swich_RightRawPressed(void){
   return (bool)!(GPIO_PORTF_DATA_R & 0x01U); /* return bit 0 */ 
}
__inline bool Swich_LeftRawPressed(void){
   return (bool)!(GPIO_PORTF_DATA_R & 0x10U); /* return bit 4 */ 
}