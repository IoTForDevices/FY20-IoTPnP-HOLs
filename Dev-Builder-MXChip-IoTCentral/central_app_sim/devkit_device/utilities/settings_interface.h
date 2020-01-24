/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.8.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: 1/24/2020
 ***********************************************************************************************/

#ifndef SETTINGS_INTERFACE_H
#define SETTINGS_INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "digitaltwin_interface_client.h"
#include "azure_c_shared_utility/xlogging.h"
#include "azure_c_shared_utility/threadapi.h"

#include "digitaltwin_client_helper.h"
#include "digitaltwin_serializer.h"
#include "parson.h"
#include "../mxchip_iot_devkit_impl.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum SETTINGS_READONLY_PROPERTY_TAG
{
    Settings_FANSPEED_PROPERTY,
    Settings_VOLTAGE_PROPERTY,
    Settings_CURRENT_PROPERTY,
    Settings_IRSWITCH_PROPERTY
} SETTINGS_PROPERTY;

// DigitalTwin interface name from service perspective.
static const char SettingsInterfaceId[] = "urn:mxchip:settings:1";
static const char SettingsInterfaceInstanceName[] = "settings";

// Telemetry names for this interface.

// Property names for this interface.

#define SettingsInterface_FanSpeedProperty "fanSpeed"

#define SettingsInterface_VoltageProperty "voltage"

#define SettingsInterface_CurrentProperty "current"

#define SettingsInterface_IrSwitchProperty "irSwitch"

// Command names for this interface

// Methods
DIGITALTWIN_INTERFACE_CLIENT_HANDLE SettingsInterface_Create();

void SettingsInterface_Close(DIGITALTWIN_INTERFACE_CLIENT_HANDLE digitalTwinInterfaceClientHandle);

#ifdef __cplusplus
}
#endif

#endif  // SETTINGS_INTERFACE_H
