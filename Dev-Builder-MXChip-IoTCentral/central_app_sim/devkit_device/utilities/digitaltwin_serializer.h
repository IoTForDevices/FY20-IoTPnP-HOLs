/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.8.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: 1/24/2020
 ***********************************************************************************************/

#ifndef DIGITALTWIN_SERIALIZER
#define DIGITALTWIN_SERIALIZER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "azure_c_shared_utility/xlogging.h"
#include "parson.h"

#include "../mxchip_iot_devkit_impl.h"

#ifdef __cplusplus
extern "C"
{
#endif

bool Deviceinfo_SerializeManufacturerProperty(char * payloadBuffer, int size);

bool Deviceinfo_SerializeModelProperty(char * payloadBuffer, int size);

bool Deviceinfo_SerializeSwVersionProperty(char * payloadBuffer, int size);

bool Deviceinfo_SerializeOsNameProperty(char * payloadBuffer, int size);

bool Deviceinfo_SerializeProcessorArchitectureProperty(char * payloadBuffer, int size);

bool Deviceinfo_SerializeProcessorManufacturerProperty(char * payloadBuffer, int size);

bool Deviceinfo_SerializeTotalStorageProperty(char * payloadBuffer, int size);

bool Deviceinfo_SerializeTotalMemoryProperty(char * payloadBuffer, int size);

bool Sensors_SerializeHumidityTelemetry(char * payloadBuffer, int size);

bool Sensors_SerializeTemperatureTelemetry(char * payloadBuffer, int size);

bool Sensors_SerializePressureTelemetry(char * payloadBuffer, int size);

bool Leds_SerializeBlinkCommandResponse(LEDS_BLINK_blinkResponse* response, char* payloadBuffer, int size);

bool Screen_SerializeEchoCommandResponse(SCREEN_ECHO_echoResponse* response, char* payloadBuffer, int size);

#ifdef __cplusplus
}
#endif

#endif // DIGITALTWIN_SERIALIZER
