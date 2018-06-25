#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include "Network.hpp"

void Network::connect(JsonObject &config)
{
    const char *ssid = config["ssid"];
    const char *password = config["password"];
    const char *hostname = config["hostname"];

    WiFi.mode(WIFI_STA);
    WiFi.hostname(hostname);

    WiFi.begin(ssid, password);
    Serial.print("connecting to ");
    Serial.print(ssid);
    Serial.println();
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    Serial.print("Hostname: ");
    Serial.println(hostname);
}