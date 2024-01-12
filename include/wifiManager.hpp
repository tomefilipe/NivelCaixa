#pragma once
#include <WiFi.h>
#include <wifiManager.h>
#include <DNSServer.h>
#include <WebServer.h>

class Wifi : public WiFiManager {
    public: 
        void config(std::string SSID, std::string Password);
        void begin(std::string SSID, std::string Password);
        void reset();
};
