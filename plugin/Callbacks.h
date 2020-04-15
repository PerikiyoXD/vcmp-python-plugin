#pragma once

extern bool usesNewCallbacks;

extern PluginCallbacks* vcmpCallbacks;

extern py::module* pythonModuleCallbacks;

void RegisterCallbacks(PluginCallbacks* callbacks);