#include <nrf_gpio.h>
#include "nrf52_it.h"

#define LED_PIN		17

void SysTick_Handler(void)
{
	nrf_gpio_pin_toggle(LED_PIN);
}

int main(void)
{
	nrf_gpio_cfg_output(LED_PIN);

	/* Initialize SysTick to generate an interrupt four times per second:
	   (Interestingly, it is not possible to make the SysTick fire every
	   half-second with the default clock configuration as in the stm32-cube
	   example. It's because the SysTick's Reload register supports value
	   in range 0 to 0x00FFFFFF.) */
	SysTick_Config(SystemCoreClock / 4);

	while (1);
}
