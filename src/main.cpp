#include <Arduino.h>
#include "password.h"

#define BLYNK_PRINT Serial

// #include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial

// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial1

// or Software Serial on Uno, Nano...
//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:

// #define ESP8266_BAUD 115200

// ESP8266 wifi(&EspSerial);

void setup()
{
  // Debug console
  Serial.begin(9600);

  delay(10);

  // Set ESP8266 baud rate
  // EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, ssid, pass);
  // sigmaDeltaSetup(0, 312500);
  // sigmaDeltaAttachPin(LED_BUILTIN, 0);
  // sigmaDeltaWrite(0, 0);
  delay(10);
  analogWriteRange(255);
  // delay(1000);
  // digitalWrite(LED_BUILTIN,HIGH);
  // delay(1000);
  // digitalWrite(LED_BUILTIN,LOW);
  // delay(1000);
}
int LED_level = 0;
void loop(){
  Blynk.run();
  delay(100);
  digitalWrite(LED_BUILTIN,HIGH);
  // analogWrite(LED_BUILTIN, LED_level);
  Serial.println(LED_level);
}

BLYNK_WRITE(V0){
  //スマホ側 Blynk アプリで設定したスライダー値の受信
  LED_level = param[0].asInt();
}
