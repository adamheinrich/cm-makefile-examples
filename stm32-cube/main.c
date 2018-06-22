#include <stm32f0xx.h>
#include "stm32f0xx_it.h"

void SysTick_Handler(void)
{
	HAL_IncTick();
}

int main(void)
{
	HAL_Init();

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef gpio_init = {
		.Pin = GPIO_PIN_5,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_PULLUP,
	};
	HAL_GPIO_Init(GPIOA, &gpio_init);

	while (1) {
		HAL_Delay(500);
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	}
}
