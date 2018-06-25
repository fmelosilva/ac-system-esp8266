#include <ArduinoJson.h>
#include <FS.h>

class JsonFile : public JsonObject
{
  public:
    static JsonObject &read(const char *path);

  private:
    static std::unique_ptr<char[]> *readFileBytes(const char* path);
};
