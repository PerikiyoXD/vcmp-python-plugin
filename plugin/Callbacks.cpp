#include "pch.h"
#include "Events.h"

#include "Callbacks.h"

bool usesNewCallbacks = false;
PluginCallbacks* vcmpCallbacks = nullptr;
py::module* pythonModuleCallbacks = nullptr;


void RegisterCallbacks(PluginCallbacks* callbacks)
{
	// Check if we want to register new version functions
	if (callbacks->structSize == sizeof(PluginCallbacksNew))
		usesNewCallbacks = true;

	// Register the callbacks
	callbacks->OnServerInitialise = OnServerInitialise;
	callbacks->OnServerShutdown = OnServerShutdown;
	callbacks->OnServerFrame = OnServerFrame;
	callbacks->OnPluginCommand = OnPluginCommand;
	callbacks->OnIncomingConnection = OnIncomingConnection;
	callbacks->OnClientScriptData = OnClientScriptData;

	callbacks->OnPlayerConnect = OnPlayerConnect;
	callbacks->OnPlayerDisconnect = OnPlayerDisconnect;

	callbacks->OnPlayerRequestClass = OnPlayerRequestClass;
	callbacks->OnPlayerRequestSpawn = OnPlayerRequestSpawn;
	callbacks->OnPlayerSpawn = OnPlayerSpawn;
	callbacks->OnPlayerDeath = OnPlayerDeath;
	callbacks->OnPlayerUpdate = OnPlayerUpdate;

	callbacks->OnPlayerRequestEnterVehicle = OnPlayerRequestEnterVehicle;
	callbacks->OnPlayerEnterVehicle = OnPlayerEnterVehicle;
	callbacks->OnPlayerExitVehicle = OnPlayerExitVehicle;

	callbacks->OnPlayerNameChange = OnPlayerNameChange;
	callbacks->OnPlayerStateChange = OnPlayerStateChange;
	callbacks->OnPlayerActionChange = OnPlayerActionChange;
	callbacks->OnPlayerOnFireChange = OnPlayerOnFireChange;
	callbacks->OnPlayerCrouchChange = OnPlayerCrouchChange;
	callbacks->OnPlayerGameKeysChange = OnPlayerGameKeysChange;
	callbacks->OnPlayerBeginTyping = OnPlayerBeginTyping;
	callbacks->OnPlayerEndTyping = OnPlayerEndTyping;
	callbacks->OnPlayerAwayChange = OnPlayerAwayChange;

	callbacks->OnPlayerMessage = OnPlayerMessage;
	callbacks->OnPlayerCommand = OnPlayerCommand;
	callbacks->OnPlayerPrivateMessage = OnPlayerPrivateMessage;

	callbacks->OnPlayerKeyBindDown = OnPlayerKeyBindDown;
	callbacks->OnPlayerKeyBindUp = OnPlayerKeyBindUp;
	callbacks->OnPlayerSpectate = OnPlayerSpectate;
	callbacks->OnPlayerCrashReport = OnPlayerCrashReport;

	callbacks->OnVehicleUpdate = OnVehicleUpdate;
	callbacks->OnVehicleExplode = OnVehicleExplode;
	callbacks->OnVehicleRespawn = OnVehicleRespawn;

	callbacks->OnObjectShot = OnObjectShot;
	callbacks->OnObjectTouched = OnObjectTouched;

	callbacks->OnPickupPickAttempt = OnPickupPickAttempt;
	callbacks->OnPickupPicked = OnPickupPicked;
	callbacks->OnPickupRespawn = OnPickupRespawn;

	callbacks->OnCheckpointEntered = OnCheckpointEntered;
	callbacks->OnCheckpointExited = OnCheckpointExited;

	callbacks->OnEntityPoolChange = OnEntityPoolChange;
	callbacks->OnServerPerformanceReport = OnServerPerformanceReport;

	if (usesNewCallbacks) {
		reinterpret_cast<PluginCallbacksNew*>(callbacks)->OnPlayerModuleList = OnPlayerModuleList;
	}
}