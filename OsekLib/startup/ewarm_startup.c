/* startup code for TM4C MCU */

extern int CSTACK$$Limit;			      /*This symbol is provided by linker */
extern void __iar_program_start(void); /*This symbol is provided by linker */
extern void Default_Handler(void);
extern void NMI_Handler(void);
extern void HardFault_Handler(void);
extern void MemManage_Handler(void);
extern void BusFault_Handler(void);
extern void UsageFault_Handler(void);
extern void SVC_Dispatcher(void);
extern void Default_Handler(void);
extern void OsPort_PendSVHandler(void);
extern void SystemTimerHandler(void);

#pragma location=".intvec"
int const __vector_table[] = {
	(int)&CSTACK$$Limit,
	(int)&__iar_program_start,
	(int)&NMI_Handler,
	(int)&HardFault_Handler,
	(int)&MemManage_Handler,
	(int)&BusFault_Handler,
	(int)&UsageFault_Handler,
	0, /* Reserved */
	0, /* Reserved */
	0, /* Reserved */
	0, /* Reserved */
	(int)&SVC_Dispatcher,
	(int)&Default_Handler,
	0, /* Reserved */
	(int)&OsPort_PendSVHandler,
	(int)&SystemTimerHandler,

	/* external interrupts (IRQs) */
	(int)&Default_Handler, /* GPIO Port A                  */
	(int)&Default_Handler, /* GPIO Port B                  */
	(int)&Default_Handler, /* GPIO Port C                  */
	(int)&Default_Handler, /* GPIO Port D                  */
	(int)&Default_Handler, /* GPIO Port E                  */
	(int)&Default_Handler, /* UART0 Rx and Tx              */
	(int)&Default_Handler, /* UART1 Rx and Tx              */
	(int)&Default_Handler, /* SSI0 Rx and Tx               */
	(int)&Default_Handler, /* I2C0 Master and Slave        */
	(int)&Default_Handler, /* PWM Fault                    */
	(int)&Default_Handler, /* PWM Generator 0              */
	(int)&Default_Handler, /* PWM Generator 1              */
	(int)&Default_Handler, /* PWM Generator 2              */
	(int)&Default_Handler, /* Quadrature Encoder 0         */
	(int)&Default_Handler, /* ADC Sequence 0               */
	(int)&Default_Handler, /* ADC Sequence 1               */
	(int)&Default_Handler, /* ADC Sequence 2               */
	(int)&Default_Handler, /* ADC Sequence 3               */
	(int)&Default_Handler, /* Watchdog timer               */
	(int)&Default_Handler, /* Timer 0 subtimer A           */
	(int)&Default_Handler, /* Timer 0 subtimer B           */
	(int)&Default_Handler, /* Timer 1 subtimer A           */
	(int)&Default_Handler, /* Timer 1 subtimer B           */
	(int)&Default_Handler, /* Timer 2 subtimer A           */
	(int)&Default_Handler, /* Timer 2 subtimer B           */
	(int)&Default_Handler, /* Analog Comparator 0          */
	(int)&Default_Handler, /* Analog Comparator 1          */
	(int)&Default_Handler, /* Analog Comparator 2          */
	(int)&Default_Handler, /* System Control (PLL,OSC,BO)  */
	(int)&Default_Handler, /* FLASH Control                */
	(int)&Default_Handler, /* GPIO Port F                  */
	(int)&Default_Handler, /* GPIO Port G                  */
	(int)&Default_Handler, /* GPIO Port H                  */
	(int)&Default_Handler, /* UART2 Rx and Tx              */
	(int)&Default_Handler, /* SSI1 Rx and Tx               */
	(int)&Default_Handler, /* Timer 3 subtimer A           */
	(int)&Default_Handler, /* Timer 3 subtimer B           */
	(int)&Default_Handler, /* I2C1 Master and Slave        */
	(int)&Default_Handler, /* Quadrature Encoder 1         */
	(int)&Default_Handler, /* CAN0                         */
	(int)&Default_Handler, /* CAN1                         */
	(int)&Default_Handler, /* CAN2                         */
	0,					   /* Reserved                     */
	(int)&Default_Handler, /* Hibernate                    */
	(int)&Default_Handler, /* USB0                         */
	(int)&Default_Handler, /* PWM Generator 3              */
	(int)&Default_Handler, /* uDMA Software Transfer       */
	(int)&Default_Handler, /* uDMA Error                   */
	(int)&Default_Handler, /* ADC1 Sequence 0              */
	(int)&Default_Handler, /* ADC1 Sequence 1              */
	(int)&Default_Handler, /* ADC1 Sequence 2              */
	(int)&Default_Handler, /* ADC1 Sequence 3              */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	(int)&Default_Handler, /* GPIO Port J                  */
	(int)&Default_Handler, /* GPIO Port K                  */
	(int)&Default_Handler, /* GPIO Port L                  */
	(int)&Default_Handler, /* SSI2 Rx and Tx               */
	(int)&Default_Handler, /* SSI3 Rx and Tx               */
	(int)&Default_Handler, /* UART3 Rx and Tx              */
	(int)&Default_Handler, /* UART4 Rx and Tx              */
	(int)&Default_Handler, /* UART5 Rx and Tx              */
	(int)&Default_Handler, /* UART6 Rx and Tx              */
	(int)&Default_Handler, /* UART7 Rx and Tx              */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	(int)&Default_Handler, /* I2C2 Master and Slave        */
	(int)&Default_Handler, /* I2C3 Master and Slave        */
	(int)&Default_Handler, /* Timer 4 subtimer A           */
	(int)&Default_Handler, /* Timer 4 subtimer B           */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	(int)&Default_Handler, /* Timer 5 subtimer A           */
	(int)&Default_Handler, /* Timer 5 subtimer B           */
	(int)&Default_Handler, /* Wide Timer 0 subtimer A      */
	(int)&Default_Handler, /* Wide Timer 0 subtimer B      */
	(int)&Default_Handler, /* Wide Timer 1 subtimer A      */
	(int)&Default_Handler, /* Wide Timer 1 subtimer B      */
	(int)&Default_Handler, /* Wide Timer 2 subtimer A      */
	(int)&Default_Handler, /* Wide Timer 2 subtimer B      */
	(int)&Default_Handler, /* Wide Timer 3 subtimer A      */
	(int)&Default_Handler, /* Wide Timer 3 subtimer B      */
	(int)&Default_Handler, /* Wide Timer 4 subtimer A      */
	(int)&Default_Handler, /* Wide Timer 4 subtimer B      */
	(int)&Default_Handler, /* Wide Timer 5 subtimer A      */
	(int)&Default_Handler, /* Wide Timer 5 subtimer B      */
	(int)&Default_Handler, /* FPU                          */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	(int)&Default_Handler, /* I2C4 Master and Slave        */
	(int)&Default_Handler, /* I2C5 Master and Slave        */
	(int)&Default_Handler, /* GPIO Port M                  */
	(int)&Default_Handler, /* GPIO Port N                  */
	(int)&Default_Handler, /* Quadrature Encoder 2         */
	0,					   /* Reserved                     */
	0,					   /* Reserved                     */
	(int)&Default_Handler, /* GPIO Port P (Summary or P0)  */
	(int)&Default_Handler, /* GPIO Port P1                 */
	(int)&Default_Handler, /* GPIO Port P2                 */
	(int)&Default_Handler, /* GPIO Port P3                 */
	(int)&Default_Handler, /* GPIO Port P4                 */
	(int)&Default_Handler, /* GPIO Port P5                 */
	(int)&Default_Handler, /* GPIO Port P6                 */
	(int)&Default_Handler, /* GPIO Port P7                 */
	(int)&Default_Handler, /* GPIO Port Q (Summary or Q0)  */
	(int)&Default_Handler, /* GPIO Port Q1                 */
	(int)&Default_Handler, /* GPIO Port Q2                 */
	(int)&Default_Handler, /* GPIO Port Q3                 */
	(int)&Default_Handler, /* GPIO Port Q4                 */
	(int)&Default_Handler, /* GPIO Port Q5                 */
	(int)&Default_Handler, /* GPIO Port Q6                 */
	(int)&Default_Handler, /* GPIO Port Q7                 */
	(int)&Default_Handler, /* GPIO Port R                  */
	(int)&Default_Handler, /* GPIO Port S                  */
	(int)&Default_Handler, /* PWM 1 Generator 0            */
	(int)&Default_Handler, /* PWM 1 Generator 1            */
	(int)&Default_Handler, /* PWM 1 Generator 2            */
	(int)&Default_Handler, /* PWM 1 Generator 3            */
	(int)&Default_Handler  /* PWM 1 Fault                  */

};

void HardFault_Handler(void)
{
  while (1)
	;
}

void NMI_Handler(void)
{
  while (1)
	;
}

void MemManage_Handler(void)
{
  while (1)
	;
}

void BusFault_Handler(void)
{
  while (1)
	;
}

void UsageFault_Handler(void)
{
  while (1)
	;
}

void Default_Handler(void)
{
  while (1)
	;
}
