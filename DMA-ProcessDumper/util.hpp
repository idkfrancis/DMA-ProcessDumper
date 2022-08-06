#pragma once
#include <Windows.h>
#include <memory>
#include <string_view>
#include <TlHelp32.h>

namespace util
{
	inline std::string get_path() {
		char buffer[MAX_PATH];
		GetModuleFileNameA(NULL, buffer, MAX_PATH);
		std::string::size_type pos = std::string(buffer).find_last_of("\\/");
		return std::string(buffer).substr(0, ++pos);
	}
}