#include <stdint.h>
#include <stdio.h>

/* This function executes in THREAD MODE of the processor */
void generate_interrupt()
{
	uint32_t *p_stir  = (uint32_t*) 0xE000EF00;
	uint32_t *p_iser0 = (uint32_t*) 0xE000E100;

	// enable IRQ3 interrupt
	*p_iser0 |= (1 << 3);

	// generate an interrupt from software for IRQ3
	*p_stir = (3 & 0x1FF);
}


/* This function executes in THREAD MODE of the processor */
int main(void)
{
	printf("In thread mode: before interrupt\n");

	generate_interrupt();

	printf("In thread mode: after interrupt\n");

	for(;;);
}

/* This function (ISR) executes in Handler Mode of the processor */
void RTC_WKUP_IRQHandler(void)
{
	printf("In handler mode: ISR\n");
}

















































