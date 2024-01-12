#pragma once
#include <Arduino.h>
#include "wifiManager.hpp"
#include <Firebase_ESP_Client.h>

// Wifi variables
Wifi wifi;
const std::string SSID = "Sensor";
const std::string WifiPassword = "12345678";
const int RESET_WIFI_PIN = 12;

// Firebase variables
const std::string API_KEY = "AIzaSyBgkHUN6xtG42Jpq-RHfCqFMb5MOns3Hkg";
const std::string PROJECT_ID = "condominio-inteligente-788c6";
const std::string FB_EMAIL = "petfeeder@petfeeder.com";
const std::string FB_PASSWORD = "12345678";
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

// Time variables
const char *ntpServer = "1.br.pool.ntp.org"; // NTP server
const long timezone = -10800;                // Timezone: GMT-3 in seconds
const int daylightSavingOffset = 0;          // Daylight saving time: 1 hour in seconds

// Tanks
