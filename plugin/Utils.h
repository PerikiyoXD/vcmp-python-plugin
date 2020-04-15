#pragma once

extern FILE* logFile;

bool ReadServerConfig(const char* filename, std::string& moduleName);
void PrintStdErrAndLogFile(const char* str);