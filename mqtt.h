
#ifndef MQTT_H_
#define MQTT_H_

int mqtt_initialize();

void mqtt_send_core_temperature(float temperature);
#endif /*MQTT_H_*/
