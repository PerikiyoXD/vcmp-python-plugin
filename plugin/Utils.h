#pragma once

extern FILE* logFile;

bool ReadServerConfig(const char* filename, std::string& moduleName);
void PrintStdErrAndLogFile(const char* str);
void OutputScriptInfo(const char* msg);
void OutputDebug(const char* msg);
void OutputMessage(const char* msg);
void OutputWarning(const char* msg);
void OutputError(const char* msg);
