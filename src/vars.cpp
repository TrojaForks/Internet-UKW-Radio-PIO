#include "MakeRadio.h"

String ssid1     = s_ssid;
String password1 = s_password;

String ssid2     = s_ssid;
String password2 = s_password;

String mode = "wlan";
uint8_t Stationsnummer = 0;
uint32_t lastchange = 0;
uint8_t actStation = Stationsnummer;

//uint32_t Frequenz = UKW_MIN;
uint32_t Frequenz = UKW_DEF_FREQ;
const char* stationurl[STATIONS];
String stationname[STATIONS];

uint8_t Stat_Pos_x2 = 3;


//Instanzen einrichten
SI4703 radio;  
RDSParser rds;
LiquidCrystal_PCF8574 lcd(0x27,20,4, convert_small);
Audio audio(true, I2S_DAC_CHANNEL_BOTH_EN);
//Audio audio(true);

AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, ROTARY_ENCODER_VCC_PIN, ROTARY_ENCODER_STEPS);

