/*******************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.8.
 *
 * You need to add your implementation here to:
 *    - get telemetry data from device/sensor
 *    - set read-only property data
 *    - handle read-write property callback
 *    - process device command
 *
 * Generated Date: 20/01/24
 *******************************************************************************************/

#include "mxchip_iot_devkit_impl.h"
#include "utilities/digitaltwin_serializer.h"
#include "utilities/deviceinfo_interface.h"
#include "utilities/sensors_interface.h"
#include "utilities/leds_interface.h"
#include "utilities/screen_interface.h"
#include "utilities/settings_interface.h"

#define Payload_Buffer_Size 256

void SendTelemetry_Succeeded_Callback(const char* interfaceName)
{
    // If needed, put your business logic here to handle the confirmation of the delivery for device telemetry on success.

    LogInfo("DigitalTwin successfully delivered telemetry message for component %s", interfaceName);
}

void SendTelemetry_Error_Callback(const char* interfaceName)
{
    // If needed, put your business logic here to handle the confirmation of the delivery for device telemetry on failure.

    LogInfo("DigitalTwin failed to deliver telemetry message for %s", interfaceName);
}

void ReportProperty_Succeeded_Callback(const char* interfaceName, const char* propertyName)
{
    // If needed, put your business logic here to handle the result callback reporting property on success.

    LogInfo("DigitalTwin successfully report writable property for %s::%s", interfaceName, propertyName);
}

void ReportProperty_Error_Callback(const char* interfaceName, const char* propertyName)
{
    // If needed, put your business logic here to handle the result callback of reporting property on failure.

    LogInfo("DigitalTwin failed to report writable property for %s::%s", interfaceName, propertyName);
}

char* Deviceinfo_Property_GetManufacturer()
{
    // TODO: provide implementation here
    return "abc";
}

char* Deviceinfo_Property_GetModel()
{
    // TODO: provide implementation here
    return "abc";
}

char* Deviceinfo_Property_GetSwVersion()
{
    // TODO: provide implementation here
    return "abc";
}

char* Deviceinfo_Property_GetOsName()
{
    // TODO: provide implementation here
    return "abc";
}

char* Deviceinfo_Property_GetProcessorArchitecture()
{
    // TODO: provide implementation here
    return "abc";
}

char* Deviceinfo_Property_GetProcessorManufacturer()
{
    // TODO: provide implementation here
    return "abc";
}

long Deviceinfo_Property_GetTotalStorage()
{
    // TODO: provide implementation here
    return 0L;
}

long Deviceinfo_Property_GetTotalMemory()
{
    // TODO: provide implementation here
    return 0L;
}

double Sensors_Telemetry_ReadHumidity()
{
    // TODO: provide implementation here
    return 0.0;
}

double Sensors_Telemetry_ReadTemperature()
{
    // TODO: provide implementation here
    return 0.0;
}

double Sensors_Telemetry_ReadPressure()
{
    // TODO: provide implementation here
    return 0.0;
}

DIGITALTWIN_COMMAND_RESULT Leds_Command_Blink(long interval, LEDS_BLINK_blinkResponse* response, unsigned int* statusCode)
{
    // TODO: provide implementation here
    // You need to process the device command, and set the command response and statusCode correspondingly.
    // Finally, return DIGITALTWIN_COMMAND_OK if the command execution succeeded, or 'DIGITALTWIN_COMMAND_ERROR' on failure.

    LogInfo("Parameter: interval = %ld", interval);

    // Set command response and status code

    response->description = "abc";

    *statusCode = 200;
    LogInfo("Device executed 'blink' command successfully");
    return DIGITALTWIN_COMMAND_OK;
}

DIGITALTWIN_COMMAND_RESULT Leds_Command_TurnOnLed(unsigned int* statusCode)
{
    // TODO: provide implementation here

    *statusCode = 200;
    LogInfo("Execute 'turnOnLed' command successfully");
    return DIGITALTWIN_COMMAND_OK;
}

DIGITALTWIN_COMMAND_RESULT Leds_Command_TurnOffLed(unsigned int* statusCode)
{
    // TODO: provide implementation here

    *statusCode = 200;
    LogInfo("Execute 'turnOffLed' command successfully");
    return DIGITALTWIN_COMMAND_OK;
}

DIGITALTWIN_COMMAND_RESULT Screen_Command_Echo(char* text, SCREEN_ECHO_echoResponse* response, unsigned int* statusCode)
{
    // TODO: provide implementation here
    // You need to process the device command, and set the command response and statusCode correspondingly.
    // Finally, return DIGITALTWIN_COMMAND_OK if the command execution succeeded, or 'DIGITALTWIN_COMMAND_ERROR' on failure.

    LogInfo("Parameter: text = %s", text);

    // Set command response and status code

    response->echo = "abc";

    *statusCode = 200;
    LogInfo("Device executed 'echo' command successfully");
    return DIGITALTWIN_COMMAND_OK;
}

DIGITALTWIN_COMMAND_RESULT Screen_Command_Countdown(int number, unsigned int* statusCode)
{
    // TODO: provide implementation here

    LogInfo("Parameter: number = %d", number);

    *statusCode = 200;
    LogInfo("Execute 'countdown' command successfully");
    return DIGITALTWIN_COMMAND_OK;
}

bool Settings_Property_FanSpeedCallback(double fanSpeed)
{
    // TODO: provide implementation here
    LogInfo("FanSpeed property new value: %f", fanSpeed);
    return true;
}

bool Settings_Property_VoltageCallback(double voltage)
{
    // TODO: provide implementation here
    LogInfo("Voltage property new value: %f", voltage);
    return true;
}

bool Settings_Property_CurrentCallback(double current)
{
    // TODO: provide implementation here
    LogInfo("Current property new value: %f", current);
    return true;
}

bool Settings_Property_IrSwitchCallback(bool irSwitch)
{
    // TODO: provide implementation here
    LogInfo("IrSwitch property new value: %d", irSwitch);
    return true;
}

