#include "wifiManager.hpp"

void Wifi::config(std::string SSID, std::string Password) {
    this->setClass("invert");
    this->autoConnect(SSID.c_str(), Password.c_str());
    Serial.println("Wifi concectado!");
};

void Wifi::begin(std::string SSID, std::string Password) {
    this->setClass("invert");
    this->setWiFiAutoReconnect(true);
    this->setConnectTimeout(60);
    this->setConnectRetries(10);
    this->autoConnect(SSID.c_str(), Password.c_str());
    Serial.println("Wifi concectado!");
};

void Wifi::reset() {
    this->resetSettings();
};