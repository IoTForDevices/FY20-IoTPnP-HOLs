/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.8.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: 20/01/24
 ***********************************************************************************************/

#include "digitaltwin_serializer.h"

//
// Serialize telemetry data
//

bool Sensors_SerializeHumidityTelemetry(char * payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    double humidity = Sensors_Telemetry_ReadHumidity();

    int neededSize = snprintf(NULL, 0, "%f", humidity);

    if (neededSize > size - 1)
    {
        LogError("Failed to build humidity payload string");
        return false;
    }
    else
    {
        snprintf(payloadBuffer, size, "%f", humidity);
    }

    return true;
}

bool Sensors_SerializeTemperatureTelemetry(char * payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    double temperature = Sensors_Telemetry_ReadTemperature();

    int neededSize = snprintf(NULL, 0, "%f", temperature);

    if (neededSize > size - 1)
    {
        LogError("Failed to build temperature payload string");
        return false;
    }
    else
    {
        snprintf(payloadBuffer, size, "%f", temperature);
    }

    return true;
}

bool Sensors_SerializePressureTelemetry(char * payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    double pressure = Sensors_Telemetry_ReadPressure();

    int neededSize = snprintf(NULL, 0, "%f", pressure);

    if (neededSize > size - 1)
    {
        LogError("Failed to build pressure payload string");
        return false;
    }
    else
    {
        snprintf(payloadBuffer, size, "%f", pressure);
    }

    return true;
}

//
// Serialize read-only property
//

bool Deviceinfo_SerializeManufacturerProperty(char * payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    char* manufacturer = Deviceinfo_Property_GetManufacturer();

    int neededSize = snprintf(NULL, 0, "\"%s\"", manufacturer);

    if (neededSize > size - 1)
    {
        LogError("Failed to build manufacturer payload string");
        return false;
    }
    else
    {
        snprintf(payloadBuffer, size, "\"%s\"", manufacturer);
    }

    return true;
}

bool Deviceinfo_SerializeModelProperty(char * payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    char* model = Deviceinfo_Property_GetModel();

    int neededSize = snprintf(NULL, 0, "\"%s\"", model);

    if (neededSize > size - 1)
    {
        LogError("Failed to build model payload string");
        return false;
    }
    else
    {
        snprintf(payloadBuffer, size, "\"%s\"", model);
    }

    return true;
}

bool Deviceinfo_SerializeSwVersionProperty(char * payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    char* swVersion = Deviceinfo_Property_GetSwVersion();

    int neededSize = snprintf(NULL, 0, "\"%s\"", swVersion);

    if (neededSize > size - 1)
    {
        LogError("Failed to build swVersion payload string");
        return false;
    }
    else
    {
        snprintf(payloadBuffer, size, "\"%s\"", swVersion);
    }

    return true;
}

bool Deviceinfo_SerializeOsNameProperty(char * payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    char* osName = Deviceinfo_Property_GetOsName();

    int neededSize = snprintf(NULL, 0, "\"%s\"", osName);

    if (neededSize > size - 1)
    {
        LogError("Failed to build osName payload string");
        return false;
    }
    else
    {
        snprintf(payloadBuffer, size, "\"%s\"", osName);
    }

    return true;
}

bool Deviceinfo_SerializeProcessorArchitectureProperty(char * payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    char* processorArchitecture = Deviceinfo_Property_GetProcessorArchitecture();

    int neededSize = snprintf(NULL, 0, "\"%s\"", processorArchitecture);

    if (neededSize > size - 1)
    {
        LogError("Failed to build processorArchitecture payload string");
        return false;
    }
    else
    {
        snprintf(payloadBuffer, size, "\"%s\"", processorArchitecture);
    }

    return true;
}

bool Deviceinfo_SerializeProcessorManufacturerProperty(char * payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    char* processorManufacturer = Deviceinfo_Property_GetProcessorManufacturer();

    int neededSize = snprintf(NULL, 0, "\"%s\"", processorManufacturer);

    if (neededSize > size - 1)
    {
        LogError("Failed to build processorManufacturer payload string");
        return false;
    }
    else
    {
        snprintf(payloadBuffer, size, "\"%s\"", processorManufacturer);
    }

    return true;
}

bool Deviceinfo_SerializeTotalStorageProperty(char * payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    long totalStorage = Deviceinfo_Property_GetTotalStorage();

    int neededSize = snprintf(NULL, 0, "%ld", totalStorage);

    if (neededSize > size - 1)
    {
        LogError("Failed to build totalStorage payload string");
        return false;
    }
    else
    {
        snprintf(payloadBuffer, size, "%ld", totalStorage);
    }

    return true;
}

bool Deviceinfo_SerializeTotalMemoryProperty(char * payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    long totalMemory = Deviceinfo_Property_GetTotalMemory();

    int neededSize = snprintf(NULL, 0, "%ld", totalMemory);

    if (neededSize > size - 1)
    {
        LogError("Failed to build totalMemory payload string");
        return false;
    }
    else
    {
        snprintf(payloadBuffer, size, "%ld", totalMemory);
    }

    return true;
}

bool Leds_SerializeBlinkCommandResponse(LEDS_BLINK_blinkResponse* response, char* payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);

    json_object_set_string(root_object, "description", response->description);

    char * serializedString = json_serialize_to_string(root_value);

    int neededSize = (int)strlen(serializedString);
    if (serializedString == NULL || neededSize > size - 1)
    {
        LogError("Failed to build blink payload string");
        return false;
    }
    else
    {
        memcpy(payloadBuffer, serializedString, neededSize);
        free(serializedString);
    }

    json_value_free(root_value);

    return true;
}

bool Screen_SerializeEchoCommandResponse(SCREEN_ECHO_echoResponse* response, char* payloadBuffer, int size)
{
    if (payloadBuffer == NULL)
    {
        return false;
    }

    memset(payloadBuffer, 0, size);

    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);

    json_object_set_string(root_object, "echo", response->echo);

    char * serializedString = json_serialize_to_string(root_value);

    int neededSize = (int)strlen(serializedString);
    if (serializedString == NULL || neededSize > size - 1)
    {
        LogError("Failed to build echo payload string");
        return false;
    }
    else
    {
        memcpy(payloadBuffer, serializedString, neededSize);
        free(serializedString);
    }

    json_value_free(root_value);

    return true;
}

