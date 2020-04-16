#include "pch.h"

#include "ScriptingCore.h"

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
	fputs("\n", stderr);
	if (logFile)
		fputs(str, logFile);
		fputs("\n", logFile);
}

void OutputScriptInfo(const char* msg)
{
#ifdef WIN32
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbBefore;
	GetConsoleScreenBufferInfo(hstdout, &csbBefore);
	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	core->rawprint("[SCRIPT]  ");

	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	core->rawprint(msg);

	SetConsoleTextAttribute(hstdout, csbBefore.wAttributes);
	core->rawprint("\n");
#else
	core->printf("%c[0;36m[SCRIPT]%c[0;37m %s\n", 27, 27, msg);
#endif
}

void OutputDebug(const char* msg)
{
#ifdef _DEBUG
	OutputMessage(msg);
#endif
}

void OutputMessage(const char* msg)
{
#ifdef WIN32
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbBefore;
	GetConsoleScreenBufferInfo(hstdout, &csbBefore);
	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN);
	core->rawprint("[MODULE]  ");

	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	core->rawprint(msg);

	SetConsoleTextAttribute(hstdout, csbBefore.wAttributes);
	core->rawprint("\n");
#else
	core->printf("%c[0;32m[MODULE]%c[0;37m %s\n", 27, 27, msg);
#endif
}

void OutputWarning(const char* msg)
{
#ifdef WIN32
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbBefore;
	GetConsoleScreenBufferInfo(hstdout, &csbBefore);
	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	core->rawprint("[WARNING] ");

	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	core->rawprint(msg);

	SetConsoleTextAttribute(hstdout, csbBefore.wAttributes);
	core->rawprint("\n");
#else
	core->printf("%c[0;30m[WARNING]%c[0;37m %s\n", 27, 27, msg);
#endif
}

void OutputError(const char* msg)
{
#ifdef WIN32
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbBefore;
	GetConsoleScreenBufferInfo(hstdout, &csbBefore);
	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	core->rawprint("[ERROR]   ");

	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	core->rawprint(msg);

	SetConsoleTextAttribute(hstdout, csbBefore.wAttributes);
	core->rawprint("\n");
#else
	core->printf("%c[0;30m[ERROR]%c[0;37m %s\n", 27, 27, msg);
#endif
}
