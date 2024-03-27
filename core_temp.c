#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/adc.h"

// ADC conversion factor
const float adc_conversion_factor = 3.3f / (1 << 12);

static float convert_volts_to_celsius(float volts)
{
    return 27 - (volts - 0.706) / 0.001721;
}

bool timer_callback(struct repeating_timer *t)
{
    float voltage = 0;
    printf("Nova amostra de temperatura\n");
    voltage = adc_read() * adc_conversion_factor;
    printf("Voltage: %fV => %fºC\n", voltage, convert_volts_to_celsius(voltage));
    printf("---------------------------\n");
    return true;
}

void core_temp_init()
{
    // Configura o ADC
    adc_init();
    // Input 4 é o sensor onboard!
    adc_select_input(4);
}

float core_temp_read()
{
    float voltage = 0;
    voltage = adc_read() * adc_conversion_factor;
    return convert_volts_to_celsius(voltage);
}