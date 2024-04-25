#ifndef ROTARY_H
#define ROTARY_H

void wlan_rotary_loop();
void ukw_rotary_loop();
void IRAM_ATTR readEncoderISR();
void setup_rotary();

#endif
