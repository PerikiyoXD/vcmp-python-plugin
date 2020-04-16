#pragma once

class ScriptingCore
{
	// Singleton pattern
private:
	ScriptingCore();
	static ScriptingCore* instance;
public:
	static ScriptingCore* Instance() {
		if (instance == nullptr) {
			// Create instance
			instance = new ScriptingCore();
		}
		refCount++;
		return instance;
	}

	// Class methods, functions, fields
public:
	~ScriptingCore();
	void printf(char* pszFormat, ...);
	void rawprint(const char* pszOutput);
	void LoadScript();
private:
	static uint32_t refCount;
	static FILE* pLogFile;
};

extern ScriptingCore* core;
