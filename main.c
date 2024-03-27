/**
 * @author Rafael Martins de Sousa - RA: 220023201
 * @brief Arquivo referente à "Atividade 01 - Envio temperatura do nucleo Raspberry Pi Pico W via MQTT"
 */

#include <stdio.h>
#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"
#include "bsp/board.h"
#include "mqtt.h"
#include "core_temp.h"

int main()
{
  stdio_init_all();
  printf("Initializing..\n");

  if (mqtt_initialize() != 0)
  {
    return 1;
  }

  core_temp_init();
  cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

  while (1)
  {
    if (board_button_read())
    {
      mqtt_send_core_temperature(core_temp_read());
    }
    sleep_ms(200);
  }

  return 0;
}
