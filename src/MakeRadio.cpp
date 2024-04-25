#include "MakeRadio.h"


void setup() {

  Serial.begin(115200);

  // Wait for Serial port to open
  while (!Serial) {
    delay(10);
  }
  delay(500);

  Serial.println("Total heap : " + String( ESP.getHeapSize() ) );
  Serial.println("Free  heap : " + String( ESP.getFreeHeap() ) );
  Serial.println("Total PSRAM: " + String( ESP.getPsramSize() ) );
  Serial.println("Free  PSRAM: " + String( ESP.getFreePsram() ) );

  setup_rotary();
  setup_senderList();
  UKW_setup();

  Serial.println("set Relais LOW");
  pinMode(RELAIS_PIN, OUTPUT);
  digitalWrite(RELAIS_PIN, LOW);

  Wire.begin();
  lcd.init();
  lcd.backlight();
  //Station mode
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  //Verbindung zu Netz1
  WiFi.begin(ssid1.c_str(), password1.c_str());
    showText(0,0,"Suche WLAN ");
    showText(0,1,ssid1);
    delay(5000);
    if (WiFi.status() == WL_CONNECTED) {
      showText(0,0,"WLAN-Verbindung mit ");
      showText(0,1,ssid1);
    }
   //Falls Netz1 nicht da ist, Versuch mit Netz2
   if (WiFi.status() != WL_CONNECTED) {
      lcd.clear();
      showText(0,0,"Suche WLAN");
      showText(0,1,ssid2);
      WiFi.disconnect();
      WiFi.begin(ssid2.c_str(), password2.c_str());
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("WLAN verbunden");
      showText(0,0,"WLAN-Verbindung mit ");
      showText(0,1,ssid2);
   }
  
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());
  delay(2000);
  lcd.clear();
  showText(0,0,"Radio gestartet");
  delay(500);
  audio.setVolume(100);
  audio.connecttohost(stationurl[Stationsnummer]);
  delay(500);
  showText(0,0,String(Stationsnummer+1));
  showText(Stat_Pos_x2,0,stationname[Stationsnummer]);  
}

void loop()
{
  // Run audio player
  if (mode == "wlan") {
    audio.loop();
    wlan_rotary_loop();
  }
  if (mode == "ukw") {
    ukw_rotary_loop();
  }
}

// Audio status functions
void audio_showstation(const char *info) {
    if (mode == "wlan") {
    Serial.print("station     "); 
    Serial.println(info);
    showText(0,0,"                    ");
    String Text = info;
    showText(0,0,String(Stationsnummer+1));
    showText(Stat_Pos_x2,0,stationname[Stationsnummer]);
  }
}
void audio_showstreamtitle(const char *info) {
  if (mode == "wlan") {
    lcd.setCursor(0,1);
    lcd.print("                    ");
    lcd.setCursor(0,2);
    lcd.print("                    ");
    lcd.setCursor(0,3);
    lcd.print("                    ");
    Serial.print("Titelname: "); 
    Serial.println(info);
    String Text = info;
    lcd.setCursor(0,1);
    lcd.print(Text.substring(0,20));
    lcd.setCursor(0,2);
    lcd.print(Text.substring(20,40));
    lcd.setCursor(0,3);
    lcd.print(Text.substring(40,60));
  }
}
void showText(int Spalte, int Zeile, String Text) {
    lcd.setCursor(Spalte,Zeile);
    lcd.print("                    ");
    lcd.setCursor(Spalte,Zeile);
    lcd.print(Text);
}

void audio_info(const char *info){
    Serial.print("info        "); Serial.println(info);
}

