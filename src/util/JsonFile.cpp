#include <ArduinoJson.h>
#include "./JsonFile.hpp"

JsonObject &JsonFile::read(const char *path)
{
    std::unique_ptr<char[]> *buf = JsonFile::readFileBytes(path);
    StaticJsonBuffer<200> *jsonBuffer = new StaticJsonBuffer<200>();
    if (buf == nullptr){
        Serial.println("Failed to read file");
        return jsonBuffer->createObject();
    }
    
    JsonObject &root = jsonBuffer->parseObject(buf->get());
    if (!root.success())
    {
        Serial.println("Failed to read JSON from file");
        return jsonBuffer->createObject();
    }
    Serial.println("Json successfully read");
    return root;
}

std::unique_ptr<char[]> *JsonFile::readFileBytes(const char *path)
{
    File file = SPIFFS.open(path, "r");
    if (!file)
    {
        Serial.print("Failed to open ");
        Serial.print(path);
        Serial.println(" file");
        return nullptr;
    }

    size_t size = file.size();
    if (size > 1024)
    {
        Serial.print("Warning: ");
        Serial.print(path);
        Serial.println(" file has more than 1024 bytes");
    }

    std::unique_ptr<char[]> *buf = new std::unique_ptr<char[]>(new char[size]);
    file.readBytes(buf->get(), size);
    file.close();
    return buf;
}
