/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.8.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: 1/24/2020
 ***********************************************************************************************/

#include "leds_interface.h"

#define MAX_MESSAGE_SIZE 256

//
//  Callback function declarations and DigitalTwin command names for this interface.
//

static void LedsInterface_Command_BlinkCallback(const DIGITALTWIN_CLIENT_COMMAND_REQUEST* commandRequest, DIGITALTWIN_CLIENT_COMMAND_RESPONSE* commandResponse, void* userInterfaceContext);

static void LedsInterface_Command_TurnOnLedCallback(const DIGITALTWIN_CLIENT_COMMAND_REQUEST* commandRequest, DIGITALTWIN_CLIENT_COMMAND_RESPONSE* commandResponse, void* userInterfaceContext);

static void LedsInterface_Command_TurnOffLedCallback(const DIGITALTWIN_CLIENT_COMMAND_REQUEST* commandRequest, DIGITALTWIN_CLIENT_COMMAND_RESPONSE* commandResponse, void* userInterfaceContext);

//
// Application state associated with this interface.
// It contains the DIGITALTWIN_INTERFACE_CLIENT_HANDLE used for responses in callbacks along with properties set
// and representations of the property update and command callbacks invoked on given interface
//
typedef struct LEDS_INTERFACE_STATE_TAG
{
    DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceClientHandle;

} LEDS_INTERFACE_STATE;

static LEDS_INTERFACE_STATE appState;

// Callback function to process the command "blink".
void LedsInterface_Command_BlinkCallback(const DIGITALTWIN_CLIENT_COMMAND_REQUEST* commandRequest, DIGITALTWIN_CLIENT_COMMAND_RESPONSE* commandResponse, void* userInterfaceContext)
{
    LEDS_INTERFACE_STATE* interfaceState = (LEDS_INTERFACE_STATE*)userInterfaceContext;
    LogInfo("LEDS_INTERFACE: blink command invoked.");
    LogInfo("LEDS_INTERFACE: blink request payload=<%.*s>, context=<%p>", (int)commandRequest->requestDataLen, commandRequest->requestData, interfaceState);

    // Get payload string
    char* requestData = (char*)malloc(commandRequest->requestDataLen + 1);
    if (requestData != NULL)
    {
        strncpy(requestData, (char*)commandRequest->requestData, commandRequest->requestDataLen);
        requestData[commandRequest->requestDataLen] = 0;
    }
    else
    {
        LogError("Failed to allocate memory for request payload");
    }

    // Parse request parameters from request payload string
    JSON_Value *jsonValue = NULL;
    jsonValue = json_parse_string((const char*)requestData);

    long interval = (long)json_value_get_number(jsonValue);

    // Invoke device command here
    unsigned int statusCode = 200;

    char responsePayload[MAX_MESSAGE_SIZE];

    LEDS_BLINK_blinkResponse response;

    DIGITALTWIN_COMMAND_RESULT commandResult = Leds_Command_Blink(interval, &response, &statusCode);

    // Serialize command response payload

    if (commandResult == DIGITALTWIN_COMMAND_OK &&
        Leds_SerializeBlinkCommandResponse(&response, responsePayload, MAX_MESSAGE_SIZE))
    {
        DigitalTwinClientHelper_SetCommandResponse(commandResponse, (const unsigned char*)responsePayload, statusCode);

    }
    else
    {
        LogError("Failed to execute blink command");
        const unsigned char errorResponse[] = "\"Failed to execute blink command\"";
        DigitalTwinClientHelper_SetCommandResponse(commandResponse, errorResponse, statusCode);
    }

    free(requestData);

    if (jsonValue)
    {
        json_value_free(jsonValue);
    }

}

// Callback function to process the command "turnOnLed".
void LedsInterface_Command_TurnOnLedCallback(const DIGITALTWIN_CLIENT_COMMAND_REQUEST* commandRequest, DIGITALTWIN_CLIENT_COMMAND_RESPONSE* commandResponse, void* userInterfaceContext)
{
    LEDS_INTERFACE_STATE* interfaceState = (LEDS_INTERFACE_STATE*)userInterfaceContext;
    LogInfo("LEDS_INTERFACE: turnOnLed command invoked.");
    LogInfo("LEDS_INTERFACE: turnOnLed request payload=<%.*s>, context=<%p>", (int)commandRequest->requestDataLen, commandRequest->requestData, interfaceState);

    // Invoke device command here
    unsigned int statusCode = 200;

    DIGITALTWIN_COMMAND_RESULT commandResult = Leds_Command_TurnOnLed(&statusCode);

    if (commandResult == DIGITALTWIN_COMMAND_OK)
    {
        DigitalTwinClientHelper_SetCommandResponse(commandResponse, NULL, statusCode);

    }
    else
    {
        LogError("Failed to execute turnOnLed command");
        const unsigned char errorResponse[] = "\"Failed to execute turnOnLed command\"";
        DigitalTwinClientHelper_SetCommandResponse(commandResponse, errorResponse, statusCode);
    }

}

// Callback function to process the command "turnOffLed".
void LedsInterface_Command_TurnOffLedCallback(const DIGITALTWIN_CLIENT_COMMAND_REQUEST* commandRequest, DIGITALTWIN_CLIENT_COMMAND_RESPONSE* commandResponse, void* userInterfaceContext)
{
    LEDS_INTERFACE_STATE* interfaceState = (LEDS_INTERFACE_STATE*)userInterfaceContext;
    LogInfo("LEDS_INTERFACE: turnOffLed command invoked.");
    LogInfo("LEDS_INTERFACE: turnOffLed request payload=<%.*s>, context=<%p>", (int)commandRequest->requestDataLen, commandRequest->requestData, interfaceState);

    // Invoke device command here
    unsigned int statusCode = 200;

    DIGITALTWIN_COMMAND_RESULT commandResult = Leds_Command_TurnOffLed(&statusCode);

    if (commandResult == DIGITALTWIN_COMMAND_OK)
    {
        DigitalTwinClientHelper_SetCommandResponse(commandResponse, NULL, statusCode);

    }
    else
    {
        LogError("Failed to execute turnOffLed command");
        const unsigned char errorResponse[] = "\"Failed to execute turnOffLed command\"";
        DigitalTwinClientHelper_SetCommandResponse(commandResponse, errorResponse, statusCode);
    }

}

// DigitalTwinSample_ProcessCommandUpdate receives commands from the server.  This implementation acts as a simple dispatcher
// to the functions to perform the actual processing.
void LedsInterface_ProcessCommandUpdate(const DIGITALTWIN_CLIENT_COMMAND_REQUEST* dtCommandRequest, DIGITALTWIN_CLIENT_COMMAND_RESPONSE* dtCommandResponse, void* userInterfaceContext)
{
    if (strcmp(dtCommandRequest->commandName, LedsInterface_BlinkCommand) == 0)
    {
        LedsInterface_Command_BlinkCallback(dtCommandRequest, dtCommandResponse, userInterfaceContext);
        return;
    }

    if (strcmp(dtCommandRequest->commandName, LedsInterface_TurnOnLedCommand) == 0)
    {
        LedsInterface_Command_TurnOnLedCallback(dtCommandRequest, dtCommandResponse, userInterfaceContext);
        return;
    }

    if (strcmp(dtCommandRequest->commandName, LedsInterface_TurnOffLedCommand) == 0)
    {
        LedsInterface_Command_TurnOffLedCallback(dtCommandRequest, dtCommandResponse, userInterfaceContext);
        return;
    }

    // If the command is not implemented by this interface, by convention we return a 501 error to server.
    LogError("LEDS_INTERFACE: Command name <%s> is not associated with this interface", dtCommandRequest->commandName);
    const unsigned char commandNotImplementedResponse[] = "\"Requested command not implemented on this interface\"";
    (void)DigitalTwinClientHelper_SetCommandResponse(dtCommandResponse, commandNotImplementedResponse, 501);
}

// LedsInterface_InterfaceRegisteredCallback is invoked when this interface
// is successfully or unsuccessfully registered with the service, and also when the interface is deleted.
static void LedsInterface_InterfaceRegisteredCallback(DIGITALTWIN_CLIENT_RESULT dtInterfaceStatus, void* userInterfaceContext)
{
    LogInfo("LedsInterface_InterfaceRegisteredCallback with status=<%s>, userContext=<%p>", MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, dtInterfaceStatus), userInterfaceContext);
    if (dtInterfaceStatus == DIGITALTWIN_CLIENT_OK)
    {
        // Once the interface is registered, send our reported properties to the service.  
        // It *IS* safe to invoke most DigitalTwin API calls from a callback thread like this, though it 
        // is NOT safe to create/destroy/register interfaces now.
        LogInfo("LEDS_INTERFACE: Interface successfully registered.");
    }
    else if (dtInterfaceStatus == DIGITALTWIN_CLIENT_ERROR_INTERFACE_UNREGISTERING)
    {
        // Once an interface is marked as unregistered, it cannot be used for any DigitalTwin SDK calls.
        LogInfo("LEDS_INTERFACE: Interface received unregistering callback.");
    }
    else
    {
        LogError("LEDS_INTERFACE: Interface received failed, status=<%s>.", MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, dtInterfaceStatus));
    }
}

//
// Create DigitalTwin interface client handle
//
DIGITALTWIN_INTERFACE_CLIENT_HANDLE LedsInterface_Create()
{
    DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceHandle;
    DIGITALTWIN_CLIENT_RESULT result;

    memset(&appState, 0, sizeof(LEDS_INTERFACE_STATE));

    if ((result = DigitalTwin_InterfaceClient_Create(LedsInterfaceId,  LedsInterfaceInstanceName, LedsInterface_InterfaceRegisteredCallback, (void*)&appState, &interfaceHandle)) != DIGITALTWIN_CLIENT_OK)
    {
        LogError("LEDS_INTERFACE: Unable to allocate interface client handle for interfaceId=<%s>, interfaceInstanceName=<%s>, error=<%s>", LedsInterfaceId, LedsInterfaceInstanceName, MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, result));
        interfaceHandle = NULL;
    }

    else if ((result = DigitalTwin_InterfaceClient_SetCommandsCallback(interfaceHandle, LedsInterface_ProcessCommandUpdate, (void*)&appState)) != DIGITALTWIN_CLIENT_OK)
    {
        LogError("LEDS_INTERFACE: DigitalTwin_InterfaceClient_SetCommandsCallbacks failed. error=<%s>", MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, result));
        LedsInterface_Close(interfaceHandle);
        interfaceHandle = NULL;
    }

    else
    {
        LogInfo("LEDS_INTERFACE: Created DIGITALTWIN_INTERFACE_CLIENT_HANDLE successfully for interfaceId=<%s>, interfaceInstanceName=<%s>, handle=<%p>", LedsInterfaceId, LedsInterfaceInstanceName, interfaceHandle);
        appState.interfaceClientHandle = interfaceHandle;
    }

    return interfaceHandle;
}

void LedsInterface_Close(DIGITALTWIN_INTERFACE_CLIENT_HANDLE digitalTwinInterfaceClientHandle)
{
    // On shutdown, in general the first call made should be to DigitalTwin_InterfaceClient_Destroy.
    // This will block if there are any active callbacks in this interface, and then
    // mark the underlying handle such that no future callbacks shall come to it.
    DigitalTwin_InterfaceClient_Destroy(digitalTwinInterfaceClientHandle);

    // After DigitalTwin_InterfaceClient_Destroy returns, it is safe to assume
    // no more callbacks shall arrive for this interface and it is OK to free
    // resources callbacks otherwise may have needed.

}
