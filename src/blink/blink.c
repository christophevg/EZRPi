#include <stdint.h>
#include <stdbool.h>

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"

// EZR_USB
#define LED_PORT gpioPortD
#define LED_PIN  6

// EZRPi
// #define LED_PORT gpioPortE
// #define LED_PIN  2

volatile uint32_t ticks;

void SysTick_Handler(void) { ticks++; }

void delay(uint32_t ms) {
  uint32_t now;
  now = ticks;
  while( (ticks - now) < ms );
}

int main(void) {
  CHIP_Init();

  CMU_ClockEnable(cmuClock_GPIO, true);

  if( SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000) ) { while(true); }

  GPIO_PinModeSet(LED_PORT, LED_PIN, gpioModePushPull, 0);

  while(true) {
    GPIO_PinOutToggle(LED_PORT, LED_PIN);    
    delay(1000);
  }
}
