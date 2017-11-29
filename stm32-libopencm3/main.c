#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#define LED_PIN GPIO5

void sys_tick_handler(void)
{
	gpio_toggle(GPIOA, LED_PIN);
}

int main(void)
{
	rcc_clock_setup_in_hsi_out_48mhz();

	/* Enable clock for GPIOA and set GPIO pin PA5 as output: */
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN);

	/* Initialize SysTick to generate an interrupt every half-second: */
	systick_clear();
	systick_set_reload(rcc_ahb_frequency / 8 / 2);
	systick_counter_enable();
	systick_interrupt_enable();

	while (1);
}
