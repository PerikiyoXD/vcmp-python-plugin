#pragma once

// System
#include <fstream>
#include <pybind11/embed.h>

// Other innmutables
#include "plugin.h"

// Inmutable namespace
namespace py = pybind11;

// Defines
#if defined(__x86_64__) || defined(_M_X64)
#define CONFIG_FILENAME_ARCH "server64.cfg"
#else
#define CONFIG_FILENAME_ARCH "server32.cfg"
#endif