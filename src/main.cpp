#include "main.hpp"
#include <addons/TokenHelper.h>
#include <time.h>
#include "tank.hpp"

void setup()
{
  Serial.begin(115200);

  // Configurar wifi
  wifi.begin(SSID, WifiPassword);
  pinMode(RESET_WIFI_PIN, INPUT);

  // Configurar firebase
  config.api_key = API_KEY;
  auth.user.email = FB_EMAIL;
  auth.user.password = FB_PASSWORD;
  fbdo.setResponseSize(8192);
  config.token_status_callback = tokenStatusCallback;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // Configurar Tanques
  // Criar um tanque com id do firebase, pino e tamanho
  // Chamar setFirebaseSettings com os dados do firebase
  // Tank.setFirebaseSettings(&fbdo, &auth, &config, PROJECT_ID);
}

void loop()
{
  struct tm now;
  if (!getLocalTime(&now))
  {
    Serial.println("Falha ao obter hora");
    return;
  }

  // Medir nível usando tank.read()
  {
    // Se mudança > 5% enviar para o firebase como nível atual
    // Se passou 1 hora desde a última atualização enviar para o firebase como nível atual e histórico
  }

  // Ver se pino de reset de wifi destá pressionado
  if (digitalRead(RESET_WIFI_PIN) == HIGH)
    wifi.reset();
}
