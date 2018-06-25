#include <ArduinoJson.h>
#include "./util/JsonFile.hpp"
#include "./Network.hpp"
#include "./Manager.hpp"

void Manager::configureAll(const char *config_path)
{
    Serial.begin(9600);
    if (!SPIFFS.begin())
    {
        Serial.println("Failed to mount file system");
    }
    JsonObject &root_config = JsonFile::read(config_path);
    JsonObject &wifi_config = root_config["wifi"];

    root_config.printTo(Serial);
    Serial.println();

    Network::connect(wifi_config);
}