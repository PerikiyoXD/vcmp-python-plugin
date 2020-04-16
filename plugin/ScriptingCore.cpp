#include "pch.h"

#include "Utils.h"

#include "ScriptingCore.h"

ScriptingCore* ScriptingCore::instance = nullptr;
uint32_t ScriptingCore::refCount = 0;
FILE* ScriptingCore::pLogFile = nullptr;

ScriptingCore::ScriptingCore()
{
	if(logFile != nullptr)
		this->pLogFile = logFile;
	py::initialize_interpreter();
}

ScriptingCore::~ScriptingCore()
{
	py::finalize_interpreter();
	this->pLogFile = nullptr;
}

void ScriptingCore::printf(char* pszFormat, ...)
{
	char szInitBuffer[512];
	va_list va;

	va_start(va, pszFormat);
	{
		int nChars = vsnprintf(szInitBuffer, sizeof(szInitBuffer), pszFormat, va);
		if (nChars > sizeof(szInitBuffer) - 1)
		{
			char* szBuffer = new char[(char)nChars + 1];
			vsnprintf(szBuffer, nChars, pszFormat, va);
			this->rawprint(szBuffer);

			delete[] szBuffer;
		}
		else
			this->rawprint(szInitBuffer);
	}
	va_end(va);
}

void ScriptingCore::rawprint(const char* pszOutput)
{
	fputs(pszOutput, stdout);
	if (this->pLogFile != nullptr)
		fprintf(this->pLogFile, "%s", pszOutput);
}
void ScriptingCore::LoadScript()
{
	OutputDebug("Loading script...");
	py::eval_file("scripts/main.py");
}
