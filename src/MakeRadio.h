
/*
  verwendet ESP32-audioI2S Library - https://github.com/schreibfaul1/ESP32-audioI2S
*/
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include "sdkconfig.h"

// Bibliotheken einbinden
#include "Arduino.h"
#include "WiFi.h"
#include "Audio.h"
// https://werner.rothschopf.net/202003_arduino_liquid_crystal_umlaute.htm
#include <Wire.h>
#include <NoiascaLiquidCrystal.h> 
#include <NoiascaHW/lcd_PCF8574.h>
#include <SI4703.h>
#include <RDSParser.h>
#include <radio.h> /// Source Code auf https://github.com/mathertel/Radio
#include "AiEsp32RotaryEncoder.h"


#include "rotary.h"
#include "UKW.h"
#include "WLANsenderlist.h"

#define RESET_PIN 18
#define MODE_PIN 21 
#define RELAIS_PIN 16
#define UKW_MIN 8750
#define UKW_MAX 10800
// https://de.wikipedia.org/wiki/Liste_der_UKW-H%C3%B6rfunksender_in_%C3%96sterreich
// 8990 ... Radio Wien
#define UKW_DEF_FREQ 9450
#define UKW_STEP 10
#define STATIONS 15
#define ROTARY_ENCODER_A_PIN 33
#define ROTARY_ENCODER_B_PIN 32
#define ROTARY_ENCODER_BUTTON_PIN 34
#define ROTARY_ENCODER_VCC_PIN -1 
#define ROTARY_ENCODER_STEPS 4

extern String s_ssid;
extern String s_password;

extern String ssid1;
extern String password1;
extern String ssid2;
extern String password2;

extern String mode;
extern uint8_t Stationsnummer;
extern uint32_t lastchange;
extern uint8_t actStation;
//extern uint32_t Frequenz;
extern uint32_t Frequenz;
extern const char* stationurl[STATIONS];
extern String stationname[STATIONS];

extern uint8_t Stat_Pos_x2;


//Instanzen einrichten
extern SI4703 radio;  
extern RDSParser rds;
extern LiquidCrystal_PCF8574 lcd;
extern Audio audio;
extern AiEsp32RotaryEncoder rotaryEncoder;

#ifndef MAKERADIO_H
#define MAKERADIO_H
void audio_showstation(const char *info);
void audio_showstreamtitle(const char *info);
void showText(int Spalte, int Zeile, String Text);
void audio_info(const char *info);
#endif
