#include "pch.h"

#include "Utils.h"

FILE* logFile = nullptr;

bool ReadServerConfig(const char* filename, std::string& moduleName)
{
	std::ifstream f(filename, std::ios::binary);

	std::string prefix("pymodule ");
	for (std::string line; std::getline(f, line);)
	{
		if (line.compare(0, prefix.size(), prefix) == 0)
		{
			moduleName = line.substr(prefix.size());
			return true;
		}
	}
	return false;
}


void PrintStdErrAndLogFile(const char* str)
{
	fputs(str, stderr);
	if (logFile)
		fputs(str, logFile);
}