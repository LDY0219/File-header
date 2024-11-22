/*
 ESP8266WiFi.h - esp8266 Wifi support.
 Based on WiFi.h from Arduino WiFi shield library.
 Copyright (c) 2011-2014 Arduino.  All right reserved.
 Modified by Ivan Grokhotkov, December 2014

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef WiFi_h
#define WiFi_h

#include <stdint.h>

extern "C" {
#include <wl_definitions.h>
}

#include "IPAddress.h"

#include "ESP8266WiFiType.h"
#include "ESP8266WiFiSTA.h"
#include "ESP8266WiFiAP.h"
#include "ESP8266WiFiScan.h"
#include "ESP8266WiFiGeneric.h"

#include "WiFiClient.h"
#include "WiFiServer.h"
#include "WiFiServerSecure.h"
#include "WiFiClientSecure.h"
#include "BearSSLHelpers.h"
#include "CertStoreBearSSL.h"

#ifdef DEBUG_ESP_WIFI
#ifdef DEBUG_ESP_PORT
#define DEBUG_WIFI(fmt, ...) DEBUG_ESP_PORT.printf_P( (PGM_P)PSTR(fmt), ##__VA_ARGS__ )
#endif
#endif

#ifndef DEBUG_WIFI
#define DEBUG_WIFI(...) do { (void)0; } while (0)
#endif

extern "C" void enableWiFiAtBootTime (void) __attribute__((noinline));

class ESP8266WiFiClass : public ESP8266WiFiGenericClass, public ESP8266WiFiSTAClass, public ESP8266WiFiScanClass, public ESP8266WiFiAPClass {
    public:

        // workaround same function name with different signature
        using ESP8266WiFiGenericClass::channel;

        using ESP8266WiFiSTAClass::SSID;
        using ESP8266WiFiSTAClass::RSSI;
        using ESP8266WiFiSTAClass::BSSID;
        using ESP8266WiFiSTAClass::BSSIDstr;

        using ESP8266WiFiScanClass::SSID;
        using ESP8266WiFiScanClass::encryptionType;
        using ESP8266WiFiScanClass::RSSI;
        using ESP8266WiFiScanClass::BSSID;
        using ESP8266WiFiScanClass::BSSIDstr;
        using ESP8266WiFiScanClass::channel;
        using ESP8266WiFiScanClass::isHidden;

        // ----------------------------------------------------------------------------------------------
        // ------------------------------------------- Debug --------------------------------------------
        // ----------------------------------------------------------------------------------------------

    public:

        void printDiag(Print& dest);

        friend class WiFiClient;
        friend class WiFiServer;

};

extern ESP8266WiFiClass WiFi;

#endif
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pins:
  for (int thisPin = 2; thisPin < 7; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // read the sensor:
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    // do something different depending on the character received.
    // The switch statement expects single number values for each case;
    // in this exmaple, though, you're using single quotes to tell
    // the controller to get the ASCII value for the character.  For
    // example 'a' = 97, 'b' = 98, and so forth:

    switch (inByte) {
      case 'a':
        digitalWrite(2, HIGH);
        break;
      case 'b':
        digitalWrite(3, HIGH);
        break;
      case 'c':
        digitalWrite(4, HIGH);
        break;
      case 'd':
        digitalWrite(5, HIGH);
        break;
      case 'e':
        digitalWrite(6, HIGH);
        break;
      default:
        // turn all the LEDs off:
        for (int thisPin = 2; thisPin < 7; thisPin++) {
          digitalWrite(thisPin, LOW);
        }
    }
  }
}

